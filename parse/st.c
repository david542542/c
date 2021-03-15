#include <stdio.h>
#include <unistd.h>

/* #include <time.h> */

struct Person {
    char name[40];
    int age;
};

struct Funds {
    char bank[50];
    double bankfund;
    char save[50];
    double savefund;
};

float sum(const struct Funds *bank)
{
    return bank->bankfund + bank->savefund;
}
int main(void)
{
    printf("Sleeping for a second...\n");
    sleep(1);
    struct Funds stan = {
        "Galic Bank", 4032.20, "Lucky Savings", 123.50
    };
    printf("Stan has a total of %.2f in his bank accounts\n", sum(&stan));
}


int _main(void) 
{
    struct Person friends[] = {
        {"Bob", 23},
        {"Sally", 30}
    };

    for (int i=0; i < sizeof(friends)/sizeof(*friends); i++)
        printf("Friend %d: %s\n", i+1, friends[i].name);
    struct Person *person = friends; // same as &friends[0]
    printf("First friend: %s\n", (person++)->name);
    printf("Second friend: %s\n", person->name);
    printf("Second friend: %s\n", (*person).name);  // this is the equivalent of doing the ->

    printf("Hi!\n");
}
