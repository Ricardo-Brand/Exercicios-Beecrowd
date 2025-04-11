//
//  main.c
//  divisor-binario
//
//  Created by Ricardo Augusto da Silva Brandão on 19/03/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

long divi(long divisor){
    char vetor[13];
    long num = 0;
    int i = 0, exp10, potencia2;
    
    if(divisor == 1){
        return 1;
    }
    
    exp10 = log10(divisor);
    potencia2 = pow(2, exp10);
    num = pow(10, exp10);
    
    sprintf(vetor, "%ld", num);
    i = strlen(vetor);
    vetor[i] = '\0';
    
    for(int j=potencia2;j>=0;j--){
        if(num % divisor == 0){
            return num;
        }
        if(vetor[i-1] == '0' && vetor[i-2] == '0'){ // adiciona 1 no primeiro valor
            vetor[i-1] = '1';
            num = atol(vetor);
        }
        else if(vetor[i-1] == '1' && vetor[i-2] == '0'){ // adiciona 1 no segundo valor e 0 no primeiro
            vetor[i-1] = '0';
            vetor[i-2] = '1';
            num = atol(vetor);
        }
        else if(vetor[i-1] == '0' && vetor[i-2] == '1'){ // adiciona 1 no primeiro e segundo valor
            vetor[i-1] = '1';
            vetor[i-2] = '1';
            num = atol(vetor);
        }
        else if(vetor[i-1] == '1' && vetor[i-2] == '1'){ // caso o primeiro e o segundo valor sejam 1 , adiciona 1 nos valores seguintes, até encontrar o divisor
            for(int k=i-1;k>0;k--){
                if(vetor[k] == '0'){
                    vetor[k] = '1';
                    num = atol(vetor);
                    break;
                }
                else{
                    vetor[k] = '0';
                }
            }
        }
    }
    while(potencia2 != 2048){
        exp10++;
        potencia2 = pow(2, exp10);
        num = pow(10, exp10);
        
        sprintf(vetor, "%ld", num);
        i = strlen(vetor);
        vetor[i] = '\0';
        if(i > 10){
            return -1;
        }
        
        for(int j=potencia2;j>=0;j--){
            if(num % divisor == 0){
                return num;
            }
            if(vetor[i-1] == '0' && vetor[i-2] == '0'){
                vetor[i-1] = '1';
                num = atol(vetor);
            }
            else if(vetor[i-1] == '1' && vetor[i-2] == '0'){
                vetor[i-1] = '0';
                vetor[i-2] = '1';
                num = atol(vetor);
            }
            else if(vetor[i-1] == '0' && vetor[i-2] == '1'){
                vetor[i-1] = '1';
                vetor[i-2] = '1';
                num = atol(vetor);
            }
            else if(vetor[i-1] == '1' && vetor[i-2] == '1'){
                for(int k=i-1;k>0;k--){
                    if(vetor[k] == '0'){
                        vetor[k] = '1';
                        num = atol(vetor);
                        break;
                    }
                    else{
                        vetor[k] = '0';
                    }
                }
            }
        }
    }
 
    
    return -1;
}

int main(int argc, const char * argv[]) {
    long divisor, dividendo;
    
    printf("Digite qualquer número inteiro entre 1 e 10^12 - 1, para achar seu divisor feito de 0s e 1s\nDigite: ");
    while(scanf("%ld", &divisor) != EOF){
        if(divisor >= pow(10,12)){
            printf("número invalido!!!\n");
        }
        else if(divisor == 0){
            return 0;
        }
        else{
            dividendo = divi(divisor);
            printf("%ld\n", dividendo);
        }
        
        printf("\nDigite outro valor: ");
    }
    
    return 0;
}

