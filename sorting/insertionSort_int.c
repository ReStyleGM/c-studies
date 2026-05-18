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
  int i, j, x, desl = 0;
  for(j = 1; j < n; j++){
    x = v[j];
    // insere v[j] na sequência ordenada v[0... j -1] 
    i = j - 1;
    while(i >= 0 && v[i] > x){
      v[i+1] = v[i];
      // imprime(v, n); para imprimir todos os deslocamentos
      i -= 1;
      desl += 1;
    }
    v[i+1] = x;
  }
  imprime(v, n);
  printf("Deslocamentos: %d", desl);
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
ATENÇÃO: CÓDIGO SOMENTE PARA INTEIROS!
Exemplo de input:
10
2 4 6 8 10 1 3 5 7 9
*/