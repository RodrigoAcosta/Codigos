#include "grafo.h"

void cabecalho(int menu){
   
   switch(menu){
   
     case 1:
		printf(" ----------------------------------------------------\n");
		printf("|                      *h-HELP | *Quit               |\n");
		printf("|                      Menus Suportados:             |\n");
		printf("|   *Queries   |   *Edges   |   *Arcs  |  *Vertices  |\n");
		printf(" ----------------------------------------------------\n");
		break;
	case 2:                                                             
	    printf(" --------------------------------------------------------------------------------------------\n");
		printf("|                                         *Quit                                              |\n");
		printf("|                                 Instrucoes Suportadas:                                     |\n");
		printf("| get | delete | vizinhos | conexao | ordemtopologica | arvoreminima  | menorcaminho ID1 ID2 |\n");
		printf(" --------------------------------------------------------------------------------------------\n");
	    break;
	case 0:                                                             /*ajuda*/    	
        printf("Opcpes:\n*Vertice - Diz que tamanho tera a estrutura do grafo.\n*Arcs - Determina de que modo o grafo sera trabalhado. Nesse caso com arestas direcionadas.\n");
        printf("*Edges - Determina de que modo o grafo sera trabalhado. Nesse caso com arestas nao direcionadas.\n");
        printf("*Quit - Encerra a execucao do algoritmo.\n");
        break;   
    default:
       printf("Menu nao implementado.\n");
   }

}
