#include<stdio.h>
#include<stdlib.h>

#include "fila_encadeada.h"

void create(queue *q, int max_size){

	q->proximo = NULL;
	q->tam_max = max_size;
	q->item = 0;
}

void destroy(queue *q){

	queue *p = q;

	if(p->proximo == NULL){

		return;
	}

	queue *pp = p->proximo;

	while(pp != NULL){

		free(pp);

		pp = pp->proximo;
	}

	p->proximo = NULL;

	return;
}

int empty(queue *q){

	queue *p = q->proximo;

	if(p == NULL) {

		return 0;
	}

	return 1;
}

int full(queue *q){

	queue *p = q->proximo;
	int cont = 0;

	while(p != NULL){

		cont++;
		p = p->proximo;
	}

	if(cont == q->tam_max){

		return 1;
	
	} else {

		return 0;
	}
}

int put(queue *q, int item){

	int valor;
	
	queue *p = (queue*)malloc(sizeof(queue));
	p->item = item;
	p->proximo = NULL;

	valor = full(q);

	if(valor == 1){

		return 0;
	}

	queue *pp = q;
	queue *ppp = q;

	while(pp != NULL){

		ppp = pp;
		pp = pp->proximo;

	}

	ppp->proximo = p;

	return 1;
}

int get(queue *q){

	int valor;

	valor = empty(q);

	if(valor == 0 ){

		return 0;
	}

	q->proximo = q->proximo->proximo;

	return 1;

}

unsigned size(queue *q){

	queue *p = q->proximo;
	int cont = 0;

	while(p != NULL){

		cont++;
		p = p->proximo;
	}

	return cont;
}

int front(queue *q) {

	if(q->proximo == NULL){

		return -1;
	}

	return q->proximo->item;
}