// FILE_1
#include<stdio.h>
/* int a; */
// Logical -- variables and 'scope' (lifetime of the variable) -- global, static (similar to global), local, heap
//         -- *heap* variables are managed by the programmer (if not garbage collected), they do not have a scope
//         -- scope is a lexical construct, that is, it matters where it is in program
//         -- *static* is a global variable (only initialized once -- lifetime sense) -- and outlives the scope it that it was defined in.
//         -- that is restricted to only being accessed within the scope it is defined.

// Physical -- memory and cpu registers (one-byte addressible, though can pack bits), double- quad-, quad2x-, word-size for the processor.
//          -- movb, movw, movl, movq
//          -- if data is aligned, item must be within the same page (~4K) / cache-line (~16B). 
//          -- ABI and calling convention -- int num: %rdi; return int: %rax (linux)
//          -- Heap: malloc returns pointer to an address of certain size. *Pointer* is like the stack-pointer (%rsp or perhaps/ %rbp) of a FIXED memory size.
//          --       the pointer is really our only reference to the memory (think of it like %rbp usage). offset(base, size, index), displace+base_reg
//          --       (stack is often pushed into the L1 cache because used pretty frequently)


int_5 x = 500 (5 bytes);
(could pad it with 0's, or could do something like movl + movb, but NOT grabbing all 8 and bit-shifting, as could error easily, or could do movb * 5)

// dynamic tiling algorithms (look up sounds interesting)

static int gs;           // only accessible from 'this file scope' --> here to the end
static int gss;          // only accessible from 'this file scope' --> here to the end


// 'extern static' MUST be in the given file
// allows for forward declrations
extern static int static_ext;  // forward declaration for a static variable

// ### To run a C program do: ###
// 1. Open a terminal with :term
// 2. Define the file to run automatically, for example $ file=test && S
// 3. Do Cmd-R to run the file. (Note: have to flush the bashrc once, with the S above)
// 4. To cancel out of the terminal window can do Ctrl-D (doesn't recognize the Cmd-W here)

// Shift-Command-G to push changes to git with a generic commit.
int square(int num) { // num is in %rdi
    static int a;  // -4(%rbp) (points to middle of stack frame, positive offset points to params, negative to local vars), or %rsp (positive), 
    // rbp often inefficient, but can make things a bit simpler.
    // if push/pop is used, need to understand where offsets are relative to local variables and params.

    return num*num;
}

// 
static int static_ext = 7

int main(void)
{
    /* int b; */
    static int static_ext = 7; // ??

    printf("Hello!\n");
    printf("Goodbye!\n");
    int a = 2;
    int b = square(a);
    printf("Ok!\n");
    printf("asdf\nk!\n");
    return b;
}

