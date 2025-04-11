#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int num_linha, tamanho_mina, inicio_diamante, fim_diamante, diamantes, contador;
    char mina[1001];

    scanf("%d", &num_linha);

    while(num_linha--){
        diamantes = 0;
        contador = 0;
        inicio_diamante = -1;
        fim_diamante = -1;

        scanf("%s", mina);

        tamanho_mina = strlen(mina);
        mina[tamanho_mina] = '\0';
       
        while(contador < tamanho_mina){
            if(mina[contador] == '<'){
                inicio_diamante = contador;
            }
            else if(mina[contador] == '>' && inicio_diamante >= 0){
                fim_diamante = contador;
                diamantes++;
                mina[inicio_diamante] = '.';
                mina[fim_diamante] = '.';
                contador = 0;
                inicio_diamante = -1;
                fim_diamante = -1;
                continue;
            }

            contador++;
        }
        printf("%d\n", diamantes);
    }

    return 0;
}