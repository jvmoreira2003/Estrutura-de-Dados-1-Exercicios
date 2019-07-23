#include <stdio.h>
#include <stdlib.h>
#include "fila_vetor.h"

//Essa funcao é responsavel por criar e inicializar uma fila.
void create(queue *q, int max_size){

	q->item = (int*)malloc(sizeof(int)*max_size);
	q->numitens = 0;
	q->numax = max_size;
}

//Essa funcao é responsavel por destruir uma fila.
void destroy(queue *q){

	free(q->item);
	q->numitens = 0;
}

//Essa funcao é responsavel por verificar se a fila esta vazia.
int empty(queue *q){

	if(q->numitens != 0) {

		return 1;
	}
	return 0;
}

//Essa funcao é responsavel por verificar se a fila esta cheia.
int full(queue *q){

	if(q->numitens < q->numax) {

		return 1;
	}
	return 0;
}

//Essa funcao é responsavel por adicionar um elemento no final da fila.
int put(queue *q, int item) {

	int valor;

	valor = full(q);

	if(valor == 0){

		return 0;
	}

	q->item[q->numitens] = item;
	q->numitens++;

	return 1;
}

//Essa funcao é responsavel por remover o primeiro elemento da fila
int get(queue *q) {

	int valor, i;

	valor = empty(q);

	if(valor == 0){

		return 0;
	}

	for(i=0; i < (q->numitens-1); i++) {

		q->item[i] = q->item[i+1];
	}

	q->numitens--;

	return 1;

}

//Essa funcao é responsavel por verificar o tnumero de elementos da fila.
unsigned size(queue *q) {

	return q->numitens;
}

//Essa funcao é responsavel por exibir o primeiro elemento da fila.
int front(queue *q) {

	if(q->numitens > 0){

		return q->item[0];
	
	} else {

		return -1;
	}


}