#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void){



    // chars
    printf("Nb of bits in a char: %d\n", CHAR_BIT );
    printf("Maximum length of a multibyte character: %d\n", MB_LEN_MAX );
    printf("Min value signed char: %d\n", SCHAR_MIN );
    printf("Max value signed char: %d\n", SCHAR_MAX );
    printf("Max value unsigned char : %d\n", UCHAR_MAX );

    printf("Min value char: %d\n", CHAR_MIN );
    printf("Max value char: %d\n", CHAR_MAX );

    // ints

    printf("Min value signed short in : %d\n", SHRT_MIN );
    printf("Max value signed short int: %d\n", SHRT_MAX );
    printf("Max value unsigned short int: %d\n", USHRT_MAX );

    printf("Min value signed int: %d\n", INT_MIN );
    printf("Max value signed int: %d\n", INT_MAX );
    printf("Max value unsigned int: %u\n", UINT_MAX );

    printf("Min value signed long int: %ld\n", LONG_MIN );
    printf("Max value signed long int: %ld\n", LONG_MAX );
    printf("Max value unsigned long int: %lu\n", ULONG_MAX );

    // On my machine long long and long have same size
    printf("Min value signed long long int: %lld\n", LLONG_MIN );
    printf("Max value signed long long int: %lld\n", LLONG_MAX );
    printf("Max value unsigned long long int: %llu\n", ULLONG_MAX );

    // floats

    printf("Nb of base digits (significand p.) float: %d\n", FLT_MANT_DIG );
    printf("Nb of base digits (significand p.) double: %d\n", DBL_MANT_DIG );
    printf("Nb of base digits (significand p.) long double: %d\n", LDBL_MANT_DIG );

    printf("Nb of decimal digits float: %d\n", FLT_DIG );
    printf("Nb of decimal digits double: %d\n", DBL_DIG );
    printf("Nb of decimal digits long double: %d\n", LDBL_DIG );


   // ...

   // conversions

   printf("%d\n", -1L < 1U);
   printf("%d\n", -1L > 1UL);
}