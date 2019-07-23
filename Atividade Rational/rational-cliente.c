#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rational.h"

int main(int argc, char* argv[]) {

	int val, num1, num2, den1, den2;

	//Será decidido os valores para a inicializacao do programa
	printf("Digite o numerador e o denominador da primeira fracao:\n");
	scanf("%d %d", &num1, &den1);
	printf("Digite o numerador e o denominador da segunda fracao:\n");
	scanf("%d %d", &num2, &den2);
	
	rational fra1 = define(num1, den1);
	rational fra2 = define(num2, den2);


	//Sera exibido todas as operações realizadas nas funcao na tela(Soma, Subtraçao, Multiplicacao e Divisao)
	rational fra3 = plus(fra1, fra2);
	printf("A soma das duas fracoes tem como numerador:%d e denominador:%d\n", fra3.numerator, fra3.denominator);

	fra3 = minus(fra1, fra2);
	printf("A diferenca das duas fracoes tem como numerador:%d e denominador:%d\n", fra3.numerator, fra3.denominator);

	fra3 = times(fra1, fra2);
	printf("O quociente das duas fracoes tem como numerador:%d e denominador:%d\n", fra3.numerator, fra3.denominator);

	fra3 = divides(fra1, fra2);
	printf("A divisao das duas fracoes tem como numerador:%d e denominador:%d\n", fra3.numerator, fra3.denominator);

	//Sera verificado se as fracoes tidas como entrada no código sao equivalentes 
	val = equals(fra1, fra2);

	if(val == 1){

		printf("As fracoes abaixo sao equivalentes\n");

	} else {

		printf("As fracoes abaixo nao sao equivalentes\n");
	}

	//Sera exibido as fracoes de inicialização na tela.
	char msg[512];
	toString(fra1,msg);
	printf("%s", msg);
	toString(fra2,msg);
	printf("%s\n", msg);
	
	return 0;
	
}