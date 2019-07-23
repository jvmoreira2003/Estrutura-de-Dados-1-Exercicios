#include "priority_queue.h"
#include <stdlib.h>

void swap(T *A, T *B) { 
	T t = *A; 
	*A = *B;
	*B = t; 
}
    
void fixUp(priority_queue *q, int filho) {

	int pai = (filho - 1)/2;

	while (filho > 0 && (q->vetor[pai].idade <= q->vetor[filho].idade)) {  
		
		//Troca o filho pelo pai
		swap(&(q->vetor[filho]), &(q->vetor[(filho-1)/2]));
		filho = pai;
		pai = (filho - 1)/2;
	}
}

//Realiza a muntenção da Heap, a partir da inserção de um elemento no final da Heap
void fixDown(priority_queue *q, int pai) {

	int filho = (2*pai) + 1;

	while (filho < q->n){

		//filho tem pelo menos um irmmão
		if(filho < (q->n-1)) {

			//Verifica quais dois filhos dele tem maior prioridade na heap
			if(q->vetor[filho].idade < q->vetor[filho+1].idade) {

				//Caso for o irmao, pega ele
				filho++;

			}
		}

		//Caso o pai tenha maior prioridade ou igual do filho, entao a arvore já esta balanceada
		if(q->vetor[filho].idade <= q->vetor[pai].idade) {

			break;
		}

		//Troca o pai pelo filho
		swap(&(q->vetor[filho]), &(q->vetor[(filho-1)/2]));
		pai = filho;
		filho = (2*pai) + 1;
	}
}


//Inicializa a Heap, zerando o número de elementos
void inicializar(priority_queue *q) {
	q->n = 0;
}

//Inseri um elemento no final na Heap(vetor) e logo em seguida realiza a manutenção da Heap
void inserir(priority_queue *q, T item) { 
	
	//Verifica se a Heap não está cheia para inserir um elemento
	if(q->n == MAX){

		return;
	}

	if(q->n < MAX) {
		
		q->vetor[q->n] = item;
		
		//Realiza a manutenção da Heap, verificando se o elemento inserido tem maior prioridade que seus "pais"
		fixUp(q, q->n);
		q->n++;
	}

	return;
}

//Remove o elemento com maior prioridade na Heap(no caso, a raiz)
void remover(priority_queue *q, T* item)  {


	//Caso a fila não contenha nenhum elemento(vazia)
	if(q->n == 0){

		return;
	}

	else {

		q->n--;
		q->vetor[0] = q->vetor[q->n];
		//Passa a raiz da Heap como referência
		fixDown(q, 0); 

		return;	
	}
}

//Verifica qual elemento tem maior prioridade na Heap(A raiz no caso)
void prioritario( priority_queue *q, T* item ) {

	//Caso a Heap esteja vazia, logo não tem elementos
	if(q->n == 0) {

		item->idade = -1;
	}

	//Caso a Heap contenha pelo menos um elemento
	if(q->n > 0) {
		
		*item = q->vetor[0];
	}
}

//Retorna o tamanho da Heap(no caso é o numero de elemento do vetor)
int tamanho( priority_queue *q ) {
	
	return q->n;
}

//Imprime os nós da Heap
void imprimir( priority_queue *q ) {
	
	if(q->n == 0){

		printf("A Heap está vazia!\n");
		return;
	}

	printf("Heap = ");

	for(int i=0;i<q->n; i++){
		
		printf("%d ", q->vetor[i].idade );
	}

	printf("\n");
}
