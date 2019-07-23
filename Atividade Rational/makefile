rational-cliente:	rational.o	rational-cliente.o
	gcc	rational-cliente.o	rational.o	-o	rational-cliente	-Wall	-lm

rational.o:	rational.c	rational.h
	gcc	rational.c	-c	-Wall	-lm

rational-cliente.o:	rational-cliente.c	rational.h
	gcc	rational-cliente.c	-c	-Wall	-lm

clean:
	rm	rational-cliente	*.o
