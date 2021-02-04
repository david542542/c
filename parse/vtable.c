#include<stdio.h>
#include<stdlib.h>

typedef struct VTable VTable;

typedef struct Thing {
    const VTable *vtable;
    char* name;
} Thing;

typedef struct VTable {
    void (*print)   (Thing* self);
} VTable;


void print_hello(Thing *self) {printf("Hello, %s", self->name);}
static const VTable thing_vtable = {
    .print = print_hello
};
typedef struct Alien {
    const VTable *vtable;
    char* name;
    // add one more function to vtable -- should that be a stand-alone? do a second 'subclass vtable'? etc.
} Alien;

void alien_function(void) {printf("Alien");}
Alien* init_alien(void)
{
    Alien* alien = malloc(sizeof(Alien));
    alien->vtable = &thing_vtable;
    /* alien->vtable->alien_function = alien_function; */
    return alien;
}

int main(void) {
    Alien *alien = init_alien();
    /* alien->vtable->alien_function(); */
    return 0;
}




/* void increment_id(Person* person) { */
    /* person->id = 4; // since this is pass-by-reference from the pointer, it will modify the values in place */
    /* printf("Ok!\n"); */
/* } */
/* void print_name(Person* person) { */
    /* printf("Hello %s (ID: %d)\n", person->name, person->id); */
/* } */
/* static const Person_VTable vtable1 = { */
    /* .print = print_name, */
    /* .adjust = increment_id */
/* }; */
/* Person* init_person( */
        /* Person_VTable vtable */
        /* [> void(*print)(Person*), <] */
        /* [> void(*adjust)(Person*)  <] */
/* ) { */
    /* [> printf("Adjust: %p | Print: %p\n", adjust, print); <] */
    /* Person *person = malloc(sizeof(Person)); */
    /* person->vtable  =  &vtable1; */
    /* return person; */
/* } */
/* int main(void) { */
    /* Person* self = init_person(vtable1); */
    /* self->name = "Greg"; */
    /* self->vtable->print(self); */
    /* self->vtable->adjust(self); */
    /* self->vtable->print(self); */
    /* return 0; */
/* } */
