#include"calculator.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /* Test icin kullanilacak onceden hesaplanmis degerler */
    long int fact_test[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800};
    int fibo_test[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
    int expo_test[] = {1, 2, 4, 8, 16, 32, 64, 128};

    int i;

    printf("sizeof(int): %zu\n", sizeof(int));
    printf("sizeof(long int): %zu\n\n", sizeof(long int));

    /* Ozyineleme faktoriyel testi*/
    for(i = 0; i < (sizeof(fact_test) / sizeof(long int)); ++i) {
        assert(factorial_recursive(i) == fact_test[i]);
        printf("factorial_recursive(%d): OK\n", i);
    }
    printf("\n");

    /* Yinelemeli Faktoriyel testi */
    for(i = 0; i < (sizeof(fact_test) / sizeof(long int)); ++i) {
        assert(factorial_iterative(i) == fact_test[i]);
        printf("factorial_iterative(%d): OK\n", i);
    }

    /* OBEB hesabi testi*/
	assert(gcd(10, 2) == 2);
	assert(gcd(2, 10) == 2);
	assert(gcd(10, 15) == 5);
	assert(gcd(15, 10) == 5);
	assert(gcd(1, 1) == 1);
	assert(gcd(2, 1) == 1);
	assert(gcd(1, 2) == 1);
	printf("Gcd : All tests passed.\n");


    /* Fibonacci dizisi testi */
    for(i = 0; i < (sizeof(fibo_test) / sizeof(int)); ++i) {
        assert(compute_fibonacci(i) == fibo_test[i]);
    }

    printf("Fibonacci: All tests passed.\n");


    /* Kuvvet Hesabi testi*/
    for(i = 0; i < (sizeof(expo_test) / sizeof(int)); ++i) {
        assert(exponentiation(2, i) == expo_test[i]);
    }
    printf("Exponentiation: All tests passed for exponentiation().\n");

    /* Kuvvek Hesabi testi - 2*/
    for(i = 0; i < (sizeof(expo_test) / sizeof(int)); ++i) {
        assert(fast_exponentiation(2, i) == expo_test[i]);
    }
    printf("Exponentiation: All tests passed for fast_exponentiation().\n\n");

    TIMEIT(exponentiation(1, 1000), 100);
    TIMEIT(fast_exponentiation(1, 1000), 100);

    return 0;
}
