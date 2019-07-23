program:	balanco.o	program.o
	gcc	program.o	balanco.o	-o	program	-Wall	-lm

balanco.o:	balanco.c	balanco.h
	gcc	balanco.c	-c	-Wall	-lm

program.o:	program.c	balanco.h
	gcc	program.c	-c	-Wall	-lm

clean:
	rm	program	*.o
