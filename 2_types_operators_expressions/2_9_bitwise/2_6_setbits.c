#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);
int main(void)
{

    int x = 435;
    int y = 213;
    int n = 5;
    int p = 6;
    printf("%u\n", setbits( x,  p,  n,  y));


}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned last = x & ~(~0 << p+1-n);
    unsigned u = (x >> (p + 1)) << n;
    u = u | ((y & ~(~0 << n)));
    u = u << (p+1-n);
    u = u | last;
    return u;
}