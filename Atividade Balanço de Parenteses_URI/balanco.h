#ifndef BALANCO_H_
#define BALANCO_H_

typedef struct _vetor{

	char *item;

}Vetor;

void inicializa(Vetor *s, int max_size);
void destroi(Vetor *s);
int empilhadesempilha(Vetor *s, int tam, char *q);

#endif