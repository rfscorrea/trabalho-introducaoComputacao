//EXERCÍCIO 1.a
/*#include <stdlib.h>
#include <math.h>

int main(){
    const float pi = 3.14159265359;
    float anguloA, senoA, cossenoA;
    int n;
    printf("Valor do angulo em graus: ");
    scanf("%f", &anguloA);
    for(n = 0; n <= 2; n = n+1){
        senoA += (pow(anguloA * pi / 180, 2 * n + 1) / fatorial(2*n+1)) * pow(-1, n);
        cossenoA += (pow(anguloA * pi / 180, 2 * n)  / fatorial(2*n)) * pow(-1, n);
    }
    printf("Angulo digitado: %.3f graus \nSeno = %.100f \nCosseno = %.100f", anguloA, senoA, cossenoA);
    printf("\n\n Seno: %.100f \nCosseno: %.100f", sin(anguloA*pi/180), cos(anguloA*pi/180));
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
}*/