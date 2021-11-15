#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void){


    char min_char = 0;
    char max_char = 0;
    while (max_char <=0)
        max_char--;
    min_char = max_char+1;
    printf("Max char value : %d\n", max_char);
    printf("Min char value : %d\n", min_char);

    unsigned char max_uchar = 0;
    max_uchar--;
    printf("Max unsignedchar value : %d\n", max_uchar);


    unsigned short int max_usint = 0;
    max_usint--;
    printf("Max unsigned short int value : %d\n", max_usint);
    short int max_sint;
    short int min_sint;

    min_sint = max_usint / 2;
    while (min_sint >=0)
        min_sint++;
    max_sint = min_sint-1;

    printf("Max short int value : %d\n", max_sint);
    printf("Min short int value : %d\n", min_sint);

    // chars
    // printf("Nb of bits in a char: %d\n", CHAR_BIT );
    // printf("Maximum length of a multibyte character: %d\n", MB_LEN_MAX );
    // printf("Min value signed char: %d\n", SCHAR_MIN );
    // printf("Max value signed char: %d\n", SCHAR_MAX );
    // printf("Max value unsigned char : %d\n", UCHAR_MAX );

    // printf("Min value char: %d\n", CHAR_MIN );
    // printf("Max value char: %d\n", CHAR_MAX );

    // // ints

    // printf("Min value signed short in : %d\n", SHRT_MIN );
    // printf("Max value signed short int: %d\n", SHRT_MAX );
    // printf("Max value unsigned short int: %d\n", USHRT_MAX );

    // printf("Min value signed int: %d\n", INT_MIN );
    // printf("Max value signed int: %d\n", INT_MAX );
    // printf("Max value unsigned int: %u\n", UINT_MAX );

    // printf("Min value signed long int: %ld\n", LONG_MIN );
    // printf("Max value signed long int: %ld\n", LONG_MAX );
    // printf("Max value unsigned long int: %lu\n", ULONG_MAX );

    // // On my machine long long and long have same size
    // printf("Min value signed long long int: %lld\n", LLONG_MIN );
    // printf("Max value signed long long int: %lld\n", LLONG_MAX );
    // printf("Max value unsigned long long int: %llu\n", ULLONG_MAX );

}