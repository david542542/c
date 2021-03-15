/* #include "scope_other.h" */


// variables with block scope, function scope, or function prototype scope have NO linkage.
// that means they are private to the block, function, or prototype in which they were defined.
// A variable with file scope can have either INTERNAL or EXTERNAL linkage
// A variable with EXTERNAL linkage can be used anywhere in a multifile program.
// A variable with INTERNAL linkage can only be used in a single translation unit (i.e., the file and header, etc.)
// **File scope** is often used to mean FILE SCOPE with INTERNAL LINKAGE
// **Program/Global scope** is often used to mean FILE SCOPE with EXTERNAL LINKAGE
// The difference here is whether the word "static" is used in the global definition
// A STATIC variable means that the variable stays put in memory, not necessarily in value


/* extern int external, internal; // doing it this way, it will fail on the Linker step */
#include<stdio.h>
#include<stdbool.h>
extern int external, internal;         // doing it this way, Internal will be zero, unless defined elsewhere
int x=4;
/* int y=x+2; */
/* { */
    /* int b; */
/* } */
/* int hello=99; */

void call_stat(bool is_initialized) {
    if (is_initialized) {
        static int var=99;    // a static variable is only created-initialized once
        printf("Var1: %d\n", var++);
    } else {
        static int var;    // a static variable is initialized to 0 if no initializer provided.
        printf("Var2: %d\n", var++);
    }
}
int main(void)
{
    call_stat(0); call_stat(0);
    call_stat(1); call_stat(1);
    // you can initialize an automatic variable to a non-constant, but cannot do so with a global or static variable anywhere
    int x=4;
    int y=x+2;
    int a=4;
    printf("a=%d", a);
    /* printf("b=%d", b); */
    int b=7;
    printf("External: %d\n", external);
    /* printf("Internal (static): %d\n", internal); // should error */
    /* printf("ZZ: %d\n", zz); // should error */
}

/* int internal=4; */


int _main(void)
{
    int a=4;
    if (a == 4)
    {
        int b=7;
label:
        b+=1;
        printf("Hello\n");
        if (b > 10) goto end;
    }
    goto label;

end:
    return 0;
}
