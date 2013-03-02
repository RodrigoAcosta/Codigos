grafo_main: grafo.o grafo_main.o 
	gcc grafo.o grafo_main.o -o grafo_main

grafo.o: grafo.c
	gcc -c grafo.c
grafo_main.o: grafo_main.c grafo.h
	gcc -c grafo_main.c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf grafo_main
