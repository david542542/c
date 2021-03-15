#include <stdio.h>
#include <stddef.h>
#include <stdint.h>


int sum_array(int nums[], size_t size) {
    printf("The sum of the array within sum_array is: %zu\n", sizeof((int*) nums)); // this will be 8 now since it's converted to a pointer
    int sum=0;
    for (int i=0; i < size; i++)
        sum += nums[0];
    return sum;
}
int main(void) {

    // td (ptrdiff_t) is address differences, zu (size_t) is the sizeof operator
    // intptr_t, uintptr_t to work with pointers like numbers
    int xar[3] = {1,2,3};
    printf("%d | %d\n", xar[1], *(xar+1));
    int xar2[2][3] = {{1,2,3}, {4,5,6}};
    printf("%d | %d\n", xar2[1][2], *(*(xar2+1)+2));
    int xar3[2][2][2] = {
                          {{1, 2},{3, 4}}, 
                          {{5, 6}, {7, 8}}
                        };
    printf("%d | %d\n", xar3[1][1][1], *(*(*(xar3+1)+1)+1));
    /* return 0; */

    int zippo[4][2] = {{1,2}, {3,4}, {5,6}, {7,8}};
    printf("The value at zippo[1][1] is: %d (%p)\n", zippo[2][1], &zippo[2][1]);
    printf("The value at zippo[1][1] is: %d (%p)\n", *(*(zippo+2)+1), *(zippo+2)+1);

    printf("Zippo[2][1] --> %d (+%td)\n", *(*(zippo+2)+1), *(zippo+2)+1 - *zippo); // basically means the 5th element has value 6
    printf("Zippo[0] = %p (an address), Zippo[0][0] = %d (a value)\n", zippo[0], zippo[0][0]); // in other words, the lowest-level item represents the type of the array (int) in that case, but previously it'll be an address
    return 0;
    /* printf("Zippo element has size: %td\n", (char*)(zippo+1)-(char*)zippo); */
    /* printf("Zippo element entry has size: %td\n", (char*)(zippo+1)-(char*)zippo); */
    /* printf("Array zippo[1]=%p or %p\n", &zippo[1][1], &(zippo+1)+1); */

    /* printf("The value at zippo[0][1] is: %d (%p)\n", *(*zippo+1), zippo */

    int array[3];
    int *pointer1, *pointer2;

    pointer1++; // OK  -- increment the memory address of pointer1 (but it's not initialized?)
    /* array++;    // BAD -- cannot do because an array is not a lvalue */

    pointer2 = pointer1 + 2;                    // OK  -- set the memory address of pointer2 to 2-ints past pointer1
    ptrdiff_t pointer3 = &array[2] - &array[1];   // OK -- can also do difference between pointers/arrays, but type will be ptrdiff_t type (like integer)
    ptrdiff_t pointer4 = pointer2 - pointer1;   // OK -- though it should be done on items within the same array.
    /* pointer2 = pointer1 + pointer2; // BAD -- cannot add two pointers together, though can get the difference */

    pointer2 = array + 1;           // OK -- array+i is the same as &array[i]
    /* pointer2 = array * pointer1     // BAD -- again, operations  */
    printf("%d", array+1 == &array[1]);
    return 0;

    int urn[5] = {1,2,8};
    int *ptr1 = urn; // same as &urn[0]; --> *urn is the same thing as &urn[0];
    int *ptr2 = &urn[2];
    printf("Diff is: %d or %d| Ptr diff is: %td\n", *(urn+2) - *urn, *ptr2-*ptr1, ptr2 - ptr1);


    printf("Ptr1=%d, Ptr2=%d, 2=%d", *ptr1, *ptr2, *(urn+1));

    int total = 10;
    int _start = 4;
    int *start = &_start;
    printf("Start address: %p |Uint_ptr: %zu\n", start, (uintptr_t) start); // print it like size_t...
    printf("Total: %d | Start: %p\n", total, start);
    total += *start++;        // the '++' evaluated first...but it doesn't increment after the sequence point
                              // so this comes to: total += *start; start++;
    printf("Total: %d | Start: %p\n", total, start);
    total += *--start;        // the -- evaluates first...and does decrement start (it doesnt need a sequence point)
                              // so this comes to: start--; total += *start;
    printf("Total: %d | Start: %p\n", total, start);
    total += ++(*start);      // increments the value-of start before adding it total.
                              // so this comes to: *start++; total += *start;
    printf("Total: %d | Start: %p\n", total, start);
    /* total += *++start;      // we will first increment the pointer address, then we'll get a garbage value to add to total */
    /* printf("Total: %d | Start: %p\n", total, start); */
    /* total += *++start;      // we will first increment the pointer address, then we'll get a garbage value to add to total */
    /* printf("Total: %d | Start: %p\n", total, start); */
    getchar();

    int arr[] = {1,2,3};
    printf("The sum of the array within main is: %zu\n", sizeof(arr));
    int sum = sum_array(arr, 3);
    printf("The sum of the array is: %d\n", sum);
    int *a = &(int) {4};
    ptrdiff_t b = (a+1) - a;
    ptrdiff_t c = (void*) (a+1) - (void*) a; // actual memory difference
    // pointer arithmetic needs to be done on elements of the same size.
    printf("The first memory address is at: %p and the one after is: %p\n"
           "The difference with pointer arithmetic is: %td\n"
           "And actual difference in memory address is: %td\n",
        (void*) a, (void*) (a+2), b, c);
}









#include <stdlib.h>












/* typedef struct VTable VTable; */

/* typedef struct Thing { */
    /* const VTable *vtable; */
    /* char* name; */
/* } Thing; */

/* typedef struct VTable { */
    /* void (*print)   (Thing* self); */
/* } VTable; */


/* void print_hello(Thing *self) {printf("Hello, %s", self->name);} */
/* static const VTable thing_vtable = { */
    /* .print = print_hello */
/* }; */
/* typedef struct Alien { */
    /* const VTable *vtable; */
    /* char* name; */
    /* // add one more function to vtable -- should that be a stand-alone? do a second 'subclass vtable'? etc. */
/* } Alien; */

/* void alien_function(void) {printf("Alien");} */
/* Alien* init_alien(void) */
/* { */
    /* Alien* alien = malloc(sizeof(Alien)); */
    /* alien->vtable = &thing_vtable; */
    /* [> alien->vtable->alien_function = alien_function; <] */
    /* return alien; */
/* } */

/* int main(void) { */
    /* Alien *alien = init_alien(); */
    /* [> alien->vtable->alien_function(); <] */
    /* return 0; */
/* } */




/* void increment_id(Person* person) { */
    /* person->id = 4; // since this is pass-by-reference from the pointer, it will modify the values in place */
    /* printf("Ok!\n"); */
/* } */
/* void print_name(Person* person) { */
    /* printf("Hello %s (ID: %d)\n", person->name, person->id); */
/* } */
/* static const Person_VTable vtable1 = { */
    /* .print = print_name, */
    /* .adjust = increment_id */
/* }; */
/* Person* init_person( */
        /* Person_VTable vtable */
        /* [> void(*print)(Person*), <] */
        /* [> void(*adjust)(Person*)  <] */
/* ) { */
    /* [> printf("Adjust: %p | Print: %p\n", adjust, print); <] */
    /* Person *person = malloc(sizeof(Person)); */
    /* person->vtable  =  &vtable1; */
    /* return person; */
/* } */
/* int main(void) { */
    /* Person* self = init_person(vtable1); */
    /* self->name = "Greg"; */
    /* self->vtable->print(self); */
    /* self->vtable->adjust(self); */
    /* self->vtable->print(self); */
    /* return 0; */
/* } */
