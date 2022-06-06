//EXERCÍCIO 1.b

/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fatorial(int x){
    double resultado = 1;
    while(x>1){
        resultado *= x;
        x --;
    }
    return(resultado);
}

int main(){
    float pi = 3.14159265359;
    float anguloB;
    double senoB, cossenoB;
    int n;
    printf("Valor do angulo em graus: ");
    scanf("%f", &anguloB);
    for (n = 0; n <= 39; n = n + 1)
    {
        senoB += (pow(anguloB * pi / 180, 2 * n + 1) / fatorial(2*n+1)) * pow(-1, n);
        cossenoB += (pow(anguloB * pi / 180, 2 * n)  / fatorial(2*n)) * pow(-1, n);
    }
    printf("Angulo digitado: %.2f graus \nSeno = %.10f \nCosseno = %.1000f", anguloB, senoB, cossenoB);
    printf("\n\n%.1000f", cos(anguloB * pi / 180));
    return (0);
}*/