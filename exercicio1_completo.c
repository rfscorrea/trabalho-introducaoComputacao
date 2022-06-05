///////////////////* EXERCÍCIO 1.d *///////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>

int main(){
    const float pi = 3.14159265359;
//A
    float angulo, senoA, cossenoA;
    int n;
    printf("Valor do angulo em graus: ");
    scanf("%f", &angulo);
    for(n = 0; n <= 2; n = n+1){
        senoA += pow(-1,n) * pow(angulo*pi/180, 2*n+1) / fatorial(2*n+1);
        cossenoA += pow(-1,n) * pow(angulo*pi/180, 2*n) / fatorial(2*n);
    }
    printf("Angulo digitado: %.2f graus \nSeno = %.2f \nCosseno = %.2f", angulo, senoA, cossenoA);
//B
    double senoB, cossenoB;
    for (n = 0; n <= 39; n = n + 1)
    {
        senoB += pow(-1, n) * pow(angulo * pi / 180, 2 * n + 1) / fatorial(2 * n + 1);
        cossenoB += pow(-1, n) * pow(angulo * pi / 180, 2 * n)  / fatorial(2 * n);
    }
    printf("Angulo digitado: %.2f graus \nSeno = %g \nCosseno = %g", angulo, senoB, cossenoB);
//C
    float anguloRAD = (angulo * pi) / 180;  //convertendo o valor do ângulo de grau para radianos
    printf("=== Utilizando a biblioteca math.h para calculo de sen e cos ===\n");
    printf("\nAngulo digitado: %.2f graus \nSeno = %.2f \nCosseno = %.2f", angulo, sin(anguloRAD), cos(anguloRAD));
//D
    /*ERROS EM VALORES ABSOLUTOS*/
    double erroAbs_ac_sen = abs(senoA - sin(anguloRAD));
    double erroAbs_bc_sen = abs(senoB - sin(anguloRAD));
    double erroAbs_ac_cos = abs(cossenoA - cos(anguloRAD));
    double erroAbs_bc_cos = abs(cossenoB - cos(anguloRAD));

    /*ERROS EM PORCENTAGEM*/
    double erroPorc_ac_sen = ((fmax(senoA, sin(anguloRAD)) / fmin(senoA, sin(anguloRAD)))-1) * 100;
    double erroPorc_bc_sen = ((fmax(senoB, sin(anguloRAD)) / fmin(senoB, sin(anguloRAD))) -1) * 100;
    double erroPorc_ac_cos = ((fmax(cossenoA, cos(anguloRAD)) / fmin(cossenoA, cos(anguloRAD)))-1) * 100;
    double erroPorc_bc_cos = ((fmax(cossenoB, cos(anguloRAD)) / fmin(cossenoB, cos(anguloRAD))) -1) * 100;

    printf("ERROS EM VALORES ABSOLUTOS: \n");
    printf("===========entre a-c:=========== \nseno: %f \ncos: %f", erroAbs_ac_sen, erroAbs_ac_cos);
    printf("\n===========entre b-c:=========== \nseno: %f \ncos: %f\n", erroAbs_bc_sen, erroAbs_bc_cos);

    printf("\nERROS EM VALORES PORCENTAGEM:\n");
    printf("===========entre a-c:=========== \nseno: %f%% \ncos: %f%%\n", erroPorc_ac_sen, erroPorc_ac_cos);
    printf("===========entre b-c:=========== \nseno: %f%% \ncos: %f%%", erroPorc_bc_sen, erroPorc_bc_cos);
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