#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include"strassen.h"

int main(int argc, char *argv[]) {
    double A[4*4] = {
            1, 2, 3, 1,
            -1, 1, 2, 3,
            0, 4, 5, -3,
            -1, 1, 2, 3
    };
    double B[4*4] = {
            1, 2, 3, 4,
            4, 3, 2, 1,
            -1, -1, 2, 2,
            3, 0, 1, 2
    };
    double C[4*4] = {0};
    double D[4*4] = {0};
    double b[4];
    vecrand(4,b);

    printf("\n===================[ A ]===================\n");
    matprint(4,4,A);
    printf("===================[ B ]===================\n");
    matprint(4,4,B);
    printf("=================[ A + B ]=================\n");
    matadd(4,4,A,B,D);
    matprint(4,4,D);
    printf("=================[ A - B ]=================\n");
    matsub(4,4,A,B,D);
    matprint(4,4,D);
    printf("===================[ b ]===================\n");
    vecprint(4,b);
    printf("\n=============[ A + b (dim 0) ]=============\n");
    matvecadd(4,4,A,b,4,D,0);
    matprint(4,4,D);
    printf("=============[ A + b (dim 1) ]=============\n");
    matvecadd(4,4,A,b,4,D,1);
    matprint(4,4,D);
    printf("==================[ A^T ]==================\n");
    mattranspose(4,4,A,4,D);
    matprint(4,4,D);
    printf("\n\n");

    printf("================== A x B ==================\n");
    matmult(4, 4, A, 4, B, 4, C);
    matprint(4, 4, C);

    printf("===========================================\n");
    double Cfast[4*4] = {0};
    matmult_fast(4, 4, A, 4, B, 4, Cfast, 2);
    matprint(4, 4, Cfast);

    double err = 0.0;
    int i ;
    for (i = 0; i < sizeof(C) / sizeof(double); ++i) {
        err += C[i] - Cfast[i];
    }
    printf("\nError between methods: %.5f\n", err);
    assert(err < 0.0000001);

    /* Matris boyutu (int)      : argv[1] */
    /* recursion base case (int): argv[2] */
    if (argc != 3) {
        printf("Usage: %s <matrix dimension> <base recursion case>\n", argv[0]);
        exit(1);
    }

    int mat_size = atoi(argv[1]);
    int min_mat_recurse = atoi(argv[2]);

    /* Zaman olcumu icin */
    struct timeval tvBegin, tvEnd, tvDiff;

    double *X, *Y, *Z, *Zfast;
    X = malloc(mat_size*mat_size*sizeof(double));
    Y = malloc(mat_size*mat_size*sizeof(double));
    Z = malloc(mat_size*mat_size*sizeof(double));
    Zfast = malloc(mat_size*mat_size*sizeof(double));

    if (!X||!Y||!Z||!Zfast) {
      fprintf(stderr, "Error allocating memory.\n");
      exit(1);
    }

    matrand(mat_size,mat_size,X);
    matrand(mat_size,mat_size,Y);

    /* Klasik carpim algoritmasinin olcumu */
    gettimeofday(&tvBegin, NULL);
    matmult(mat_size, mat_size, X, mat_size, Y, mat_size, Z);
    gettimeofday(&tvEnd, NULL);
    timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
    printf("matmult (%dx%d) --> %ld.%06ld\n", mat_size, mat_size, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

    /* Strassen carpim algoritmasinin olcumu */
    gettimeofday(&tvBegin, NULL);
    matmult_fast(mat_size, mat_size, X, mat_size, Y, mat_size, Zfast, min_mat_recurse);
    gettimeofday(&tvEnd, NULL);
    timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
    printf("matmult_fast (%dx%d - base_case: %d) --> %ld.%06ld\n", mat_size, mat_size, min_mat_recurse, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

    free(X);free(Y);free(Z);free(Zfast);
    return 0;
}