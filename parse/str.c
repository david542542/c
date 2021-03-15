#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MSG = "I am a symbolic constant"
#define MAXLENGTH 80

char* s_gets(char st[], int n)
{
    /*
    given a pointer and length, write that to the char arry, 
    discarding extra output, ignoring strings
    */
    int i=0;

    // write to st, if NULL output, can exit immediately
    st[0] = 0;
    if (!fgets(st, n, stdin)) return NULL; 

    // another way to process this using 'strchr' or 'str-contains-char':
    /* char* find = strchr(st, '\n'); */
    /* if (find) *find = '\0'; */
    /* else while (getchar() != '\n'); */

    while (st[i] != '\n' && st[i] != 0) i++;

    char last_char = st[i];
    if (last_char == '\n') st[i] = 0; // means string is smaller than max
    else while (getchar() != '\n');   // consume extract chars
    /* printf("|%s|", st); */

    return st;
}


int puts_with_sep (const char* text, char sep, bool newline)
{
    char c;
    int i;
    
    putchar(sep);
    for (char c, i=0; (c=*text); text++, i++) putchar(c);
    putchar(sep);
    if(newline) putchar('\n');

    return i;

}
char* shrink (char* text, int size)
{
    return (strlen(text) <= size) ? text : (text[size]='\0', text);

    // long-form way to do it
    if (strlen(text) > size)
        text[size] = '\0';
    return text;

}

bool s_compare(const char* str1, const char* str2)
{
    // if its the same pointer can return immediately
    // also covers the case where both are null pointers
    if (str1 == str2) 
        return true;

    // way 2
    /* int i=0; */
    /* do { */
        /* if (str1[i] != str2[i]) return false; */
    /* } while (str1[i++] != 0); */

    // if str1 is empty and str2 is non-empty
    size_t len = strlen(str1);
    if (!len && str2[0] != 0)
        return false;

    // see if for length of str1 > 1, all letters in str2 match
    // we also go up through the nul char to make sure the size
    // of both strings is the same
    for (int i=0; i<=len; i++)
        if (str1[i] != str2[i]) 
            return false;

    return true;
}

int main(void)
{

    char *s = "Howdy";

    // strpbrk(char* string, char* string) -- second string contains a list of characters to break on
    printf("%d %d\n", (bool) strpbrk("Hello", "xyz"), (bool) strpbrk("Hello", "lox"));

    //strrchr -- same as strchr except returns a pointer to the LAST instead of the first occurrence.
    // for example, to find the last segment in a filepath. kind of like: str.split(',')[-1] --> strrchr(str, ',') + 1
    const char* path = "/my/big/file.mov";
    char* ptr_last_slash = strrchr(path, '/') + 1;
    printf("The file is: %s\n", ptr_last_slash);

    // strchr(char* string, char c) -- first occurrence of character in string -- STRing CHaRacter --> "STCHR"
    char testchars[] = {'a','b','c','d','e','f','g','h', 'H'};
    for (char i=0, c; i<sizeof testchars; i++) {
        c = testchars[i];
        printf( "The char '%c' is %sin '%s'\n", c, strchr(s, c) ? "" : "not ", s);
    }
    // strstr(char* string1, char*string2) -- first occurrence of string2 in string1
    char* teststrings[] = {"Ho", "ho"};
    for (int i=0; i<sizeof teststrings / sizeof (*teststrings); i++) {
        char* this = teststrings[i];
        /* printf("%d", i); */
        printf( "The string '%s' is %sin '%s'\n", this, strstr(s, this) ? "" : "not ", s);
    }
    return 0;

    /* if (strchr("Hello", 'H')) printf("Yes!"); */
    /* if strchr("Hello", 'H') printf("Yes!"); */
    /* printf("%p %p" */

            /* ) */
    /* char mystr[20]; */
    /* char mystr2[40] = {0}; */

    /* sprintf(mystr, "String has len: %zu", sizeof(mystr) / sizeof(*mystr)); */
    /* strcat(mystr, " MORE"); */
    /* strncpy(mystr2, mystr, 40); */
    /* puts(mystr); */
    /* puts(mystr2); */

    // strcpy(desetination, source), just like assignment 
    // your="New" --> strcpy(your, "New");
    // returns the address of the first char written to
    char your[10];
    strcpy(your, "Newnnnnnn");
    strcpy(your, "N"); // copies over all the chars + the nil character at the end
    strncpy(your, "Hippopotamus", 5); // note: the null character is not copied if the specified LEN is less than the string length.
    your[4] = '\0'; // need to add in the null character to the Nth character if strncpy hasn't copied up through the '\0' char.

    puts(your);
    /* char* addr = strncpy(your+2, "Newerest", 10);  */
    /* printf("%p...%p %td\n", your, addr, addr-your); */

    const char* startswith = "He";
    const char* wordss[4] = {"Hello", "Hey", "Her", "Him"};
    // strcmp compares the two strings until the end of the lhs string or until the first difference
    // strncmp compares the two strings for the first N chars until the end of the lhs string or until the first difference
    for (int i=0; i < sizeof(wordss)/sizeof(*wordss); i++)
        printf("Word: %-5s Starts with prefix: %s\n", wordss[i], strncmp(startswith, wordss[i], strlen(startswith))==0 ? "Yes" : "No");
    /* puts(wordss[i]); */
    // string compare
    return 0;
    char input[10];
    s_gets(input, 10);
    printf("Your input was: '%s'\n", input);
    bool same = s_compare(input, "Hello");
    printf("Your input was the same as 'Hello': %d\n", same);

    if(strcmp(input, "Hello") == 0)
        printf("The input you entered was hello!\n");

    // ***strcmp(const char* lhs, const char* rhs)
    // why does strcmp return 0 if the two strings are the same?
    // The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as unsigned char) that differ in the strings being compared.
    // - Negative value if lhs appears before rhs in alphabetical order.
    // - Zero if lhs and rhs compare equal.
    // - Positive value if lhs appears after rhs in alphabetical order.
    printf("%d %d\n", strcmp("A", "C"), strcmp("x", "d")); // 
    printf("The input you entered was %shello\n", strcmp(input, "Hello") ? "" : "not ");
    return 0;


    char xx[44] = {0};
    strcat(xx, "Hello");
    strcat(xx, " there");
    strncat(xx, " there", 3); // note: this is up to N-1 chars since the \0 takes up one char.
    strncat(xx, " there", 13); // note: this is up to N-1 chars since the \0 takes up one char.
    puts(xx);

    char first_name[20]={0}, last_name[20]={0}, full_name[40]={0};
    puts("First Name?"); 
    s_gets(full_name, 10);
    puts("Last Name?");  
    s_gets(last_name, 10);
    strcat(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    /* strcat(full_name, " "); */
    /* strcat(full_name, s_gets(last_name, 10)); */
    printf("Your full name is: %s\n", full_name);

    /* char big[] = "Hello there!"; */
    /* printf("Shrunk: '%s'", shrink(big, 9)); */
    return 0;

    // example of a buffer overflow
    /* char arr[5]; */
    /* gets(arr); */
    /* printf("What was entered into the arr[5] was: %s", arr); */
    /* return 0; */

    /* return 0 */
    char xml[5];
    /* while (gets(xml)) puts(xml); */
    while(s_gets(xml, 5)) {
        int xi = puts_with_sep(xml, '*', 1);
        printf("%d\n", xi);
        /* puts(xml); */
        /* putchar('*'); */
        /* fputs(xml, stdout); */
        /* putchar('*'); */
        /* putchar('\n'); */
    }
    return 0;
    fputs("Hello Everyone!\n", stdout);
    fgets(xml, 6, stdin);
    printf("Fgets gave us: %s\n", xml);



    return 0;
    char* nm = "hello";
    // puts takes an address of a string (can even be a string literal, which evals to its address)
    puts("hello");
    puts("hello" + 2); // does pointer arithmetic to add on 2
    puts(&"hello"[2]); // gets address of 2nd element
    puts(nm);
    char bad[] = {'h', 'e', 'l', 'l', 'o'}; // not a char-array, does not have a null terminator, so undefined behavior
    puts(bad);

    const int max=6;
    char hello[max];
    puts("Enter some text: ");
    s_gets(hello, max);
    printf("|"); 
    fputs(hello, stdout); // only useful if not writing to stdout, otherwise could use puts or printf
    printf("|\n"); 

    puts("Now enter in two names: ");
    char name1[4];
    char name2[10];
    scanf("%4s %10s", name1, name2);
    printf("Name1: %s, Name2: %s", name1, name2);
    return 0;

    char words[MAXLENGTH] = "I am a string in an array!";
    const char* pt1 = "Something is pointing at me!";
    pt1 = "Adios";
    // compiler will initialize the same string once -- character arrays placed in the static storage class
    char* x = "Hello";

    // Array string -- basically creates an address constant, character-modifiable
  { char car[10] = "Tata";
    car[0] = 'X';   // can change any character in the array
    // car = "New"; // cannot do: array is not lvalue
    printf("%s\n", car);
  }

    // Ptr string -- basically creates a string constant, address-modifiable
  {
    char *car = "Dada";
    /* car[0] = 'X'; // cannot do: string-literal is constant (rodata) */
    car = "OK";  // can change the memory address ptr points to
    printf("%s\n", car);
  }
  
  // array of char-arrays (must have the same length, can often be quite inefficient due to different string-sizes
  // and the array has to be the same size for every element and able to hold the largest string.
  {
      char cars[][10] = {"Honda", "Buick"}; // outer array length will be automatically filled in
      for (int i=0; i<2; i++) printf("%s,", cars[i]);
  }
  {
      putchar('\n');
      // an array of character-pointers, will take up 8 bytes per element, size can be omitted if initialized
      char* cars[] = {"Dodge", "Camry"};
      for (int i=0; i<2; i++) printf("%s,", cars[i]);
  }
  {
      /* char *name = "Hello"; // -- will show as a warning if we do -Wall or -Wuninitialized */
      /* char name[10]; */
      /* printf("%p\n", name); */
      /* scanf("%10s", name); // will be a run-time error if we try writing to the memory address of .rodata */
      /* printf("%s\n", name); */

  }
  {
    #define STRLEN 5
   // char*  fgets(pointer_to_write_to, length, file_handler)
   // char*  fgets(char * __restrict, int, FILE *);

    char words[STRLEN];
    words[0] = 0;
    int i;
    puts("\nEnter strings (# quit):");
    // this first writes to `words`, then the && is a sequence point and so it evaluates `words` after fgets(...)
    while (fgets(words, STRLEN, stdin) != NULL)
    {

        // if the word is less than n-1 --> that is, 4 chars, then it will Write it as "H" (72) "i" (105) \n (10) NULL (0)
        // however if the word is more than that (4 chars or more), it will right it as "H" (72) "e" (101) "r" (114) "e" (101) NULL (0)
        // and the newline will START the next input...
        i = 0;

        /* for (int i=0; i<strlen(words); i++) printf("%c (%d) ", words[i], words[i]); */
        // read up to the end of the first occurrence of NULL or \n
        while (words[i] != '\n' && words[i] != 0) i++;
        // if we get a newline first, it means the word is shorter than the max length (otherwise we would have gotten \0 first
        // so we can replace that newline with a \0 and shorten the word
        // otherwise, we chop off the runover
        if (words[i] == '\n') words[i] = 0;
        else while (getchar() != '\n');
        puts(words);

    }

        // asci code 10 is line feed
        /* printf("Words: %s (%zu)\n", words, strlen(words)); */
        // OK, so the word is 'processed' on a newline (that is, the buffer is flushed)



        /* printf("Char at %d = %c (%d)\n", i, words[i], words[i]); */
        /* i++; */
        /* while(words[i] != '\n' && words[i] != '\0') */
        /* { */
            /* printf("Char at %d = %c (%d)\n", i, words[i], words[i]); */
            /* i++; */
        /* } */
            /* words[i] = '\0'; */
        /* else */
            /* while (getchar() != '\n'); */
        /* fputs(words, stdout); */
        /* printf("The newline is at: %d", i); */
    /* puts("Done."); */
    /* puts("Enter a string please:"); */
    /* fgets(words, STRLEN, stdin); // will read up through the first (N-1) characters or until a newline or until an EOF char. */
    /* printf("\nThe string you entered was: %s\n", words); */
    /* fputs(words, stdout); // if there is more than 8 chars from the first, those will go to the next fgets */

    /* fgets(words, STRLEN, stdin); // will read up through the first (N-1) characters or until a newline or until an EOF char. */
    /* printf("\nThe string you entered was: %s\n", words); */
    /* fputs(words, stdout); */
    
    return 0;

  }
  {
    #define STLEN 8
    char words[STLEN];
    puts("Enter a string, please.");
    // should not be used as gets does not do any bounds checking, it receives a pointer address and doesn't know how far to go
    /* gets(words); */
    printf("Your string: %s\n", words);
    puts(words);
    puts("Done");

  }
    return 0;
    /* char *car2 = "Buick";   // however, in this */
    /* car = "hello"; */
    /* printf("%d %d %d\n", car == &car[0], *car == car[0], *(car+1) == car[1]); */

    printf("%s %p %p %p\n", "Hello", x, "Hello", "Hello");
    /* pt1[2] = 'a'; */
    /* pt1 = "Hello"; */
    puts("Here are some strings:");
    puts(words);
    puts(pt1);
    words[8] = 'p';
    puts(words);

    return 0;

}
