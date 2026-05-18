#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime(char **v, int n) {
  int i;
  for(i = 0; i<n; i++){
    printf("%s ", v[i]);
  }
  printf("\n");
}

void insercao (char **v, int n){
  int i, j, total = 0, total_s = 0;
  char *x;

  for(i = 0; i < n-1; i++){
    for(j=0; j < n-1-i; j++){
      if(strcmp(v[j], v[j+1]) > 0){
        x = v[j];
        v[j] = v[j+1];
        v[j+1] = x;
        total_s++;
        // imprime(v, n); para imprimir todas as linhas do bubble
      }
      total++;
    }
  }
  imprime(v, n);
  printf("Total de IFs executados: %d \n", total); // total de trocas realizadas
  printf("Total de IFs satisfeitos: %d", total_s); // total de vezes que o IF foi verdadeiro
}

int main(){
    char **v, aux[100];
    int n, i;
    scanf("%d", &n);
    v = (char **) malloc(sizeof(char *) * n);
    if(v == NULL){
      return 1;
    }
    for(i=0; i < n; i++) {
      scanf("%s", aux);
      v[i] = (char *) malloc(sizeof(char) * (strlen(aux) + 1));
      if(v[i] == NULL){
        return 1;
      }
      strcpy(v[i], aux);
    }
    insercao(v, i);
    for(i = 0; i < n; i++){
      free(v[i]); // libera todas as palavras uma por uma
    }
    free(v); // libera vetor principal
}

/*
Exemplo que pode ser realizado na execução:
5
banana uva maca pera abacaxi
ATENÇÃO: SÓ FUNCIONA PARA TEXTO SEM ESPAÇOS!!!
*/