#include <stdio.h>
#include "q.h"

void print_num(const Item *item, int pos) {
    printf("%d -> %d\n", pos, *item);
}
int main(void)
{
    Queue line;
    InitializeQueue(&line);
    printf("Is the queue empty? %d\n", QueueIsEmpty(&line));

    Item a=7, b=4, c=2;
    EnQueue(&line, a);
    EnQueue(&line, b);
    EnQueue(&line, c);
    printf("Size of queue is now: %zu. Empty? %d, Full? %d\n", 
            QueueItemCount(&line), QueueIsFull(&line), QueueIsEmpty(&line)
    );
    PrintTheQueue(&line, print_num);

    Item d;
    DeQueue(&line, &d);
    printf("Last item was: %d\n", d);
    printf("Size of queue now: %zu\n", QueueItemCount(&line));

    EmptyTheQueue(&line);
    printf("Queue is now empty? %d\n", QueueIsEmpty(&line));
}
