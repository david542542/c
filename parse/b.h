// b.h

#ifndef _b_h_
#define _b_h_ 
#include <stdbool.h>
#define Bool bool
#define MAXITEMS 10

typedef struct item {
    char petname[20];
    char petkind[20];
} Item;

#define MAXITEMS 10

typedef struct trnode {
    Item item;
    struct trnode *parent;  // useful for a lot of operations
    struct trnode *left;
    struct trnode *right;
} Trnode;

typedef struct tree {
    Trnode *root;
    size_t size;
} Tree;

// function prototypes
void InitializeTree(Tree *ptree);

Bool TreeIsEmpty(const Tree *ptree);
Bool TreeIsFull(const Tree *ptree);
size_t TreeItemCount(const Tree *ptree);

Bool AddItem(Tree *ptree, const Item *pi);
Bool InTree(const Tree *ptree, const Item *pi);
void Traverse(const Tree *ptree, void (*pfun)(Item item));
void DeleteAll(Tree *ptree);
Bool DeleteItem(Tree *ptree, const Item *pi);




#endif /* ifndef _b_h_ */
