#include <stdio.h>
#include <stdlib.h>

void troca(int *v, int i, int j) {
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

void imprimir(int *v, int n, int d) {
    for (int i = n; i < d; i++) {
        if (i < d - 1){
            printf("%d ", v[i]); // se i for menor que d - 1 ("indice n final") da espaço
        }else{
            printf("%d", v[i]); //se estiver no indice final, n dá espaço
        }
    }
    printf("\n"); // pula linha
}

int particiona(int *v, int n, int d, int p) {
    troca(v, p, d - 1); // pivô vai lá pro final
    int i = n - 1;
    for (int j = n; j < d - 1; j++) {
        if (v[j] <= v[d - 1]) {
            i++;
            troca(v, i, j);
        }
    }
    i++;
    troca(v, i, d - 1);
    return i;
}

void quickSortR(int *v, int n, int d) {
    if (n < d - 1) {
        int p = d - 1;
        p = particiona(v, n, d, p);
        printf("Pivo: [%d] %d\n", p, v[p]); // imprime o pivô e o indice dele e onde está percorrendo (foi oq entendi)
        // imprimir(v, n, d); imprime o quick sort
        quickSortR(v, n, p);
        quickSortR(v, p + 1, d);
    }
}

void quickSort(int *v, int n) {
    quickSortR(v, 0, n);
}

int main (){
  int n; // n tam do vetor e k o pivô
  scanf("%d", &n);
  
  int *v = malloc(sizeof (int) * n);
  for (int i = 0; i < n; i++) {
      scanf ("%d", &v[i]);
  }
  quickSort(v, n);
  imprimir(v, 0, n); // imprime o vetor final
  free(v);
  return 0;
}

/*
Exemplos:
10
2 5 6 8 2 63 100 1 34 3

ATENÇÃO: SÓ FUNCIONA COM NÚMEROS INTEIROS!
*/