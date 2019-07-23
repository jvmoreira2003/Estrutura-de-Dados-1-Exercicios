#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

int main() {

	int opcao, opcao2, valor, item, tam;
	queue fila;

	printf("Bem Vindo ao Programa de Estrutura de Dados: Fila\n");

	printf("Digite o tamanho da fila: ");
	scanf("%d", &tam);

	create(&fila, tam);

	printf("A fila foi criada com sucesso\n");

	printf("Deseja modificar a fila?:\nSim: 1		Não: 0\n");
	scanf("%d", &opcao);

	do {

		valor = 0;

		printf("O que você deseja fazer com a fila nas seguintes opcoes?:\n2-Destruir todos os seus elementos\n3-Verificar se a fila esta vazia\n4-Verificar se a fila esta cheia\n5-Incrementar um elemento no fim da fila\n6-Decrementar um elemento no começo da fila\n7-Indicar o tamanho da fila\n8-Acessar o elemento do começo da fila\n");
 
		scanf("%d", &opcao2);

		switch(opcao2){

			case 2: 

			destroy(&fila);

			printf("Todos os elementos da fila foram removidos com sucesso\n");

			break;

			case 3: 

				valor = empty(&fila);

				if(valor == 1) {

					printf("A fila nao esta vazia\n");
				
				} else {

					printf("A fila esta vazia\n");
				}

				break;

			case 4:

				valor = full(&fila);

				if(valor == 1) {

					printf("A fila nao esta cheia\n");
				
				} else {

					printf("A fila esta cheia\n");
				}

				break;
			
			case 5:

				printf("Qual valor será colocado na fila: ");
				scanf("%d", &item);

				valor = put(&fila, item);

				if(valor == 0){

					printf("Nao foi possivel inserir um elemento na fila, pois ela esta cheia!\n");
				
				} else {

					printf("O elemento foi inserido com sucesso no começo da fila\n");
				}

				break;

			case 6:

				valor = get(&fila);

				if(valor == 0){

					printf("A fila esta vazia, nao há nada para remover\n");
				
				} else {

					printf("O primeiro elemento da fila foi removido com sucesso\n");
				}

				break;

			case 7:

				valor = size(&fila);

				printf("A fila tem %d elementos\n", valor);

				break;

			case 8:

				valor = front(&fila);

				if(valor == -1){

					printf("A fila esta vazia\n");

				} else {

					printf("O elemento do começo da fila é o %d\n", valor);
				}

				break;
		}

		printf("Deseja continuar modificando a fila?:\nSim: 1		Não: 0\n");
		scanf("%d", &opcao);

	} while(opcao);


	return 0;
}