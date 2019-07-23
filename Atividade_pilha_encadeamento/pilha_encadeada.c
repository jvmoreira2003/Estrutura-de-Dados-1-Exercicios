#include<stdio.h>
#include<stdlib.h>

#include "pilha_encadeada.h"

//Essa funçao sera responsavel por realizar a criaçao da pilha.
void create(stack *s, unsigned max_size){

	s->proximo = NULL;
	s->tam_max = max_size;
	s->item = 0;

}

//Essa funçao sera responsavel por destruir todos os elementos da pilha.
void destroy(stack *s){

	stack *p = s;

	if(p->proximo == NULL){

		return;
	}

	stack *pp = p->proximo;

	while(pp != NULL){

		free(pp);

		pp = pp->proximo;
	}

	p->proximo = NULL;

	return;
}

//Essa funçao sera responsavel por verificar se a pilha esta vazia.
int empty(stack *s){

	stack *p = s->proximo;

	if(p == NULL) {

		return 0;
	}

	return 1;
}

//Essa funçao sera responsavel por verificar se a pilha esta cheia
int full(stack *s){

	stack *p = s->proximo;
	int cont = 0;

	while(p != NULL){

		cont++;
		p = p->proximo;
	}

	if(cont == s->tam_max){

		return 1;
	
	} else {

		return 0;
	}
}

//Essa funçao sera responsavel por incrementar um valor na pilha.
int push(stack *s, int item){

	int valor;
	stack *p = (stack*)malloc(sizeof(stack));
	p->item = item;

	valor = full(s);

	if(valor == 1){

		return 0;
	}

	stack *pp = s;

	if(pp->proximo == NULL) {

		pp->proximo = p;
		pp->proximo->proximo = NULL;
		return 1;
	
	} else {

		p->proximo = s->proximo;
		s->proximo = p;
	}
	return 1;


}

//Essa funçao sera responsavel por remover o elemento do topo da pilha.
int pop(stack *s){

	int valor;
	stack *p = s;

	valor = empty(s);

	if(valor == 0){

		return -1;
	}

	p->proximo = p->proximo->proximo;

	return 1;
}

//Essa funçao sera responsavel por indicar o tamanho da pilha até o estado atual.
unsigned size(stack *s) {

	stack *p = s->proximo;
	int cont = 0;

	while(p != NULL){

		cont++;
		p = p->proximo;
	}

	return cont;
}

//Essa funçao sera responsavel por acessar o elemento posicionado no topo da pilha.
int top(stack *s){

	int valor;
	stack *p = s;

	valor = empty(s);

	if(valor == 0){

		return -1;
	}

	return p->proximo->item;
}