#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "grafo.h"

int main()
{
  
  int vertices=0;
  int sair=0;
  char entrada[255];
  
  do{
    cabecalho(1); 
    scanf("%s",entrada);
    if((strcmp(entrada,"*Quit")==0)||(strcmp(entrada,"*quit")==0)){
	   sair=1;  														/*sair do algoritmo*/
	}
    else{  
      if((strcmp(entrada,"*Vertices")==0)||(strcmp(entrada,"*vertices")==0)){
        scanf("%d",&vertices);
        printf("vertices - %d\n",vertices);
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
