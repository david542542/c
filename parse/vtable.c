#include<stdio.h>
#include<stdlib.h>

typedef struct Person Person;
typedef struct Person_VTable {
    void (*print) (Person* self);
} Person_VTable;

typedef struct Person {
    int id;
    char* name;
    Person_VTable *vtable;
} Person;

void print_name(Person* person) {
    printf("Hello %s\n", person->name);
}
Person* init_person(void) {
    Person *person = malloc(sizeof(Person));
    person->vtable  =  malloc(sizeof(Person_VTable));
    person->vtable->print = print_name;
    return person;
}
int main(void) {
    Person* self = init_person();
    self->name = "Greg";
    self->vtable->print(self);
    return 0;
}
