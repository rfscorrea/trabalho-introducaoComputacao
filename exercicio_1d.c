// EXERCÍCIO 1.d 

 /*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>

int main(){
    double senoA, senoB, anguloRAD, cossenoA, cossenoB;
    //ERROS EM VALORES ABSOLUTOS
    double erroAbs_ac_sen = abs(senoA - sin(anguloRAD));
    double erroAbs_bc_sen = abs(senoB - sin(anguloRAD));
    double erroAbs_ac_cos = abs(cossenoA - cos(anguloRAD));
    double erroAbs_bc_cos = abs(cossenoB - cos(anguloRAD));

    //ERROS EM PORCENTAGEM
    double erroPorc_ac_sen = ((fmax(senoA, sin(anguloRAD)) / fmin(senoA, sin(anguloRAD)))-1) * 100;
    double erroPorc_bc_sen = ((fmax(senoB, sin(anguloRAD)) / fmin(senoB, sin(anguloRAD))) -1) * 100;
    double erroPorc_ac_cos = ((fmax(senoA, sin(anguloRAD)) / fmin(cossenoA, cos(anguloRAD)))-1) * 100;
    double erroPorc_bc_cos = ((fmax(senoB, sin(anguloRAD)) / fmin(cossenoB, cos(anguloRAD))) -1) * 100;

    printf("ERROS EM VALORES ABSOLUTOS: \n");
    printf("===========entre a-c:=========== \nseno: %f \ncos: %f", erroAbs_ac_sen, erroAbs_ac_cos);
    printf("\n===========entre b-c:=========== \nseno: %f \ncos: %f\n", erroAbs_bc_sen, erroAbs_bc_cos);

    printf("\nERROS EM VALORES PORCENTAGEM:\n");
    printf("===========entre a-c:=========== \nseno: %f \ncos: %f\n", erroPorc_ac_sen, erroPorc_ac_cos);
    printf("===========entre b-c:=========== \nseno: %f \ncos: %f", erroPorc_bc_sen, erroPorc_bc_cos);
    return(0);
}*/