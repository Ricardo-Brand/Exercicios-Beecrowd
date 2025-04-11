//
//  main.c
//  raiz-quadrada
//
//  Created by Ricardo Augusto da Silva Brandão on 19/03/25.
//

#include <stdio.h>

double raiz_quadrada(double a){
    double parada = 0.0000001, x;
    x = 0;
    
    if(a > 1)
    {
        x = a; //'a' é o valor inicial de entrada
    }
        
    else if(a <= 1){
        x = 1;
    }
        
    while (((x * x) - a) > parada){
        x = 0.5 * (x + (a/x)); // x_n+1 = x_n - (f(x_n) / f'(x_n))
    }
    
    return x;
}

int main(int argc, const char * argv[]) {
    double num;
    
    printf("Digite um valor entre 0 e 2^32, para extrair a raiz quadrada\nDigite: ");
    scanf("%lf", &num);
    
    
    if((num <= 4294967296) && (num > 0)){
        num = raiz_quadrada(num);
        printf("\n\nO valor da raiz quadrada eh: %.2lf\n\n", num);
    }
    else
        printf("\n\nNao eh um numero valido!!\n\n");
    
    return 0;
}
