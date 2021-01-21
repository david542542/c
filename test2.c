// FILE_2
#include<stdio.h>

// definition can only happen once (or zero), declarations can be repeated.
// 1. declaration
// 2. definition
// 3. ambiguous

int gss;        // ambiguous (goes into .bss storage)
int gss=2;      // definition -- declaration+assignment/initialization
/* extern int gss; // declaration, but not a definition */


// forward declaration (aka the *prototype* in more advanced languages)
void foo(); // semi-colon vs. curly brace whether it is a declaration or def

// mutual recursion is only possible with a forward declaration.
extern static int forward_declaration;
int main(void)
{
    foo();
    gs = 4;
    gss = 5; // ok?
    return 0;
    
}
static int forward_declaration=2;
// function definition
void foo() {
    main();
}
