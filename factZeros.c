#include <stdio.h>

typedef unsigned long long int huge_int;

int val = 20;
// huge_int Yuge = fact;

huge_int fact_huge( int n ) {
    return (n == 1) ? 1 : n * fact_huge(n - 1);
}

unsigned long int fact( int n ) {
    return (n == 1) ? 1 : n * fact(n - 1);
}

int min( int x, int y ) {
    return x < y ? x : y;
}

int dividesQ( int k, unsigned long int n ) {
    return n % k == 0;
}

unsigned long int multiplicity( long int p, unsigned long int n ) {
    return dividesQ(p, n) ? 1 + multiplicity(p, n / p) : 0;
}

int trailingZeros( unsigned long int x ) {
    int twos, fives;
    
    twos = multiplicity(2, x);
    fives = multiplicity(5, x);
    return min(twos, fives);
}

int main() {
    printf("fact %d = %lu\n", val, fact(val));
    printf("%lu\n", multiplicity(5, fact(val)));
    printf("%lu\n", multiplicity(2, fact(val)));
    
    printf("%lu\n", multiplicity(5, 22789888000));
    printf("5s in 500: %lu\n", multiplicity(5, 500));
    printf("5s in 20922789888000: %lu\n", multiplicity(5, 20922789888000));
    printf("num of trailing zeros = %d\n", trailingZeros(fact(val)));
    
    printf("\nVal = %d and fact(Val) = %llu\n", val, fact_huge(val));
    
}
