
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<iso646.h>
#define BOOL_STRING(x) (x ? "true" : "false")
#define PRINT_SEP(x) for(int i=1; i<x; i++) putchar('-'); putchar('\n')
// cmd-b to toggle a breakpoint
// ctrl-opt-cmd-g to enter debugging in adjacent panel -- :vert term -- to open a vertical terminal (:term for horizontal)

// gdb shortcuts:
// c  -- run program until next breakpoint (or finished)4
// s  -- run next line of code (for example, in c)the next line of the program
// n  -- run next line of code (but dont go into functions -- helpful, for example to skip big library functions like printf
// si -- run next assembly instruction

// !ctags -R --c++-kinds=+p --fields=+iaS --extra=+q /usr/include
// :set tags+=tags
int square(int n)
{
    return n*n;
}
void ctype()
{
    int a = 4;
    // note the if/else is considered a single statement, so dont need braces in the below.
    // an 'else' goes with the most recent 'if' statement unless braces indicate otherwise.
    if (a == 5)
        printf("OK\n");
    else
        if (a==6)
            printf("Nok\n");
        else if (a==4)
            printf("Voila!\n");
        else
            printf("Something else!\n");


    int x=7,y=-2,z=4;

    if (x>7 && y<-2)
        printf("OK");

    if (x > 7 and z < 4)
        printf("Iso646 is here\n");

    // note: && and || are sequence points, so something like a post-increment happens before the next sub-expression after &&
    x = 5;
    if (x++ > 5 || x > 5) // this will evaluate to true since the post-increment happens before the || sequence point.
        printf("Yes!\n");

    x = 5;
    if (x++ > 5 && x++ > 5) // even though this evaluates to false, it will still post-increment (but && will exit on first false)
        printf("Ok!\n");
    printf("***%d\n", x);


   /* order of operations
    ++ --, -, +, !
    / *
    + - %s
    > >= < <=
    != ==
    &&
    ||
    ?: (ternary)
    =, +=, -=, ...

    */


    exit(1);
    return;
    int c;
    while ((c=getchar()) != EOF) {
        if (c == 'H')
            printf("Yup, it's an H!\n");
        else if (c == 'e')
            printf("Yup its an e!\n");
        else
            printf("S");
        printf("'%c' is %s a letter.\n", tolower(c), isalpha(c)? "indeed" : "not");
        printf("c=%c, upper=%c, lower=%c\n", c, toupper(c), tolower(c));
        if (c == '.') break;
    }
    /* while ((c = getchar()) != '.') */
    /* printf("'%c' is %s a letter.\n", c, isalpha(c)? "indeed" : "not"); */
}
void ctype2()
{
    char c;
    while ((c = getchar()) != '.')
        printf("'%c' is %s a letter.\n", c, isalpha(c)? "indeed" : "not");
    printf("'%c' is %s a letter.\n", c, isalpha(c)? "indeed" : "not");
    
    char ch;
    do {
        ch = getchar();
        printf("'%c' is %s a letter.\n", ch, isalpha(ch)? "indeed" : "not");
    } while (ch != '.');
}
int main(void)
{

    ctype();
    return 0;
    int a=2;
    int b=square(a);
    // abs -->  absolute value (int)
    // fabs --> absolute value (float)
    // labs --> absolute value long)
    /* printf("Abs: -3.2 = %.1f, %d\n", fabs(-3.2), abs(-2)); */

    // Relational operators (==, <, >=, etc.) are less thatn arithmetic, but greater than assignment.
    // a = b > a --> a = (b > a)
    // x = a + b > c+d --> x = (a+b) > (c+d) --> x = ((a+b) > (c+d)) --> x will be 'true' or 'false'
    // within the relational operators, the 'equivalency checks', == and !=, have the lower precedence
    // x > 2 == x > 3 --> (x > 2) == (x > 3)
    // Logical operators have lower precedence than relational operators --> ==/!=  >   &&   >   ||   

    /* char ch = getchar(); // For example: enter in CALL ME  */
    /* putchar(ch); */
    #define SPACE ' '
    char ch; // For example, enter in CALL ME HAL: it will keep iterating until the newline.
    while ((ch = getchar()) != '\n') {
        if (ch == SPACE)
            putchar(ch);
        else
            putchar(ch + 1);
    }

    // if statement
    int f_num;
    printf("What is your favorite number? ");
    scanf("%d", &f_num);
    if (f_num > 10)
        printf("Your favorite number is greater than 10!\n");
    else
        printf("Your favorite number is less than 10!\n");

    // average of five numbers entered
    #define ARRAY_SIZE 5
    int numbers[ARRAY_SIZE];
    printf("Enter in 5 numbers: \n");
    for (int i=0; i < ARRAY_SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    int sum=0;

    float avg;
    // note: we want the sum to outlive this, so don't initialize it within the for loop (because will only live within that scope)
    for(int i=0; i < ARRAY_SIZE; sum += numbers[i++]); 
    avg = (float) sum / ARRAY_SIZE;
    printf("The sum is: %d and the average is: %.2f\n", sum, avg);
    return 0;


    // do-while vs. while -- 
    char *string = "String!";
    int pos_d=0, pos_w=0;

    // while
    while (string[pos_w] != 0) {
        printf("At Pos %d The letter is: %c\n", pos_w, string[pos_w]);
        pos_w ++;
    }
    return 0;

    PRINT_SEP(20);
    /* PRINT_SEP(10); */
    /* for(int i=1; i<=20; i++) putchar('-'); putchar('\n'); */

    // do-while
    do {
        printf("At Pos %d The letter is: %c\n", pos_d, string[pos_d]);
    } while (string[pos_d++] != 0);


    return 0;



    // zenos paradox -- assume time to go four meters, rate is 2m/s
    
    int n=1, max_n=2;
    printf("%d %d\n", n, max_n);
    double rate=1.0, distance=2.0;

    printf("Enter the number of iterations you want: \n");
    if (scanf("%d", &max_n)  != 1) printf("Error! Items parsed != 1\n");

    for (double t=0.0, distance=0.0, dt; n <=max_n ; n++) {
        dt =  1.0 / pow(2, n-1);
        t += dt;
        distance += dt * rate;
        printf("%2d. Time: %8.4f | Distance: %.4f \n", n, t, distance);
    }


    return 1;

    for (char letter='a'; letter <= 'z'; letter++) {
        printf("The ASCII value for %c is %d\n", letter, letter);
    }
    // note: comma (,) is a sequence point so all side effects are evaluated before moving on
    // its value is the right-most value, so x = (z=2) + 2 --> x=4
    for (int i=2, j=3; i<10 && j < 9; i++, i++, i++) {
        printf("i=%d, j=%d\n", i, j);
    }


    for (printf("Hello!"); a <= 10; a=(++a+1)) {
        printf("Again! A: %d\n", a);
    }
    for (int x=1, y=55; y <= 75; y = (++x*5)+50 + 1) {
        printf("%10d %10d\n", x, y);
    }

    bool is_good=0, is_bad=1;
    printf("%d %d %s %s\n", is_good, is_bad, BOOL_STRING(is_good), BOOL_STRING(is_bad));
    int status, current_number, summy=0;
    bool input_is_good;
    bool another = true; // stdbool.h allows us to use 'true' and 'false'
    /* printf("%d", another); */
    /* printf("Enter a number: "); */
    /* while(input_is_good=(scanf("%d", &current_number)==1)) { */
        /* sum += current_number; */
        /* printf("Status: %d. The current sum is: %d. Enter another number: ", input_is_good, sum); */
    /* } */
    /* printf("\nStatus: %s. The total sum is: %d\n", BOOL_STRING(input_is_good), sum); */
    /* status = scanf("%d", &status); // scanf returns num of arguments successfully parsed */
    /* printf("a=%d | a**2=%d | Status: %d\n", a, b, status); // break */
    return 0;
}
