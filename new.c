#include<stdio.h>
// cmd-b to toggle a breakpoint
// ctrl-opt-cmd-g to enter debugging

// gdb shortcuts:
// c  -- run program until next breakpoint (or finished)4
// s  -- run next line of code (for example, in c)the next line of the program
// n  -- run next line of code (but dont go into functions -- helpful, for example to skip big library functions like printf
// si -- run next assembly instruction

int square(int n)
{
    return n*n;
}
int main(void)
{
    int a=2;
    int b=square(a);
    printf("a=%d | a**2=%d\n", a, b); // break
    return 0;
}
