#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <string.h>

void cat(char* filename)
{
    printf("%d\n", errno);  // 0 if no error
    strerror(errno);
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        char buffer[50];
        sprintf(buffer, "The file %s could not be opened", filename);
        perror(buffer);
        /* char buf[1024]; */
        /* errstring = __strerror_r (errnum, buf, sizeof buf); */
        /* __strerror_r (errno, buf, sizeof buf); */
        printf("%d\n", errno);
        char x[1024];
        strcpy(x, strerror(errno));
        printf("%d --> %s\n", errno, x);
        return;
    }

    puts("======== CAT ==========");
    int c;  // int and not char because of EOF
    // getchar() <-- get char from stdin
    // getc(fp)  <-- get char from the file identified by fp
    while((c=getc(fp)) != EOF) 
        // putchar(ch)      <-- put the character ch to stdout
        // putc(ch, fpout)  <-- put the character ch into the file identified by fp
        putc(c, stdout);

    // close the file now -- returns a 0 if successful
    if (fclose(fp) != 0)
        printf("Error in closing file %s\n", filename);

}

int main(int argc, char* argv[]) {

    /* printf("The first arg is: %s\n", argv[1]); */
    cat(argv[1]);
    return 0;

    // make sure we have two arguments
    if (argc != 2) {
        printf("Usage is $ %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open the file for reading
    // fopen(filename, mode)
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    // get each character and increment the char counter.
    unsigned long count=0;
    for (int ch; (ch=getc(fp)) != EOF;) {
        putc(ch, stdout);   // same as putchar(ch)
        count++;
    }

    // and let's write the output to a string while we're at it for fun
    char buffer[50];
    snprintf(buffer, 30, "File %s has %lu characters\n", argv[0], count);
    printf("%s\n", buffer);

    /* printf(FILE); */



}
