#include <stdio.h>
#include <stdlib.h>
#define TOTALVERTICES 8

typedef struct item{
	int campo;
	struct item* prox;
}ITEM;

ITEM lista[TOTALVERTICES+1];

void Imprimir(ITEM *lista);
void Inserir_Aresta(ITEM *lista, int a, int b); 

int main(int argc, char *argv[]){
  int i,a,b;
  FILE *fp;
  fp = fopen("teste01.txt","r");
  if (!fp) {
    printf("Erro ao abrir o arquivo %s.\n",argv[1]);
    return 0;
  }
  
  // inicia a lista de adjacencia 
  for(i=1; i<=TOTALVERTICES; i++){
    lista[i].campo = 0;
    lista[i].prox = NULL;
  }
        
  // le vertices (a,b)
  fscanf(fp,"%d %d", &a, &b);
  while (!feof(fp)) {
    Inserir_Aresta(lista,a,b);
    Inserir_Aresta(lista,b,a);
    fscanf(fp,"%d%d", &a, &b);
  }

  Imprimir(lista);
  return 0;
}


void Imprimir(ITEM *lista){
  int i;
  ITEM * tmp;
  for(i=1; i<=TOTALVERTICES; i++) {
    tmp = lista[i].prox;
    printf("%2d: (%d) ==>", i, lista[i].campo);
    while (tmp != NULL) {
      printf("%d  ", tmp->campo);
      tmp = tmp->prox;
    }
    printf("\n");
  }
}

void Inserir_Aresta(ITEM *lista, int a, int b){
  ITEM *aux;
  ITEM *tmp;
 
  aux = (ITEM*) malloc((int)sizeof(ITEM)); 
  aux->campo = b;
  aux->prox = NULL;
  
  lista[a].campo++;
  if(lista[a].prox == NULL)
    lista[a].prox = aux;
  else	{
    tmp = lista[a].prox;
    if (tmp->campo > b) {
      aux->prox = tmp;
      lista[a].prox = aux;
    } 		          
    else if (tmp->prox == NULL) { 
      aux->prox = tmp->prox;
      tmp->prox = aux;  
    }
    else {
      while((tmp->prox != NULL) &&(tmp->prox->campo < b))
	tmp = tmp->prox;
      aux->prox = tmp->prox;
      tmp->prox = aux;  
    }
  }
}


