#include<stdio.h>
#include <unistd.h>
#define CHAR_BUFFER 3

int main(void)
{

    // buffered input --> the characters I type are collected and stored in an area of
    //                    temporary storage called a buffer. Pressing [Enter] causes
    //                    the block of characters you typed to be made available to your program.

    // - Having buffered input also allows us to do things like deletions (rather than having the
    //   text being read back to us immediately.
    // unbuffered input responds immediately to the input (such as a game that accepts a key input)

    // There are two types of buffering: line-buffered I/O and fully-buffered I/O
    // - Line-buffered I/O 'flushes' the buffer whenever a newline character shows up.
    //   Keyboard input is normally line-buffered, so that pressing [Enter] flushes the buffer.
    // - Fully-buffered I/O 'flushes' to the buffer usually after 4096 bytes
    int ch;
    int num=0;

    // case 1 -- no newline
    printf("1. Before (unbuffered)");
    sleep(1);
    printf("After...\n");
    printf("------------------------------\n");

    // case 2 - newline
    printf("2. Before (newline)\n");
    sleep(2);
    printf("After...\n");
    printf("-----------------------------\n");

    // case 3 - autoflush
    printf("3. Before (manual flush)");
    fflush(stdout);
    sleep(2);
    printf("After...\n");
    printf("------------------------------\n");

    return 0;
    printf("Before ");
    sleep(2);
    printf("After");
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') continue; // ignore counting newline as a character
        putchar(ch);
        if (++num % CHAR_BUFFER == 0) {
            printf("Num: %d\n", num);
            fflush(stdout);            
        }
    }

    return 0;
    

    while ((ch = getchar()) != EOF) {
        putchar(ch);
        if (ch == '\n') continue; // ignore counting newline as a character
        if (++num % CHAR_BUFFER == 0) {
            printf("Num: %d\n", num);
            fflush(stdout);
        }
    }

    printf("Hi");
    getchar();
    printf("OK!\n");


    return 0;
}
