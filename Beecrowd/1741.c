//
//  main.c
//  notacao-reversa
//
//  Created by Ricardo Augusto da Silva Brandão on 19/03/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 2000001

void pilha(char *c, int tamanho) {
    int topo, a, b;
    bool zero = false, invalid = false;
    int *valor = (int *)malloc(tamanho * sizeof(int)); // sistema operacional aloca um espaço na memória com o valor de tamanho

    if (valor == NULL) {
        return;
    }

    a = 0;
    b = 0;
    topo = -1;

    if (tamanho % 2 == 1) {
        for (int i = tamanho - 1; i >= 0; i--) {
            if (isdigit(c[i])) { // caso o char seja um digito, ele entra na pilha
                valor[++topo] = c[i] - '0';
            }
            else if (c[i] == '*' || c[i] == '/' || c[i] == '+' || c[i] == '-') { // se o char for um operando, ele retira dois valores da string e faz a conta
                if (topo < 1) { // se caso tiver apenas um valor na string, ele retorna invalid
                    invalid = true;
                    break;
                }
                a = valor[topo--];
                b = valor[topo--];

                if (c[i] == '/' && a == 0) {
                    zero = true;
                    a = 1;  // Para evitar divisão por zero, substituímos por 1 temporariamente
                }

                switch (c[i]) {
                    case '*':
                        valor[++topo] = a * b;
                        break;
                    case '/':
                        valor[++topo] = b / a;
                        break;
                    case '-':
                        valor[++topo] = b - a;
                        break;
                    case '+':
                        valor[++topo] = b + a;
                        break;
                }
            }
            else {
                invalid = true;
                break;
            }
        }
    }
    else if (c[0] == '\0') {
        free(valor);
        return;  // Linha vazia, sem expressão
    }
    else {
        invalid = true;
    }

    if (invalid || topo != 0) {
        printf("\nInvalid expression.\n");
    }
    else if (zero && invalid == false) {
        printf("\nDivision by zero.\n");
    }
    else if (topo == 0) {
        printf("\nThe answer is %d.\n", valor[0]);
    }

    free(valor);
    return;
}

int main() {
    char *valor = (char *)malloc(MAX * sizeof(char)); // sistema operacional aloca um espaço na memória com o valor de MAX
    char *conta = (char *)malloc(MAX * sizeof(char)); // sistema operacional aloca um espaço na memória com o valor de MAX
    int i;

    if (valor == NULL || conta == NULL) { // caso não consiga achar um espaço válido, retorna 0
        return 0;
    }
    printf("Digite uma conta em formato de pilha, por exemplo '+ 2 + 2 2', sera lido da direita para esquerda, e sera feita a conta\nDigite sua conta: ");

    while (fgets(valor, MAX, stdin) != NULL) {
        i = strlen(valor);
        if (i > 0 && valor[i - 1] == '\n') { // tira os espaços da string
            valor[i - 1] = '\0';
            i--;
        }

        int k = 0;
        for (int j = 0; valor[j] != '\0'; j++) {
            if (valor[j] != ' ') {
                conta[k] = valor[j];
                k++;
            }
        }
        conta[k] = '\0';

        pilha(conta, k);  // Processa a expressão após eliminar espaços
        
        printf("\nDigite um novo valor: ");
    }

    free(valor);
    free(conta);

    return 0;
}
