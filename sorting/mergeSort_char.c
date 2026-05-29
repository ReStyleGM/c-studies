#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime(char **v, int n) {
    int i;
    for(i = 0; i < n; i++){
        printf("%s", v[i]);
        if(i < n - 1){
            printf(" ");
        }
    }
    printf("\n");
}

void intercala(char **v, int e, int m, int d){
    int i, j, k, n = d - e;
    char **vaux = (char **) malloc(sizeof(char *) * n);
    for(i = 0; i < n; i++){
        vaux[i] = (char *) malloc(sizeof(char) * 100);
    }
    for(i = 0, j = e, k = m; j < m && k < d; i++){

        if(strcmp(v[j], v[k]) < 0){
            strcpy(vaux[i], v[j]);
            j++;
        }
        else{
            strcpy(vaux[i], v[k]);
            k++;
        }
    }
    for(; j < m; i++, j++){
        strcpy(vaux[i], v[j]);
    }
    for(; k < d; i++, k++){
        strcpy(vaux[i], v[k]);
    }
    for(i = 0; i < n; i++){
        strcpy(v[e + i], vaux[i]);
    }
    for(i = 0; i < n; i++){
        free(vaux[i]);
    }
    free(vaux);
}

void mergeSortR(char **v, int e, int d){
    int meio;
    if(e < d - 1){
        meio = (e + d) / 2;
        mergeSortR(v, e, meio);
        mergeSortR(v, meio, d);
        intercala(v, e, meio, d);
        // imprime(v, d); // para visualizar as intercalações
    }
}

void mergeSort(char **v, int n){
    mergeSortR(v, 0, n);
}

int main(){
    char **v, aux[100];
    int n, i;
    scanf("%d", &n);
    v = (char **) malloc(sizeof(char *) * n);
    if(v == NULL){
        return 1;
    }

    for(i = 0; i < n; i++){
        scanf("%s", aux);
        v[i] = (char *) malloc(sizeof(char) * (strlen(aux) + 1));
        if(v[i] == NULL){
            return 1;
        }
        strcpy(v[i], aux);
    }
    mergeSort(v, n);
    imprime(v, n);
    for(i = 0; i < n; i++){
        free(v[i]);
    }
    free(v);
    return 0;
}

/*
Exemplo:
5
banana uva maca pera abacaxi

ATENÇÃO: SÓ FUNCIONA EM ESCRITA, NÃO COM NÚMEROS!
*/