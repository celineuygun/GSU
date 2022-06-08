#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "strassen.h"

/* Zaman olcum fonksiyonlari */
int timeval_subtract(struct timeval *result,
                     struct timeval *t2, struct timeval *t1){
    long int diff =
            (t2->tv_usec + 1000000 * t2->tv_sec) -
            (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;
    return (diff < 0);
}

/* Verilen tek boyutlu diziyi rastgele
 * sayilarla doldurur.
 * Tek boyutlu dizinin bir matrisi
 * ifade etmesi icin ayrica pitch degiskeni kullaniliyor.
 * Ornegin: {2,3,4,6,7,8,1,2,3} dizisi pitch = 3 olarak
 * 3x3 luk bir matrisi ifade eder */
void matrand(int n, int pitch, double M[]) {
    srand((unsigned)time(NULL));
    const double r = 10.0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)M[i] = r*((double)rand()/RAND_MAX*2.0-1.0);
    }
}

/* Verilen vektoru [-10,10] araliginda
 * rastgele sayilarla doldurur.
 */
void vecrand(int pitch, double M[]){
    srand((unsigned)time(NULL));
    const double r = 10.0;
    for(int i = 0; i < pitch; ++i){
        M[i] = r*((double)rand()/RAND_MAX*2.0-1.0);
    }
}

/* Parametre olarak verilen matrisi ekrana basar.
 * Tek boyutlu oldugu icin pitch degeri kullanilir.
 */
void matprint(int n, int pitch, const double M[]){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)printf("%10.2f ", M[i*pitch + j]);
        printf("\n");
    }
}

/* Parametre olarak verilen vektoru ekrana basar.
 */
void vecprint(int pitch, const double M[]) {
    for (int j = 0; j < pitch; ++j)printf("%10.2f ", M[j]);
}

/* Parametre olarak verilen iki matrisin toplamini
 * yeni bir matriste saklar.
 */
void matadd(int n,
            int pitch, const double A[], const double B[], double S[]) {
    for(int i=0; i<n*pitch; ++i)S[i] = A[i] + B[i];
}



/* Parametre olarak verilen iki matrisin farkini
 * yeni bir matriste saklar.
 */
void matsub(int n,
            int pitch, const double A[], const double B[], double S[]) {
    for(int i=0; i<n*pitch; ++i)S[i] = A[i] - B[i];
}


/* Matris vektor toplami
 */
void matvecadd(int n,
               int Apitch, const double A[], const double b[],
               int Spitch, double S[],int dim) {
    if(dim==0){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)S[i*Spitch+j] = A[i*Apitch+j] + b[j];
        }
    }else if(dim==1){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)S[i*Spitch+j] = A[i*Apitch+j] + b[i];
        }
    }
}

/* A nin devrigi S matrisinde saklanacak.
 */
void mattranspose(int n,
                  int Apitch, const double A[],
                  int Spitch, double S[]) {
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)S[i*Spitch+j] = A[j*Apitch+i];
    }
}


/* Parametre olarak verilen iki matris
 * carpimini geri dondurur.
 */
void matmult(int n,
             int Apitch, const double A[],
             int Bpitch, const double B[],
             int Cpitch, double C[]) {

    //C(i,j) = L(i)A x C(j)B = k: 1->n, sum(a(i,k) . b(k,j))
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<n; ++k)C[i*Cpitch+j] += A[i*Apitch+k]*B[k*Bpitch+j];
        }
    }
}

/* Parametre olarak verilen iki matris
 * carpimini ozyinelemeli olarak geri dondurur.
 *
 *      X = | A  B |    Y = | E F |
 *          | C  D |        | G H |
 *
 *      P0 = A * (F - H)
 *      P1 = (A + B) * H
 *      P2 = (C + D) * E
 *      P3 = D * (G - E)
 *      P4 = (A + D) * (E + H)
 *      P5 = (B - D) * (G + H)
 *      P6 = (C - A) * (E + F)
 *         _                                            _
 *    Z = | (P4 + P3) - (P1 - P5)    P0 + P1             |
 *        |  P2 + P3                (P4 - P2) + (P0 + P6)|
 *         -                                            -
 */
void matmult_fast(int n,
                  int Xpitch, const double X[],
                  int Ypitch, const double Y[],
                  int Zpitch, double Z[], int min_mat_recurse) {

    if (n <= min_mat_recurse) {
        matmult(n, Xpitch, X, Ypitch, Y, Zpitch, Z);
        return;
    }

    const int new_n = n/2;
    const int sz = new_n*new_n*sizeof(double);

    double *P[7];
    for(int i=0; i<7; ++i){
        P[i]= malloc(sz);
        if(!P[i]){fprintf(stderr, "Error allocating memory.\n");exit(1);}
    }

    double *T = malloc(sz), *U = malloc(sz);
    if(!T||!U){fprintf(stderr, "Error allocating memory.\n");exit(1);}

    double *A = malloc(sz), *B = malloc(sz), *C = malloc(sz), *D = malloc(sz);
    if(!A||!B||!C||!D){fprintf(stderr, "Error allocating memory.\n");exit(1);}

    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_n; j++) {
            A[i*new_n+j] = X[i*Xpitch+j];
            B[i*new_n+j] = X[i*Xpitch + (j+new_n)];
            C[i*new_n+j] = X[(i+new_n)*Xpitch+j];
            D[i*new_n+j] = X[(i+new_n)*Xpitch+j+new_n];
        }
    }

    double *E = malloc(sz), *F = malloc(sz), *G = malloc(sz), *H = malloc(sz);
    if(!E||!F||!G||!H){fprintf(stderr, "Error allocating memory.\n");exit(1);}

    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_n; j++) {
            E[i*new_n+j] = Y[i*Ypitch+j];
            F[i*new_n+j] = Y[i*Ypitch + (j+new_n)];
            G[i*new_n+j] = Y[(i+new_n)*Ypitch+j];
            H[i*new_n+j] = Y[(i+new_n)*Ypitch+j+new_n];
        }
    }

    /* P0 = A*(F - H) */
    matsub(new_n,new_n,F,H,U);
    matmult_fast(new_n,new_n,A,new_n,U,new_n,P[0],min_mat_recurse);
    /* P1 = (A + B)*H */
    matadd(new_n,new_n,A,B,T);
    matmult_fast(new_n,new_n,T,new_n,H, new_n,P[1],min_mat_recurse);
    /* P2 = (C + D)*E */
    matadd(new_n,new_n,C,D,T);
    matmult_fast(new_n,new_n,T,new_n,E, new_n,P[2],min_mat_recurse);
    /* P3 = D*(G - E) */
    matsub(new_n,new_n,G,E,U);
    matmult_fast(new_n,new_n,D,new_n,U, new_n,P[3],min_mat_recurse);
    /* P4 = (A + D)*(E + H) */
    matadd(new_n,new_n,A,D,T);
    matadd(new_n,new_n,E,H,U);
    matmult_fast(new_n,new_n,T,new_n,U,new_n,P[4],min_mat_recurse);
    /* P5 = (B - D)*(G + H) */
    matsub(new_n,new_n,B,D,T);
    matadd(new_n,new_n,G,H,U);
    matmult_fast(new_n,new_n,T,new_n,U,new_n,P[5],min_mat_recurse);
    /* P6 = (C - A)*(E + F)*/
    matsub(new_n,new_n,C,A,T);
    matadd(new_n,new_n,E,F,U);
    matmult_fast(new_n,new_n,T,new_n,U,new_n,P[6],min_mat_recurse);

    /* Z sol ust = (P4 + P3) - (P1 - P5) */
    matadd(new_n,new_n,P[4],P[3],T);
    matsub(new_n,new_n,P[1],P[5],U);
    matsub(new_n,new_n,T,U,A);
    /* Z sag ust = (P0 + P1) */
    matadd(new_n,new_n,P[0],P[1],B);
    /* Z sol alt = (P2 + P3) */
    matadd(new_n,new_n,P[2],P[3],C);
    /* Z sag alt = (P4 - P2) + (P0 + P6) */
    matsub(new_n,new_n,P[4],P[2],T);
    matadd(new_n,new_n,P[0],P[6],U);
    matadd(new_n,new_n,T,U,D);

    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_n; j++) {
            Z[i*Zpitch+j] = A[i*new_n+j];
            Z[i*Zpitch + (j+new_n)] = B[i*new_n+j];
            Z[(i+new_n)*Zpitch+j] = C[i*new_n+j];
            Z[(i+new_n)*Zpitch+j+new_n] =  D[i*new_n+j];
        }
    }

    free(U);free(T);
    free(A);free(B);free(C);free(D);
    free(E);free(F);free(G);free(H);
    for(int i=0; i<7; ++i)free(P[i]);
}