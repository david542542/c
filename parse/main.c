#include "common.h"
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
    char buffer[len + 1 + 1];
    int buffer_index=0;
    bool is_start_of_expression = true;


    // don't go to end of string -- the last character is the '\0' and not the last char.
    for(int i=0; i < len; i++) {

        // We start by skipping any whitespace in the expression
        char c = argv[1][i];
        if (is_start_of_expression && isspace(c)) 
            continue;
        else
            is_start_of_expression = false;

        buffer[buffer_index] = c;
        if (c == ';') 
        {
            strcpy(buffer, trim_expr_end(buffer, buffer_index));
            if (!is_empty_expr(buffer)) 
                parse(buffer);

            buffer_index = 0;
            is_start_of_expression = true;
        } 
        else {
            buffer_index++;
        }
    }

    // call parse if we still left-over buffer
    strcpy(buffer, trim_expr_end(buffer, buffer_index));
    if (!is_empty_expr(buffer)) 
        parse(buffer);

    return 0;

}
