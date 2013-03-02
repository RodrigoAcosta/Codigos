#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "grafo.h"

int main()
{
   int vertices=0,vertices_ok=0,arestas_ok=0;
   int code=0;
   int i=0,j=0,k=0;	                                                    /*percorre string*/
   int indice=0,tamanho=0;
  /* int saida=0,chegada=0,peso=0;*/
   char nome[255];
   char aux[255];
   char entrada[255];
   char string[255];
   
   do{
	cabecalho(1);
	scanf("%s",entrada);
menu:	
	if(strcmp(entrada,"*Quit")==0){ 
	  printf("Algoritmo encerrado.\n");
      exit(0);
    }
    if(strcmp(entrada,"*Vertices")==0){
	   scanf("%d",&vertices);
	   if(vertices_ok!=1){
		 code=1;
	   }
	   else{  															/*mensagem de que o grafo ja tem vertices inicializados*/
	      code=-2;
	   }
	}
    if(strcmp(entrada,"*Edges")==0){
	   if(vertices_ok!=0){
	     if(arestas_ok!=1){
	       code=2;
	     } 
	     else{
		   code=-2; 
		 }
	   }
	   else{
	     code=-1; 
	   }  
     }  
    if(strcmp(entrada,"*Arcs")==0){
	   if(vertices_ok!=0){
	     if(arestas_ok!=1){
	       code=3;
	     } 
	     else{
		   code=-2; 
		 }
	   }
	   else{
	     code=-1; 
	   }  
	}
	if(strcmp(entrada,"*Queries")==0){
	  if(arestas_ok!=0){
	    code=4;
	  }	
	  else{
	    code=-3;
	  }
	}
   
    switch(code){
   
      case -4:
           printf("Arestas ja inicializadas.\n");  
           break;
      case -3:
           printf("Arestas nao inicializadas. Digite '*Edges' ou '*Arcs' para mapear as Arestas.\n");  
           break;
      case -2:
           if(arestas_ok!=1){
             printf("Grafo ja inicializado. Digite '*Edges' ou '*Arcs' para mapear as Arestas.\n");  
           }
           else{
		     printf("Grafo ja inicializado.Arestas ja inicializadas. Selecione uma Operacao a ser realizada no grafo.\n");
		   }  
           break;
      case -1:
           printf("Grafo nao inicializado. Digite inicialmente '*Vertices' e o numero de vertices do grafo.\n");  
           break;
      case 1:   														/* *Vertices*/
           if(vertices>0){
			  NOME_VERTICES nodos[vertices];                            /*guarda o nome de cada vertices da matriz de adjacencia*/
			  init_nome(nodos,vertices);
			  MATRIZ grafo[vertices][vertices];
			  /*inicializar o a matriz grafo*/
			  for(j=0;j<vertices;j++){
			     for(i=0;i<vertices;i++){
                    grafo[j][i].conexo=0; 
			      }
              }			  
			  /*fim do inicializar o a matriz grafo*/
			  i=-1;
			  do{
			    i++;  													/*percorre todos o vertices do grafo*/
			    j=-1;
			    do{   					 								/*ateh dar enter*/  
			      j++;
			      scanf("%c",&string[j]);
			    }while(string[j]!='\n');	
			    string[j]='\0'; 										/*fim*/
			    tamanho=strlen(string);
			    if(string[0]!='*'){
			      j=0;
			      while(string[j]!=' '){
				     aux[j]=string[j];
				     j++;
				  }
				  aux[j]='\0';
				  indice=atoi(aux);
				  k=0;
				  j+=2;
				  while(j<tamanho){
				     aux[k]=string[j];
				     j++;
				     k++;
				  }
				  aux[k-1]='\0';
				  strcpy(nome,aux);
                  if(indice<(vertices)){
                    strcpy(nodos[indice].nome,nome);  				/*linha*/
                    nodos[indice].ini=1;
                  }
			      else{
				    printf("Indice superior ao maior indice na matriz de adjacencia.\n");
					i--;										 		/*para poder mexer na mesma posicao*/
				  }
				} 
			 }while((i<(vertices))&&(strcmp(string,"*Edges")!=0)&&(strcmp(string,"*Arcs")!=0));
		     if(i>=(vertices)){
		        printf("A Matriz de Adjacencia do grafo ja esta completa.\n");
	         }
		     else{  													/*foi *Arcs ou *Edges*/
			   printf("Encerrado a insercao de vertices.\n");
			 }
			 vertices_ok=1;
			 if(strcmp(string,"*Edges")==0){
			    strcpy(entrada,"*Edges");
			    goto menu;   											/*burlar a lida da instrucao a ser executada e manda a *Edges*/
		     }
			 else{
               if(strcmp(string,"*Arcs")==0){
			      strcpy(entrada,"*Arcs");                           
			      goto menu;                                            /*burlar a lida da instrucao a ser executada e manda a *Arcs*/
		       }  			 
			 }
		   }
		   else{
		     printf("Erro.Numero minimo de 1 vertice nao atingido.\n");
		     vertices_ok=0;
		   }
           break;
      case 2:															/* *Edges - arestas nao direcionadas*/		
           printf("*Edges.\n");
           do{
			 j=-1;
			 do{   					 								    /*ateh dar enter*/  
			   j++;
			   scanf("%c",&string[j]);
			 }while(string[j]!='\n');	
			 string[j]='\0'; 										    /*fim*/
			 tamanho=strlen(string);
			 if(string[0]!='*'){                                        /*tratar entrada para nao ser um comando no grafo*/ 
                /*fazer metodo para separa em campos a string*/
                
                printf("string - %s\n",string);		      
		      } 
           }while(strcmp(string,"*Queries")!=0);
		   
		   
		   printf("Encerrado a insercao de Arestas Nao-Direcionadas.\n");
           
           arestas_ok=1;
           break;     
     case 3:															/* *Arcs*/		
           printf("*Arcs.\n");
           arestas_ok=1;
           break;     
     case 4:															/* *Queries*/		
           printf("*Queries.\n");
           break;          
     
   
      default:
           printf("Instrucao nao implementada.\n");
           code=5;  /*modificar no menu*/
           break;
       
    }
   sleep(2);
   printf("\33[H\33[2J");
   }while(code!=0);







   return 0;
}
