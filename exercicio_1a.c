///////////////////* EXERCÍCIO 1.a *///////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    const float pi = 3.14159265359;
    float anguloA, senoA, cossenoA;
    int n;
    printf("Valor do angulo em graus: ");
    scanf("%f", &anguloA);
    for(n = 0; n <= 2; n = n+1){
        senoA += pow(-1,n) * pow(anguloA*pi/180, 2*n+1) / fatorial(2*n+1);
        cossenoA += pow(-1,n) * pow(anguloA*pi/180, 2*n) / fatorial(2*n);
    }
    printf("Angulo digitado: %.2f graus \nSeno = %.2f \nCosseno = %.2f", anguloA, senoA, cossenoA);
    return(0);
}

int fatorial(int f){        //função para calcular fatorial de um número f
    int resultado = 1;
    if(f>=2){
        for(f; f >= 2; f = f-1){
            resultado = resultado * f;
        }
    }
    else{
        resultado = 1;
    }
    return(resultado);
}