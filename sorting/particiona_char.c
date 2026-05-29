#include <stdio.h>
#include <stdlib.h>

void troca(char *v, int i, int j) {
    char aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particionaSimplificado(char *v, int n, int k) {
    troca(v, k, n - 1); // troca o pivô para o final
    int j = 0, i = -1;
    while (j < n - 1) {
        if (v[j] <= v[n - 1]) {
            i++;
            troca(v, i, j);
        }
        j++;
    }
    i++;
    troca(v, i, n - 1);
    return i;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char *v = malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &v[i]);
    }
    int p = particionaSimplificado(v, n, k);
    printf("%d\n", p);
    for (int i = 0; i < n; i++) {
        printf("%c", v[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    free(v);
}

/*
Exemplo:
10 5
j i h g f e d c b a
*/