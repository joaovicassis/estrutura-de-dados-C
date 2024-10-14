#include <stdlib.h>
#include "pilha.h"

typedef struct elem{
  char dado;
  struct elem * prox;
}elemento;

struct pilhaa{
  elemento * topo;
};

pilha criar_pilha(){
  pilha P = (pilha) malloc(sizeof(struct pilhaa));
  P->topo = NULL;
  return P;
}

void empilhar(pilha P, char c){
  elemento * e = (elemento *) malloc(sizeof(elemento));
  e->dado = c;
  e->prox = P->topo;
  P->topo = e;
  return;
}

char desempilhar(pilha P){
  elemento * T = P->topo;
  char r = T->dado;
  P->topo = T->prox;
  free(T);
  return r;
}

int pilha_vazia(pilha P){
  if(P == NULL) return 1;
  if(P->topo == NULL) return 1;
  return 0;
}

void liberar_lista_elementos(elemento * e){
  if(e == NULL) return;
  
  liberar_lista_elementos(e->prox);
  free(e);
}

void liberar_pilha(pilha P){
  liberar_lista_elementos(P->topo);
  free(P);
}



































