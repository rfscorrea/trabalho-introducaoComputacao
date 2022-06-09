#include <stdio.h>
#include <stdlib.h>

int main(){
    #define numeroDeClientes 100 //número máximo de clientes que podem ser cadastrados
    #define numeroDeCaracteres 100 //número máximo de caracteres nas info de um cliente 
    int i = 0; //índice para relacionar cada cliente e suas info a um número inteiro único i

    //variáveis para cadastrar clientes
    char clienteNome[numeroDeClientes][numeroDeCaracteres];
    char clienteEndereco[numeroDeClientes][numeroDeCaracteres];
    char clienteNascimento[numeroDeClientes][numeroDeCaracteres];
    int clienteCpf[numeroDeClientes][numeroDeCaracteres];

    char clienteEmp_data[numeroDeClientes][numeroDeCaracteres];
    int clienteEmp_valor[numeroDeClientes][numeroDeCaracteres];

    int clienteEmp_parcelaInfo_valor[numeroDeClientes][numeroDeCaracteres];
    char clienteEmp_parcelaInfo_situacao[numeroDeClientes][numeroDeCaracteres];
    char clienteEmp_parcelaInfo_dataVencimento[numeroDeClientes][numeroDeCaracteres];
    char clienteEmp_parcelaInfo_dataPagamento[numeroDeClientes][numeroDeCaracteres];

    //cadastrando um cliente
    printf("=== CADASTRO DE CLIENTE ===\n");
    printf("Nome: ");
    gets(clienteNome[i]);
    printf("\nEndereco: ");
    gets(clienteEndereco[i]);
    printf("\nData de nascimento (dd/mm/aa): ");
    gets(clienteNascimento[i]);
    printf("\nCpf: ");
    scanf("%i", &clienteCpf[i]);
    printf("\nValor do emprestimo: R$");
    scanf("%i", &clienteEmp_valor[i]);
    printf("\nData do emprestimo (dd/mm/aa): ");
    getchar();
    gets(clienteEmp_data[i]);
    printf("\nValor da parcela: R$");
    scanf("%f", &clienteEmp_parcelaInfo_valor[i]);
    printf("\nSituacao da parcela: ");
    getchar();
    gets(clienteEmp_parcelaInfo_situacao[i]);
    printf("\nData de vencimento da parcela: ");
    gets(clienteEmp_parcelaInfo_dataVencimento[i]);
    printf("\nData de pagamento da parcela: ");
    gets(clienteEmp_parcelaInfo_dataPagamento[i]);
    return(0);
}