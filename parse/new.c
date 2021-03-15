#include <stdio.h>
#include <string.h>
#define MAXMOVIES 4

struct Movie {
    char title[40];
    int rating;
};
int main(void)
{
    int entries=0;
    struct Movie movies[MAXMOVIES];
    for(int i=0; i<MAXMOVIES; i++, entries++) {
        printf("Enter movie #%d (enter to quit)\n", i+1);
        int n = scanf("%40[^\n]s", movies[i].title);
        getchar();
        if (n) getchar();
        else break;
        printf("How would you rate %s? (1-10)\n", movies[i].title);
        scanf("%d", &(movies[i].rating));
        getchar();
    }
    for (int i=0; i < entries; i++) {
        struct Movie movie = movies[i];
        printf("%d. {title: %s, rating: %d}\n", i+1, movie.title, movie.rating);
    }

    
}
