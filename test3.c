// ### To run a C program do: ###
// 1. Open a terminal with :term
// 2. Define the file to run automatically, for example $ file=test && S -- without the extension!!
// 3. Do Cmd-R to run the file. (Note: have to flush the bashrc once, with the S above)
// 4. To cancel out of the terminal window can do Ctrl-D (doesn't recognize the Cmd-W here)
#include <stdio.h>

void print_stack_pointers(void)
{
    // kind of useless since it will almost always print the same
    // from the calling function (since that will have to reset things before calling it often..
    char *rsp, *rbp;
    asm("mov %%rsp, %0;" "mov %%rbp, %1;" : "=r" (rsp), "=r" (rbp));
    printf("%%rsp = %p\n" "%%rbp = %p\n", rsp, rbp);
}

int do_arithmetic(int x)
{

    char *rsp, *rbp;

    asm("mov %%rsp, %0;" "mov %%rbp, %1;" : "=r" (rsp), "=r" (rbp));
    printf("%%rsp = %p\n" "%%rbp = %p\n", rsp, rbp);
    /* printf("11111 First!\n"); */
    /* print_stack_pointers(); */


    /* printf("2222 Second!\n"); */
    /* print_stack_pointers(); */

    /* asm("mov %%rbp, %0;": "=r" (rbp):); */
    /* printf("%%rbp=%#lx\n", rbp); */
    /* printf("%s\n", ); */

    // y   = (x+1)*2+5
    // tmp = x+1        inc %in_reg
    // tmp = tmp*2      add %in_reg, %in_reg
    // tmp = tmp + 5    add $5, %in_reg
    // y = tmp          mov %in_reg, %out_reg

    /* asm("mov %%rsp, %0;" "mov %%rbp, %1;" : "=r" (rsp), "=r" (rbp)); */
    /* printf("%%rsp = %#lx\n" "%%rbp = %#lx\n", rsp, rbp); */
    /* return y; */
}

void run(void)
{
    long rsp, rbp;
    asm("mov %%rsp, %0;" "mov %%rbp, %1;" : "=r" (rsp), "=r" (rbp));
    printf("Middle\n%%rsp = %#lx\n" "%%rbp = %#lx\n", rsp, rbp);
}
int main(void)
{
    char *rsp, *rbp;
    asm("mov %%rsp, %0;" "mov %%rbp, %1;" : "=r" (rsp), "=r" (rbp));
    printf("Start\n%%rsp = %p\n" "%%rbp = %p\n", rsp, rbp);

    run();
    long a,b,c;
    char* d = "Hello";
    char e[10];

    asm("mov %%rsp, %0;" "mov %%rbp, %1;" : "=r" (rsp), "=r" (rbp));
    printf("End\n%%rsp = %p\n" "%%rbp = %p\n", rsp, rbp);

    /* asm ("movl %1, %%eax; movl %%eax, %0;" */
    /* asm ("movl %1, %0;" // moves the item in the input (a) into the output (c)  */
          /* "inc %0;"     // increments the output (c) */
            /* :"=r"(c)         [> output -- referred to by %0 <] */
            /* :"r" (a)         [> input  -- referred to by %1 <] */
            /* );       */
    /* printf("a=%d, b=%d c=%d\n", a, b, c); */
    /* do_arithmetic(y); */
    /* int y=plus_one_times_two(x); */
    /* asm ("inc %eax"); */
    /* printf("X: %d | (X+1)*2: %d\n", y, plus_one_times_two(y)); */
    /* return y; */
}
