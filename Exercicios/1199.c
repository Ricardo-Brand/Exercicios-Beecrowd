//
//  main.c
//  conversor-base
//
//  Created by Ricardo Augusto da Silva Brandão on 18/03/25.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void dec_hex(char v[]){ // converte o numero de hexadecimal para decimal
    int numero, i, resto;
    numero = atoi(v);
    if(numero == 0) { // verifica se a entrada é igual a 0
        return;
    }
    
    i = 0;
    char hexa[20], hexa_x[20];
    while(numero > 0){
        resto = numero % 16;
        if(resto < 10){ // se o resto for menor que 10 ele adiciona o número a string
            hexa[i++] = '0' + resto;
        }
        else{
            hexa[i++] = 'A' + (resto - 10); // se o numero for maior ou igual a 10, adiciona a letra correspondente aquele numero a string
        }
        numero /= 16;
    }
    hexa[i] = '\0'; // sinaliza o final da string
    
    for(int j=0;j<i;j++){
        hexa_x[j] = hexa[i - j - 1]; // inverte a string
    }
    
    hexa[i] = '\0'; // sinaliza novamente o fim da string
    
    printf("\n0x%s\n\n", hexa_x);
}

void hex_dec(char v[]){
    int tamanho, total, numero;
    total = 0;
    numero = 0;
    
    tamanho = strlen(v);
    v[tamanho] = '\0';
    for(int i = 0; i <= (tamanho - 3); i++){
        if(isdigit(v[tamanho - i - 1])){ // verifica se o que está armazenado naquele char é um digito
            numero = v[tamanho - i - 1] - '0';
        }
        else { // caso seja não um digito, então é uma letra, e verifica qual letra é
            switch(v[tamanho - i - 1]){
                case 'A':
                    numero = 10;
                    break;
                case 'B':
                    numero = 11;
                    break;
                case 'C':
                    numero = 12;
                    break;
                case 'D':
                    numero = 13;
                    break;
                case 'E':
                    numero = 14;
                    break;
                case 'F':
                    numero = 15;
                    break;
                case 'a':
                    numero = 10;
                    break;
                case 'b':
                    numero = 11;
                    break;
                case 'c':
                    numero = 12;
                    break;
                case 'd':
                    numero = 13;
                    break;
                case 'e':
                    numero = 14;
                    break;
                case 'f':
                    numero = 15;
                    break;
                default:
                    break;
            }
            
        }
        total += (numero * pow(16,i)); 
    }
    
    printf("\n%d\n\n", total);
}

int main(){
    char valor[20];
    
    while(1){
        printf("1 - Para escolher se quer converter um hexa em dec, comece com 0x, caso contrário escreva o numero em decimal\n2 - Para sair digite um numero negativo\n\nDigite: ");
        scanf("%s", valor);
        
        if(valor[0] == '-'){
            return 0;
        }
        
        if(valor[0] == '0' && valor[1] == 'x'){
            hex_dec(valor);
        }
        else{
            dec_hex(valor);
        }

    }
    
    return 0;
}
