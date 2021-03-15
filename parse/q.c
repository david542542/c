// q.c
#include <stdio.h>
#include <stdlib.h>
#include "q.h"

void InitializeQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}

size_t QueueItemCount(const Queue *pq)
{
    return pq->items;
}

static void PrintTheQueueInternal(Node *node, void (prnt)(const Item *item, int pos), int pos) {
    if (node == NULL)
        return;
    else {
        PrintTheQueueInternal(node->next, prnt, ++pos);
        prnt(&(node->item), pos);
        return;
    }
}
void PrintTheQueue (const Queue *pq, void (*prnt)(const Item *item, int pos)) {
    if (QueueIsEmpty(pq))
        printf("Empty!");
    else
        PrintTheQueueInternal(pq->front, prnt, 0);
}
static void CopyData(Node *to_node, Item from_item)
{
    to_node->item = from_item;
}
bool EnQueue(Queue *pq, Item item) {
    
    // 1. create a new node
    Node *node;
    if (QueueIsFull(pq))
        return false;
    else {
        node = malloc(sizeof(Node));
        if (node == NULL) {
            fprintf(stderr, "Unable to allocate memory");
            exit(EXIT_FAILURE);
        }
    }
    
    // 2. Copy the item to the node, update next
    CopyData(node, item);
    /* node->item = item; */
    node->next = NULL;

    // 3. update the rear of the queue (and front if first object)
    if (QueueIsEmpty(pq))
        pq->front = node;
    else
        pq->rear->next = node;

    pq->rear  = node;

    // 4. update the queue size
    pq->items++;
    return true;
}

bool DeQueue(Queue *pq, Item* pitem) {
    if (QueueIsEmpty(pq))
        return false;

    // 1. Copy Item to the passed-in variable
    Node *current_front = pq->front;
    *pitem = current_front->item;

    // 2. Update front of queue
    pq->front = current_front->next;

    // 3. free memory from previous
    free(current_front);

    // 4. update size of queue (if 0, set rear=NULL too)
    pq->items--;
    if (pq->items == 0) pq->rear=NULL;

    return true;

}

void EmptyTheQueue(Queue *pq) {

    Item dummy;
    while (!QueueIsEmpty(pq))
        DeQueue(pq, &dummy); // can we do DeQueue(pq, &(Item){});
    Node *next, *current = pq->front;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    // short-hand way to set everything to zero again
    InitializeQueue(pq);    
}
