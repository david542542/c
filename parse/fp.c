#include <stdio.h>


int square(int n)
{
    return n*n;
}
int cube(int n)
{
    return n*n*n;
}
typedef unsigned char BYTE;
typedef int (*INT_FUNC)(int n);
/* typedef  */
int apply(int (*fp)(int n), int n)
{
    printf("before: %d\n", n);
    int after = fp(n);
    printf("after: %d\n", after);
    return after;
}

void bin(unsigned char n)
{
    if (n > 1) bin(n>>1);
    putchar(n&1 ? '1' : '0');
}
int main(void) {

    /* bin(255); */
    for (unsigned char i = 255; i; i--) {
        printf("%d --> ", i), bin(i);
        getchar();
    }
    return 0;
    #define BITS 8
    bin(4);
    return 0;

    unsigned char d = 0b00001011;
    d = -d; // ~ + 1 is the same as -
    char buffer[BITS+1] = "00000000";
    for(int ix=0; d!=0; d>>=1, ix++) {
        buffer[BITS-1-ix] = d&1 ? '1' : '0';
    }
    printf("%s\n", buffer);

    int xy=799;
    printf("-- %d -- \n", (char) xy);
    printf("-- %d -- ", xy & 0xFF);
    return 0;

    
    /* do { */
        /* printf("%d", d&1); */
    /* } while (d>>=1); */
    /* printf("---"); */

    BYTE x = 0x4;
    printf("%#x\n", x);
    int num = 4;
    int (*fp1) (int n), (*fp2) (int n);
    fp1 = square;
    fp2 = cube;
    INT_FUNC fp3 = cube;    // using a typedef for it instead -- cool!
    printf("File: %s | Line: %d | Function: %s | Date: %s | C Version: %ld\n",__FILE__,  __LINE__, __FUNCTION__, __DATE__, __STDC_VERSION__);

    printf("Num: %d, f1: %d, f2: %d, f3: %d\n", num, fp1(num), (*fp2)(num), fp3(num));

    int k = apply(fp1, 5);
    printf("***%d***\n", k);
    /* fp1 = square; */

    /* fp1 = cube; */
    printf("Num: %d, Squared: %d, Cubed: %d\n", num, square(num), cube(num));

    
    printf("OK\n");
}
