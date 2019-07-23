#include<stdlib.h>
#include<stdio.h>
#include "lista.h"

//Essa funcao é resposavel por indicar que se o iterador esta apontado para algum elemento da lista.
int acabou(Iterador *it) {

	return it->p == NULL;
}

//Essa funcao é responsavel por inicializar a lista no começo do programa;
void inicializa(Lista* l) {

	l->ini = NULL;
	l->qtd = 0;
}

//Essa funcao é responsavel por destruir todos os elementos da lista.
void destroi(Lista* l) {

	No* p = l->ini;

	if(l->ini == NULL){

		free(p);
		return;
	}

	while(p != NULL) {

		No* aux = p->prox;
		free(p);
		p = aux;
	}
	
	l->ini = NULL;
	return;
}

//Essa funcao é responsavel por inserir um elemento no começo da Lista de acordo com seu item.
void insereInicio(Lista* l, T item) {

	No* p = (No*)malloc(sizeof(No));
	
	//Se a lista estiver vazia.
	if(l->ini == NULL) {

		p->item = item;
		p->prox = NULL;
		p->anter = NULL;
		l->ini = p;
		l->qtd++;

	//Se conter um ou mais elementos na lista.
	} else {

		p->item = item;
		p->prox = l->ini;
		p->anter = NULL;
		p->prox->anter = p;
		l->ini = p;
		l->qtd++;
	}
}

//Essa funcao é responsavel por inserir um elemento no final da Lista de acordo com seu item.
void insereFim(Lista* l, T item) {

	No* p = (No*)malloc(sizeof(No));
	p->item = item;
	l->qtd++;

	No* atual = l->ini;
	No* anterior;

	//Percorre a lista até o ultimo elemento.
	while(atual != NULL){

		anterior = atual;
		atual = atual->prox;
	}

	p->anter = anterior;
	p->prox = NULL;
	anterior->prox = p;
}

//Essa funcao é responsavel por remover um elemento no começo da lista.
void removeInicio(Lista* l, T* item) {

	No* p = l->ini;

	//Se a lista estiver vazia, nao há nada para remover.
	if(p == NULL){

		return;
	}

	//Se a lista tiver apenas um elemento.
	if(p->prox == NULL) {

		l->ini = NULL;
		*item = p->item;
		l->qtd--;
		free(p);
		return;
	}

	//Se a lista conter mais de um elemento.
	l->ini = p->prox;
	l->ini->anter = NULL;
	*item = p->item;
	l->qtd--;
	free(p);
	return;
}

//Essa funcao é responsavel por remover um elemento no final da lista.
void removeFim(Lista* l, T* item) {

	No* p = l->ini;

	//Se a lista estiver vazia, nao há nada para remover.
	if(p == NULL){

		return;
	}

	No* atual = l->ini;
	No* anterior = l->ini;

	//Percorre a lista até o ultimo elemento.
	while(atual->prox != NULL){

		anterior = atual;
		atual = atual->prox;
	}

	*item = anterior->prox->item;
	anterior->prox = NULL; 
	l->qtd--;
	free(atual);
	return;
}

//Indica o iterador como sendo o primeiro elemento da lista.
Iterador inicio(Lista* l) {

	Iterador it;
	it.p = l->ini;
	it.l = l;

	return it;	
}

//Indica o iterador como sendo o ultimo elemento da lista.
Iterador fim(Lista* l) {

	Iterador it;
	it.p = l->ini;
	it.l = l;

	//Percorre até o final da lista.
	while(it.p->prox != NULL) {

		proximo(&it);
	}

	return it;
}

//Essa funcao é responsavel por retornar o valor do elemento que esta naquela posicao.
void elemento(Iterador* it, T* item) {

	if(!acabou(it))
	*item = it->p->item;
}

//Essa funcao é responsavel por indicar que o iterador agora é o proximo elemento da lista.
void proximo(Iterador* it) {

	if(!acabou(it)) {
		
		it->p = it->p->prox;
	}
}

//Essa funcao é responsavel por indicar que o iterador agora é o elemento anterior da lista.
void anterior(Iterador* it) {

	if(!acabou(it)) {
		
		it->p = it->p->anter;
	}
}

//Essa funcao é responsavel por realizar uma busca crescente na lista, desde o seu primeiro elemento.
Iterador buscaPrimeiro(Lista* l, T item) {

	Iterador it = inicio(l);
	
	while(!acabou(&it)) {
		
		if(it.p->item == item) {
			
			return it;
		}
		proximo(&it);
	}
	return it;
}

//Essa funcao é responsavel por realizar uma busca decrescente na lista, desde o seu ultimo elemento.
Iterador buscaUltimo(Lista* l, T item) {

	Iterador it = fim(l);
	
	while(!acabou(&it)) {
		
		if(it.p->item == item) {
			
			return it;
		}
		anterior(&it);
	}
	return it;

}

//Essa funcao é responsavel por buscar o proximo elemento da lista, de acordo com o iterador passado como parametro na funcao.
Iterador buscaProximo(Iterador* it, T item) {

	while(!acabou(it)) {
		
		if(it->p->item == item) {
			
			return *it;
		}
		proximo(it);
	}
	return *it;
}

//Essa funcao é responsavel por buscar o elemento anterior da lista, de acordo com o iterador passado como parametro na funcao.
Iterador buscaAnterior(Iterador* it, T item) {

	while(!acabou(it)) {
		
		if(it->p->item == item) {
			
			return *it;
		}
		anterior(it);
	}
	return *it;
}

//Essa funcao é reponsavel por inserir um elemento depois do iterador passado como parametro na funcao.
void insereDepois(Iterador* it, T item) {

	No* p = it->p;

	//Caso a lista for vazia.
	if(it == NULL){

		return;
	}

	//Caso o elemento for inserido no fim da lista.
	if(p->prox == NULL) {

		No* novo = (No*)malloc(sizeof(No));
		
		novo->item = item;
		novo->prox = NULL;
		novo->anter = it->p;
		p->prox = novo;
		it->l->qtd++;
	
	//Caso o elemento for inserido no meio da lista.
	} else {

		No* novo = (No*)malloc(sizeof(No));
		
		novo->item = item;
		novo->prox = it->p->prox;
		novo->anter = it->p;
		p->prox = novo;
		p->prox->prox->anter = novo;
		it->l->qtd++;
	}
	return;
}

//Essa funcao é reponsavel por inserir um elemento antes do iterador passado como parametro na funcao.
void insereAntes(Iterador* it, T item) {

	No* p = it->p;

	//Caso a lista for vazia.
	if(it == NULL){

		return;
	}

	//Caso o elemento for inserido no começo da lista.
	if(p->anter == NULL){

		No* novo = (No*)malloc(sizeof(No));
		novo->item = item;
		novo->prox = it->p;
		novo->anter = NULL;
		it->p = novo;
		it->p->prox = p;
		it->p->prox->anter = novo; 
		it->l->qtd++;
		it->l->ini = it->p;
		return;

	//Caso o elemento for inserido no meio da lista.
	} else {

		No* novo = (No*)malloc(sizeof(No));
		novo->item = item;
		novo->prox = p;
		novo->anter = p->anter;
		p->anter = novo;
		p->anter->anter->prox = novo;
		it->l->qtd++;
		return;
	}
}

//Essa funcao é reponsavel por remover o elemento depois do iterador passado como paramentro na lista.
void removeDepois(Iterador* it, T* item) {

	No* p = it->p;

	//Se a lista estiver vazia.
	if(it == NULL){

		*item = '0';
		return;
	}
	
	//Se não houver elemento depois do iterador, nao há nada para remover.
	if(p->prox == NULL){

		*item = '0';
		return;

	//Se o elemento a ser removido for o ultimo elemento da lista.
	} else if(p->prox->prox == NULL){

		No* aux = p->prox;
		*item = it->p->prox->item;
		p->prox = NULL;
		it->l->qtd--;
		free(aux);
		return;
	
	//Se o elemento a ser removido se encontrar no meio da lista.
	} else {

		No* aux = p->prox;
		*item = it->p->prox->item;
		p->prox->prox->anter = p;
		p->prox = p->prox->prox;
		it->l->qtd--;
		free(aux);
		return;
	}
}

//Essa funcao é responsavel por remover o proprio elemento do iterador passado como parametro na função.
void remover(Iterador* it, T* item) {

	No* p = it->p;

	//Se a lista estiver vazia.
	if(it == NULL){

		return;
	}

	//Se antes do iterador não houver elemento.
	if(p->anter == NULL){

		*item = p->item;
		it->p = it->p->prox;
		it->p->anter = NULL;
		it->l->ini = it->p;
		it->l->qtd--;
		free(p);
		return;
	
	//Se repois do iterador não houver elemento.
	} else if(p->prox == NULL){

		*item = p->item;
		it->p->anter->prox = NULL;
		it->l->qtd--;
		free(p);
		return;

	//O iterador se encontra no meio da lista para ser removido.
	} else {

		*item = p->item;
		p->anter->prox = p->prox;
		p->prox->anter = p->anter;
		it->l->qtd--;
		free(p);
		return;
	}
}

//Essa funcao é responsavel por remover o elemento antes do iterador passado como parametro na função.
void removeAntes(Iterador* it, T* item) {

	No* p = it->p;

	//Se a lista estiver vazia.
	if(it == NULL){

		*item = '0';
		return;
	}

	//Se antes do iterador nao houver elemento, nao há nada para remover.
	if(p->anter == NULL){	

		*item = '0';
		return;

	//Se o elemento a ser removido estiver no começo da lista.
	} else if(p->anter->anter == NULL) {
		
		*item = p->anter->item;
		it->p->anter = NULL;
		free(it->l->ini);
		it->l->ini = it->p;
		it->l->qtd--;
		return;

	//Se o elemento estiver no meio da lista.
	} else {

		No* aux =  it->p->anter;
		*item = p->anter->item;
		p->anter->anter->prox = p;
		p->anter = p->anter->anter;
		it->l->qtd--;
		free(aux);
		return;
	}
}

//Essa funcao é responsavel por retornar o numero de elementos da lista.
int quantidade(Lista* l) {

	return l->qtd;
}

//Essa funcao é responsavel por indicar se a lista contem algum elemento.
int vazia(Lista* l) {

	if(l->ini == NULL){

		return 1;
	
	} else {

		return 0;
	}
}