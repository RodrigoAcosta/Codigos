#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "grafo.h"

int main()
{
  
  int vertices=0;
  int sair=0;
  int i=0,indice=0;
  char entrada[255];
  char string[255];
      
  do{
    cabecalho(1); 
    scanf("%s",entrada);
    if((strcmp(entrada,"*Quit")==0)||(strcmp(entrada,"*quit")==0)){
	   sair=1;  														/*sair do algoritmo*/
	}
    else{  
      if((strcmp(entrada,"*Vertices")==0)||(strcmp(entrada,"*vertices")==0)){
        scanf("%d",&vertices);
        i=1;
        if(vertices>0){
          scanf("%d",&indice);
          
          /*verificar se indice eh uma numero*/
          
          scanf("%s",string);
          while((i<vertices)&&((strcmp(string,"*Arcs")!=0)&&(strcmp(string,"*arcs")!=0))&&((strcmp(string,"*Edges")!=0)&&(strcmp(string,"*edges")!=0))){
          
          
            /*nao ta funcionando o while direito*/
            /*testar para ver se ja existe nodo inicializado com o indice*/           
          
          
            printf("indice - %d | Nome_Nodo - %s\n",indice,string);
            scanf("%d",&indice);
            scanf("%s",string);    
            i++;    
          }																/*fim while*/
		  
		} 																/*fim if sem vertices*/  
		else{
		   printf("Nenhum vertice a ser inicializado.\n");
		}
		printf("Fim da inicializacao dos vertices, inicio da inicializazao das arestas.\n");
		/*comecar a tratar as arestas*/
		sleep(2);   
        printf("\e[H\e[2J");   
        sair=0;
      }
      else{
        printf("Comando inexistente.\n");
        sleep(2);   
        printf("\e[H\e[2J");   
        sair=0;
      }
    }     
    getchar();
  }while(sair==0);
  
  printf("Algoritmo sendo encerrado.\n");
  /*free(matriz);*/
  return 0;
}
