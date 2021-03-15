#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define BUFLEN 10
// create an array of 10 random integers between 0 and 1000
void fillarray(int buffer[], size_t num_ints)
{
    srand(time(0));
    for (int i=0; i < num_ints; i++)
        buffer[i] = (rand() % 1000) + 1;
}
void printarray(int buffer[], size_t num_ints)
{
    for (int i=0; i < num_ints; i++)
        printf("%d%s", buffer[i], i == num_ints-1? "": ", ");
    putchar('\n');
}
int comp1(const void *p1, const void *p2)
{
    const int *v1 = p1;
    const int *v2 = p2;
    if (*v1 == *v2)
        return 0;
    else if (*v1 > *v2)
        return 1;
    else
        return -1;
}
int comp2(const void *p1, const void *p2)
{
    if (*(int*)p1 == *(int*)p2)
        return 0;
    else if (*(int*)p1 > *(int*)p2)
        return 1;
    else
        return -1;
}
int comp(const void *p1, const void *p2)
{

    // have to first cast it to their actual value...
    /* printf("%d", *(int*)p1); */
    const int *v1 = p1;
    const int *v2 = p2;
    if (*v1 == *v2)
        return 0;
    else if (*(int*)p1 > *(int*)p2)
        return 1;
    else
        return -1;


}
int comp3(const void *p1, const void *p2)
{
    return (*(int*)p1 > *(int*)p2 ? 1 : (*(int*)p1==*(int*)p2)? 0 : -1);
}
#include <ctype.h>

void lower_string(char buffer[], const char* str, size_t len)
{
    char str_lower[len+1];
    str_lower[len] = 0;
    for (int i=0; str[i] != 0; i++)
        str_lower[i] = tolower(str[i]);

}
int scmp(const void *p1, const void *p2)
{
    // if it were int
    /* const int* i1 = *(int*) p1 */
    /* const int* i2 = *(int*) p1 */

    // being a string (pointer-to-char)
    const char* s1 = *(const unsigned char**) p1;
    const char* s2 = *(const unsigned char**) p2;

    char s1_lower[strlen(s1)+1];
    lower_string(s1_lower, s1, strlen(s1));
    
    char s2_lower[strlen(s2)+1];
    lower_string(s2_lower, s2, strlen(s2));

    return strcmp(s1_lower, s2_lower);
}
int main(void)
{
    printf("Hi\n");

    char* strings[4] = {"Onus", "deacon", "Alex", "zebra"};
    for (int i=0; i<4; i++) printf("%d. %s\n", i+1, strings[i]);
    // element, number of elements being sorted, size of each element, compare function
    qsort(strings, 4, 8, scmp);
    printf("------------\n");
    for (int i=0; i<4; i++) printf("%d. %s\n", i+1, strings[i]);
    return 0;

    int buffer[BUFLEN];
    fillarray(buffer, BUFLEN);
    printarray(buffer, BUFLEN);
    qsort(buffer, BUFLEN, sizeof(*buffer), comp3);
    printarray(buffer, BUFLEN);
}
