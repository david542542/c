#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char* name;
} Person;
typedef struct Car {
    char* make;
} Car;
struct Car* create_car(void)
{
    puts("Creating a car");
    return NULL;
}
struct Person* create_person(void)
{
    puts("Creating a person");
    return NULL;
}
// can use a NULL or 0 so that we can pass it as the object and not have to first define it.
#define NewObj(X)  _Generic(((X*)NULL), struct Person*: create_person(), struct Car*: create_car())
int main(void)
{
    NewObj(Car);
    NewObj(Person);

}
