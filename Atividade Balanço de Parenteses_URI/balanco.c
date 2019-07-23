#include<stdio.h>
#include<stdlib.h>

#include "balanco.h"

void inicializa(Vetor *s, int max_size){

	s->item = (char*)malloc(sizeof(char)*max_size);

}



int empilhadesempilha(Vetor *s, int tam, char *q){

	int i, f = 0, x = 0;

	for(i=0; i< tam; i++){

		if(q[i] == '(') {

			s->item[f] = q[i];
			f++;
			x = 1;
		
		} else if(q[i] == ')'){

			f--;
			x = 0;
		}
	}

	if(f == 0 && x == 0){

		return 1;
	
	} else {

		return 0;
	}
}
