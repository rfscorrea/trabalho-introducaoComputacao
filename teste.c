//Criando uma função para calcular fatorial de um número

#include <stdio.h>
#include<stdlib.h>

int fatorial(int f){
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
int main(){
int num;
printf("Número: ");
scanf("%i", &num);
printf("O fatorial de %i é %i",num, fatorial(num));
}