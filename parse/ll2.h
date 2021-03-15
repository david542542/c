// ll2.h

#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#include <stddef.h>

// size of array to hold the title
#define TLEN 45

struct movie {
    char title[TLEN];
    int year;
};

// general type definitions
typedef struct movie Item;

typedef struct node {
    Item        item;
    struct node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    size_t      size;
} LinkedList;

// function prototypes

// 1. init()
// operation:       initialize a list
// preconditions:   `plist` points to a LinkedList
// postconditions:  the LinkedList is initialized to empty
void InitializeList(LinkedList* plist);

// 2. isempty()
// operation:       check if the list is empty or not
// preconditions:   `plist` points to an initialized LinkedList
// postconditions:  returns True if list is empty else False
bool ListIsEmpty(const LinkedList *plist);

// 3. isfull()
// operation:       determines if the list if full or not
// preconditions:   `plist` points to an initialized LinkedList
// postconditions:  returns True if list is full else False
bool ListIsFull(const LinkedList *plist);

// 4. size()
// operation:       determines the number of items in the list
// preconditions:   `plist` points to an initialized LinkedList
// postconditions:  returns number of items in the list
size_t ListItemCount(const LinkedList *plist);

// 5. append()
// operation:       add item to end of list
// preconditions:   `item` points to an Item, `plist` points to an initialized LinkedList
// postconditions:  will add item to list if possible and return True, else False
bool AddItem(Item item, LinkedList *plist);

// 6. empty()
// operation:       empty the list and free the memory
// preconditions:   `plist` points to an initialized LinkedList
// postconditions:  memory is freed and the list is set to empty
void EmptyTheList(LinkedList *plist);

// 7. apply()
// operation:       apply a function to each item in list
// preconditions:   `plist` points to an initialized LinkedList
//                  pfun points to a function that takes an Item argument and has no return value
// postconditions:  the function pointed to by *pfun is executed once for each item in the list
void Apply(LinkedList *plist, void (*pfun)(Item item));

#endif /* ifndef LIST_H_ */

