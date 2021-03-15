#include<stdio.h>

typedef struct Person_ {
    char* name;
    char* parents[2];
} Person;

/* int process(int (*coord)[2], size_t size) */
int process(int coord[][2],  size_t size)
/* int process(int coord[4][2], size_t size) */
{
    int total = 0;
    for (int i=0; i < size; i++){
        for (int j=0; j < 2; j++) {
            total += coord[i][j];
        }
    }
    printf("Size: %zu\n", size);
    return total;
}

void print_arr(int arr[], size_t size) {
    for (int i=0; i<size; i++) printf("%d,", arr[i]);
    putchar('\n');
}
void print_arr2(int (*arr)[3], size_t size) {
    for (int i=0; i<size; i++)
        for (int j=0; j<3; j++)
            printf("%d,", arr[i][j]);
    putchar('\n');
}
int main(void)
{
    print_arr((int[3]) {1,2,3}, 3); // compound literal is like an anonymous array in a sense (doesn't have a name -- it's like a string-literal, for example, not having a variable name)
    print_arr2((int[2][3]) {{1,2,3}, {3,6,9}}, 2);
    print_arr2((int[][3]) {{1,2,3}, {3,6,9}}, 2);
    print_arr2((int(*)[3])(int[2][3]) {{1,2,3}, {3,6,9}}, 2);
    print_arr((int*)(int[]){1,2,93}, 3);    // compound literal can be easily **CAST** to a pointer.
    int d=4;

    int (*xr)[2];
    xr = (int[2][2]) {{1,2},{3,4}};
    int (*xd)[2]  = (int[3][2]) {{1,2},{3,4},{5,6}};
    // xd

    /* int dd[d] = {1,2,3,4}; // variable-length arrays cannot be initialized! */
    // and VLAs must have automatic storage duration (i.e., be within a function/function param and not use extern or static)
    int coords[3][2] = {{1,2}, {3,4}, {5,6}};
    int total = process(coords, sizeof(coords)/sizeof(*coords));
    printf("The total is: %d\n", total);
    return 0;
    int *a1  = (int[2]) {1,2};  // this is ok (from ptr)
    int a3[] = {1,2};
    /* int a4[] = a3;              // this is not ok (cannot initialize from another array); */
    /* int a2[] = (int[2]) {1,2};  // this is not ok (from array, cannot initialize with compound literal) */

    int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
    int (*zippo_ptr)[2];    // zippo_ptr points to an aray of 2 ints
    int* zippo_ptr_2[2];    // this is not what we want --> this just creates an array of two pointers to ints.
    zippo_ptr = zippo;
    printf("Hello, [2][1]=%d\n", zippo_ptr[2][1]);



    int *xx = (int[2]){1,2};    // this is ok
    /* int yy[2] = (int[2]){1,2};  // not ok to initialize array with compound literal */
    int zz[2] = {1,2};          // but can initialize with a diret array type

    int *p = (int [3]){1,2,3};
    p[0] = 4;
    int *z = (int[2]){1,2};
    printf("{%d,%d}\n", z[0], z[1]);
    int x[2][2] = {{1,2}, {3,4}};
    /* *(x+1) = 3; */
    *(*(x+1)+1) = 7;
    printf("x[1][1]=%d\n", x[1][1]);
    Person jack = {.name="Jack", .parents={"Jim", "Julia"}};
    Person tom = {.name="Tom", .parents={"Terry", "Tina"}};
    Person bill = {.name="Bill", .parents={"Brad", "Brianne"}};

    Person friends[2] = {jack, tom};
    Person friends_2[1] = {bill};
    Person* friends_3p[3] = {&jack, &tom, &bill};

    // assignment to an array...not a possibility
    /* friends = friends_2;  // friends array is not an lvalue -- type Person [2] */
    /* &friends = 1234;      // this really makes not sense -- its the address of Person* [2] */

    friends[0] = tom;   // can assign to a new struct
    /* friends[1] = (Person) &tom; */
    friends_3p[0] = &tom;
    friends_3p[0] = (Person*) 1234; // can assign a struct to a new memory address (if a ptr) or a new object, so the struct itself is an lvalue, and all its non-array fields.
    // The &  -- address-of operator -- cannot be used as an lvalue


    int a = 2, b=7;
    int *a_ptr = &a;
    printf("a_ptr val: %d | a_ptr addr: %p\n", *a_ptr, (void*) a_ptr);
    *a_ptr = 3; // can update the the value-of
    printf("a_ptr val: %d | a_ptr addr: %p\n", *a_ptr, (void*) a_ptr);
    /* &a_ptr = &b; // this makes no sense, since a_ptr is already the pointer address, this gets the address of the pointer (not the address the pointer points to)! */
    a_ptr = &b;     // but this is ok, since a_ptr is already the address, and now we're just changing the address that the pointer points to.
    printf("a_ptr val: %d | a_ptr addr: %p\n", *a_ptr, (void*) a_ptr);



    /* Person friends[2]; */


    printf("Running\n");
}
