accumulator-cliente:	accumulator.o	accumulator-cliente.o
	gcc	accumulator-cliente.o	accumulator.o	-o	accumulator-cliente	-Wall	-lm

accumulator.o:	accumulator.c	accumulator.h
	gcc	accumulator.c	-c	-Wall	-lm

accumulator-cliente.o:	accumulator-cliente.c	accumulator.h
	gcc	accumulator-cliente.c	-c	-Wall	-lm

clean:
	rm	accumulator-cliente	*.o
