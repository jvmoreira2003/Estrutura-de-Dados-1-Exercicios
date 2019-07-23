#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "complex.h"

typedef struct _complex {

	double re, im;
	
} *Complex;

//Essa funçao sera responsavel por adicionar o numero real e imaginario a um determinado numero complexo
Complex newComplex (double re, double im) {

	Complex comp = (Complex)malloc(sizeof(Complex));

	comp->re = re;
	comp->im = im;

	return comp;
}

//Essa funçao sera responsavel por destruir um numero complexo
void destroyComplex (Complex c) {

	free(c);

}

//Essa funçao sera responsavel por retornar o numero real de um determinado numero complexo
double complexRe (Complex c) {

	return c->re;

}

//Essa funçao sera responsavel por retornar o numero imaginario de um determinado numero complexo
double complexIm (Complex c) {

	return c->im;

}

//Essa funçao sera responsavel por fazer a soma entre dois numeros complexos
Complex complexAdd (Complex w, Complex z) {

	Complex comp = (Complex)malloc(sizeof(Complex));
	double real, imag;

	real = w->re + z->re;
	imag = w->im + z->im;

	comp->re = real;
	comp->im = imag;

	return comp;
}

//Essa funçao sera responsavel por realizar a multiplicaçao entre dois numeros complexos
Complex complexMultiply (Complex w, Complex z) {

	Complex comp = (Complex)malloc(sizeof(Complex));
	double real, imag;

	real = w->re * z->re;
	imag = w->im * z->im;

	comp->re = real;
	comp->im = imag;

	return comp;

}

//Essa funçao sera responsavel por determinado o modulo de um numero complexo
double complexMod (Complex w){

	double valor;

	valor = sqrt(pow(w->re, 2) + pow(w->im, 2));

	return valor;
}

//Essa funçao sera responsavel por determinar o argumento de um numero complexo
double complexArg (Complex w) {

	double val, cos, sen, tang;

	val = sqrt(pow(w->re, 2) + pow(w->im, 2));
	
	sen = w->im/val;
	cos = w->re/val;

	//Caso o valor de seno e cosseno forem iguais, podemos retornar qualquer um deles, caso contrario retornaremos a tangente 
	if(sen == cos){

		return cos;
	
	} else {

		tang = sen/cos;
		return tang;

	}

}
