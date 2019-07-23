#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

	Lista letras;
	Iterador it, itera, aux;
	int opcao = 1, opcao2, valor;
	char item, item2;
	
	inicializa(&letras);

	while(opcao) {

		printf("Escolha uma das opcoes abaixo para manipular a Lista Ligada:\n");
		printf("1 - Destruir todos os elementos da Lista!\n");
		printf("2 - Inserir um elemento no começo da Lista!\n");
		printf("3 - Inserir um elemento no final da Lista!\n");
		printf("4 - Remover um elemento no começo da Lista!\n");
		printf("5 - Remover um elemento no fim da Lista!\n");
		printf("6 - Imprimir em ordem crescente!\n");
		printf("7 - Imprimir em ordem decrescente!\n");
		printf("8 - Busca crescente de elementos na Lista!\n");
		printf("9 - Busca decrescente de elementos na Lista!\n");
		printf("10 - Busca crescente de elementos na Lista de um determinado iterador!\n");
		printf("11 - Busca decrescente de elementos na Lista de um determinado iterador!\n");
		printf("12 - Insere o elemento depois do iterador na Lista!\n");
		printf("13 - Insere o elemento antes do iterador na Lista!\n");
		printf("14 - Remove o elemento antes do iterador na Lista!\n");
		printf("15 - Remove o elemento depois do iterador na Lista!\n");
		printf("16 - Remove o elemento do iterador em si na Lista!\n");
		printf("17 - Exibi a quantidade de elementos na Lista!\n");
		printf("18 - Verificar se a lista está vazia!\n");
		printf("19 - Inicializar uma nova Lista!\n\n");

		scanf("%d", &opcao2);

		switch(opcao2){

			case 1:

				destroi(&letras);
				printf("A lista foi destruida!\n");
				return 0;
				break;

			case 2:

				printf("Digite o item que sera inserido: ");
				scanf(" %c", &item);
				insereInicio(&letras, item);
				printf("O elemento %c foi inserido com sucesso no inicio da Lista!\n", item);
			
				break;

			case 3:

				printf("Digite o item que sera inserido: ");
				scanf(" %c", &item);
				insereFim(&letras, item);
				printf("O elemento %c foi inserido com sucesso no fim da Lista!\n", item);
				
				break;

			case 4:

				removeInicio(&letras, &item);
				printf("O elemento %c foi remvido com sucesso no começo da Lista!\n", item);

				break;

			case 5:


				removeFim(&letras, &item);
				printf("O elemento %c foi remvido com sucesso no final da Lista!\n", item);
				
				break;

			case 6:
				
				for(Iterador it = inicio(&letras); !acabou(&it); proximo(&it)) {
					
					elemento(&it,&item);
					printf("%c ",item);
				}

				printf("\n");
		
				break;

			case 7:

				for(Iterador it = fim(&letras); !acabou(&it); anterior(&it)) {
					
					elemento(&it,&item);
					printf("%c ",item);
				}

				printf("\n");

				break;

			case 8:

				printf("Digite o elemento que deseja procurar: ");
				scanf(" %c", &item);	

				it = buscaPrimeiro(&letras, item);

				if(it.p == NULL){

					printf("Não foi encontrado o elemento na Lista ou a Lista esta vazia\n");
				
				} else {

					printf("O elemento %c foi encontrado na Lista\n", it.p->item);						

				}
			
				break;

			case 9:

				printf("Digite o elemento que deseja procurar: ");
				scanf(" %c", &item);

				it = buscaUltimo(&letras, item);

				if(it.p == NULL){

					printf("Não foi encontrado o elemento na Lista ou a Lista esta vazia\n");
				
				} else {

					printf("O elemento %c foi encontrado na Lista\n", it.p->item);						

				}

				break;

			case 10:

				printf("Digite o elemento que deseja procurar: ");
				scanf(" %c", &item);

				printf("Digite o elemento do Iterador: ");
				scanf(" %c", &item2);

				aux = inicio(&letras);

				it = buscaPrimeiro(&letras, item2);
				itera = buscaProximo(&it, item);

				if(itera.p == NULL || aux.p == NULL){

					printf("Não foi encontrado o elemento na Lista do iterador ou a Lista esta vazia\n");
				
				} else {

					printf("O elemento %c foi encontrado na Lista\n", it.p->item);						
				}				

				break;

			case 11:

				printf("Digite o elemento que deseja procurar: ");
				scanf(" %c", &item);

				printf("Digite o elemento do Iterador: ");
				scanf(" %c", &item2);

				aux = inicio(&letras);

				it = buscaUltimo(&letras, item2);
				itera = buscaAnterior(&it, item);

				if(itera.p == NULL || aux.p == NULL){

					printf("Não foi encontrado o elemento na Lista a partir do iterador ou a Lista esta vazia\n");
				
				} else {

					printf("O elemento %c foi encontrado na Lista\n", it.p->item);						

				}

				break;

			case 12:

				printf("Digite o valor do elemento que deseja inserir: ");
				scanf(" %c", &item);

				printf("Digite o valor do iterador: ");
				scanf(" %c", &item2);				

				it = inicio(&letras);
				itera = buscaProximo(&it, item2);

				insereDepois(&itera, item);
				printf("O elemento %c foi inserido com sucesso na Lista depois do iterador!\n", item);

				break;

			case 13:

				printf("Digite o valor do elemento que deseja inserir: ");
				scanf(" %c", &item);

				printf("Digite o valor do iterador: ");
				scanf(" %c", &item2);				

				it = inicio(&letras);
				itera = buscaProximo(&it, item2);

				insereAntes(&itera, item);
				printf("O elemento %c foi inserido com sucesso na Lista antes do iterador!\n", item);

				break;

			case 14:

				printf("Digite o valor do iterador: ");
				scanf(" %c", &item2);				

				it = inicio(&letras);
				itera = buscaProximo(&it, item2);

				removeAntes(&itera, &item);
				printf("O elemento %c foi removido com sucesso da Lista antes do iterador!\n", item);

				break;

			case 15: 

				printf("Digite o valor do iterador: ");
				scanf(" %c", &item2);				

				it = inicio(&letras);
				itera = buscaProximo(&it, item2);

				removeDepois(&itera, &item);
				printf("O elemento %c foi removido com sucesso da Lista depois do iterador!\n", item);

				break;

			case 16:

				printf("Digite o valor do iterador: ");
				scanf(" %c", &item2);				

				it = inicio(&letras);
				itera = buscaProximo(&it, item2);

				remover(&itera, &item);
				printf("O elemento %c foi removido com sucesso da Lista pelo proprio iterador!\n", item);
				
				break;

			case 17:

				valor = quantidade(&letras);

				printf("A quantidade de elementos da Lista é: %d elementos!\n", valor);

				break;

			case 18:

				if(vazia(&letras)){

					printf("A Lista se encontra vazia neste momento\n");
				
				} else {

					printf("A Lista não esta vazia neste momento\n");	
				}

				break;


			case 19:

				inicializa(&letras);
				printf("A Lista foi novamente incializada!\n");
		
				break;	
		}

		printf("-----------------------------------------------------------\n");
	}
	return 0;
}
