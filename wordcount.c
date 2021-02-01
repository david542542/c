#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(void)
{
    // grab a segment of text until EOF
    exit()
    putchar('X'); putchar('\n');
    int a, b;
    /* a > b ? a=4 : b=2; */
    a > b ? (a=5) : (b=4);
    printf("a: %d | b: %d\n", a, b);

    int i=0;
    while (i++<10)
        printf("%d...", i);

    i = 0;
loop:
    i++;
    printf("%d...", i);
    if (i<10) 
        goto loop;
loop_exit:
    return 0;

    // a break is a goto statement that jumps to the end of the current loop.
    // a continue is a goto statement that jumps to the start of the loop (or the update part of a `for` if it exists)
    goto label1;
    printf("Item 1\n");
    printf("Item 2\n");
    label1:
        printf("Item 3\n");
    return 0;

    // a switch statement must have an integer value the label or comparison value: switch (4.2) is invalid, as is case 3.7:
    // in that case, you need to use an `if` statement instead.
    // additionally, to test a range of values, such as (i > 0) && (i < 10000), use an `if` statement and not a switch 
    /* #define MAX_LEN 10 */
    /* int c[MAX_LEN] = {0,1,2,3,4,5,6,7,8,9}; */
    /* for (int num, i = 0; i < MAX_LEN; i++) { */
        /* num = c[i]; */
        /* printf("***%d***\n", num); */
        /* switch (num) { */
            /* case 4: */
            /* case 5: */
                /* printf("Case 4 or 5!...\n"); */
            /* case 6: */
            /* case 7: */
                /* printf("Case 6 or 7!...\n"); */
            /* default: */
                /* printf("Default...\n"); */
        /* } */
    /* } */
    /* return 0; */

    return 0;
    int current_char;
    int num_words=0, num_chars=0, num_lines=0; // ignore whitespace
    bool in_word;
    printf("Enter your text here:\n");
    while ((current_char=getchar()) != EOF)
    { if (current_char == '\n')
            in_word ? num_words++, num_lines ++, in_word=false : num_lines++;
         else if (isalnum(current_char))
            num_chars ++, in_word=true;
        else if (isspace(current_char))
            in_word ? num_words++, in_word=false : ' '; }
    if (in_word) num_words ++;
    printf("\nChar Count: %d | Line count: %d | Word count: %d\n", num_chars, num_lines, num_words);
}
