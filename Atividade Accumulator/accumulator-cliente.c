#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "accumulator.h"

int main() {

	char msg[512];
	double val, valortotal, media;
	acumulator *cont = (acumulator*)malloc(sizeof(acumulator));
	int opcao;

	//Sera inicializado o acumulador no programa
	initialize(cont);

	do{

		//A cada iteração o usuario dara um valor como entrada no programa, sendo que se o mesmo digitar um será pedido um novo valor, caso for digitado 0 o programa finalizara
		printf("Insira um valor no acumulador: ");
		
		scanf("%lf", &val);

		printf("O valor inserido é: ");

		addDataValue(cont, val);

		toString(cont, msg);
		printf("%s", msg);


		media = mean(cont);

		printf("A media de todos os valores que estao inseridos no contador é: %lf\n", media);

		valortotal = value(cont);

		printf("O valor do acumulador é: %lf\n", valortotal);

		printf("Deseja inserir mais valores no contador?\nSim = 1	Nao = 0\n");
		scanf("%d", &opcao);

	} while(opcao);

	free(c);

	return 0;
}