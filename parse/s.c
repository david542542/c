#include <stdio.h>

typedef struct _Person {
    char   name[20];
    int    age;
    double weight;
} Person;

int main(void)
{

    Person tom = (Person) {.name="Tom", .age=20, .weight=125.0};
    printf("%zu", sizeof tom);
    // write the struct to a binary file
    FILE *fout = fopen("person.b", "wb");
    fwrite(&tom, sizeof tom, 1, fout);
    fclose(fout);

    // read the binary data and set the person to that
    Person unknown;
    FILE *fin = fopen("person.b", "rb");
    fread(&unknown, sizeof unknown, 1, fin);
    fclose(fin);

    // confirm all looks ok
    printf("{name=%s, age=%d, weight=%f}", unknown.name, unknown.age, unknown.weight);


}
