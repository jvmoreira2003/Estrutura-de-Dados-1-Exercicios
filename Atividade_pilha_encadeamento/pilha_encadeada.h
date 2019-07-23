#ifndef PILHA_ENCADEADA_H_
#define PILHA_ENCADEADA_H_

typedef struct _pilha {

	struct _pilha *proximo;
	int item;
	int tam_max;

}stack;

//Essa funçao sera responsavel por realizar a criaçao da pilha.
void create(stack *s, unsigned max_size);

//Essa funçao sera responsavel por destruir todos os elementos da pilha.
void destroy(stack *s);

//Essa funçao sera responsavel por verificar se a pilha esta vazia.
int empty(stack *s);

//Essa funçao sera responsavel por verificar se a pilha esta cheia
int full(stack *s);

//Essa funçao sera responsavel por incrementar um valor na pilha.
int push(stack *s, int item);

//Essa funçao sera responsavel por remover o elemento do topo da pilha.
int pop(stack *s);

//Essa funçao sera responsavel por indicar o tamanho da pilha até o estado atual.
unsigned size(stack *s);

//Essa funçao sera responsavel por acessar o elemento posicionado no topo da pilha.
int top(stack *s);


#endif