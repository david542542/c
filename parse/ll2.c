/* ll2.c */
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include "ll2.h"

// set the list to empty
void InitializeList(LinkedList *plist) 
{
    plist->head = NULL;
    plist->size = 0;
}

// return true if the list is empty
bool ListIsEmpty(const LinkedList *plist)
{
    return (plist->head == NULL)? true : false;
}

// returns true if cannot allocate another node
bool ListIsFull(const LinkedList *plist)
{
    Node *node = malloc(sizeof(Node));
    bool is_full = (node == NULL)? true : false;
    free(node);
    return is_full;
}

// returns number of nodes
size_t ListItemCount(const LinkedList *plist)
{
    // short-form way to do it
    /* return plist->size; */

    size_t size=0;
    Node *pnode = plist->head;

    while (pnode) {
        size++;
        pnode = pnode->next;
    }

    return size;
}

// For example, using the static qualifier to make this method private
static void CopyItemToNode(Item item, Node *pnode)
{
    pnode->item = item;
    pnode->next = NULL;
}
// creates node to hold the item and adds it to the end of the list
bool AddItem(Item item, LinkedList *plist)
{
    Node *pnode = malloc(sizeof (Node));
    if (pnode == NULL)
        return false;

    // copy the Item to the new malloc'd node.
    // note, since it's passed as a copy we don't need to do anything else
    /* pnode->item = item; */
    /* pnode->next = NULL; */
    CopyItemToNode(item, pnode);
    plist->size++;

    // if it's currently an empty LinkedList, just add it to the head and leave
    if (ListIsEmpty(plist)) {
        plist->head=pnode;
    }
    else {
        // slow way -- traverse to end of list and add it there
        Node *cur = plist->head;
        while (cur->next)
            cur=cur->next;
        cur->next=pnode;
    }
    return true;
}

// free memory allocated by malloc()
void EmptyTheList(LinkedList *plist)
{
    Node *next, *head = plist->head;
    while (head) {
        // get the next node before freeing the current
        Node *next = head->next;
        free(head);
        head = next;
    }
    plist->size = 0;
}

// visit each node and execute function pointed to by pfun
void Apply(LinkedList *plist, void (*pfun)(Item item))
{
    Node *cur = plist->head;
    while (cur)
    {
        pfun(cur->item);
        cur=cur->next;
    }
}
