# file.s
.globl add_five_asm
.type add_five_asm, @function
add_five_asm:
    # INPUT: int, OUTPUT: int
    lea 5(%rdi), %rax
    ret
