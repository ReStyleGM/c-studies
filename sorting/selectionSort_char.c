#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime(char **v, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%s ", v[i]);
    }
    printf("\n");
}

void ordena(char **v, int n) {
    int i, j, min, total = 0;
    char *aux;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) { // procura o índice do menor texto
            if(strcmp(v[j], v[min]) < 0) {
                min = j;
            }
            total += 1;
        }
        aux = v[i]; // troca os ponteiros
        v[i] = v[min];
        v[min] = aux;
        // imprime(v, n); para adquirir todas as trocas feitas
    }
    imprime(v, n);
    printf("Total de IFs executados: %d\n", total);
}

int main() {
    char **v, aux[100];
    int n, i;
    scanf("%d", &n);
    v = (char **) malloc(sizeof(char *) * n);
    if(v == NULL) {
        return 1;
    }
    for(i = 0; i < n; i++) {
        scanf("%s", aux);
        v[i] = (char *) malloc(sizeof(char) * (strlen(aux) + 1));
        if(v[i] == NULL) {
            return 1;
        }
        strcpy(v[i], aux);
    }
    ordena(v, n);
    for(i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
    return 0;
}
/*
Exemplo:
5
banana uva maca pera abacaxi
*/