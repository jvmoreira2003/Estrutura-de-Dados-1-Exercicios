client:	lista.o	client.o
	gcc	client.o	lista.o	-o	client	-Wall	-lm

lista.o:	lista.c	lista.h
	gcc	lista.c	-c	-Wall	-lm

client.o:	client.c	lista.h
	gcc	client.c	-c	-Wall	-lm

clean:
	rm	client	*.o
