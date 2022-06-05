///////////////////* EXERCÍCIO 1.b *///////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float pi = 3.14159265359;
    float anguloB;
    double senoB, cossenoB;
    int n;
    printf("Valor do angulo em graus: ");
    scanf("%f", &anguloB);
    for (n = 0; n <= 39; n = n + 1)
    {
        senoB += pow(-1, n) * pow(anguloB * pi / 180, 2 * n + 1) / fatorial(2 * n + 1);
        cossenoB += pow(-1, n) * pow(anguloB * pi / 180, 2 * n)  / fatorial(2 * n);
    }
    printf("Angulo digitado: %.2f graus \nSeno = %g \nCosseno = %g", anguloB, senoB, cossenoB);
    return (0);
}

int fatorial(int f){ // função para calcular fatorial de um número f
    int resultado = 1;
    if (f >= 2)
    {
        for (f; f >= 2; f = f - 1)
        {
            resultado = resultado * f;
        }
    }
    else
    {
        resultado = 1;
    }
    return (resultado);
}