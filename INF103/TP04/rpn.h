#include"stack.h"

#ifndef _RPN_H_
#define _RPN_H_

double evaluate_RPN(char *expr, struct stackNode **top);
double compute_operation(double op1, double op2, char operation);
void rpn_test_evaluate_RPN();
#endif