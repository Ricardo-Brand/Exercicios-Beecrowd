//
//  main.c
//  relogio-binario
//
//  Created by Ricardo Augusto da Silva Brandão on 18/03/25.
//

#include <stdio.h>
#include <stdlib.h>

void tela(char hora[], char minuto[]){
    int binario;

    // Forma o desenho do relogio
    printf(" ____________________________________________\n");
    printf("|                                            |\n");
    printf("|    ____________________________________    |_\n");
    printf("|   |                                    |   |_)\n");
    printf("|   |   8         4         2         1  |   |\n");
    printf("|   |                                    |   |\n");
    printf("|   |   %c         %c         %c         %c  |   |\n", hora[0], hora[1], hora[2], hora[3]);
    printf("|   |                                    |   |\n");
    printf("|   |                                    |   |\n");
    printf("|   |   %c     %c     %c     %c     %c     %c  |   |\n", minuto[0], minuto[1], minuto[2], minuto[3], minuto[4], minuto[5]);
    printf("|   |                                    |   |\n");
    printf("|   |   32    16    8     4     2     1  |   |_\n");
    printf("|   |____________________________________|   |_)\n");
    printf("|                                            |\n");
    printf("|____________________________________________|\n\n");
}

char* binario_hora(char h[], int hora){
    for(int i=3;i>=0;i--){ // Indica se a hora deve estar marcada ou não
        if(hora % 2 == 0){
            h[i] = ' ';
        }
        else{
            h[i] = 'o';
        }
        
        hora /= 2;
    }
    
    return h;
}

char* binario_minuto(char m[], int minuto){
    for(int i=5;i>=0;i--){ // Indica se o minuto deve estar marcado ou não
        if(minuto % 2 == 0){
            m[i] = ' ';
        }
        else{
            m[i] = 'o';
        }
        
        minuto /= 2;
    }
    
    return m;
}

int main(){
    int hora, minuto;
    char h[5], m[7];
    
    h[4] = '\0'; // fim da string
    m[6] = '\0'; // fim da string
    
    while(1){
        
        printf("Digite hora <= 12 e minutos <= 59 'hora:minuto', e veja como ficara no relogio\nDigite: ");
        scanf("%2d:%2d", &hora, &minuto);
        if(hora > 12 || minuto > 59){
            printf("\nHora ou minuto está acima do limite\n\n");
        }
        else{
            binario_hora(h, hora);
            binario_minuto(m, minuto);
            tela(h, m);
        }
    }
    
    return 0;
}

