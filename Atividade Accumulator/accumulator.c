#include <stdio.h>
#include <string.h>
#include "accumulator.h"

//Essa função sera responsavel por inicializar os campos do acumulador e do contador em 0
void initialize(acumulator* a){
	
	a->valor = 0;
	a->cont = 0;
}

//Essa função sera responsável por adicionar um determinado valor passado como argumento no acumulador e o contador será incrementado
void addDataValue(acumulator* a, double val) {
	
	a->valor = val + a->valor;
	a->cont++;
	a->valatual = val;
}

//Essa função sera responsavel por exibir a média do acumulador de acordo com a quantidade de entrada de dados no programa
double	mean(acumulator* a) {
	
	double media;
	media = a->valor/a->cont;
	return media;
}

//Essa função sera responsável por exibir o valor do acumulador
double value(acumulator* a) {
	
	return a->valor;

}

//Essa função sera responsável por exibir o argumento passado como parametro na função em forma de string, sendo nessa caso a média
void toString(acumulator* a, char* str) {
	
	sprintf(str, "%lf\n", a->valatual);

}