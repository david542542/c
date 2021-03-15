// films.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll2.h"

#define FGETS(ptr, len)  fgets(str, len, stdin); str[strcspn(str, "\n")] = 0

void showmovies(Item item);
int main(void)
{
    // Declare the variables we'll be using
    auto LinkedList movies; // LinkedList is stored on the stack, so don't need to `free` it
    Item temp;

    // Initialize
    InitializeList(&movies);

    // Append
    while(true)
    {
        // check to make sure the list is not already full
        if (ListIsFull(&movies)) {
            fprintf(stderr, "The list is full or no memory available.");
            break;
        };

        // Write title to temp.title, removing newline
        puts("Enter movie title (blank line to quit): ");
        fgets(temp.title, TLEN-1, stdin);
        temp.title[strcspn(temp.title, "\n")] = 0; // get span until character in string
        if (*temp.title == 0) break;

        // write year to temp.year, eating any chars after it
        // note: `year` is an int and not a (char) buffer of sorts
        puts("Enter the year it was released");
        scanf("%d", &temp.year);
        while(getchar() != '\n') continue;

        // add the item to the LinkedList
        bool item_added = AddItem(temp, &movies);
        if (!item_added) {
            fprintf(stderr, "There was a problem allocating memory.\n");
            break;
        }

    }

    // Display (Apply a function)
    if (ListIsEmpty(&movies))
        printf("No data entered.\n");
    else {
        printf("Your list contains %zu items.\n", ListItemCount(&movies));
        printf("Retrieving movie list...\n");
        Apply(&movies, showmovies);
    }

    // Clean up
    EmptyTheList(&movies);

}

void showmovies(Item item)
{
    static int count=0;
    count++;
    printf("%2d. Movie: %s (%d)\n", count, item.title, item.year);
}





int main2(void) 
{
    // if it's a pointer such as how *Node (typdef struct node*) is, then we need to malloc the memory
    // note: item is a movie

    // Note: if we separate the definition so it's not part of the assignment, we must explicitly declare the type
    /* LinkedList movies1; */
    /* movies1 = (LinkedList) { */
        /* .head=&(Node){{"Avatar", 2010}, NULL}, */
        /* .size=1 */
    /* }; */

    /* LinkedList movies2 = { */
        /* .head=&(Node){{"Avatar", 2010}, NULL}, */
        /* .size=1 */
    /* }; */

    /* LinkedList movies3; */
    /* Item rocky2 = {"Rocky", 1980}; */
    /* movies3.head = &(Node){rocky2, NULL}; */

    /* LinkedList movies4; */
    /* Node x = {{"Species", 2000}, NULL}; */
    /* movies4 = (LinkedList){.head=&x, .size=4}; */


    /* Item rocky = {"Rocky", 1980}; */
    /* Node first = {rocky, NULL}; */
    /* Node *first_p = &(Node){rocky, NULL}; */
    /* Node second = {{"Rocky", 1980}, NULL}; */
    /* Node *second_p = &(Node){{"Rocky", 1980}, NULL}; */
    /* LinkedList one = { */
        /* .head = &(Node){{"Rocky", 1980}, NULL}, */
        /* .size = 1 */
    /* }; */
    /* LinkedList two = {.head = &second, .size=1}; */
    /* LinkedList *three = &(LinkedList){ */
        /* .head = &(Node){{"Rocky", 1980}, NULL}, */
    /* }; */
    /* printf("%s\n", three->head->item.title); */





















    /* struct node *first = &(struct node){{"Rocky", 1980}, NULL}; */
    /* List movies = malloc(sizeof(Item)); */
    /* movies->item = avatar; */
    /* printf("Movie: %s\n", movies->item.title); */

    /* Node* current; */
    /* Node* head = malloc(sizeof(Item)); */
    /* head->item = (Item) {"Molly", 9}; */
    /* current = head; */
    /* printf("Movie: %s\n", current->item.title); */

    /* // can create the item directly on the stack if it's not a pointer */
    /* Node movies2; */
    /* movies2.item = avatar; */
    /* printf("Movie: %s\n", movies->item.title); */

}
