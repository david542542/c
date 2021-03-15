#include<stdio.h>

int Hocus;
int magic(void);
int main(void) {
    extern int Hocus;   // Hocus declared external
}
int magic(void) {
    extern int Hocus;   // same as above
}

int magic2(void);
int magic2(void) {
    // Hocus not declared but it is known
}



/* Example 3 */
int Hocus;      // declare a first (global) variable -- static storage duration, file scope, external linkage
int magic(void);
int main(void) {
    int Hocus;  // declare a second (local) variable
}
int magic(void) {
    auto int Hocus;  // declare a third (local) variable, 'auto' is optional
}

