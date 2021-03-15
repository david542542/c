SYS_EXIT = 60
LOOP_MAX = 2000000000
.globl _start

loop:
    # do a billion increments
    mov $0, %eax
  _loop:
    inc %rax
    cmp $LOOP_MAX, %rax
    jne _loop
    ret

_start:

    # start time
    call loop
    # printf("It took %.8f to run", end_time - start_time)
    mov $4,  %edi
    mov $SYS_EXIT, %eax
    syscall

