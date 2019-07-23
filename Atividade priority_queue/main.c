#include <stdio.h>
#include "priority_queue.h"

int main() {
	
	priority_queue idade;
	int opcao = 1, valor;
	T item;

	inicializar(&idade);

	while(opcao){

		printf("Escolha uma das opcoes para manipular a Heap:\n");
		printf("1 - Inserir Elemento\n");
		printf("2 - Remover elemento\n"); 
		printf("3 - Elemento com maior prioridade\n");
		printf("4 - Tamanho\n");	
		printf("5 - Imprimir\n");
		printf("6 - Sair\n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:

				printf("Escolha o valor do item: ");
				scanf("%d", &item.idade);
				printf("\n\n");

				inserir(&idade, item);
				break;

			case 2:

				remover(&idade, &item);
				break;

			case 3:

				prioritario(&idade, &item);

				if(item.idade == -1){

					printf("A Heap não tem elemento(s)!\n\n");

				} else {

					printf("O elemento %d tem maior prioridade na Heap!\n\n", item.idade);

				}
				
				break;

			case 4:

				valor = tamanho(&idade);
				printf("O tamanho da Heap é %d!\n\n", valor);
				break;

			case 5:

				imprimir(&idade);
				printf("\n");
				break;

			case 6:

				printf("O programa será fechado!\n\n");
				return 0;

			default: 

				printf("Escolha uma opcao válida!\n\n");
				break;
		}
	}
	
	return 0;
}
