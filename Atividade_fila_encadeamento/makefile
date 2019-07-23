program:	fila_encadeada.o	program.o
	gcc	program.o	fila_encadeada.o	-o	program	-Wall	-lm

fila_encadeada.o:	fila_encadeada.c	fila_encadeada.h
	gcc	fila_encadeada.c	-c	-Wall	-lm

program.o:	program.c	fila_encadeada.h
	gcc	program.c	-c	-Wall	-lm

clean:
	rm	program	*.o
