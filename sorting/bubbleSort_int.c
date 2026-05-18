#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int n) {
  int i;
  for(i = 0; i<n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
}

void insercao (int *v, int n){
  int i, j, x, total = 0, total_s = 0;
  for(i = 0; i < n-1; i++){
    for(j=0; j < n-1-i; j++){
      if(v[j] > v[j+1]){
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
  printf("Total de IFs satisfeitos: %d", total_s); // total de trocas que foram realizadas com sucesso
}

int main(){
    int *v, n, i;
    scanf("%d", &n);
    v = (int *) malloc(sizeof(int) * n);
    if(v == NULL){
      return 1;
    }
    for(i=0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    insercao(v, i);
    free(v);
}

/*
Exemplo que pode ser realizado na execução:
10
2 4 6 8 10 1 3 5 7 9

ATENÇÃO: SÓ FUNCIONA PARA INTEIROS
*/