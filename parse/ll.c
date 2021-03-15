#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TITLE_MAX 50
void mygets(char buffer[], size_t limit);

struct film {
    char title[TITLE_MAX];
    int rating;
    struct film *next;
};

int main(void)
{
    struct film *head = NULL, *current = NULL;
    char tbuffer[TITLE_MAX];

    while (true) 
    {
        printf("Enter the name of the film (empty line to stop)\n");
        mygets(tbuffer, TITLE_MAX);
        if (*tbuffer=='\0') break;

        if (!head) 
            current = head = malloc (sizeof(struct film));
        else
            current = current->next = malloc (sizeof(struct film));

        current->next = NULL;
        strcpy(current->title, tbuffer);
        printf("Now enter in your rating for it: ");
        scanf("%d", &(current->rating));
        for (int c; (c=getchar()) != '\n' && c != EOF; ); // clean up garbage in scanf -- should probably write a function for this
    }

    // print the Linked List
    current = head;
    for (int i=1; current != NULL; current=current->next)
        printf("Linked List Item #%d: %s (Rating: %d)\n", 
                i++, current->title, current->rating
        );

    // free the list -- need to get the next item pointer before freeing the current
    for(struct film *current=head, *next; current != NULL; current=next) {
        next = current->next;
        free(current);
    }
}

void mygets(char buffer[], size_t limit)
{
    // first non-space char until newline or EOF, 
    // eating any extra chars in buffer
    // will add \0 at the end, so will get up to N-1 chars

    int c, idx=0;
    bool started=false;
    while ((c=getchar()) != EOF && c != '\n')
    {
        if (!started && isspace(c));
        if (idx < limit-1) 
            buffer[idx++] = c;
    }
    buffer[idx] = '\0';

}
