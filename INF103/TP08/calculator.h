#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <sys/time.h>

/* FUNC ile verilen fonksiyonu REP defa calistirip
 * ortalama calisma suresini ekrana yazar.
 */
#define TIMEIT(FUNC, REP) do { \
    struct timeval t1, t2; \
    int i; \
    gettimeofday(&t1, NULL); \
    for(i = 0; i < REP; ++i) { \
        FUNC; \
    } \
    gettimeofday(&t2, NULL); \
    printf("Average execution time of '%s' (Repetition = %d): %f ms\n", #FUNC, i, ((((t2.tv_sec - t1.tv_sec) * 1000.0) + ((t2.tv_usec - t1.tv_usec) / 1000.0)) / REP)); \
} while (0)



long int factorial_iterative(int n);
long int factorial_recursive(int n);
int gcd(int x, int y);
int compute_fibonacci(int n);
int exponentiation(int x,int n);
int fast_exponentiation(int x,int n);


#endif /* CALCULATOR_H_ */
