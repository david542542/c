#include <stdio.h>

struct Magazine {
    float cost;
    char publisher[20];
};

struct Novel {
    float cost;
    char genre[10];
};

struct Book {
    char title[20];
    char author[20];
    union {
        struct Magazine magazine;
        struct Novel    novel;
    };
};
enum Brothers {Snee, Snoo, Snum};

union Type {
    char    a;
    double   b;
}; // this type will be 8 bytes regardless of which one is used.

int main(void) {

    enum Brothers k;
    k = Snee;
    k = 9;
    struct Book current = {"Tom Sawyer", "Mark Twain"};
    current.novel = (struct Novel) {2.20, "Fiction"};
    printf("{Title: %s, Author: %s}} (Cost: %.2f, Genre: %s)\n", current.title, current.author, current.novel.cost, current.novel.genre);
  {
    // write a few records
    struct Book books[] = {
        {"Moby Dick", "Melville"},
        {"Hamlet", "Shakespeare"},
    };
    union Type types[] = {
        {.a='a'},
        {.b=2.7}
    };
    printf("%d (%zu) %f (%zu)\n", types[0].a, sizeof types[0], types[1].b, sizeof types[1]);
    printf("%f (%zu) %d (%zu)\n", types[0].b, sizeof types[0], types[1].a, sizeof types[1]);    // we have to internally keep track of it, or this will have garbage output
    /* types[0].a = 'b'; */
    FILE *fp = fopen("books.struct", "ab");
    fwrite(&books, sizeof (struct Book), 2, fp);    // write starting at address &books for sizeof(struct Book) bytes to file fp
    fclose(fp);
  }

  {
    // read a few records
    struct Book books[2];
    FILE *fp = fopen("books.struct", "rb");
    fread(&books, sizeof (struct Book), 2, fp);    // write starting at address &books for sizeof(struct Book) bytes to file fp
    for (int i=0; i < sizeof books / sizeof *books; i++)
        printf("%d. {Title: %s, Author: %s}\n", i+1, books[i].title, books[i].author);
  }

}
