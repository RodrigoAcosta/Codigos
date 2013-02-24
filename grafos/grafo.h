#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifndef GRAFO_H_
#define GRAFO_H_

typedef char info; 

typedef struct matriz{
	int peso;                                                           /*peso nao vale para as posicoes grafo[0][x] e grafo[x][0] , pois eh onde ficara o nome*/
	int conexo;                                                         /*1-conectado 0-nao conectado*/
	info nome[255];
	int indice;                                                         /*qualquer indice que o usuario quizer*/                                                    

}MATRIZ;

/*grafo estrutura grafo[linha][coluna]*/

/*ex: na diagonal principal se o vertice esta conectado a si mesmo quer dizer que ele eh valido e que foi inicializado com um nome*/

void cabecalho(int menu);    

#endif
