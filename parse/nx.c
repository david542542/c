#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name {
    char *first;
    char *last;
    int letters;
};

void getinfo(struct name *person);
void makeinfo(struct name *person);
void showinfo(const struct name *person);
void cleanup(struct name *person);

int main(void)
{
    struct name person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
}

void makeinfo(struct name *person)
{
    person->letters = strlen(person->first) + strlen(person->last) + 1; // +1 for space
}
void showinfo(const struct name *person)
{
    printf("Name: %s %s (%d)\n", person->first, (*person).last, person->letters);
}
void cleanup(struct name *person)
{
    free(person->first);
    free(person->last);
}

struct rect {
    int height;
    int width;
};
int area(struct rect *r)
{
    return r->height * r->width;
}
int area2(struct rect r)
{
    return r.height * r.width;
}
void getinfo(struct name *person)
{

    FILE *f = fopen("AHello.txt", "w");
    fprintf(f, "Hello, %s", "Tom");
    fclose(f);
    printf("The area of Rect(%d, %d) = %d\n", 4, 5, area(&(struct rect){4,5}));
    printf("The area of Rect(%d, %d) = %d\n", 4, 5, area2((struct rect){4,5}));
    char temp[100];

    // first name
    printf("Please enter in your first name: ");
    fgets(temp, 100, stdin);
    temp[strcspn(temp, "\n")] = '\0';   // remove newline

    // - malloc and copy
    person->first = malloc(strlen(temp)+1);
    strcpy(person->first, temp);

    // last name
    printf("Please enter in your last name: ");
    fgets(temp, 100, stdin);
    temp[strcspn(temp, "\n")] = '\0';   // remove newline

    // malloc and copy
    person->last = malloc(strlen(temp)+1);
    strcpy(person->last, temp);

}
