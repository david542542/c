#include <stdio.h>

// To practice a few (3) recursive functions
int power(unsigned int x, unsigned int y)
{
    int out = 1;
    for (int i=0; i<y; i++)
        out *= x;
    return out;
}
int power_r(unsigned int x, unsigned int y)
{
    if (y==0)
        return 1;
    return x * power_r(x, y-1);
}
int sum(unsigned int n)
{
    int out = 0;
    for (int i=n; i>0; i--)
        out += i;
    return out;
}
int sum_r(unsigned int n)
{
    if (n==1) 
        return 1;
    return n + sum_r(n-1);
}
void bin_r(unsigned int n)
{
    // how many total digits -- this will be finished before unwinding the stack
    static int digits, sep;
    if (digits==0) printf("%d --> ", n);
    digits++;   

    if (n>1) 
        bin_r(n>>1);
    putchar((n&1)==0? '0' : '1'); // == has higher precedence than &

    // unwinding the stack -- separate every four digits from RTL, newline at end
    sep ++;
    if (!((digits-sep)%4) && digits != sep) putchar(' ');
    if (digits==sep) {
        putchar('\n');
        digits = sep = 0;
    }
}
int invert_end(unsigned int num, unsigned int digits)
{
    int mask = (1<<digits)-1;
    return num ^ mask;
}
struct font {
    unsigned int bold : 1;
    unsigned int italics : 1;
    unsigned int underline : 1;
};

int main(void)
{
    // _Alignof gets number of bytes to align that type
    // _Alignas aligns that on the size-boundary
    //   though it should not be smaller than the fundamental type alignment
    unsigned char _Alignas(double) hello;
    int xx[5];
    printf("%zu %zu\n", _Alignof(xx), sizeof (xx));
    printf("%zu %zu\n", _Alignof(int), sizeof (int));
    printf("%zu %zu\n", _Alignof(char), sizeof (char));
    /* size_t d_align = _Alignof(font);    // gives the alignment requirements for a type */
    /* printf("%zu %zu\n", _Alignofint), sizeof (int)); */
    struct font myFont = {1,1,1};
    struct font ufont;
    ufont.bold=1;
    ufont.italics=1;
    ufont.underline=1; 
    int x=3;
    int y=3;
    printf("%d^%d=%d\n", x, y, power(x,y));
    printf("%d^%d=%d\n", x, y, power_r(x,y));
    int n=5;
    printf("SUM(%d)=%d\n", n, sum(n));
    printf("SUM(%d)=%d\n", n, sum_r(n));
    int z=72;
    bin_r(z);
    z = invert_end(72, 4);  // invert last n bits
    bin_r(z);
    /* bin_r(1777, 0); */
    int s=0;

    return 0;
}
