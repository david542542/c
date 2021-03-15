#include <stdio.h>
#include <stdlib.h>

void run_before_exiting1(void)
{
    printf("111\n");
}
void run_before_exiting2(void)
{
    printf("222\n");
}
int main(void)
{

    // note: the last function registered is the first one called: it's LIFO
    // note: main() calls exit() at the end, implicitly, even if not specifically called.
    atexit(run_before_exiting1);
    atexit(run_before_exiting2);
    printf("Hi!\n");
}
