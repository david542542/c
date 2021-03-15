.globl _start
_start:
    push %rbp
    mov %rsp, %rbp
    movb $'c', -4(%rbp)
    mov $7, %rdi
    mov $60, %eax
    syscall
    mov $1, %rbp
