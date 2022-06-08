#include "lib.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

int sum(int x, int y) {
    return x + y;
}

int isLetter(char c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int isDigit(char c) {
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int isVowel(char c) {
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
        return 1;
    return 0;
}

int isEven(int value) {
    return value % 2 == 0;
}

int isPrime(int value) {
    int prime = 1;
    if(value == 1) return !prime;
    for(int i = 2; i <= value/2; ++i) {
        if(value % i == 0) {
            prime = 0;
            break;
        }
    } return prime;
}

int digitSum(int value) {
    int sum = 0, tmp, val = value;
    for(int i = 1; i < value; i *= 10) {
        tmp = val % 10;
        sum += tmp;
        val /= 10;
    } return sum;
}

int reverseNumber(int value) {
    int val = value, prev = value % 10, cur = prev;
    while(val >= 10) {
        val /= 10;
        cur = val % 10;
        prev = (prev * 10) + cur;
    } return prev;
}

int isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

void upperCase(char *c) {
    if(*c >= 'a' && *c <= 'z')
        *c -= 32;
}

void downCase(char *c) {
    if(isUpperCase(*c))
        *c += 32;
}

int factoriel(int value) {
    if(value < 0) return -1;
    else if(value == 0 || value == 1) return 1;
    else return value * factoriel(value - 1);
}

int power(int base, int degree) {
    if(degree == 0) return 1;
    else if(degree == 1) return base;
    else return base * power(base, degree - 1);
}

void findRoots(int a, int b, int c) {
    printf("====>   %dx^2 %c %dx %c %d\n", a, (b >= 0) ? '+' : '-', (b >= 0) ? b : -b, (c >= 0) ? '+' : '-', (c >= 0) ? c : -c);
    int discriminant = power(b, 2) - 4*a*c;
    float result1 = 0, result2 = 0;
    if(discriminant == 0) {
        result1 = (-b + sqrt(discriminant))/(2*a);
        printf("\tL'equation admet une unique solution dans R qui est %.2f\n", result1);
    } else if(discriminant > 0) {
        result1 = (-b + sqrt(discriminant))/(2*a);
        result2 = (-b - sqrt(discriminant))/(2*a);
        printf("\tL'equation admet deux solutions dans R qui sont %.2f et %.2f\n", result1, result2);
    } else {
        float re = -b / (2*a);
        float im = sqrt(-discriminant)/(2*a);
        printf("\tL'equation admet deux solutions dans C qui sont %.2f - %.2fi et %.2f + %.2fi\n", re, (im >= 0) ? im : -im, re, (im > 0) ? im : -im);
    }
}

int isPalindromeNumber(int value) {
    return value == reverseNumber(value);
}

int isPalindromeText(char *c, int size) {
    for(int i = 0, j = size - i - 1; i < size/2; ) {
        if(!isalpha(c[i])) ++i;
        if(!isalpha(c[j])) --j;
        if(c[i] == c[j] || c[i] == tolower(c[j]) || c[j] == tolower(c[i])) {
            ++i;
            --j;
        } else
            if(i != size/2)
                return 0;
    } return 1;
}

int exist(int *arr, int size, int value) {
    for(int i = 0; i < size; ++i) {
        if(arr[i] == value) return 1;
    } return 0;
}

int getIndex(int *arr, int size, int value) {
    for(int i = 0; i < size; ++i) {
        if(arr[i] == value) return i;
    } return -1;
}

int count(int *arr, int size, int value) {
    int counter = 0;
    for(int i = 0; i < size; ++i) {
        if(arr[i] == value) counter++;
    } return counter;
}

int findMax(int *arr, int size) {
    int largest = arr[0];
    for(int i = 1; i < size; ++i) {
        if(largest < arr[i]) largest = arr[i];
    } return largest;
}

int findMax2(int *arr, int size) {
    int largest = arr[0], second = INT_MIN;
    for(int i = 1; i < size; ++i) {
        if(largest < arr[i]) {
            second = largest;
            largest = arr[i];
        } else if(second < arr[i] && arr[i] <= largest) {
            second = arr[i];
        }
    } return second;
}

int findMin(int *arr, int size) {
    int smallest = arr[0];
    for(int i = 1; i < size; ++i) {
        if(smallest > arr[i]) smallest = arr[i];
    } return smallest;
}

int findMin2(int *arr, int size) {
    int smallest = arr[0], second = INT_MAX;
    for(int i = 1; i < size; ++i) {
        if(smallest > arr[i]) {
            second = smallest;
            smallest = arr[i];
        } else if(second > arr[i] && arr[i] >= smallest) {
            second = arr[i];
        }
    } return second;
}

int sumArray(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; ++i)
        sum += arr[i];
    return sum;
}

double averageArr(int *arr, int size) {
    return (double)sumArray(arr, size) / size;
}
