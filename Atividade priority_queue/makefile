main:	priority_queue.o	main.o
	gcc	main.o	priority_queue.o	-o	main	-Wall	-lm

priority_queue.o:	priority_queue.c	priority_queue.h
	gcc	priority_queue.c	-c	-Wall	-lm

main.o:	main.c	priority_queue.h
	gcc	main.c	-c	-Wall	-lm

clean:
	rm	main	*.o
