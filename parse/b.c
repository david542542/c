// b.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b.h"

static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfun)(Item item));
static void DeleteAllNodes(Trnode *root);

void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

Bool TreeIsEmpty(const Tree *ptree)
{
    return ptree->size == 0;
}
Bool TreeIsFull(const Tree *ptree) {
    return ptree->size == MAXITEMS;
}

size_t TreeItemCount(const Tree *ptree) {
    return ptree->size;
}

static Trnode* MakeNodeFromItem(const Item *pi)
{
    Trnode *new_node = malloc(sizeof(Trnode));
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't malloc tree node\n");
        exit(EXIT_FAILURE);
    }
    // need to update the parent when added
    new_node->item   = *pi;
    new_node->left   = NULL;
    new_node->right  = NULL;
    new_node->parent = NULL;
    return new_node;
}

static int CmpNodes(const Item *i1, const Item *i2)
{
    int cmp;
    cmp = strcmp(i1->petname, i2->petname);
    if (cmp==0) strcmp(i1->petkind, i2->petkind);
    return cmp;
}

static Trnode* SeekItem(const Item *pi, const Tree *ptree)
{
    Trnode *root = ptree->root;
    if (!root) 
        return NULL;

    while (root)
    {
        int cmp = CmpNodes(pi, &root->item);
        if (cmp==0) 
            break;
        root = (cmp<0)? root->left : root->right;
    }
    return root;
}

Bool AddItem(Tree *ptree, const Item *pi)
{
    
    // 1. see if there is space to add a new node
    if (TreeIsFull(ptree)) 
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }

    // 2. see if that item already exists (we skip on duplicates)
    if (SeekItem(pi, ptree) != NULL)
    {
        fprintf(stderr, "Item already added\n");
        return false;
    }

    // 3. add the new node
    Trnode *new_node = MakeNodeFromItem(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    ptree->size++;

    // 4. add node to the tree and update the parent of the node
    if (ptree->root == NULL)
        ptree->root = new_node;
    else {
        AddNode(new_node, ptree->root);
    }
    return true;

};

static void AddNode(Trnode *new_node, Trnode *root)
{
    int comp = CmpNodes(&new_node->item, &root->item);

    // duplicate
    if (comp == 0) {
        fprintf(stderr, "Location error in AddNode() -- No dupes allowed\n");
        exit(EXIT_FAILURE);
    } 

    // less than --> add to left side
    else if (comp < 0) {
        if (root->left == NULL) {
            root->left = new_node;
            new_node->parent = root;
        }
        else
            AddNode(new_node, root->left);
    }

    // greater than --> add to right side
    else {
        if (root->right == NULL) {
            root->right = new_node;
            new_node->parent = root;
        }
        else
            AddNode(new_node, root->right);
    }
}

Bool InTree(const Tree *ptree, const Item *pi)
{
    return SeekItem(pi, ptree) ? true : false;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL) {
        InOrder(root->left, pfun);
        pfun(root->item);
        InOrder(root->right, pfun);
    }
}

void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);

    *ptree = (Tree){.size=0, .root=NULL};
}
static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static Trnode* SeekInsertionParent(const Trnode *root, const Trnode *pnode)
{
    int cmp = CmpNodes(&(pnode->item), &(root->item));
    if (cmp == 0) return NULL; // ignore this for now
    Trnode *child = (cmp < 0)? root->left : root->right;
    if (child == NULL)
        return (Trnode*) root; // so it doesn't complain about const discard
    else
        return SeekInsertionParent(child, pnode);
}

Bool DeleteItem(Tree *ptree, const Item *pi)
{
    Trnode *node = SeekItem(pi, ptree);
    if (node == NULL) return false;
    Trnode *parent = node->parent;
    if (parent==NULL) {
        fprintf(stderr, "Deleting root node not supported.\n");
        return false; // don't allow deleting root node
    }

    printf("Deleting: %s...\n", node->item.petname);

    // (1) if no children, then it's a leaf, just delete it
    if (!node->left && !node->right) {
        (node->parent->left == node) ? (node->parent->left=NULL) : (node->parent->right=NULL);
        free(node);
    }

    // (2) if it has one child, link that child to the parent then free the node
    else if (!node->left || !node->right) {
        Trnode *descendant = (node->left)? node->left : node->right;
        descendant->parent = parent;
        if (parent && parent->left == node)
            parent->left = descendant;
        else if (parent && parent->right == node)
            parent->right = descendant;
    }

    // (3) if it has two children, then:
    //     (a) attach the child same-side child to the parent node;
    //     (b) using the root of the attachment, find the place to insert the other-side child
    else {
        Trnode *insert_at, *other_side;
        if (parent->left == node) {
            node->left->parent = parent;
            parent->left = node->left;
            other_side = node->right;
        } else {
            node->right->parent = parent;
            parent->right = node->right;
            other_side = node->left;
        }

        free(node);
        insert_at = SeekInsertionParent(parent, other_side);

        if (insert_at->left == NULL) {
            insert_at->left=other_side;
            other_side->parent=insert_at;
        } else {
            insert_at->right=other_side;
            other_side->parent=insert_at;
        }
    }
    ptree->size--;
    free(node);
    return true;

}

