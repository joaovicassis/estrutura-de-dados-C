#include <stdio.h>
#include <string.h>
#include "pilha.h"

int casa_caracter(char c, char t){
  if(c == '(' && t == ')') return 1;
  if(c == '[' && t == ']') return 1;
  if(c == '{' && t == '}') return 1;
  return 0;
}

int main(){
  pilha P = criar_pilha();
  char sequencia[100];
  
  scanf("%s", sequencia);
  
  for(int i = 0; i < strlen(sequencia); i++){
    char c = sequencia[i];
    if(c == '(' || c == '[' || c == '{'){
      empilhar(P, c);
    }else if(c == ')' || c == ']' || c == '}'){
      if(pilha_vazia(P)){
        printf("Sequencia desbalanceada!\n");
        return 0;
      }
      char topo = desempilhar(P);
      if(casa_caracter(topo, c) == 0){
      	printf("Sequencia desbalanceada!\n");
      	return 0;
      }
    }
  }
  
  if(pilha_vazia(P)){
    printf("Sequencia balanceada!\n");
  }else{
    printf("Sequencia desbalanceada!\n");
  }
  
  liberar_pilha(P);
  return 0;
}
