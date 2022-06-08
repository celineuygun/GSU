#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "stack.h"
#include "rpn.h"

int main(int argc, char *argv[]){
	struct stackNode* tmp = malloc(sizeof(struct stackNode));
	if(tmp==NULL)exit(EXIT_FAILURE);
	tmp->data=0;
	tmp->next=NULL;
	printf("\n1. yigit %s\n",is_empty(tmp)?"bos":"dolu");
	struct stackNode* tmp2 = NULL;
	printf("2. yigit %s\n",is_empty(tmp2)?"bos":"dolu"); 

	/*
	 * stach_push() fonksiyon kontrol
	 */
	stack_print(tmp);
	stack_push(&tmp, 1);
	stack_print(tmp);
	/*
	 * stack_pop() fonksiyon kontrol
	 */ 
	stack_pop(&tmp);
	stack_print(tmp);
	/*
	 * stack_multi_pop() fonksiyon kontrol
	 */
	stack_push(&tmp, 1);
	stack_push(&tmp, 2);
	stack_push(&tmp, 3);
	printf("\nMULTIPOP ONCESI YIGIT\n");
	stack_print(tmp);
	struct stackNode* popped = stack_multi_pop(&tmp, 3);
	printf("MULTIPOP SONRASI YIGIT\n");
	stack_print(tmp);
	printf("MULTIPOP DONUS YIGITI\n");
	stack_print(popped);
	printf("\n");

	stack_free(&tmp);
	stack_free(&popped);

    rpn_test_evaluate_RPN();

	/*
	 * Hesaplanmasi icin bir tanim degerini
	 * kullanicidan alir ve daha once tanimli
	 * fonksiyonlari cagirip hesaplar.
	 * Kullanici sistemden cikis yapmak icin exit yazip Enter a basmalidir.
	 */
	struct stackNode *stack = NULL;
	char selection[10], str[20];
	printf("\nRPN Hesap Makinesi\n");
	while(1){
		printf("Hesaplanacak tanimi giriniz: ");
		scanf(" %[^\n]%*c", str);
		printf("Sonuc: %.2lf\n", evaluate_RPN(str, &stack));
		printf("Cikis yapmak icin 'exit' yazin: ");
		scanf(" %[^\n]%*c", selection);
		if(!strcmp(selection, "exit"))break;
	}
	printf("Hesaplama isleminden cikildi.\n");
	return 0;
}