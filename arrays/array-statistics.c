#include <stdio.h>
#include <stdlib.h>

// imprime cada elemento do vetor
void imprime(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

// retorna o maior elemento do vetor v
int maior(int *v, int n){
    int i, maior = v[0];
    for(i = 1; i < n; i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
    return maior;
}

// retorna o menor elemento do vetor v
int menor(int *v, int n){
    int i, menor = v[0];
    for(i = 1; i < n; i++){
        if(v[i] < menor){
            menor = v[i];
        }
    }
    return menor;
}

// somatoria de todos os elementos dentro do vetor v
int soma(int *v, int n){
    int i, soma = 0;
    for(i = 0; i < n; i++){
        soma += v[i]; // incrementa na soma (e soma) todos os elementos do vetor
    }
    return soma;
}

// quantos pares existem nos elementos de v
int pares(int *v, int n){
    int i, cont = 0;
    for(i = 0; i < n; i++){
        if(v[i] % 2 == 0){ // se o resto de divisão de dois for 0 (é par)
            cont++; // incrementa no contador
        }
    }
    return cont;
}

// quantos impares existem nos elementos de v
int impares(int *v, int n){
    int i, cont = 0;
    for(i = 0; i < n; i++){
        if(v[i] % 2 != 0){ // se for diferente de 0 o resto de divisão de 2 (é impar)
            cont++; // incrementa no contador
        }
    }
    return cont;
}

int main(){
    int *v;
    int n, i;
    int total;
    float media;
    scanf("%d", &n);
    v = (int *) malloc(sizeof(int) * n);
    
    if(v == NULL){
        return 1;
    }
    // leitura dos elementos do vetor v
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    total = soma(v, n);
    media = (float) total / n; // calcula a media

    // MOSTRA OS VALORES
    printf("Maior: %d\n", maior(v, n));
    printf("Menor: %d\n", menor(v, n));
    printf("Soma: %d\n", total);
    printf("Media: %.2f\n", media);
    printf("Quantidade de pares: %d\n", pares(v, n));
    printf("Quantidade de impares: %d\n", impares(v, n));
    free(v); // libera a memoria do vetor
    return 0;
}

/*
Exemplo de input:
5
7 2 9 1 4

Saida:

Maior: 9
Menor: 1
Soma: 23
Media: 4.60
Quantidade de pares: 2
Quantidade de impares: 3
*/