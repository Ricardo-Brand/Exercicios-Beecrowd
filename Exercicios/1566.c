#include <stdio.h>
#include <stdlib.h>

void merge(int vet[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;  // Tamanho da primeira metade
    int n2 = fim - meio;         // Tamanho da segunda metade

    int *esquerda = malloc(n1 * sizeof(int));       // Vetores auxiliares para armazenar as metades
    int *direita = malloc(n2 * sizeof(int));   

    // Copiar os dados para os vetores auxiliares
    for (int i = 0; i < n1; i++)
        esquerda[i] = vet[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = vet[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    // Mesclar os vetores auxiliares de volta no vetor original
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vet[k++] = esquerda[i++];
        } else {
            vet[k++] = direita[j++];
        }
    }

    while (i < n1) vet[k++] = esquerda[i++];
    while (j < n2) vet[k++] = direita[j++];

    free(esquerda);
    free(direita);
}

void merge_sort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(vet, inicio, meio);        // Ordenar a primeira metade
        merge_sort(vet, meio + 1, fim);       // Ordenar a segunda metade

        merge(vet, inicio, meio, fim);        // Mesclar as duas metades ordenadas
    }
}

int main(){
    int num_casos, pessoas;

    scanf("%d", &num_casos);

    while(num_casos--){
        int i = 0;
        scanf("%d", &pessoas);

        int *vet = malloc(pessoas * sizeof(int));

        if(vet == NULL){
            return 1;
        }
        
        for(int j = 0; j < pessoas; j++){
            scanf("%d", &vet[i++]);
        }

        merge_sort(vet, 0, i - 1);

        for (int j = 0; j < i; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", vet[j]);
        }
        printf("\n");
        free(vet);
    }

    
    return 0;
}