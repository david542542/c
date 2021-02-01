#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int main(void) {
    int ch;

    // Note: doing the following will read text from the file.txt!
    // $ ./io2.o < file.txt 
    // $ ./io2.o > new.txt will create a new file and write to it on EOF or when buffer is full.
    /* while (i < 100) { */
    
    /* } */
    int num_bytes = 1024, multiplier=1;
    while (multiplier++ < 10) {
        for (int i=0; i < num_bytes-1; i++)
            putchar('x');
        putchar(48 + multiplier);
        sleep(2);
    }

    /* while ((ch=getchar()) != EOF) { */
        /* // printf("Hello!\n"); --> will go to whatever stdout is... */
        /* putchar(ch); */
        /* if (ch=='#') fflush(stdout); */
    /* } */
}

    // when writing to a file, it will only be flushed after 1024 or 4096
    /* printf("Enter a character now...\n"); */
    /* // possible to prompt input now from a user? */
    /* ch = getchar(); */
    /* printf("The character you entered was: %c with code %d\n", (char) ch, ch); */
    
    /* printf("Done!Now it's your turn...\n"); */
    /* printf("Enter a character\n"); */
    /* scanf("%c", (char*) &ch); // &ch has type `(int *)` and we want to cast it to `(char *)` */
    /* printf("The character you entered was: %c\n", ch); */
    /* printf("Hi!\n"); */


