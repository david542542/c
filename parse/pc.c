#include <stdio.h>
#define SQUARE(x)   (x*x)
#define MEAN(x,y)   ((x+y)/2)
#define PSQR(x) printf("The square of " #x " is %d.\n", ((x)*(x)))  // note that the #x goes outside the string.
#define TELL(x) printf("The variable of x is " #x ".\n")            // The "x" argument is shown with the #x
#define PRNT(x, y) printf("X is %s and Y is %s\n", #x, #y)
/* #define _PX(x)   x ## 1 */
#define PX(x)   x ## n
#define XNAME(n)    x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n)
#define PRINT(type) print_ ## type
#define PR(X, ...)     printf("Message " #X ": " __VA_ARGS__)
#define PR2(...)    printf(__VA_ARGS__)
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#define abs(x) ((x)>0? (x): -(x))

// example of defining a debug
#define DEBUG
#ifdef DEBUG
    #define DEBUG_PRINT(...) printf("File: %s, Funtion: %s (%d) --  ", __FILE__, __func__, __LINE__); printf(__VA_ARGS__); putchar('\n')
#else
    #define DEBUG_PRINT(...)
#endif
/* #define DEBUG_PRINT(...)  */
/* #define DEBUG_PRINT(...) if (DEBUG) printf(__VA_ARGS__) else */
/* #define DEBUG_PRINT */
/* #undef  DEBUG_PRINT */
void print_string(char *s)
{
    printf("%s\n", s);
}
void print_num(int n)
{
    printf("%d\n", n);
}

int main(void)
{
#include <string.h>
    /* printf("%p\n", strstr(__func__, "maind")); */
    if (strcmp(__func__, "main") == 0) {
        printf("Calling withing main!");
    }
#define GREAT
#ifndef GREAT
    #error What the fuck man? -- needs to be called from main.c
#endif
    #line 10000 "somefile.c" // <-- reset the line number (why?)
    DEBUG_PRINT("I believe I can fly.");
    DEBUG_PRINT("I believe I can touch the sky...");
    printf("File: %s, Line: %d", __FILE__, __LINE__);
    #define SYS 1
    #if SYS == 1
        printf("Sys is not defined kid.");
    #elif SYS == 2
        printf("Sys is still not defined kid.");
    #else
        printf("Nooooo");
    #endif

    DEBUG_PRINT("Hello");
#ifdef HELLO
    printf("1 - Kellogg");
#else
    printf("1 - Nope!\n");
#endif

    #define HELLO 12    

#ifdef HELLO
    printf("2 - Kellogg\n");
#else
    printf("2 - Nope!");
#endif
    printf("Print Hello1: %d\n", HELLO);
    #undef HELLO
    #define HELLO 13    
    printf("Print Hello2: %d\n", HELLO);

    printf("%d %d %d\n", 2, abs(2), abs(-2));
    eprintf("Hello %s %s", "Bob" "Bill", "Bax");
    PR2("hello %d %d\n", 2, 3);
    PR(1, "x=%g\n", (double) 48.0);
    PR(2, "x=%.2f, y=%.4f\n", (double) 48.0, (double) 7);
    PR("HOWDY\n");
    /* PR("weight = %d, shipping = $%.2f\n", wt, sp); */
    /* PR(2); */
    return 0;
    int XNAME(1) = 14;  // ==> x1 = 14
    int XNAME(2) = 20;
    int x3 = 30;
    PRINT_XN(1);
    PRINT_XN(2);
    PRINT_XN(3);
    PRINT(string)("Hello");
    PRINT(num)(4);
    print_string("Hello");
    print_num(5);
    char *sn = "YES";
    printf("%s\n", PX(s));
    PRNT("HELLO", 4);
    
    printf("X is %s and Y is %d", "\"HELLO\"", 4);
    PSQR(4+1);
    TELL(2);
    TELL('c');  // now it will print as both a char and int
    TELL("HELLO");
    int x=2, y=4;
    printf("%d^2=%d, MEAN(%d, %d)=%d\n", x, SQUARE(x), x, y, MEAN(x,y));
    int/**/hello = 4;
    printf("%d\n", hello);

    printf("OK\n");
    /* pri\ */
/* ntf("OK\n"); */
    /* pri[><]ntf("Hi"); */
    return 0;
}
