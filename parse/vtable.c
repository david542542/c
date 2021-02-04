#include<stdio.h>
#include<stdlib.h>

typedef struct Person Person;
typedef struct Person {
    int id;
    char* name;
    void (*print) (Person* self);
} Person;

void print_name(Person* person) {
    printf("Hello %s\n", person->name);
}
Person* init_person() {
    Person *person;
    person->print = print_name;
}
int main(void) {
    Person* p = init_person();
    p->name = "Greg";
    p->print(p);
    return 0;
}
