// common.c

#include "common.h"

/* Helper function to determine if the expression is '' or ';' */
bool is_empty_expr(char* buffer) 
{
    if (buffer[0] == ';' || buffer[0] == '\0')
        return true;
    else
        return false;
}

/* Removes trailing whitespace (ignoring the semi-colon) 
   And then appends a terminating semi-colon. 
   Note: doesn't clean beyond last char.
   Example: "a + b  ; " --> "a + b;"
*/
char* trim_expr_end(char* buffer, int buffer_index) 
{
    while(buffer_index-- > 0) {
        if(!isspace(buffer[buffer_index])) 
            break;
    }
    if (buffer_index >= 0) {
        buffer[buffer_index+1] = ';';
        buffer[buffer_index+2] = '\0';
    }
    return buffer;
}
