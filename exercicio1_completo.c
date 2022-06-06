///////////////////* EXERCÍCIO 1.d *///////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>

double fatorial(int x){ //FUNÇÃO PARA CALCULAR FATORIAL
    double resultado = 1;
    while(x>1){
        resultado *= x;
        x --;
    }
    return(resultado);
}

int main(){
    float pi = 3.14159265359;

//A
    float angulo, senoA, cossenoA;
    int n;
    printf("Valor do angulo em graus: ");
    scanf("%f", &angulo);

    if(angulo>=360){     //para que o ângulo sempre esteja no intervalo [0,360)
        angulo -= 360;
    }
    else if(angulo<0){
        angulo += 360;
    }

    float anguloRAD = (angulo * pi) / 180;  //convertendo o valor do ângulo de grau para radianos
    for(n = 0; n <= 2; n = n+1){
        senoA += (pow(angulo * pi / 180, 2 * n + 1) / fatorial(2*n+1)) * pow(-1, n);
        cossenoA += (pow(angulo * pi / 180, 2 * n)  / fatorial(2*n)) * pow(-1, n);
    }
    printf("Angulo digitado: %.2f graus\n\n ============================== PARA 3 TERMOS ============================== \nSeno = %.20f \nCosseno = %.20f", angulo, senoA, cossenoA);
    printf("\n============================================================================\n\n ");

//B
    double senoB, cossenoB;
    for (n = 0; n <= 39; n = n + 1)
    {
        senoB += (pow(angulo * pi / 180, 2 * n + 1) / fatorial(2*n+1)) * pow(-1, n);
        cossenoB += (pow(angulo * pi / 180, 2 * n)  / fatorial(2*n)) * pow(-1, n);
    }
    printf("============================== PARA 40 TERMOS ============================== \nSeno = %.20f \nCosseno = %.20f",senoB, cossenoB);
    printf("\n============================================================================\n\n");

//C
    printf("======================== UTILIZANDO A BIBLIOTECA MATH.H ========================\n");
    printf("Seno = %.20f \nCosseno = %.20f", sin(anguloRAD), cos(anguloRAD));
    printf("\n============================================================================\n\n");

//D
    /*ERROS EM VALORES ABSOLUTOS*/
    double erroAbs_ac_sen = senoA - sin(anguloRAD);
    double erroAbs_bc_sen = senoB - sin(anguloRAD);
    double erroAbs_ac_cos = cossenoA - cos(anguloRAD);
    double erroAbs_bc_cos = cossenoB - cos(anguloRAD);

    /*ERROS EM PORCENTAGEM*/
    double erroPorc_ac_sen = ((fmax(senoA, sin(anguloRAD)) / fmin(senoA, sin(anguloRAD)))-1) * 100;
    double erroPorc_bc_sen = ((fmax(senoB, sin(anguloRAD)) / fmin(senoB, sin(anguloRAD))) -1) * 100;
    double erroPorc_ac_cos = (fmax(cossenoA, cos(anguloRAD)) / fmin(cossenoA, cos(anguloRAD))-1) * 100;
    double erroPorc_bc_cos = (fmax(cossenoB, cos(anguloRAD)) / fmin(cossenoB, cos(anguloRAD))-1)*100;

    printf("==== ERROS EM VALORES ABSOLUTOS: ====\n\n");
    printf("============ Entre a-c: ============ \nseno: %.30f \ncos: %.30f", fabs(erroAbs_ac_sen), fabs(erroAbs_ac_cos));
    printf("\n=================================\n\n");
    printf("\n=========== Entre b-c: =========== \nseno: %.30f \ncos: %.30f\n", fabs(erroAbs_bc_sen), fabs(erroAbs_bc_cos));
    printf("=================================\n\n");

    printf("\n=== ERROS EM VALORES PORCENTAGEM: ===\n\n");
    printf("=========== Entre a-c: =========== \nseno: %.30f%% \ncos: %.30f%%\n", fabs(erroPorc_ac_sen), fabs(erroPorc_ac_cos));
    printf("=================================\n\n");
    printf("============== Entre b-c: ============== \nseno: %.30f%% \ncos: %.30f%%", fabs(erroPorc_bc_sen), fabs(erroPorc_bc_cos));
    printf("\n================ FIM =================\n\n");
    return(0);
}