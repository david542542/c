#include <stdio.h>
extern int add_five_asm(int n);

int add_five(int n)
{
    n = n + 5;
    return n;
}


int add_five_inline(int n) {
    asm("lea 5(%1), %0" : "=r" (n) : "r" (n));
    return n;
}

int main(void)
{
    int a=add_five(7);
    int b=add_five_inline(8);
    int c=add_five_asm(9);
    printf("7+5=%d | 8+5=%d | 9+5=%d\n", a, b, c);

}
