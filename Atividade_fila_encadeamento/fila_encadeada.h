#ifndef FILA_ENCADEADA_H_
#define FILA_ENCADEADA_H_

typedef struct _fila {

	struct _fila *proximo;
	int item;
	int tam_max;

}queue;

//Essa funcao é responsavel por criar e inicializar uma fila.
void create(queue *q, int max_size);

//Essa funcao é responsavel por destruir uma fila.
void destroy(queue *q);

//Essa funcao é responsavel por verificar se a fila esta vazia.
int empty(queue *q);

//Essa funcao é responsavel por verificar se a fila esta cheia.
int full(queue *q);

//Essa funcao é responsavel por adicionar um elemento no final da fila.
int put(queue *q, int item);

//Essa funcao é responsavel por remover o primeiro elemento da fila
int get(queue *q);

//Essa funcao é responsavel por verificar o tnumero de elementos da fila.
unsigned size(queue *q);

//Essa funcao é responsavel por exibir o primeiro elemento da fila.
int front(queue *q);

#endif