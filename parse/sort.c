#include<stdio.h>
#include<string.h>

void sort(char* strings[], size_t len)
{
    char *outer_string, *inner_string, *tmp_string;
    // start with n=0 string and go until the second to last (last string will equal itself of course)

    for (int i=0; i < len-1; i++)
    {
        // j is the offset from the outer string, for example, if there are 5 strings like this:
        // ['a', 'b', 'c', 'd', 'e']
        // and i=b
        //           j=c, d, e
        // so j will go up to length-i
        // for (int j=i+1; j<len; j++) <-- simpler way to write it and then j is not the offset from i, but the index of "i+j"
        for (int j=1; j<(len-i); j++)
        {
            // grab the outer string every time in case it's swapped (just makes reading the code easier)
            outer_string = strings[i]; 
            inner_string = strings[i+j];
            printf("Need to re-order: %s <--> %s? %s\n", outer_string, inner_string, strcmp(inner_string, outer_string) < 1 ? "Yes" : "No");

            if (strcmp(outer_string, inner_string) > 1)
            {
                // Note: this is rearranging string pointers! not the char-arrays on the stack
                tmp_string = outer_string;
                strings[i] = inner_string;
                strings[i+j] = tmp_string;
                /* getchar(); */

            }
        }

    }

}

void print(char* strings[], size_t len)
{
    for(int i=0; i<len; i++){
        printf("%-14s (Stack: %p String: %p)\n", strings[i], &strings[i], strings[i]);
        /* puts(strings[i]); */
    }
}
#include<ctype.h>
#include<stdlib.h> // contains atof, atol, atoi
                   // there's also strtol, strtod, and strtoul to convert a string to a long, double, and unsigned long
void to_upper_in_place(char* string)
{
    while(*string++ = toupper(*string));
    /* while (*string) */
        /* *string++ = toupper(*string); */
        /* printf("%c", *string++); */
        /* =toupper(*string++)); */
}
int main(int argc, char* argv[])
{
    // atoi takes a STRING that looks like a number, stopping at the first number

    strtol(char* string, char** address_of_string, int base);
    char* num = "49cdd";
    char *end;  
    strtol(num, &end, 10); // note: we pass the address of the string, because here it will update that pointer to point to the end of the parsable number.
    printf("%s %s (%d)", num, end, *end);
    getchar();
    puts("The %d command line args are:");
    for (int i=0; i< argc; i++)
        printf("%d -- %s\n", i, *(argv+i));


    // can use the following in gdb to double dereference:
    // >>> p *(char**) ($rbp-32)

    // >>> printf "0x%x: 0x%x: %s\n", ($rbp-0x20), *(char**)($rbp-0x20), *(char**)($rbp-0x20)
    //    0xffffe0d0: 0x55554a3e: Hello
    char* _hero = "Hero", hero[10];
    strcpy(hero, _hero);
    puts(hero);
    to_upper_in_place(hero);
    puts(hero);

    char* strings[4] = {"Hello", "Brando", "Its", "Me"};
    size_t len = sizeof strings / sizeof *strings;
    // 0xffffe0d0: 0x55554a3e: Hello
    print(strings, len);
    sort(strings, len);
    print(strings, len);
    // 0xffffe0d0: 0x55554a44: Brando
    // notice stack address is the same but pointer is changed! -- cool!



    printf("Running\n");
    return 0;
}
