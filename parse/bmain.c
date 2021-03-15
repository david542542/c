#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "b.h"

void myprint(Item item)
{
    printf("%s (%s)\n", item.petname, item.petkind);
}
int main(void)
{
    Tree pets;
    InitializeTree(&pets);

    Item *annie = &(Item) {.petname="Annie", .petkind="Collie"};
    Item *mike = &(Item) {.petname="Mike", .petkind="Collie"};
    Item *sam = &(Item) {.petname="Sam", .petkind="Collie"};
    Item *rocky = &(Item) {.petname="Rocky", .petkind="Samoyed"};
    Item *dodger1 = &(Item) {.petname="Dodger B", .petkind="Lab"};
    Item *dodger2 = &(Item) {.petname="Dodger A", .petkind="Lab"};
    Item *dodger3 = &(Item) {.petname="Dodger C", .petkind="Lab"};

    AddItem(&pets, sam);
    AddItem(&pets, rocky);
    AddItem(&pets, mike);
    AddItem(&pets, annie);
    AddItem(&pets, dodger1);
    AddItem(&pets, dodger2);
    AddItem(&pets, dodger3);

    Traverse(&pets, myprint);
    DeleteItem(&pets, annie);
    DeleteItem(&pets, mike);
    DeleteItem(&pets, sam);
    DeleteItem(&pets, rocky);
    DeleteItem(&pets, dodger1);
    printf("Size: %zu\n", TreeItemCount(&pets));
    puts("---------------\n");
    Traverse(&pets, myprint);

    DeleteAll(&pets);
    printf("Deleted. Size is: %zu. Empty? %d. Full? %d", pets.size, TreeIsEmpty(&pets), TreeIsFull(&pets));

    printf("\nDone with the book!");


}
