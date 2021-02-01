#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include <stdint.h>
#include "other/new.h"

void countdown(int n) {

    // Statements in a recursive function that come after the recursive call are
    // executed in the opposite order from which the functions are called.    static intptr_t initial_address=0;
    /* if (n!=0) { */
        /* initial_address = initial_address > (intptr_t) &n ? initial_address : (intptr_t) &n; */
        /* printf("%d...at address %p | offset: -%#zx\n", n, &n, initial_address - (intptr_t) &n); // pushing upto the stack (will grow down...) */
        /* countdown(n-1); */
        /* printf("%d...at address %p | offset: -%#zx\n", n, &n, initial_address - (intptr_t) &n); // pushing upto the stack (will grow down...) */
    /* } else  */
        /* printf("Liftoff!\n"); */
}
void print_binary(int n) {
    if (n > 1) {
        print_binary(n>>1);
        putchar((n%2+'0'));
    } else {
        putchar(n+'0');
    }
}
void swap(int* a, int* b) {
    // remember, a and be are both memory addresses now!
    // * indirection or dereferencing or value-of
    printf("The address of a is: %p\n", a);
    printf("The address of address-of a is: %p\n", &a);
    int tmp = *a;
    *a=*b;
    *b=tmp;
}
int main(void)
{

    int ax=6;
    short xar[ax];
    for (int i = 0; i < sizeof(xar)/sizeof(*xar); ++i) {
        xar[i]=i*i;
        printf("Element %d = %d\n", i, xar[i]);
    }

    int newarr[10] = {1, [4] = 5, 6, [9]=10}; // same as doing {1,0,0,0,5,6,0,0,10}
    for (int i = 0; i < sizeof(newarr)/sizeof(newarr[0]); ++i) {
        printf("_arr_[%d]=%d\n", i, newarr[i]);
    }
    // if you only *partially* initialize an array, the non-initialized values will be set to zero.
    // but if the array isn't initialized at all, its values are garbage.
    const int arr[4] = {2,4,8,};
    size_t arr_size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    /* const int arr[4]; */
    /* arr[0] = 2; */
    /* size_t num_arr_elements = sizeof(arr); */
    printf("The num of array elements is %zu\n", sizeof(arr)/sizeof(arr[0]));
    for (int i=0, arr_i; arr_i=arr[i], i<4; i++) {
        printf("The int at array index %d is %d\n", i, arr_i);
        printf("The int at array index %d is %d\n", i, arr[i]);
    }
    // swap values of hey, you
    int hey=9, you=6;
    printf("Hey=%d, You=%d\n", hey, you);
    int *hey_ptr = &hey;
    int *you_ptr = &you;

    you_ptr = hey_ptr;
    /* int *tmp_addr = you_ptr; */
    /* int tmp_value = *you_ptr; */
    /* you_ptr = hey_ptr; */
    /* hey_ptr = tmp_addr; */

    printf("Hey=%d, You=%d\n", hey, *you_ptr);

    char * hello    = "Hello";
    char * goodbye  = "Goodbye";
    printf("hello=%s, goodbye=%s\n", hello, goodbye);

    char * tmp_str  = hello;
    hello = goodbye; // here we change the address, not the value at the address
    goodbye = hello; 
    printf("hello=%s, goodbye=%s\n", hello, goodbye);

    /* int tmp_value = *hey_pointer; */
    /* *you_pointer = *hey_pointer; */
    /* *hey_pointer = tmp_value; */
    /* printf("Hey=%d, You=%d\n", hey, you); */
    // hey_pointer ==> address of hey

    return 0;


    char girl1[] = "Cindy";
    char girl2[] = "Carmen";

    printf("Girl1: %s | Girl2: %s\n", girl1, girl2);

    printf("Girl1: %s | Girl2: %s\n", girl1, girl2);

    int x=7;
    int* cc=&x; // cc equals the address of x
    *cc=17;   // the value of cc (which is also the address of x) is now 17
    printf("%d\n", x); // this means the value of x is also 17!


    int a=7, b=27, tmp;
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return 1;



    printf("%s\n", HELLO);
    print_binary(8);
    putchar('\n');
    countdown(7);
    return 1;
    // 1. Send text from stdin to an output file
    // gcc test.c -o test.o && ./test.o <<< "Hello this is something new" > new.txt

    // 2. Send text from a file to an output file
    // gcc test.c -o test.o && ./test.o < test.c > new.txt

    // 3. Or can do an echo and use that as stdin
    // gcc test.c -o test.o && echo 'hello' | ./test.o

    // 4. Or can do the same thing with printf
    // $ gcc test.c -o test.o && printf 'hello%d\n' 44 | ./test.o
    char c;
    bool is_newline = true;
    bool inword = false;
    int num_words = 0;

    while ((c = getchar()) != EOF) {
        if (isspace(c) && inword) 
            num_words ++;
        if (!isspace(c))
            inword = true;
        else
            inword = false;
        if (is_newline) {
            putchar('/'); 
            putchar('/');
            is_newline = false;
        }
        putchar(c);
        if (c=='\n')
            is_newline=true;
    }
    printf("The number of words was %d\n", num_words);
}
