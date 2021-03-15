#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    char *str = "first,last,age\ntom,smith,20\nsarah,jones,30";
    char row_buffer[80];
    char c;
    int str_i = 0, buf_i = 0;

    do {
        c = str[str_i];
        if (c != '\n' && c != '\0')
            row_buffer[buf_i++] = c;
        else
        {
            row_buffer[buf_i] = '\0';
            printf("Processing buffer: %s\n", row_buffer);
            buf_i = 0;
        }
    } while (str[str_i++]);


    typedef int XYZ;
    XYZ four = 4;
    printf("%d\n", four);

    typedef int ABC[2];
    ABC twotwo = {1,2};
    printf("{%d,%d}\n", twotwo[0], twotwo[1]);


    return 0;
    char arr[100], inner[100];
    strcpy(arr, str);
    char * token = strtok(arr, "\n"), * token_i;
    do {
        printf ("ROW: %s\n", token);
        for (int i=0, buf_i=0, c; c=token[i]; i++)
            if (!token[i+1]) {
                /* buf_i = 0; */
                inner[buf_i] = c;
                inner[buf_i+1] = 0;
                printf("*%s\n", inner);
            }
            else if (c!=',') {
                inner[buf_i++] = c;
            } else {
                inner[buf_i] = 0;
                buf_i=0;
                printf("*%s\n", inner);
            }

        /* token_i = strtok(inner, ","); */
        /* while (token_i != NULL) { */
            /* printf("-%s-", token_i); */
            /* token_i = strtok(NULL, ","); */
        /* } */
    } while (token = strtok(NULL, "\n"));

    /* strtok(string, rowdelim); */
    /* char * row; */

    /* char *token = strtok(str, s); */

    /* [> walk through other tokens <] */
    /* while( token != NULL ) { */
        /* printf( " %s\n", token ); */
        /* token = strtok(NULL, s); */
    /* } */
    /* while (row = strtok(string, rowdelim)) { */
        /* printf("%s -- %s", row, string); */
        /* break; */
    /* } */
}
