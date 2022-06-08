#ifndef LIB_H_ 
#define LIB_H_

int sum(int x, int y);
int isLetter(char c);
int isDigit(char c);
int isVowel(char c);
int isEven(int value);
int isPrime(int value);
int digitSum(int value);
int reverseNumber(int value);
int isUpperCase(char c);
void upperCase(char *c);
void downCase(char *c);
int factoriel(int value);
int power(int base, int degree);
void findRoots(int a, int b, int c);
int isPalindromeNumber(int value);
int isPalindromeText(char *c, int size);
int exist(int *arr, int size, int value);
int getIndex(int *arr, int size, int value);
int count(int *arr, int size, int value);
int findMax(int *arr, int size);
int findMax2(int *arr, int size);
int findMin(int *arr, int size);
int findMin2(int *arr, int size);
int sumArray(int *arr, int size);
double averageArr(int *arr, int size);

#endif