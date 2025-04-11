#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int num_casos;
    int tamanhos[100];
    int ordem_original[100];
    char string[10000], aux[51];
    char palavras[50][51]; // 50 palavras e 51 caracteres

    scanf("%d", &num_casos);
    getchar(); 

    while(num_casos--) {
        fgets(string, sizeof(string), stdin); 

        string[strcspn(string, "\n")] = '\0';

        int contador = 0;

        char *token = strtok(string, " ");
        while (token != NULL && contador < 50) {
            strcpy(palavras[contador], token);
            tamanhos[contador] = strlen(token);
            ordem_original[contador] = contador;  
            contador++;
            token = strtok(NULL, " ");
        }

       
        for (int i = 0; i < contador - 1; i++) {
            for (int k = i + 1; k < contador; k++) {
            
                if (tamanhos[i] < tamanhos[k] || 
                   (tamanhos[i] == tamanhos[k] && ordem_original[i] > ordem_original[k])) {
 
                    strcpy(aux, palavras[i]);
                    strcpy(palavras[i], palavras[k]);
                    strcpy(palavras[k], aux);
                    
                  
                    int temp = tamanhos[i];
                    tamanhos[i] = tamanhos[k];
                    tamanhos[k] = temp;
                    
                   
                    temp = ordem_original[i];
                    ordem_original[i] = ordem_original[k];
                    ordem_original[k] = temp;
                }
            }
        }

       
        for(int i = 0; i < contador; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%s", palavras[i]);
        }
        printf("\n");
    }

    return 0;
}
