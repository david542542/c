// r_drive0.c
#include <stdio.h>

// extern reminds us that rand0 is defined in another file but it's not required
/* extern int rand0(void); */
extern int rand1(void);
extern void srand1(unsigned int x);

int main(void) {
    unsigned int seed;
    printf("Please enter your choice for the seed.\n");
    while (scanf("%u", &seed)== 1) {
        srand1(seed); // reset seed
        for (int count=0; count < 5; count++)
            printf("%d\n", rand1());
        printf("Please enter next seed (q to quit)\n");
    }
}
