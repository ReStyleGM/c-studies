#include <stdio.h>
#include <stdlib.h>

// imprime o vetor
void imprime(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

// realiza a busca binária em um vetor ordenado
int buscaBinaria(int *v, int n, int x){
    int inicio = 0;
    int fim = n - 1;
    int meio;
    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(v[meio] == x){
            return meio;
        }
        if(v[meio] < x){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    return -1;
}

int main(){
    int *v;
    int n, i, x;
    int posicao;
    scanf("%d", &n);

    v = (int *) malloc(sizeof(int) * n); // aloca a memória no vetor com n tamanho
    if(v == NULL){
        return 1;
    }

    
    for(i = 0; i < n; i++){ // lê os elementos do vetor v
        scanf("%d", &v[i]);
    }

    scanf("%d", &x); // identifica o elemento procurado pelo usuário
    imprime(v, n);
    posicao = buscaBinaria(v, n, x);

    if(posicao != -1){
        printf("Elemento encontrado na posicao %d\n", posicao);
    }
    else{
        printf("Elemento nao encontrado.\n");
    }
    free(v); // libera a memória do vetor v
    return 0;
}

/*
ATENÇÃO: TEM QUE ESTAR ORDENADO (NÃO TEM NENHUM SORT)
Exemplo de entrada:
7
1 3 5 7 9 11 13
9

Saida:
1 3 5 7 9 11 13
Elemento encontrado na posicao 4
*/