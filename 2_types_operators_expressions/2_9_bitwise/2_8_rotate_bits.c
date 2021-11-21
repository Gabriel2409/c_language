#include <stdio.h>
unsigned rotate(unsigned x, int n);
int main(void)
{

    int x = 908;
    int n = 4;
    printf("%u\n", rotate(x, n));
    printf("%u\n", rotate(x, n));
}

unsigned rotate(unsigned x, int n)
{
    unsigned last = x & ~(~0 << n);
    unsigned xx = x;
    int p;
    for (p = 0; xx > 0; p++)
    {
        xx = xx >> 1;
    }
    printf("aaa%d\n", p);

    last = last << (p  - n);

    return last | (x >> n);
}