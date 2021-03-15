// rand0.c
#include<stdio.h>
static unsigned long int next=1;    // the seed

int rollem(int sides)
{
    int roll;
    roll = (rand() % sides) + 1;
    return roll;
}
int rand1(void) {
    next = next *1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

int srand1(unsigned int seed)
{
    printf("Resetting seed...\n");
    next = seed;
}

