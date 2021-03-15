/* #include<stdio.h> */

/* int x;          // tentative definition: will look in another file, but won't fail if not defined in another, will just initialize to zero */
/* int y;          // ...if not found in another file will initialize to zero */
/* extern int z;   // pure declaration -- if not found in another file, it will **fail** when trying to link */

/* int main(void) */
/* { */
    /* printf("%d %d %d\n", x, y, z); */
    /* return 0; */
/* } */
// t.c
#include<stdio.h>

int x;
int z=4;

int main(void)
{
    printf("%d\n", x);
}
