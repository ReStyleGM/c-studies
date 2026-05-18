#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
}

void intercala(int *v, int e, int m, int d) {
 int i, j, k, n=d-e;
 int *vaux = malloc (sizeof (int) * n);
 for (i=0, j=e, k=m; j<m && k<d; i++) {
    if (v[j] < v[k]) {
        vaux[i] = v[j++];
    }
    else {
        vaux[i] = v[k++];
    }
 }
 for (; j<m; i++,j++) {
      vaux[i] = v[j];
 }
 for (; k<d; i++,k++) {
      vaux[i] = v[k];
 }
 // imprimir(vaux,n); para verificar todo o mergeSort (intercalação)
 for (i=0; i < n; i++) {
      v[e+i] = vaux[i];
 }
 free (vaux);
}

void mergeSortR(int *v, int e, int d) {
 int meio;
 if (e < d-1) {
   meio = (e+d) / 2;
   mergeSortR (v, e, meio);
   mergeSortR (v, meio, d);
   intercala (v, e, meio, d);
 }
}

void mergeSort (int *v, int n) {
    mergeSortR (v, 0, n);
}

int main () {
    int n, i;
    scanf ("%d", &n);
    int *v = malloc (sizeof (int) * n);
    for (i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    mergeSort (v, n);
    imprimir(v,n);
    free (v);
    return 0;
}


/*
Exemplo:
10
9 7 4 11 26 29 81 90 33 2

ATENÇÃO: SOMENTE PARA NÚMEROS INTEIROS!
*/