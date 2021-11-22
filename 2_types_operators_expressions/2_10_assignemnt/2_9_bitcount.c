#include <stdio.h>
unsigned bitcoint(unsigned x);
unsigned fastbitcoint(unsigned x);
int main(void)
{

    int x = 1146542119;

    printf("%u\n", bitcoint(x));
    printf("%u\n", fastbitcoint(x));
}

unsigned bitcoint(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 1)
        {
            b++;
        }
    }
    return b;
}

unsigned fastbitcoint(unsigned x)
{
    int b = 0;
    while ((x != 0))
    {
        x &= (x - 1);
        b++;
    }
    return b;
}