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

void insercao(char **v, int n) {
    int i, j, desl = 0;
    char *x;
    for(j = 1; j < n; j++) {
        x = v[j];
        // insere v[j] na parte ordenada
        i = j - 1;
        while(i >= 0 && strcmp(v[i], x) > 0) {
            v[i + 1] = v[i];
            // imprime(v, n); Para imprimir todos as separações
            i--;
            desl++;
        }
        v[i + 1] = x;
    }
    imprime(v, n);
    printf("Deslocamentos: %d\n", desl);
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
    insercao(v, n);
    for(i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
    return 0;
}

/*
Exemplo que pode ser realizado na execução:
5
banana uva maca pera abacaxi
ATENÇÃO: SÓ FUNCIONA PARA TEXTO SEM ESPAÇOS!!!
*/
