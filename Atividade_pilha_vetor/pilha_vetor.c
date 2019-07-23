#include <stdio.h>
#include <stdlib.h>
#include "pilha_vetor.h"

//Essa funçao sera responsavel por realizar a criaçao da pilha.
void create(stack *s, int max_size){

	s->item = (int*)malloc(sizeof(int)*max_size);
	s->numitens = 0;
	s->numax = max_size;
}

//Essa funçao sera responsavel por destruir todos os elementos da pilha.
void destroy(stack *s) {

	free(s->item);
	s->numitens = 0;	
	
}

//Essa funçao sera responsavel por verificar se a pilha esta vazia.
int empty(stack *s) {

	if(s->numitens != 0) {

		return 1;
	}
	return 0;
}

//Essa funçao sera responsavel por verificar se a pilha esta cheia
int full(stack *s) {

	if(s->numitens < s->numax) {

		return 1;
	}
	return 0;
}

//Essa funçao sera responsavel por incrementar um valor na pilha.
int push(stack *s, int item) {

	int valor;

	valor = full(s);

	if(valor == 0){

		return 0;
	}

	s->item[s->numitens] = item;
	s->numitens++;

	return 1;
}

//Essa funçao sera responsavel por remover o elemento do topo da pilha.
int pop(stack *s) {

	int valor;

	valor = empty(s);

	if(valor == 0){

		return -1;
	}

	s->numitens--;

	s->item = (int*)malloc(sizeof(int)*(s->numitens-1));

	return s->item[s->numitens];
}

//Essa funçao sera responsavel por indicar o tamanho da pilha até o estado atual.
unsigned size(stack *s) {

	return s->numitens;
}

//Essa funçao sera responsavel por acessar o elemento posicionado no topo da pilha.
int top(stack *s) {

	if(s->numitens > 0){

		return s->item[s->numitens-1];
	
	} else {

		return -1;
	}
}