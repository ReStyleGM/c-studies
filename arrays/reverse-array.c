#include <stdio.h>
#include <stdlib.h>

// imprime o vetor v
void imprime(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void inverter(int *v, int n){
    int i, aux;
    for(i = 0; i < n / 2; i++){ // faz a inversão
        aux = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = aux;
    }
}

int main(){
    int *v;
    int n, i;
    scanf("%d", &n);
    v = (int *) malloc(sizeof(int) * n); // aloca a memória no vetor com n tamanho
    
    if(v == NULL){
        return 1;
    }
    for(i = 0; i < n; i++){ // lê os elementos do vetor v
        scanf("%d", &v[i]);
    }

    printf("Vetor padrão:\n");
    imprime(v, n);
    inverter(v, n);
    printf("Vetor invertido:\n");
    imprime(v, n);
    
    free(v); // libera a memória do vetor v
    return 0;
}

/*
ATENÇÃO: CÓDIGO SOMENTE PARA NÚMEROS INTEIROS!

Exemplo de entrada:
5
1 2 3 4 5

Saída:
Vetor padrão:
1 2 3 4 5

Vetor invertido:
5 4 3 2 1
*/