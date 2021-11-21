#include <stdio.h>
unsigned invertbits(unsigned x, int p, int n);
int main(void)
{

    int x = 9;
    int n = 2;
    int p = 1;
    printf("%u\n", invertbits( x,  p,  n));


}

unsigned invertbits(unsigned x, int p, int n)
{
    unsigned last = x & ~(~0 << p+1-n);
    unsigned u = (x >> (p + 1 - n));
    u = u ^ (~(~0 << n));
    u = u << (p+1 - n);
    u = u | last;
    return u;
}