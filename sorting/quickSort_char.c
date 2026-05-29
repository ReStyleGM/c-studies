#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char **v, int i, int j) {
    char *aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void imprimir(char **v, int n, int d) {
    for (int i = n; i < d; i++) {
        if (i < d - 1){
            printf("%s ", v[i]); // se i for menor que d - 1 ("indice n final") da espaço
        }else{
            printf("%s", v[i]); //se estiver no indice final, n dá espaço
        }
    }
    printf("\n");
}

int particiona(char **v, int n, int d, int p) {
    troca(v, p, d - 1); // pivô vai pro final
    int i = n - 1;
    for (int j = n; j < d - 1; j++) {
        if (strcmp(v[j], v[d - 1]) <= 0) {
            i++;
            troca(v, i, j);
        }
    }
    i++;
    troca(v, i, d - 1);
    return i;
}

void quickSortR(char **v, int n, int d) {
    if (n < d - 1) {
        int p = d - 1;
        p = particiona(v, n, d, p);
        printf("Pivo: [%d] %s\n", p, v[p]); // imprime o pivô e o indice dele e onde está percorrendo
        // imprimir(v, n, d); imprime o quick sort completo
        quickSortR(v, n, p);
        quickSortR(v, p + 1, d);
    }
}

void quickSort(char **v, int n) {
    quickSortR(v, 0, n);
}

int main (){
    int n; // n tam do vetor
    scanf("%d", &n);
    char **v = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        char aux[100];
        scanf("%s", aux);
        v[i] = malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(v[i], aux);
    }
    quickSort(v, n);
    imprimir(v, 0, n); // imprime o vetor final (resultado)
    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
    return 0;
}

/*
Exemplos:
5
banana uva maca pera abacaxi

ATENÇÃO: SÓ FUNCIONA COM PALAVRAS SEM ESPAÇOS! E NÃO NÚMEROS!!!!
*/