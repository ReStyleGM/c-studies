#include <stdio.h>
#include <stdlib.h>
void imprime(int *v, int n) {
  int i;
  for(i = 0; i<n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
}

void ordena (int *v, int n){
  int i, j, min, total = 0;
  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i+1; j < n; j++){ // procura o indice do i-esimo "menor" elemento
      if(v[j] < v[min]){
        min = j;
      }
      total += 1;
    }
    // ajusta i-esimo menor na posição i
    int aux = v[i];
    v[i] = v[min];
    v[min] = aux;
    // imprime(v, n); para pegar todos as ordenações
  }
  imprime(v, n);
  printf("Total de IFs executados: %d", total);
}

int main()
{
    int *v, n, i;
    scanf("%d", &n);
    v = (int *) malloc(sizeof(int) * n);
    if(v == NULL){
      return 1;
    }
    for(i=0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    ordena(v, i);
    free(v);
}

/*
Exemplo:
5
1 7 90 20 30
ATENÇÃO: SOMENTE PARA NÚMEROS INTEIROS!
*/
