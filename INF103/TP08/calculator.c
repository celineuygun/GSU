#include <stdio.h>
#include"calculator.h"

/*
 * Yinelemeli faktoriyel hesabi yapar.
 * Aldigi parametre n hangi sayinin
 * faktoriyelinin hesaplanacagini gosterir.
 */
long int factorial_iterative(int n){
  long fac = 1;
  for(long i=fac; i<=n; ++i){
    fac *= i;
  }
  return fac;
}

/*
 * Ozyinelemeli faktoriyel hesabi yapar.
 * Aldigi parametre n hangi sayinin
 * faktoriyelinin hesaplanacagini gosterir.
 */
long int factorial_recursive(int n){
  if(n<0){
    printf("'%d' needs to be positive.",n);
    return -1;
  }
  else if(n==0||n==1) return 1;
  else return n*factorial_recursive(n-1);
}

/*
 * Ozyinelemeli olarak OBEB
 * hesabi yapar.
 */
int gcd(int x, int y) {
  if (y != 0) return gcd(y, x%y);
  else return x;
}


/*
 * Ozyinelemeli olarak Fibonacci dizisinda n. sayisi
 * geri dondurur.
 */
int compute_fibonacci(int n){
  if(n==0) return 0;
  else if(n==1) return 1;
  else if(n>1) return (compute_fibonacci(n-1)+compute_fibonacci(n-2));
  else {
     printf("'%d' needs to be positive.",n);
     return -1;
  }
}

/*
 * Parametre olarak verilen x sayisinin
 * n kuvvetini ozyinelemeli olarak hesaplar.
 */
int exponentiation(int x,int n){
  if(n==0) return 1;
  else if(n==1) return x;
  else if(n>1)return (x * exponentiation(x,n-1));
  else{
    printf("'%d' needs to be positive.",n);
    return -1;
  }
}

/*
 * Parametre olarak verilen x sayisinin
 * n kuvvetini hesaplar.
 */
int fast_exponentiation(int x,int n){
  if(n==0) return 1;
  else if(n==1) return x;
  else if(n%2==0) return exponentiation(exponentiation(x,2),n/2);
  else if(n%2==1) return (x*exponentiation(exponentiation(x,2),(n-1)/2));
  else{
    printf("'%d' needs to be positive.",n);
    return -1;
  }
}

