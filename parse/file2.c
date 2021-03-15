#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void cat(const char* filepath, char buffer[], size_t len)
{
    FILE *f = fopen(filepath, "rb");
    if (!f) exit(EXIT_FAILURE);

    size_t cur = 0;

    for (int ch; (ch=getc(f)) != EOF && cur < len; cur++) {
        buffer[cur] = ch;
    }
    buffer[cur] = '\0';
    fclose(f);
}

#define putcharOne putchar('*')
#define putcharTwo putcharOne; putcharOne;
#define putcharFour putcharTwo; putcharTwo;
#define putcharEight putcharFour; putcharFour;

size_t
num_bytes(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    return (size_t) ftell(fp);
}

int main(int argc, char *argv[])
{
    FILE *x = fopen("parse.c", "r");
    fseek(x, 10, SEEK_CUR);
    printf("Ftell: %ld\n", ftell(x));
    fpos_t pos;
    fgetpos(x, &pos);
    fsetpos(x, &pos);
    /* printf("%d\n", zd); */
    /* fseek(x, 0, SEEK_END); */
    printf("The file is %zu bytes.\n", num_bytes(x));
    return 0;
    
    // fopen    - fopen(filename, mode)                 --> is the command to open a file - 
    // fprintf  - fprintf(file, "formatted text")       --> output formatted text to a file (same as printf but goes to a file)
    // getc     - getc(file)                            --> get the next character in the file stream
    // strncpy  - strncpy(output_buffer, string, len)   --> copy the string to the output buffer
    // strcat   - strcat(output_buffer, string)         --> append the string to the end of the output buffer.
    // fscanf   - fscanf(file, "formatted text")        --> eat from file handler, output is number of tokens eaten    

  {
    FILE *in  = fopen("in.txt", "r");
    FILE *out = fopen("out.txt", "w");

    char buffer[40];
    while (fgets(buffer, 40, in)) {
        fputs(buffer, out);
    }
    /* fflush(out);    // fclose does not automatically flush the buffer... */
    fclose(in) || fclose(out);      // using an && would short-circuit the logic because fclose(file) returns 0 if successful.
    /* fclose(in); */
    /* fclose(out); */

    // compare the two files
    char in_contents[200], out_contents[200];
    cat("in.txt", in_contents, 200);
    cat("out.txt", out_contents, 200);
    printf("%s%sSame? %s\n", in_contents, out_contents, strcmp(in_contents, out_contents)==0 ? "Yes" : "No");


    // seek around
  {
    FILE *fp = fopen("in.txt", "r");
    // fseek(file, number, seek_type)
    fseek(fp, 0L, SEEK_END);    // SEEK_END (use negative offset to go back), SEEK_SET (beginning), SEEK_CUR (from current)
    size_t last = ftell(fp);    // number of chars in the file, last char is the EOF char
    /* fseek(fp, -1L, SEEK_CUR);   // go to the last char now (before EOF) */
    // print things backwards
    puts("-----");
    char ch;
    for(size_t count=0; count < last; count++) {
        char ch = getc(fp);
        /* if (ch != EOF) printf("%c", ch);   // first time will be EOF */
        /* fseek(fp, -2, SEEK_CUR);    // seek back TWO since we just advanced by one by doing getchar */
    }
    putchar('\n');
    
    /* printf("Hell: %zu\n", last); */



  }
  /* return; */
    /* printf("%zu %zu", strlen(in_contents), strlen(out_contents)); */
    /* int x = strcmp(in_contents, in_contents); */
        /* printf("In and out are the same\n"); */
    /* else */
        /* printf("Strings are different!\n"); */


    return 0;
  }




    FILE *log = fopen("log.txt", "a+");
    FILE *oth = fopen("oth.txt", "w");
    char buffy[4];
    while (fgets(buffy, 4, log)!= NULL) {
        fputs(buffy, oth);
        putc('\0', oth);
    }
    return 0;

    char words[41];
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    // fscanf -- will scan the given file handler (or stdin) until it 'eats' the formatter, and then advance
    while (
           (fscanf(stdin, "%40s", words) == 1) 
        && (words[0] != '#')
    ) 
    {
        fprintf(log, "*%s\n", words);
        fflush(log);
    }


    int num_words=0;
    puts("File contents:");
    rewind(log); // go back to the beginning of the file
    while(fscanf(log,"%s",words)==1) {
        num_words+=1;
        putchar('*');
        puts(words);
    }
    fprintf(log, "Num words: %d\n", num_words);
    printf("Done! Words: %d", num_words);

    fclose(log);
    return 0;





    FILE *in, *out;

    // confirm two args
    if (argc != 2) {
        fprintf(log, "Need two args\n");
        exit(EXIT_FAILURE);
    }

    /* argv[1].split(".")[0] + ".log"; */
    char newname[40];                               // create a new buffer
    int len = strrchr(argv[1], '.') - argv[1];      // get the distance to the last occurrence of the "."
    strncpy(newname, argv[1], len);                 // copy the filename up to "."
    strncpy(newname + len, ".log", 5);              // now copy starting at the distance of the "." to the end
    fprintf(log, "%s\n", newname);                  // example to print the new filename

    {
        // buff = argv[1].split('.')[0] + '.david'
        char buff[50];
        strncpy(buff, argv[1], 50);
        strcpy(strrchr(buff, '.'), ".david");       // more efficient way to do it, just pass the pointer to it!
        printf("%s\n", buff);
    }
    return 0;

    // set up input
    in = fopen(argv[1], "r");
    if (!in) {
        fprintf(log, "Cannot open file\n");
        exit(EXIT_FAILURE);
    }

    // output
    #define LEN 50
    char name[LEN];
    strncpy(name, argv[1], LEN-5);  // allow five extra characters for the concat ".red" --> 4 + \0
    strcat(name, ".red");
    out = fopen(name, "w");
    if (!out) {
        fprintf(log, "Cannot create new file for writing.\n");
        exit(EXIT_FAILURE);
    }
    /* fprintf(out, "Need two args"); */

    // copy data -- copy all non-spaces.
    int ch;
    while ((ch=getc(in)) != EOF) {
        if (!isspace(ch))
            putc(ch, out);
    }

    if (fclose(in) != 0 || fclose(out) != 0 || fclose(log) != 0)
        fprintf(stderr, "Error closing file!\n");



    return 0;
}
