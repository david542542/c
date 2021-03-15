#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define container_of(ptr, type, member) (type*)(void*)((char*)ptr - offsetof(type, member))

typedef struct Printable {
    void (*print)(struct Printable*); 
} Printable;

typedef struct Freeable { 
    void (*free_)(struct Freeable*); 
} Freeable;

// Structs
typedef struct Person {
    char* name;
    int age;
    Printable printable;
    Freeable freeable;
} Person;

typedef struct Car {
    char* make;
    char* model;
    int year;
    Printable printable;
    Freeable freeable;
} Car;


void free_car(Freeable *f)
{
    printf("Freeing Car!\n");
    Car *car = container_of(f, Car, freeable);
    free(car);
}
void free_person(Freeable *p)
{
    printf("Freeing Person!\n");
    Person *person = container_of(p, Person, freeable);
    free(person);
}
void free_(Freeable* freeable) {
    freeable->free_(freeable);
}
void print_person(Printable *p)
{
    // from the printable to get the instance that implements it.
    /* struct Person *p = container_of(printable, struct Person, printable); */
    /* container_of(p, person, printable) */

    // gives us the beginning of the Person object...
    // printf("%zu", offsetof(Person, printable));
    (Person*)(void*)((char*)p - offsetof(Person, printable));

    Person *person = container_of(p, Person, printable);
    printf("<Person: %s (%d)>\n", person->name, person->age);

}
Person *create_person(char *name, int age)
{
    Person *p = malloc(sizeof *p); // *p is the same as malloc(sizeof (struct Person)) or malloc(sizeof p[0])
    p->name = strdup(name);        // this vs. strdup(name); --> strdup copies that string and returns a pointer to that new string, useful if for example it's a buffer being passed and not a string literal
    p->age = age;
    p->printable.print = print_person;
    p->freeable.free_ = free_person;
    return p;
}
void print_car(Printable *c)
{
    // macro will expand to...
    (Car*)(void*)((char*)c - offsetof(Car, printable));
    Car *car = container_of(c, Car, printable);
    printf("<Car: %s %s (%d)>\n", car->make, car->model, car->year);
}
Car *create_car(char *make, char *model, int year)
{
    Car *c = malloc(sizeof *c);
    c->make = make;
    c->model = model;
    c->year = year;
    c->printable.print = print_car;
    c->freeable.free_ = free_car;
    return c;
}
void print(Printable *printable)
{
    printable->print(printable);
}

void take_int(int n){n*n;};
void take_double(double n){n*n;};
int main(void) 
{
    #include <math.h>
    #define SQRT(X) _Generic((X), float: sqrtf, long double: exp, default: sqrt)(X)             // cool --> invokes the appropriate function, notices the (X) function call with parameter at the end!
    #define SQRT2(X) _Generic((X), float: sqrtf(X), long double: pow(2, X), default: sqrt(X))   // another way to call generic is just to put the function call within the type-value itself
    printf("%f %f %f\n", SQRT(4.), SQRT(5.0f), SQRT2(6.0l));

    take_int(238ULL);
    take_double(4.0);
    take_double(4);
    take_int(4.0L);

    #define FORMAT(X)   _Generic((X), float: "%f", double: "%f", long double: "%Lf", char*: "%s")
    #define TYPE(X)     _Generic((X), float: "float", double: "double", long double: "long_double", char*: "string")
    #define PPRINT(X)   printf(FORMAT(X), X); printf(" is of type %s\n", TYPE(X))
    #define STRINGIZE(X)   #X

    PPRINT("Hello");
    return 0;
    printf("Log10_%d=%.2f\n", 10, log10(100.0));
    printf("%f is of type %s\n", 10.0, TYPE(10.0));
    printf("%f is of type %s\n", 10.0F, TYPE(10.0F));
    printf("%Lf is of type %s\n", 10.0L, TYPE(10.0L));
    printf("%s if of type %s\n", STRINGIZE(10.), TYPE(10.));
    printf(FORMAT(10.), 10.);
    /* -- %f is of type %s -- %f if of type %s\n", 10., TYPE(10.), 10.0L, TYPE(10.0L)); */
    Person *don = create_person("Donnie", 20);
    print_person(&(don->printable));
    print(&(don->printable));
    free_(&(don->freeable));

    Car *cadillac = create_car("GM", "Cadillac", 2020);
    print(&cadillac->printable);    // &, -> have same precedence but associate from right-to-left, so becomes &(cadillac->printable)
    free_(&cadillac->freeable);    

    return 0;
}

