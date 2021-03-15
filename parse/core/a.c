#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* #define foreach(arr) for(int i=0; i < sizeof(arr) / sizeof(*arr); i++) */
#define NDEBUG
#include <assert.h>
#include <stdarg.h>
#define VA(var, num) va_list var; va_start(var, num)
int printme(int num, ...)
{
    /* VA(ap, num); */
    va_list ap;
    va_start(ap, num);
    for (int i=0; i < num; ++i) {
        char* arg = va_arg(ap, char*);
        printf("%d. %s\n", i+1, arg);
    }
    va_end(ap);
    return 1;
}
int printmy(char * format, ...)
{
    // num args
    int num = 0;
    for(char idx=0, c; c=format[idx]; idx++) {
        if (c=='\\' || (c=='%' && format[idx+1]=='%'))
            idx++;
        else if (c=='%')
            num++;
    }

    // print variable args
    va_list ap;
    va_start(ap, format);   // need to give it the last argument before the "..."
    for (int i=0; i < num; ++i) {
        char* arg = va_arg(ap, char*);
        printf("%d. %s\n", i+1, arg);
    }
    va_end(ap);
    
    // return num args received
    return num;

}

int main(void)
{

    int num_args = printmy("Hello something \% \\% %% %s %s %s", "Arg 1", "Arg 2", "Arg 3");
    printf("Num Args Parsed: %d\n", num_args);
    return 0;
    int x = printme(2, "X", "YY");


    return 0;


    int arr1[] = {1,2,9,7,6};
    int arr2[5];
    printf("%zu\n", sizeof arr1);
    memcpy(arr2, arr1, sizeof arr1);
    /* foreach(arr2) printf("%d, ", arr2[i]); */
    for(int i=0; i< sizeof(arr1)/sizeof(*arr1); i++) printf("%d, ", arr2[i]);
    puts("\n");

    int a=7;
    memcpy(arr2, &a, sizeof(int));
    for(int i=0; i< sizeof(arr1)/sizeof(*arr1); i++) printf("%d, ", arr2[i]);
    /* int z=2; */
    /* assert (z>5); */
    /* static_assert(2>4, "Something bad happened!"); */
    /* printf("OK!\n"); */
}


