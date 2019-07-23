#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complex.h"

int main(int argc, char* argv[]) {

	double valor, num1, num2, den1, den2;

	printf("Digite o numero real e a imagem do primeiro numero complexo:\n");
	scanf("%lf %lf", &num1, &den1);
	printf("Digite o numero real e a imagem do segundo numero complexo:\n");
	scanf("%lf %lf", &num2, &den2);

	Complex comp1, comp2, comp3;

	comp1 = newComplex (num1, den1);

	comp2 = newComplex (num2, den2);

	valor = complexRe(comp1);
	printf("O valor real do primeiro numero complexo  é: %lf\n", valor);

	valor = complexIm(comp1);
	printf("O valor imaginario do primeiro numero complexo é: %lfi\n", valor);

	valor = complexRe(comp2);
	printf("O valor real do segundo numero complexo é: %lf\n", valor);

	valor = complexIm(comp2);
	printf("O valor imaginario do segundo numero complexo é: %lfi\n", valor);

	comp3 = complexAdd(comp1, comp2);

	valor = complexIm(comp3);

	if(valor >= 0) {

		printf("A soma entre os dois numeros complexos é: ");
		valor = complexRe(comp3);
		printf("%lf + ", valor);
		valor = complexIm(comp3);
		printf("%lfi\n", valor);

	} else {

		printf("A soma entre os dois numeros complexos é: ");
		valor = complexRe(comp3);
		printf("%lf ", valor);
		valor = complexIm(comp3);
		printf("%lfi\n", valor);

	}

	destroyComplex(comp3);

	comp3 = complexMultiply(comp1, comp2);

	valor = complexIm(comp3);
	
	if(valor >= 0) {

		printf("A multiplicacao dos dois numeros complexos é: ");
		valor = complexRe(comp3);
		printf("%lf + ", valor);
		valor = complexIm(comp3);
		printf("%lfi\n", valor);		

	} else {

		printf("A multiplicacao dos dois numeros complexos é: ");
		valor = complexRe(comp3);
		printf("%lf ", valor);
		valor = complexIm(comp3);
		printf("%lfi\n", valor);

	}

	valor = complexMod(comp1);
	printf("O modulo do numero complexo é: %lf\n", valor);

	valor = complexArg(comp1);
	printf("O argumento do numero complexo é: %lf\n", valor);

	return 0;

}