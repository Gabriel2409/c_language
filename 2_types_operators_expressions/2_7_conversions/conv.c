#include <ctype.h> // contains functions such as tolower, is digit
#include <stdio.h>
#include <math.h>

int main(void)
{

    printf("%c\n", tolower('A')); // 'a'
    printf("%d\n", isdigit('8')); // 2048 => truthy value

    int i;
    char c;

    i = 372;
    c = 'A';
    i = c;
    c = i;
    printf("%c\n", c); // no information lost

    i = 513;
    c = 'A';
    c = i;
    i = c;
    printf("%d\n", i); // prints 1 because excess bits are lost;

    float x = 45.9;
    i = x;
    printf("%d\n", i); // 45
    x = 45.9;
    x = i;
    printf("%f\n", x); // 45.000000

    int j = 49;
    // to use sqrt need to compile with -lm option : tells the linker the location of the math library
    printf("%f\n", sqrt((double) j)); // casts j to double for the operation. j itself is not altered (still an int)
    printf("%zx\n", sizeof(j)); // size of 4, j is still an int

    printf("%f\n", 4); // 4 is coerced to a double


}