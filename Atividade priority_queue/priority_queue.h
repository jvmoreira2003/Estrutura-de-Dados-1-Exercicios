#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <stdio.h>

#define MAX 100

typedef struct {
	int idade;
} T;

typedef struct {
	int n;
	T vetor[MAX];
} priority_queue;

void swap(T *A, T *B);
void inicializar(priority_queue *q);
void inserir( priority_queue *q, T item);
void remover( priority_queue *q, T* item);
void prioritario( priority_queue *q, T* item );
int tamanho( priority_queue *q );
void imprimir( priority_queue *q );
void fixUp(priority_queue *q, int filho);
void fixDown(priority_queue *q, int pai);


#endif
