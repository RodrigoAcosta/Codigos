#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "grafo.h"

int main()
{
   int vertices=0,vertices_ok=0,arestas_ok=0;
   int code=0,valido_1=0,valido_2=0,resposta=0;
   int id=-1;
   int i=0,j=0,k=0;	                                                    /*percorre string*/
   int indice=0,tamanho=0;
   int v1=0,v2=0,peso=0;
   char nome[255];
   char aux[255];
   char entrada[255];
   char string[255];
   NOME_VERTICES *nodos;                                       
   MATRIZ **grafo;
   LISTA_ADJACENCIA *lista;
   
  
   do{
	cabecalho(1);
	scanf("%s",entrada);
	if(strcmp(entrada,"@")==0){ 
	  exit(0);
    }
    if(strcmp(entrada,"*Vertices")==0){
	   scanf("%d",&vertices);
	   if(vertices_ok!=1){
		 nodos=malloc(vertices*sizeof(NOME_VERTICES));
		 /*declaracao lista adjacencia*/ 
		 lista=malloc(vertices*sizeof(LISTA_ADJACENCIA));
		 
         init_nome(nodos,vertices);
         grafo=malloc(vertices*sizeof(MATRIZ));
         for(i=0;i<vertices;i++){
              grafo[i]=malloc(vertices*sizeof(MATRIZ));
		 }
		code=1;
	   }
	   else{  															/*mensagem de que o grafo ja tem vertices inicializados*/
	      code=-2;
	   }
	}
menu:	
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
                    strcpy(nodos[indice].nome,nome);  				    /*linha*/
                    nodos[indice].ini=1;
                  }
			      else{
				    printf("Indice superior ao maior indice na matriz de adjacencia.\n");
					i--;										 		/*para poder mexer na mesma posicao*/
				  }
				} 
			 }while((i<(vertices))&&(strcmp(string,"*Edges")!=0)&&(strcmp(string,"*Arcs")!=0));
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
            /*inicializar o a matriz grafo*/
			for(j=0;j<vertices;j++){
			  for(i=0;i<vertices;i++){
                 grafo[j][i].conexo=0; 
                 grafo[j][i].peso=pow(2,-15);                           /*peso nao valido, para dizer que nao foi inicializado*/
               }
            }			  
            for(j=0;j<vertices;j++){
              if(nodos[j].ini==1){                                      /*um nodo da matriz sempre eh conexo a si mesmo*/
			    grafo[j][j].conexo=1;
			  }
			}  
			/*fim do inicializar o a matriz grafo*/
		   do{
			 j=-1;
			 do{   					 								    /*ateh dar enter*/  
			   j++;
			   scanf("%c",&string[j]);
			 }while(string[j]!='\n');	
			 string[j]='\0'; 										    /*fim*/
			 tamanho=strlen(string);
			 if(string[0]!='*'){                                        /*tratar entrada para nao ser um comando no grafo*/ 
                valido_1=0;
                valido_2=0;
                separa_string(string,&v1,&v2,&peso);
                valido_1=validar(v1,vertices,nodos[v1].ini);  			/*retorna 1 se v1 eh valido*/
                valido_2=validar(v2,vertices,nodos[v2].ini);   			/*retorna 1 se v2 eh valido*/
				if((valido_1==1)&&(valido_2==1)){       				/*soh nessas condicoes eh que pode setar na matriz de adjacencia*/  
				   grafo[v1][v2].conexo=1;                              
                   grafo[v1][v2].peso=peso;                              
                   grafo[v2][v1].conexo=1;                              				      	
                   grafo[v2][v1].peso=peso;
                }
              }
              else{
			    if(strcmp(string,"*Queries")!=0){
				   printf("Instrucao nao suportada dentro da instrucao *Edges.\n");
				}
			  } 
           }while(strcmp(string,"*Queries")!=0);
		   arestas_ok=1;
           strcpy(entrada,"*Queries");
           goto menu;
           break;     
     case 3:															/* *Arcs*/		
           /*inicializar o a matriz grafo*/
			for(j=0;j<vertices;j++){
			  if(nodos[j].ini==1){                                      /*um nodo da matriz sempre eh conexo a si mesmo*/
			    grafo[j][j].conexo=1;
			  }
			  for(i=0;i<vertices;i++){
                 grafo[j][i].conexo=0; 
                 grafo[j][i].peso=pow(2,-15);                           /*peso nao valido, para dizer que nao foi inicializado*/
               }
            }
            for(j=0;j<vertices;j++){
              if(nodos[j].ini==1){                                      /*um nodo da matriz sempre eh conexo a si mesmo*/
			    grafo[j][j].conexo=1;
			  }
			}			  
			/*fim do inicializar o a matriz grafo*/
			do{
			 j=-1;
			 do{   					 								    /*ateh dar enter*/  
			   j++;
			   scanf("%c",&string[j]);
			 }while(string[j]!='\n');	
			 string[j]='\0'; 										    /*fim*/
			 tamanho=strlen(string);
			 if(string[0]!='*'){                                        /*tratar entrada para nao ser um comando no grafo*/ 
                valido_1=0;
                valido_2=0;
                separa_string(string,&v1,&v2,&peso);
                valido_1=validar(v1,vertices,nodos[v1].ini);  			/*retorna 1 se v1 eh valido*/
                valido_2=validar(v2,vertices,nodos[v2].ini);   			/*retorna 1 se v2 eh valido*/
				if((valido_1==1)&&(valido_2==1)){       				/*soh nessas condicoes eh que pode setar na matriz de adjacencia*/  
				   grafo[v1][v2].conexo=1;                              
                   grafo[v1][v2].peso=peso;                              
                }
              }
              else{
				printf("entrou2.\n");
			    if(strcmp(string,"*Queries")!=0){
				   printf("Instrucao nao suportada dentro da instrucao *Arcs.\n");
				}
			  } 
           }while(strcmp(string,"*Queries")!=0);
		   arestas_ok=1;
		   strcpy(entrada,"*Queries");
		   goto menu;
           break;     
     case 4:															/* *Queries*/		
           /*IF'S NAO ENCADEADOS PELO MOTIVO DE FICAR ILEGIVEL. POR ISSO TERA DE TESTAR TODAS AS OPCOES SEMPRE QUE EXECUTAR*/
           /*TEM QUE TRATAR PARA VER DE TER NO MINIMO X TERMOS*/
           sleep(2);
           printf("\33[H\33[2J");
           do{
             cabecalho(2);
             j=-1;
             do{   					 								    /*ateh dar enter*/  
			   j++;
			    scanf("%c",&entrada[j]);
			 }while(entrada[j]!='\n');	
			 entrada[j]='\0'; 										    /*fim*/        
             if(strcmp(entrada,"@")==0){ 
		       exit(0);
             }
             if(strstr(entrada,"get")){	 
				resposta=0;
		        id=separa_id(entrada);
		        resposta=get_ID(id,nome,nodos,vertices);
		        if(resposta==1){
				   printf("\"{\"vertice\":{\"ID\":%d, \"dado\":\"%s\", \"resposta\":\"sucesso\"}}\n",id,nome);
				}
				else{
				   printf("{\"vertice\":{\"ID\":%d, \"dado\":\"%s\", \"resposta\":\"falha\"}}\n",id,nome);
				}
		     }
		     if(strstr(entrada,"delete")){
				resposta=0;
		        id=separa_id(entrada);
		        resposta=delete_ID(id,vertices,grafo,nodos); 
			    if(resposta==1){
				   printf("{\"delete\":{\"ID\":%d,\"resposta\":\"sucesso\"}}",id);
				}
				else{
				   printf("{\"delete\":{\"ID\":%d,\"resposta\":\"falha\"}}",id);
				}
			 }//fim delete_id
		     if(strstr(entrada,"vizinhos")){    
                resposta=0;
		        id=separa_id(entrada);
		        resposta=vizinhos_ID(id,vertices,grafo,string);
		        if(resposta==1){
				   printf("{\"vizinhos\":{\"ID\":%d, \"resposta\":\"sucesso\", \"vizinhos\":[%s]}}",id,string);
				}
				else{
				   printf("{\"vizinhos\":{\"ID\":%d, \"resposta\":\"falha\", \"vizinhos\":[]}}",id);
				}
		     }//fim vizinhos
             if(strstr(entrada,"conexao")){
			    resposta=0;
		        separa_id_id(entrada,&v1,&v2);
		        resposta=conexao(v1,v2,vertices,grafo);
			    if(resposta==1){
				   printf("{\"conexao\":{\"ID1\":%d, \"ID2\":%d, \"resposta\":\"sucesso\", \"conexao\":\"sim\"}}",v1,v2);
				}
				else{
				   printf("{\"conexao\":{\"ID1\":%d, \"ID2\":%d, \"resposta\":\"falha\", \"conexao\":\"\"}}",v1,v2);
				}
			 }//fim conexo
             if(strstr(entrada,"ordemtopologica")){
				resposta=0; 
				string[0]='\0';
			    lista=adjacencia(lista,grafo,vertices);
			    resposta=ordem_t(grafo,lista,nodos,string,vertices);
			     
			 }
          
          
          
          
             sleep(2);
             printf("\33[H\33[2J");
           }while(1);
           break;          
     default:
           printf("Instrucao nao implementada.\n");
           code=5;  													/*modificar no menu*/
           break;
       
    }
   sleep(2);
   printf("\33[H\33[2J");
   }while(code!=0);


 return 0;
}
