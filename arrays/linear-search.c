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

// conta quantas vezes o elemento aparece no vetor
int ocorrencias(int *v, int n, int x){
    int i, cont = 0;
    for(i = 0; i < n; i++){
        if(v[i] == x){ // se encontrar o elemento x (exemplo: 5) no vetor 
            cont++; // adiciona na ocorrencia (contador)
        }
    }
    return cont;
}

// imprime todas as posições onde o elemento foi encontrado
void posicoes(int *v, int n, int x){
    int i;
    printf("Posicoes: ");
    for(i = 0; i < n; i++){
        if(v[i] == x){
            printf("%d ", i); // imprime
        }
    }

    printf("\n");
}

int main(){
    int *v;
    int n, i, x;
    scanf("%d", &n);
    v = (int *) malloc(sizeof(int) * n); // aloca memória para o vetor v

    if(v == NULL){
        return 1; // se o vetor for nulo, retorna 1
    }

    // lê os elementos do vetor v
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    scanf("%d", &x); // elemento que será procurado na ocorrencia
    imprime(v, n);

     // imprime se às ocorrencias forem maior que 0, caso não, não encontrou o elemento
    if(ocorrencias(v, n, x) > 0){
        printf("Elemento encontrado.\n");
        posicoes(v, n, x);
        printf("Ocorrencias: %d\n", ocorrencias(v, n, x));
    }
    else{
        printf("Elemento nao encontrado.\n");
    }

    free(v);  // libera a memória do vetor v
    return 0;
}

/*
ATENÇÃO: CÓDIGO SOMENTE PARA INTEIROS!
Exemplo de input:
6
1 5 2 5 7 5
5

Saída:
1 5 2 5 7 5
Elemento encontrado.
Posicoes: 1 3 5
Ocorrencias: 3
*/