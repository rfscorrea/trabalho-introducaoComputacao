#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    //variáveis para cadastrar clientes
    char clienteNome[100][100];
    char clienteEndereco[100][100];
    char clienteNascimento[100][100];
    int clienteCpf[100][100];

    char clienteEmp_data[100][100];
    int clienteEmp_valor[100][100];

    int clienteEmp_parcelaInfo_valor[100][100];
    char clienteEmp_parcelaInfo_situacao[100][100];
    char clienteEmp_parcelaInfo_dataVencimento[100][100];
    char clienteEmp_parcelaInfo_dataPagamento[100][100];

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