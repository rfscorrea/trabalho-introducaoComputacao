#include <stdio.h>
#include <math.h>
#define pi 3.14159265359


double fat(int x){     // funcao calcula fatorial de x
    double resultado;
    if(x==0){
        resultado = 1;
    }
    else{
        resultado = x;
    }
    while(x>1){
        resultado *= (x-1);
        x --;
    }
    return resultado;
}


void result(char tit[100], float sen, float cos){        //funcao imprimi resultado com titulo
    printf("\n============== %s ==============\n", tit);
    printf("Seno: %.30f \nCosseno: %.30f", sen, cos);
    printf("\n=========================================\n");
}


void fresult(char tit[100], float sen, float cos){        //funcao imprimi resultado em porcentagem com titulo
    printf("\n=============== %s ==============\n", tit);
    printf("Seno: %.30f%% \nCosseno: %.30f%%", sen, cos);
    printf("\n==========================================\n");
}


int main(){
    float angulo, anguloRAD;
    float senoA, cossenoA, senoB, cossenoB, senoC, cossenoC;
    int n;

    printf("Valor do angulo em graus entre 0 e 360: ");
    scanf("%f", &angulo);

    // convertendo o valor do ângulo de grau para radianos
    anguloRAD = (angulo * pi) / 180;   

    // aplicando formula
    for(n = 0; n <= 2; n = n+1){
        senoA += (pow(angulo * pi / 180, 2 * n + 1) / fat(2*n+1)) * pow(-1, n);
        cossenoA += (pow(angulo * pi / 180, 2 * n)  / fat(2*n)) * pow(-1, n);
    }
    for (n = 0; n <= 39; n = n + 1){
        senoB += (pow(angulo * pi / 180, 2 * n + 1) / fat(2*n+1)) * pow(-1, n);
        cossenoB += (pow(angulo * pi / 180, 2 * n)  / fat(2*n)) * pow(-1, n);
    }
    senoC = sin(anguloRAD); cossenoC = cos(anguloRAD);

    // erros absoluto e porcentagem
    double acSen_abs = fabs(senoA - sin(anguloRAD)), 
    acCos_abs = fabs(cossenoA - cos(anguloRAD)),
    bcSen_abs = fabs(senoB - sin(anguloRAD)), 
    bcCos_abs = fabs(cossenoB - cos(anguloRAD)),
    acSen_porc = ((fmax(senoA, sin(anguloRAD)) / fmin(senoA, sin(anguloRAD)))-1) * 100, 
    acCos_porc = (fmax(cossenoA, cos(anguloRAD)) / fmin(cossenoA, cos(anguloRAD))-1) * 100, 
    bcSen_porc = ((fmax(senoB, sin(anguloRAD)) / fmin(senoB, sin(anguloRAD))) -1) * 100, 
    bcCos_porc = (fmax(cossenoB, cos(anguloRAD)) / fmin(cossenoB, cos(anguloRAD))-1) * 100;
    
    // resultados
    printf("\n~~~~~~~~~~~~~~~~~~~ VALOR SENO E COSSENO ~~~~~~~~~~~~~~~~~~\n");
    result("PARA 3 TERMOS", senoA, cossenoA);
    result("PARA 40 TERMOS", senoB, cossenoB);
    result("USANDO MATH.H", senoC, cossenoC);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("\n~~~~~~~~~~~~~~~~~~~ ERROS EM VALORES ABSOLUTOS: ~~~~~~~~~~~~~~~~~~\n");
    result("ENTRE A - C", acSen_abs, acCos_abs);
    result("ENTRE B - C", bcSen_abs, bcSen_abs);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("\n~~~~~~~~~~~~~~~~~~~ ERROS EM VALORES PORCENTAGEM: ~~~~~~~~~~~~~~~~~~\n");
    fresult("ENTRE A - C", acSen_porc, acCos_porc);
    fresult("ENTRE B - C", bcSen_porc, bcCos_porc);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return(0);
}