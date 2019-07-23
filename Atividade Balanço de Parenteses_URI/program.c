#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "balanco.h"

int main() {

	int tam, tamexp, valor, cont = 1;
	Vetor vetr;
	char v[10000];

	printf("Indique a quantidade de expressões: ");
	scanf("%d", &tam);

	while(cont <= tam) {

		scanf("%s", v);

		tamexp = strlen(v);

		inicializa(&vetr, tamexp);

		valor = empilhadesempilha(&vetr, tamexp, v);

		if(valor == 1){

			printf("Correct\n");
		
		} else {

			printf("Incorrect\n");
		}

		cont++;
	}

	return 0;
}