grafo: grafo.o grafo_main.o 
	gcc -o grafo grafo.o grafo_main.o

teste.o: teste.c
	gcc -o teste.o -c teste.c -W -Wall -ansi -pedantic
main.o:  teste.h
	gcc -o main.o -c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
mrproper: clean
	rm -rf grafo
