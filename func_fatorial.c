//Criando uma função para calcular fatorial de um número

#include <stdio.h>
#include <stdlib.h>

double fatorial(int x){
    double resultado = 1;
    while(x>1){
        resultado *= x;
        x --;
    }
    return(resultado);
}