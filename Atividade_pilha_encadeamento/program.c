#include<stdio.h>
#include<stdlib.h>
#include "pilha_encadeada.h"

int main() {

	int opcao, opcao2, valor, item, tam;
	stack pilha;

	printf("Bem Vindo ao Programa de Estrutura de Dados: Pilha\n");

	printf("Digite o tamanho da pilha: ");
	scanf("%d", &tam);

	create(&pilha, tam);

	printf("A pilha foi criada com sucesso\n");

	printf("Deseja modificar a Pilha?:\nSim: 1		Não: 0\n");
	scanf("%d", &opcao);

	do {

		valor = 0;

		printf("O que você deseja fazer com a pilha nas seguintes opcoes?:\n2-Destruir todos os seus elementos\n3-Verificar se a pilha esta vazia\n4-Verificar se a pilha esta cheia\n5-Incrementar um elemento no topo da pilha\n6-Decrementar um elemento no topo da pilha\n7-Indicar o tamanho da pilha\n8-Acessar o elemento do topo da pilha\n");
 
		scanf("%d", &opcao2);

		switch(opcao2) {

			case 2: 

			destroy(&pilha);

			printf("Todos os elementos da pilha foram removidos com sucesso\n");

			break;

			case 3: 

				valor = empty(&pilha);

				if(valor == 0) {

					printf("A pilha nao esta vazia\n");
				
				} else {

					printf("A pilha esta vazia\n");
				}

				break;

			case 4:

				valor = full(&pilha);

				if(valor == 0) {

					printf("A pilha nao esta cheia\n");
				
				} else {

					printf("A pilha esta cheia\n");
				}

				break;
			
			case 5:

				printf("Qual valor será colocado na pilha: ");
				scanf("%d", &item);

				valor = push(&pilha, item);

				if(valor == 0){

					printf("Nao foi possivel inserir um elemento na pilha, pois ela esta cheia!\n");
				
				} else {

					printf("O elemento foi inserido com sucesso no topo da pilha\n");
				}

				break;

			case 6:

				valor = pop(&pilha);

				if(valor == -1){

					printf("A pilha esta vazia, nao há nada para remover\n");
				
				} else {

					printf("O ultimo elemento da pilha foi removido com sucesso\n");
				}

				break;

			case 7:

				valor = size(&pilha);

				printf("A pilha tem %d elementos\n", valor);

				break;

			case 8:

				valor = top(&pilha);

				if(valor == -1){

					printf("A pilha esta vazia\n");

				} else {

					printf("O elemento do topo da pilha é o %d\n", valor);
				}

				break;
		}

		printf("Deseja continuar modificando a Pilha?:\nSim: 1		Não: 0\n");
		scanf("%d", &opcao);

	} while(opcao);


	return 0;
}