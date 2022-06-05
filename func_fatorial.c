//Criando uma função para calcular fatorial de um número

#include <stdio.h>
#include <stdlib.h>

long long int fatorial(int f){
    long long int resultado = 1;
    if(f>=2){
        while(f>=2){
            resultado *= f;
            f -= 1;
        }
    }
    else{
        resultado = 1;
    }
    return("%e", resultado);
}

int main()
{
long long int fat, n;
printf("Insira um valor para o qual deseja calcular seu fatorial: ");
scanf("%lli", &n);

for(fat = 1; n > 1; n = n - 1)
fat = fat * n;

printf("\nFatorial calculado: %e", fat);
return 0;
}