#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int vet[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;  // Tamanho da primeira metade
    int n2 = fim - meio;         // Tamanho da segunda metade

    int esquerda[n1], direita[n2];     // Vetores auxiliares para armazenar as metades

    // Copiar os dados para os vetores auxiliares
    for (int i = 0; i < n1; i++)
        esquerda[i] = vet[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = vet[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    // Mesclar os vetores auxiliares de volta no vetor original
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vet[k] = esquerda[i];
            i++;
        } else {
            vet[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes, se houver
    while (i < n1) {
        vet[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {
        vet[k] = direita[j];
        j++;
        k++;
    }
}

void merge_sort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(vet, inicio, meio);        // Ordenar a primeira metade
        merge_sort(vet, meio + 1, fim);       // Ordenar a segunda metade

        merge(vet, inicio, meio, fim);        // Mesclar as duas metades ordenadas
    }
}

int main() {
    unsigned int num_linhas;

    scanf("%d", &num_linhas);

    unsigned int stack[num_linhas], valores, topo;
    unsigned int pares[num_linhas], impares[num_linhas], topo_par, topo_impar;
    topo = -1;
    topo_par = -1;
    topo_impar = -1;

    while (num_linhas--) {
        scanf("%d", &valores);
        stack[++topo] = valores;
    }

    for (int i = 0; i <= topo; i++) {
        if (stack[i] % 2 == 0) {
            pares[++topo_par] = stack[i];
        } else {
            impares[++topo_impar] = stack[i];
        }
    }

    merge_sort(pares, 0, topo_par);

    merge_sort(impares, 0, topo_impar);

    for (int i = 0; i <= topo_par; i++) {
        printf("%d\n", pares[i]);
    }

    for (int i = topo_impar; i >= 0; i--) {
        printf("%d\n", impares[i]);
    }

    return 0;
}