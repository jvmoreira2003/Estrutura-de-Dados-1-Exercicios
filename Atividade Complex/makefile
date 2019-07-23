complex-cliente:	complex.o	complex-cliente.o
	gcc	complex-cliente.o	complex.o	-o	complex-cliente	-Wall	-lm

complex.o:	complex.c	complex.h
	gcc	complex.c	-c	-Wall	-lm

complex-cliente.o:	complex-cliente.c	complex.h
	gcc	complex-cliente.c	-c	-Wall	-lm

clean:
	rm	complex-cliente	*.o
