// test01.c

// two ways to compile with extern/multiple files:
//  1. compile both C files together.
//  $ gcc -o combined test01.c test02.c 
//  2. compile both separately and link together 
//  $ gcc -c test01.c && gcc -c test02.c && gcc -o test03 test01.o test02.o
// example of thread-safe vs non-thread-safe
// can only have one uniquely-named DEFINITION between the files being compiled.
#include <stdio.h>
/* extern char* instructor; */
/* extern void something(); // nothing ambiguous with functions -- either declared or defined. */
/* extern int four; */

extern char* programmer1;   // will error if not defined externally/later
char* programmer2;          // will not error --> will just return NULL if not defined

extern int some_number; // forward declaration, removes ambiguity (especially when across multiple files)
void print_product_name();

// extern removes ambiguity on a variable declaration (though not ambiguous with functions)
/* char* programmer1 = "George"; */
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

// make sure with the forward variable declaration we have full definition and not just assignment.
int some_number = 42;




