
#include "parse.h"


int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Usage is $ script \'expression\'.\n");
        exit(EXIT_FAILURE);
    }

    // initialize it to one char larger to simplify things
    // in case we need to add on a ; at the end
    size_t len = strlen(argv[1]);
    char buffer[len + 1 + 1]; // str on the stack (local array)

    // 1. can initialize it as a local-array and use sizeof
    // adding in static (or putting it into global scope)
    // gives it global lifetime but local scope, so whenever it is called
    // it will not be re-initialized.

    /* strcpy, strcat, strcmp, strchr */

    /* malloc/free */

    /* sizeof char [] gives full size of array */
    /* sizeof "hello world\n" gives length of the string including null */
    /* strlen() gives dynamic length of string (to null) */

    // static "hoists" it into the data section
    // if const, can put it into the .rodata section
    // 'static' is an example of a storage class/modifier
    // 'auto' is the same thing as local --> its the storage classifer (`int` if not provided)
    // 'const' usually promotes something into read-only memory (if it can)

    static const char lit[] ="Hello world\n"; // 
    char* buffer2 = malloc(sizeof(lit)); // if not a local, will need to alloc the memory
    if (!buffer2) {
        /* { int buffer2 = 4; } */
        printf("Its bad!\n");
        exit(EXIT_FAILURE);
    }

    char* buffer2 = malloc(sizeof(lit));
    strcpy(buffer2, lit);
    printf("%s\n", buffer2);

    // 2. can initialize it as a pointer to string -- cannot do sizeof because that's always going to be
    // sizeof pointer (8 on this machine)
    char* lit2 ="Hello world\n";
    char* buffer3 = malloc(strlen(lit)+1); // if not a local, will need to alloc the memory
    strcpy(buffer3, lit2);
    printf("%s\n", buffer3);

    return 0;

    /* char *lit ="Hello world\n"; */
    /* char* buffer2 = malloc(sizeof(lit)+1); // if not a local, will need to alloc the memory */

    int buffer_index=0;

    // nice helper to trim the string before passing it? instead of going from 0 to len-1, go from first non-whitespace, to last.

    for(int i=0; i <= len; i++) {
        char c = argv[1][i];
        buffer[buffer_index] = c;
        if (c == ';') {
            buffer[buffer_index+1] = '\0';
            parse((const char*)buffer);
            buffer_index = 0;
            buffer[0] = '\0';
        } else {
            if (i != len) buffer_index++; 
        }
    }

    // if we have leftover buffer, then append a semi-colon and parse as well
    if(buffer[0]) {
        buffer[buffer_index] = ';';
        buffer[buffer_index+1] = '\0';
        parse((const char*)buffer);
    }


    /* printf("%s\n", buffer2); */
    /* free(buffer2); // buffer2=NULL: */
    /* printf("%s\n", buffer2); */


    return 0;

}
