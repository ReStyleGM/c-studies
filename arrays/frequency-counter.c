#include <stdio.h>
#include <stdlib.h>

// imprime todos os elementos do vetor
void imprime(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

// verifica se já foi contado algum elemento do vetor
int jaContado(int *v, int posicao){
    int i;
    for(i = 0; i < posicao; i++){
        if(v[i] == v[posicao]){
            return 1;
        }
    }

    return 0;
}

// conta quantidades de vezes que um número apareceu no vetor
int frequencia(int *v, int n, int x){
    int i, cont = 0;
    for(i = 0; i < n; i++){
        if(v[i] == x){
            cont++;
        }
    }
    return cont;
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
    imprime(v, n);
    printf("Frequencia dos elementos:\n");
    
    for(i = 0; i < n; i++){
        if(!jaContado(v, i)){ // se o elemento já não foi contado
            printf("%d -> %d vez(es)\n", v[i],
                   frequencia(v, n, v[i]));
        }
    }
    free(v); // libera a memória do vetor v
    return 0;
}

/*
ATENÇÃO: CÓDIGO SOMENTE PARA NÚMEROS INTEIROS!

Exemplo de entrada:
8
1 2 1 3 2 1 4 2

*a saída ficou meio grande*
*/