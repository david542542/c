#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{

    puts("Enter name of destination file");

    char file_app[40], file_src[40];
    scanf("%20s", file_app);
    printf("The file name is: %s\n", file_app);

    // set output file
    FILE *fa = fopen(file_app, "a+");
    if (!fa) {
        fprintf(stderr, "There was a problem opening: %s", file_app);
        exit(EXIT_FAILURE);
    }

    // set a custom buffer
    int x = setvbuf(fa, NULL, _IOFBF, 4096);    // 0 if ok
    if (setvbuf(fa, NULL, _IOFBF, 4096) != 0) {
        fputs("Can't create output buffer", stderr);
        exit(EXIT_FAILURE);
    }

    int count=0;
    while (true) {
        puts("Enter the name of the source file to append. q to quit.");
        scanf("%20s", file_src);
        // 1. check for exit condition
        if (strcmp(file_src, "q") == 0) break;
        // 2. check to make sure it's a different file
        if (strcmp(file_src, file_app) == 0) {
            printf("ERROR: Cannot append file to itself\n");
            continue;
        }
        // 3. open the file and check that it's ok
        FILE *fs = fopen(file_src, "r");
        if (!fs) {
            fprintf(stderr, "There was a problem opening: %s", file_src);
            exit(EXIT_FAILURE);
        }
        // 4. create an input buffer
        if (setvbuf(fs, NULL, _IOFBF, 4096) != 0) {
            fputs("Can't create input buffer", stderr);
            exit(EXIT_FAILURE);
        }
        // 5. append the actual chars and close the file
        size_t bytes;
        static char temp[4096]; // only allocate once
        // writes to the temp buffer from the input, advancing every 4096 bytes
        // then from the temp buffer, writes to the output (fa file)
        while ((bytes = fread(temp, sizeof(char), 4096, fs)) > 0)
            fwrite(temp, sizeof(char), bytes, fa);

        count++;
        fclose(fs);

    }

    fclose(fa);
    printf("Done appending %d files to %s!\n", count, file_app);



}
