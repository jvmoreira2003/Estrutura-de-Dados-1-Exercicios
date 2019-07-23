program:	fila_vetor.o	program.o
	gcc	program.o	fila_vetor.o	-o	program	-Wall	-lm

fila_vetor.o:	fila_vetor.c	fila_vetor.h
	gcc	fila_vetor.c	-c	-Wall	-lm

program.o:	program.c	fila_vetor.h
	gcc	program.c	-c	-Wall	-lm

clean:
	rm	program	*.o
