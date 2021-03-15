// q.h

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
#include <stddef.h>

// Inset item type here and max count
typedef int Item;
#define MAXQUEUE 10
extern int a;
typedef struct node {
    Item        item;
    struct node *next; // next means closer to the front
} Node;

typedef struct queue {
    Node*   front;
    Node*   rear;
    size_t  items;
} Queue;

void    InitializeQueue (      Queue *pq);

bool    QueueIsFull     (const Queue *pq);
bool    QueueIsEmpty    (const Queue *pq);
size_t  QueueItemCount  (const Queue *pq);

// Enqueue: add item to rear of queue, returns True if added
bool    EnQueue         (      Queue *pq, Item item);

// Dequeue: remove item from front of queue and return that, if empty will return NULL
// Note: we free the dequeued item, 
bool    DeQueue         (Queue *pq, Item *item);

void    EmptyTheQueue   (      Queue *pq);
void    PrintTheQueue   (const Queue *pq, void (*prnt)(const Item *item, int pos));

#endif /* ifndef _QUEUE_H_ */
