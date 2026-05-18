#include <stdio.h>
#include <stdlib.h>

void troca(int *v, int i, int j) {
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

int particionaSimplificado(int *v, int n, int k) {
   troca(v, k, n - 1); // com o pivô
   int j=0, i = -1;
   while (j < n-1) {
     if (v[j] <= v[n-1]) {
        i++;
        troca(v, i, j);
     }
     j++;
   }
   i++;
   troca (v, i, n-1);
   return i;
}


int main (){
  int n, k; // n tam do vetor e k o pivô
  scanf("%d %d", &n, &k);
  
  int *v = malloc(sizeof (int) * n);
  for (int i = 0; i < n; i++) {
      scanf ("%d", &v[i]);
  }
  
  int p = particionaSimplificado(v, n, k); // vai pegar a posição do pivô
  printf("%d\n", p); //imprime o indice do pivô
  
  for(int i = 0; i < n; i++){ //imprime vetor
        printf("%d", v[i]);
        if (i < n - 1){
          printf(" ");
        } 
    }
    printf("\n");
  free(v);
}

/*
Exemplo:
10 5
10 9 8 7 6 5 4 3 2 1

ATENÇÃO: SOMENTE FUNCIONA PARA INTEIROS!!!
*/