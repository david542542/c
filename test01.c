// test01.c
#include <stdio.h>

extern char* programmer1;   // will error if not defined externally/later
char* programmer2;          // will not error --> will just return NULL if not defined

extern int some_number; // forward declaration, removes ambiguity (especially when across multiple files)
void print_product_name();

int main()
{
    printf("Programmer1: %s\n", programmer1); // 
    printf("Programmer2: %p\n", programmer2); // 
    /* printf("%p\n", programmer2); */
    /* printf("%s\n", instructor); */
    /* printf("Hello -- test1\n"); */
    /* printf("%d\n", four); */
    /* something(); */
}
/* char* programmer1 = "George"; */

// definition of print production
void print_product_name(void)
{
    printf("Coca-cola\n");
}



