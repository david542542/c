#include<stdio.h>
#include<stdlib.h>

typedef struct Person Person;

typedef struct Person_VTable {
    void (*print)   (Person* self);
    void (*adjust)  (Person* self);
} Person_VTable;

typedef struct Person {
    int id;
    char* name;
    const Person_VTable *vtable;
} Person_Person;

void print_name(Person* person) {
    printf("Hello %s (ID: %d)\n", person->name, person->id);
}
void increment_id(Person* person) {
    /* if (!person->id) */
        /* person->id = 1; */
    /* else */
        /* person->id ++; */
}
Person* init_person(
        void(*print)(Person*),
        void(*adjust)(Person*) ) 
{
    printf("Adjust: %p | Print: %p\n", adjust, print);
    Person *person = malloc(sizeof(Person));
    const Person_VTable vtable = {
        .print = print,
        .adjust = increment_id
    };
    person->vtable  =  &vtable;
    return person;
}
int main(void) {
    Person* self = init_person(print_name, increment_id);
    self->name = "Greg";
    self->vtable->print(self);
    self->vtable->print(self);
    self->vtable->adjust(self);
    self->vtable->print(self);
    return 0;
}
