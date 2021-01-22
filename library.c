#include "library.h"
#include <stdio.h>3

// dont forget the declaration in the def!
int library_int = 4;

int library_function(void) {
    printf("Called library function...\n");
    return 7;
}
