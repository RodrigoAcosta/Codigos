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

void print_nomes(const NOME_VERTICES nodo[],int tamanho){

   int i;
   
   for(i=0;i<(tamanho);i++){
      if(nodo[i].ini==1){   
        printf("Indice - %d - Nome - %s\n",i,nodo[i].nome);      
      }
      else{
	    printf("Indice - %d - Nao Inicializado\n",i);      
	  }
   }
}

void init_nome(NOME_VERTICES nodo[],int tamanho){
  
   int i;
   
   for(i=0;i<(tamanho);i++){
       nodo[i].ini=0;                                                   /*0 - ainda nao foi inicializado*/
   }
}

void separa_string(char string[],int *v1,int *v2,int *peso){

 int i=0,j=0;
 char aux[255];
 int tamanho=0;
   
 tamanho=strlen(string);
 if(tamanho>=5){    /*tamanho 5 eh o minimo que tem que ter para o comando estar correto*/
   while(string[i]!=' '){
	 aux[i]=string[i];  
     i++;
   }
   aux[i]='\0'; 											  			/*fim string*/
   *v1=atoi(aux); 														/*transforma para inteiro*/
   i++;
   j=0;
   while(string[i]!=' '){
	 aux[j]=string[i];  
     i++;
     j++;
   }
   aux[j]='\0';   														/*fim string*/ 
   *v2=atoi(aux);														/*transforma para inteiro*/
   i++;
   j=0;
   while((string[i]!='\0')&&(string[i]!='\n')){
	 aux[j]=string[i];  
     i++;
     j++;
   }
   aux[j]='\0';
   *peso=atoi(aux);
 }
 else{
    printf("ERRO. Tamanho minimo da string de comando nao atingido.\n");
    *v1=-1;   															/*dar aviso de erro no parametro v1*/
    *v2=-1;   															/*dar aviso de erro no parametro v2*/
    *peso=-1;
 } 
   
   
}

int validar(int num,int n_vertices,const int nodo){
   
   if((num>=0)&&(num<n_vertices)){
     if(nodo!=1){                                              /*vertices existente e valido pois foi inicializado*/  
        printf("Vertice nao inicializado, nao podera ser usado.\n");
     }
     else{
	   return 1;
	 }
   }
   else{
	  printf("Vertice fora do alcance de valores possiveis. ( 0<=vertice<total_vertices ).\n"); 
   }
  return 0;
}
