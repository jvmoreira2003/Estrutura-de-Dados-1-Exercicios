#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rational.h"

//Essa função será responsável por definidar o valor do numerador e do denominador de uma determinada fração
rational define(int numerator, int denominator) {

	rational c;

	c.numerator = numerator;
	c.denominator = denominator;
	
	return c;
}

//Essa função será responsável por realizar a soma entre duas frações
rational plus(rational a, rational b) {

	rational c;

	int numerator, denominator, valor;
	int i;

	denominator = a.denominator * b.denominator;
	numerator = (denominator/a.denominator) * (a.numerator) + (denominator/b.denominator) * (b.numerator);

	c.numerator = numerator;
	c.denominator = denominator;

	if(c.numerator < 0){

		valor = (-1)*c.numerator;
	}

	//Será realizado a simplificação da fraçao até chegar fração mais simplificada possivel, percorrendo atpe o valor passado como referencia
	for(i=2; i <= valor; i++){

		if((c.numerator % i == 0) && (c.denominator % i == 0)){
			c.numerator = c.numerator/i;
			c.denominator = c.denominator/i;
			i--;
		
		}
	}

	if(c.denominator < 0 && c.numerator > 0){

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;

	
	} if(c.denominator < 0 && c.numerator < 0) {

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;		

	}

	return c;

}

rational minus(rational a, rational b) {

	rational c;

	int numerator, denominator, valor;
	int i;

	denominator = a.denominator * b.denominator;
	numerator = (denominator/a.denominator) * (a.numerator) - (denominator/b.denominator) * (b.numerator);

	c.numerator = numerator;
	c.denominator = denominator;

	if(c.numerator < 0){

		valor = (-1)*c.numerator;
	}

	//Será realizado a simplificação da fraçao até chegar fração mais simplificada possivel, percorrendo atpe o valor passado como referencia
	for(i=2; i <= valor; i++){

		if((c.numerator % i == 0) && (c.denominator % i == 0)){
			c.numerator = c.numerator/i;
			c.denominator = c.denominator/i;
			i--;
		
		}
	}

	if(c.denominator < 0 && c.numerator > 0){

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;

	
	} if(c.denominator < 0 && c.numerator < 0) {

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;		

	}

	return c;

}

rational times(rational a, rational b) {

	rational c;
	int numerator, denominator, valor;
	int i;

	numerator = a.numerator * b.numerator;
	denominator = a.denominator * b.denominator;

	c.numerator = numerator;
	c.denominator = denominator;

	if(c.numerator < 0){

		valor = (-1)*c.numerator;
	}

	
	//Será realizado a simplificação da fraçao até chegar fração mais simplificada possivel, percorrendo atpe o valor passado como referencia
	for(i=2; i <= valor; i++){

		if((c.numerator % i == 0) && (c.denominator % i == 0)){
			c.numerator = c.numerator/i;
			c.denominator = c.denominator/i;
			i--;
		
		}
	}

	if(c.denominator < 0 && c.numerator > 0){

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;

	
	} if(c.denominator < 0 && c.numerator < 0) {

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;		

	}

	return c;

}

rational divides(rational a, rational b) {

	rational c;
	int numerator, denominator, valor;
	int i;

	numerator = a.numerator * b.denominator;
	denominator = a.denominator * b.numerator;

	c.numerator = numerator;
	c.denominator = denominator;

	if(c.numerator < 0){

		valor = (-1)*c.numerator;
	}

	//Será realizado a simplificação da fraçao até chegar fração mais simplificada possivel, percorrendo atpe o valor passado como referencia
	for(i=2; i <= valor; i++){

		if((c.numerator % i == 0) && (c.denominator % i == 0)){
			c.numerator = c.numerator/i;
			c.denominator = c.denominator/i;
			i--;
		
		}
	}

	if(c.denominator < 0 && c.numerator > 0){

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;

	
	} if(c.denominator < 0 && c.numerator < 0) {

		c.numerator = (-1)*c.numerator;
		c.denominator = (-1)*c.denominator;		

	}

	return c;
}

//Essa função será responsavel por verificar se as duas frações sao equivalentes entre si.
int	equals(rational a, rational b) {

	int i;
	int valor;

	if(a.numerator < 0){

		valor = (-1)*a.numerator;
	}

	//Será realizado a simplificação da fraçao até chegar fração mais simplificada possivel, percorrendo atpe o valor passado como referencia
	for(i=2; i <= valor; i++){

		if(a.numerator % i == 0 && a.denominator % i == 0){

			a.numerator = a.numerator/i;
			a.denominator = a.denominator/i;	
		}
	}

	if(b.numerator < 0){

		valor = (-1)*b.numerator;
	}

	//Será realizado a simplificação da fraçao até chegar fração mais simplificada possivel, percorrendo atpe o valor passado como referencia
	for(i=2; i <= valor; i++){

		if(b.numerator % i == 0 && b.denominator % i == 0){

			b.numerator = b.numerator/i;
			b.denominator = b.denominator/i;	
		}
	}

	//Se as funçoes tiverem numeradores e denominadores iguais, depois de realizar a simplificaçῶao delas, a função retorna 1, caso contrario 0
	if((a.numerator == b.numerator) && (a.denominator == b.denominator)){

		return 1;
	
	} else {

		return 0;
	}
}

//essa função sera reponsável em converter termo passado como referencia para string na tela
void toString(rational r, char* str) {

	sprintf(str,"%d/%d\n",r.numerator,r.denominator);

}