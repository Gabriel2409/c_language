#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
int main(void){

    int i = 031;
    printf("%o\n",i & 027); //bitwise and
    printf("%o\n",i | 027); //bitwise or
    printf("%o\n",i ^ 027); //bitwise xor
    printf("%o\n",i << 2); //bitwise shift : same as multiply by 4
    printf("%o\n",i >> 1); //bitwise shift 
    printf("%o\n",i & ~077); // ~: complement. sets last 6 bits to 0: independent of word size


    printf("----------------------\n");
    printf("%d\n",~(~0 << 5)); // ~0 is all bits to 1. Shifts of 5 to right makes 5 last bits at 0.~ inverts again =>
    // 5 last bits at 1, which means 31
    printf("%d\n",getbits(45, 5, 3)); // 101101 becomes 101



}

unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n) ) & ~(~0 << n);
}