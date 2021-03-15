#include <stdio.h>
#include <string.h>

struct person {
    char first[40];
    char last[40];
};
struct book {
    char title[40];
    /* struct person author; */
    struct {char first[40]; char last[40];} author; // can use an anonymous struct here.
    float cost;
};

// write stdin to buffer of max size `max`, removing newline
void ffgets(char buffer[], int max)
{
    fgets(buffer, max, stdin);

    // simple way to remove newline if the last char is newline
    size_t len = strlen(buffer) - 1;
    if (*buffer && buffer[len] == '\n')
        buffer[len] = '\0';

    // getting the pointer to the first \n
    char *nptr = strchr(buffer, '\n');
    if (nptr != NULL) *nptr='\0';
}
int main(void) 
{
    struct book moby;
    puts("Enter the name of the book: ");
    ffgets(moby.title, 40);

    puts("Enter the author: ");
    scanf("%20s %20s", moby.author.first, moby.author.last);
    /* ffgets(moby.author, 40); */

    // here we use scanf, as easier to recognize a float, and also it expects char* to it, not a float...
    printf("And finally the cost: $");
    scanf("%f", &moby.cost);
    /* ffgets(moby.cost, 40); */
    
    printf("{Title: %s, Author: %s %s, Cost: $%.2f}\n", moby.title, moby.author.first, moby.author.last, moby.cost);

}
