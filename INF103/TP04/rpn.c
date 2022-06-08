#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include"rpn.h"
#include"stack.h"

/*
 * Verilen iki sayi uzerinde, verilen islemi uygular.
 * Verilen operation eger istenen 4 islem(*,+,/,-) karakterinde degilse
 * hata mesaji gosterip fonksiyondan cikar.
 */
double compute_operation(double op1, double op2, char operation) {
    double result = 0;
    switch (operation){ 
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        result = op1 / op2;
        break;
    default:
        printf("Sadece 4 islem yapilabilir!\n");
        break;
    }
    return result;
}

/*
 * Verilen expr parametresindeki sayilari, yine
 * expr icindeki islemler ile hesaplayip,
 * yigit icerisine kaydedecek.
 */
double evaluate_RPN(char *expr, struct stackNode **top) {
    double retval = 0, op1=0, op2=0;
    int i=0;
    while(expr[i]!='\0'){
        if(isdigit(expr[i])){
            double val = expr[i] - '0';
            stack_push(top, val);
        }else{
            op2 = stack_pop(top);
            op1 = stack_pop(top);
            stack_push(top, compute_operation(op1, op2, expr[i]));
        }
        ++i;
    }
    retval = stack_pop(top);
    if((*top)!=NULL){
        printf("Yigit hala dolu!\n");
        return 0;
    }
    return retval;
}


void rpn_test_evaluate_RPN(){
    struct stackNode *stack = NULL;
	assert(evaluate_RPN("13+2-", &stack) == 2.0);
	assert(evaluate_RPN("62+5*84/-", &stack) == 38.0);
	printf("Testler basarili.\n");
}