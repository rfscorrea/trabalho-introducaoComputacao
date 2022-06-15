#include <stdio.h>
#include <stdlib.h>

int main(){
    #define numeroDeClientes 100 //número máximo de clientes que podem ser cadastrados
    #define numeroDeCaracteres 100 //número máximo de caracteres nas info de um cliente 
    int i = 0; //índice para relacionar cada cliente e suas info a um número inteiro único i

    //variáveis para cadastrar clientes
    char clienteNome[numeroDeClientes][numeroDeCaracteres];
    char clienteEndereco[numeroDeClientes][numeroDeCaracteres];
    int clienteNascimento_dia[numeroDeClientes][numeroDeCaracteres];
    int clienteNascimento_mes[numeroDeClientes][numeroDeCaracteres];
    int clienteCpf[numeroDeClientes][numeroDeCaracteres];

    int clienteEmp_data_dia[numeroDeClientes][numeroDeCaracteres];
    int clienteEmp_data_mes[numeroDeClientes][numeroDeCaracteres];
    int clienteEmp_valor[numeroDeClientes][numeroDeCaracteres];

    int clienteEmp_parcelaInfo_valor[numeroDeClientes][numeroDeCaracteres];
    int clienteEmp_parcelaInfo_numero[numeroDeClientes][numeroDeCaracteres];
    char clienteEmp_parcelaInfo_dataVencimento[numeroDeClientes][numeroDeCaracteres];
    char clienteEmp_parcelaInfo_dataPagamento[numeroDeClientes][numeroDeCaracteres];

    //cadastrando um cliente
    printf("==== CADASTRO DE CLIENTE ====\n");
    printf("Nome: ");
    gets(clienteNome[i]);
    printf("Endereco: ");
    gets(clienteEndereco[i]);
    printf("Cpf: ");
    scanf("%i", &clienteCpf[i]);
    printf("\nData de nascimento:\n");
    printf("Dia: ");
    scanf("%i", &clienteNascimento_dia[i]);
    printf("Mes: ");
    scanf("%i", &clienteNascimento_mes[i]);
    printf("\nValor do emprestimo: R$");
    scanf("%i", &clienteEmp_valor[i]);
    printf("\nData do emprestimo:\n");
    printf("Dia: ");
    scanf("%i", &clienteEmp_data_dia[i]);
    printf("Mes: ");
    scanf("%i", &clienteEmp_data_mes[i]);
    printf("\nValor da parcela: R$");
    scanf("%f", &clienteEmp_parcelaInfo_valor[i]);
    printf("Quantas parcelas: ");
    scanf("%i", &clienteEmp_parcelaInfo_numero[i]);
    printf("==== CLIENTE %i CADASTRADO ====\n", i);
    return(0);
}