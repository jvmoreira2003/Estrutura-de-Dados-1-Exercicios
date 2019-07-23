program:	pilha_vetor.o	program.o
	gcc	program.o	pilha_vetor.o	-o	program	-Wall	-lm

pilha_vetor.o:	pilha_vetor.c	pilha_vetor.h
	gcc	pilha_vetor.c	-c	-Wall	-lm

program.o:	program.c	pilha_vetor.h
	gcc	program.c	-c	-Wall	-lm

clean:
	rm	program	*.o
