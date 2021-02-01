#include<stdio.h>
#include<stdlib.h>

typedef struct Person {
    char* name;
    struct Person* mother;
    struct Person* father;
} Person;
void my_print(char* str) {
    // note this only changes the value (in pass-by-value)
    // it doesn't change the actual string that's passed back
    str = "OK!";
    printf("%s\n", str);
}


int main(int argc, char *argv[])
{
    // parents (ignore their parents)
    Person *Kathy = malloc(sizeof(Person));
    Kathy->name = "Kathy";
    Person *Bill = malloc(sizeof(Person));
    Bill->name = "Bill";

    // person
    /* Person *Bob = ((Person*) malloc(sizeof(Person))) (Person) {.name="Bill"}; */
    Person* Bob = malloc(sizeof(Person));
    Bob->name = "Bob";
    Bob->mother = Kathy;
    Bob->father = Bill;

    // or can do it with the compound-literal syntax
    Person* Barry = malloc(sizeof(Person));
    *Barry = (Person) {.name="Barry", .mother=Kathy, .father=Bill};
    printf("Name: %s | Mom: %s, Dad: %s\n", Bob->name, Bob->mother->name, Bob->father->name);
    printf("Name: %s | Mom: %s, Dad: %s\n", Barry->name, Barry->mother->name, Barry->father->name);

    /* free(Bob); */
    /* free(Kathy); */
    /* free(Bill); */
    /* int a=4; */
    /* int *b=&a; */
    /* scanf("%c", (char*) &a); // address-of a (same thing as pointer-to-a) and cast that to char-pointer */
    printf("OK\n");

    /* char *str ="Hello"; */
    /* my_print(str); */
    /* printf("%s\n", str); */
    /* // conditional loop cannot contain declaration without braces */
    /* // The variable is local to the scope **where its declarared** */
    /* if (argc == 2) { */
        /* str = "Two"; */
    /* } */
    /* else { */
        /* str = "Not two"; */
    /* } */

}
