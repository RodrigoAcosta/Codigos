#include "grafo.h"

void cabecalho(int menu){
   
   switch(menu){
   
     case 1:
		printf(" ----------------------------------------------------\n");
		printf("|                      *h-HELP | @-quit              |\n");
		printf("|                      Menus Suportados:             |\n");
		printf("|   *Queries   |   *Edges   |   *Arcs  |  *Vertices  |\n");
		printf(" ----------------------------------------------------\n");
		break;
	case 2:                                                             
	    printf(" -----------------------------------------------------\n");
		printf("|                       @-Quit                        |\n");
		printf("|               Instrucoes Suportadas:                |\n");
		printf("| get | delete | vizinhos | conexao | ordemtopologica |\n"); 
		printf("|           arvoreminima  | menorcaminho ID1 ID2      |\n");
		printf(" -----------------------------------------------------\n");
	    break;
	case 0:                                                             /*ajuda*/    	
        printf("Opcpes:\n*Vertice - Diz que tamanho tera a estrutura do grafo.\n*Arcs - Determina de que modo o grafo sera trabalhado.\nNesse caso com arestas direcionadas.\n");
        printf("*Edges - Determina de que modo o grafo sera trabalhado.\nNesse caso com arestas nao direcionadas.\n");
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
    //printf("ERRO. Tamanho minimo da string de comando nao atingido.\n");
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
	  //printf("Vertice fora do alcance de valores possiveis. ( 0<=vertice<total_vertices ).\n"); 
   }
  return 0;
}

int get_ID(int id,char nome[],const NOME_VERTICES nodo[],int tamanho){
 
  if(id<tamanho){
    if(nodo[id].ini==1){
   	  strcpy(nome,nodo[id].nome);
	  return 1;
    }  
  }  
 nome[0]='\0'; 															/*nenhum nome eh retornado*/
 return 0; 																/*falha*/
}

int separa_id(char string[]){

   int i=0,j=0;
   int numero=-1;
   char aux[255];
   
   while((string[i]!=' ')&&(string[i]!='\0')){   						/*va que nao ponha a id, gera um loop infinito*/
      i++;
   }
   i++; 																/*pula o especo e o resto eh a ID*/
   while((string[i]!='\0')&&(string[i]!='\n')){
      aux[j]=string[i];
      j++;
      i++;   
   }
   aux[j]='\0';  														/*fim string*/
   numero=atoi(aux);
   
   return numero;
}

void separa_id_id(char string[],int *id1,int *id2){

   int i=0,j=0;
   char aux[255];
   
   while((string[i]!=' ')&&(string[i]!='\0')){   						/*va que nao ponha a id, gera um loop infinito*/
      i++;
   }
   i++; 																/*pula o especo e o resto eh a ID*/
   while(string[i]!=' '){
      aux[j]=string[i];
      j++;
      i++;   
   }
   aux[j]='\0';  														/*fim string*/
   *id1=atoi(aux);
   j=0;
   i++;
   while((string[i]!='\n')&&(string[i]!='\0')){
      aux[j]=string[i];
      j++;
      i++;   
   }
   aux[j]='\0';
   *id2=atoi(aux);
   
}

int delete_ID(int id,int tamanho,MATRIZ **nodo,NOME_VERTICES nodos[]){

   int i=0;
   
   if(id<tamanho){
    if(nodo[id][id].conexo==1){
     while(i<tamanho){  												/*percorre toda a coluna*/
	    nodo[id][i].conexo=0;                                           /*desconecta noh e fica como ele nao existindo*/ 
	    nodo[id][i].peso=pow(2,-15);
	    i++;
	 } 
	 i=0;
	 while(i<tamanho){  												/*percorre toda a linha*/
	    nodo[i][id].conexo=0;                                           /*desconecta noh e fica como ele nao existindo*/ 
	    nodo[i][id].peso=pow(2,-15);
	    i++;
	 }
	 nodos[id].ini=0;
	 nodos[id].nome[0]='\0';
	 nodos[id].del=1; 
	 return 1;
    }
   } 
   return 0;
}

int vizinhos_ID(int id,int tamanho,MATRIZ **nodo,char string[]){            
  
  int i=0;
  char buffer [255];
  
  string[0]='\0'; 
  if(id<tamanho){
	if(nodo[id][id].conexo==1){                                           /*ver se existe o ID*/
     i=0;
     while(i<tamanho){
	    if(nodo[id][i].conexo==1){
		   snprintf(buffer, 10,"%d",i);
		   strcat(string,buffer);
		   strcat(string,",");
		}
		i++;
	 }
	 i=strlen(string);
	 i--;
	 string[i]='\0';
	
    return 1;
	}
  }	
  return 0;
}

int conexao(int id1,int id2,int tamanho,MATRIZ **nodo){

  if((id1<tamanho)&&(id2<tamanho)){
     if(nodo[id1][id2].conexo==1){
	   return 1;
	 }
  }
  return 0;
} 

LISTA_ADJACENCIA* adjacencia(LISTA_ADJACENCIA *lista,MATRIZ **nodo,int tamanho){
	
	int i=0,j=0;
	
	for(i=0;i<tamanho;i++){
	   lista[i].id=i;
	}
	
	for(j=0;j<tamanho;j++){
     for(i=0;i<tamanho;i++){
        if(i!=j){
          if(nodo[j][i].conexo==1){
			lista[i].id=i;
		    lista[i].chegam+=1;
		  } 
         }
		}	 
    }  
    return lista;
}

LISTA_ADJACENCIA* ordenar(LISTA_ADJACENCIA *lista,int tamanho){

  int i=0;
  int percorre=0,j=0;
  int aux_id=0,aux_chegam=0;
  
  while(percorre<tamanho){  //todos os elementos da lista
	 /*ordenar lista de adjacencia por ordem topo*/
     for(j=0;j<tamanho;j++){
       for(i=0;i<tamanho-1;i++){
	      if((lista[i].chegam)>(lista[i+1].chegam)){
	    	 aux_chegam=lista[i].chegam;  								//guardar valor
		     aux_id=lista[i].id;  										//guardar valor
		     lista[i].id=lista[i+1].id;
		     lista[i].chegam=lista[i+1].chegam;
		     lista[i+1].id=aux_id;
		     lista[i+1].chegam=aux_chegam;		   
		  }
		  if((lista[i].chegam)==(lista[i+1].chegam)){
		     if((lista[i].id)>(lista[i+1].id)){
		       aux_chegam=lista[i].chegam;  							//guardar valor
		       aux_id=lista[i].id;  									//guardar valor
		       lista[i].id=lista[i+1].id;
		       lista[i].chegam=lista[i+1].chegam;
		       lista[i+1].id=aux_id;
		       lista[i+1].chegam=aux_chegam;		   
		     }
		  }
	   } 
     }
     percorre++;
  }																	//fim while      
 return lista;
}

int ordem_t(MATRIZ **nodo,LISTA_ADJACENCIA *lista,NOME_VERTICES *vet,char string[],int tamanho){

   int i=0,j=0;
   MATRIZ **copia_matriz;
   NOME_VERTICES *copia_nome;
   //LISTA_ADJACENCIA *ordenada;
   //int ok=0;
   //int vertices=0;
      
   for(i=0;i<tamanho;i++){
	  if(vet[i].ini==0){
	    return 0;  
	  } 
   }
   
   /*copia da grafo*/
   copia_matriz=malloc(tamanho*sizeof(MATRIZ));
   copia_nome=malloc(tamanho*sizeof(NOME_VERTICES));
  // ordenada=malloc(tamanho*sizeof(LISTA_ADJACENCIA));
   //declarar matriz
   for(i=0;i<tamanho;i++){
     copia_matriz[i]=malloc(tamanho*sizeof(MATRIZ));
   }
   for(j=0;j<tamanho;j++){
     for(i=0;i<tamanho;i++){
	    copia_matriz[j][i].conexo=nodo[j][i].conexo;
	    copia_matriz[j][i].peso=nodo[j][i].peso;
	 }
   }
   /*termino da copia do grafo*/
   
   /*copia lista de nomes dos nodos*/
   for(i=0;i<tamanho;i++){
     strcpy(copia_nome[i].nome,vet[i].nome);
     copia_nome[i].ini=vet[i].ini;
   }  
   /*termino copia lista de nomes dos nodos*/
   
   /*manipulacao de dados apartir daqui*/
   
   
   
   
   
   
   
   return 0;
}

int arvoreminima(MATRIZ **nodo,NOME_VERTICES *vet,char string[],int tamanho,int custo){
//BASEADO NA TRANSCRIACAO DO ALGORITMO DE KRUSKAL

   int i=0,j=0,vezes;
   int menor_peso;
   int de=0,para=0;
   int ja_add=0;
   PESOS *lista_pesos;
   PESOS *topo;
   PESOS *aux;
   
   topo=malloc(sizeof(PESOS));
   aux=malloc(sizeof(PESOS));	 
   lista_pesos=NULL;
   aux=NULL;
   
   /*achar primeiro valor valido para comecar o processo*/
   for(j=0;j<tamanho;j++){
     for(i=0;i<tamanho;i++){
        if(nodo[j][i].conexo==1){
	      menor_peso=nodo[j][i].peso;                                   //primeira aresta do grafo com peso qualquer valido  	  
	      i=tamanho;
	      j=tamanho;
		}  
     }
   }
   /*fim achar primeiro valor valido para comecar o processo*/
   for(vezes=0;vezes<(tamanho*tamanho);vezes++){
     for(j=0;j<tamanho;j++){
       for(i=0;i<tamanho;i++){
	      if(nodo[j][i].conexo==1){
		    if(nodo[j][i].peso<=menor_peso){
			   printf("entrou.\n");
			   ja_add=0;
			   while((aux!=NULL)&&(ja_add!=1)){
			     aux=topo;
			     if((aux->de==j)&&(aux->para==1)){                      //verificar se aresta ja foi adicionada
                    ja_add=1;				 
				 }
				 else{
				    aux=aux->prox;
				 }   
			   }
			   printf("passou por aqui.\n");
			   if(ja_add==0){
			     printf("alguem inserido.\n");
			     menor_peso=nodo[j][i].peso;
			     de=j;
			     para=i;
			   }  
			 } 
		  }
	    }
      }
      if(lista_pesos==NULL){
	     aux->peso=menor_peso; 
         aux->de=de; 
         aux->para=para; 
         aux->prox=NULL;
         lista_pesos=aux;
         if(vezes==0){
           topo=lista_pesos;
	     } 
       }
       else{
	     aux->peso=menor_peso; 
         aux->de=de; 
         aux->para=para; 
         aux->prox=NULL;
         lista_pesos->prox=aux;
       } 
     }
   
   printf("saiu.\n");
   
   aux=topo;
   while(aux!=NULL){
      printf("aresta - [%d][%d] - peso - %d\n",aux->de,aux->para,aux->peso);
      aux=aux->prox;
   }
   
  return 0;
}
