// manydice.c
#include <stdio.h>
#include <stdlib.h>         // for library srand()
#include <time.h>           // for time()
#include "diceroll.h"       // for roll_n_dice() and roll_count
int main(void)
{
    int dice,roll,sides;
    printf("%d\n", rand());
    srand(0);
    printf("%d\n", rand());
    srand((unsigned int) time(0));   // randomize seed
    while (1) {
        printf("Enter the number of sides per die and the number of dice\n");
        if (scanf("%d %d", &sides, &dice) != 2) continue;
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
        printf("The rollem has been caeed %d times\n", roll_count);
    }

}

