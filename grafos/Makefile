grafo_main: grafo.o grafo_main.o 
	gcc -o grafo_main grafo.o grafo_main.o

grafo.o: grafo.c
	gcc -o grafo.o -c grafo.c -W -Wall -ansi -pedantic
grafo_main.o: grafo_main.c grafo.h
	gcc -o grafo_main.o -c grafo_main.c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
mrproper: clean
	rm -rf grafo_main
