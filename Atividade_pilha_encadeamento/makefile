program:	pilha_encadeada.o	program.o
	gcc	program.o	pilha_encadeada.o	-o	program	-Wall	-lm

pilha_encadeada.o:	pilha_encadeada.c	pilha_encadeada.h
	gcc	pilha_encadeada.c	-c	-Wall	-lm

program.o:	program.c	pilha_encadeada.h
	gcc	program.c	-c	-Wall	-lm

clean:
	rm	program	*.o
