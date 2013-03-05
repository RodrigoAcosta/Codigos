#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#ifndef GRAFO_H_
#define GRAFO_H_

typedef char info; 

typedef struct nome_vertices{
	info nome[255];
	int ini;                                                            /*saber se aquele vertice foi inicializado*/ 
}NOME_VERTICES;

typedef struct matriz{
	int peso;                                                           /*peso nao vale para as posicoes grafo[0][x] e grafo[x][0] , pois eh onde ficara o nome*/
	int conexo;                                                         /*1-conectado 0-nao conectado*/
}MATRIZ;

/*grafo estrutura grafo[linha][coluna]*/
/*coluna eh quem tu segue*/
/*linha que te segue*/

/*ex: na diagonal principal se o vertice esta conectado a si mesmo quer dizer que ele eh valido e que foi inicializado com um nome*/

void cabecalho(int menu);  
void print_nomes(const NOME_VERTICES nodo[],int tamanho);               /*mandar para a tela todos os vertices existentes*/
void init_nome(NOME_VERTICES nodo[],int tamanho);                       /*iniciar o nome dos vertices*/
void separa_string(char string[],int *v1,int *v2,int *peso);            /*separa o que eh v1,v2 e peso da string lida*/  
int validar(int num,int n_vertices,const int nodo);              		/*ver se esta dentro dos valores possiveis 0<=i<=n-1*/
int get_ID(int id,char nome[],const NOME_VERTICES nodo[],int tamanho);	/*char nome[] passado por default mas o usuario nao precisa digitar*/
int separa_id(char string[]);											/*devolve o id continua na string get id*/
int delete_ID(int id,int tamanho,MATRIZ **nodo,NOME_VERTICES nodos[]);


#endif
