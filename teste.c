// estudo de clientess encadeadas utilizando ponteiros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// struct para datas
typedef struct data{
    int dia, mes, ano;
}dt;


// struct para emprestimos
typedef struct emprestimos{
    float valor;
    dt data;
}emp;


typedef struct cliente{
    char nome[1000];
    int cpf;
    char endereco[1000];
    dt nascimento;
    emp emprestimo;
    int parcelas;
    struct cliente *proximo;
}cli;


void adicionarcliente(cli **lista){
    cli *novo = malloc(sizeof(cli));
    cli *aux;
    
    if(novo){
        printf("\nNome: ");
        fgets(novo->nome, 1000, stdin);
        printf("Endereco: ");
        fgets(novo->endereco, 1000, stdin);
        printf("Cpf: ");
        scanf("%i%*c", &novo->cpf);

        printf("\nData de nascimento: ");
        printf("\nDia: ");
        scanf("%i%*c", &novo->nascimento.dia);
        printf("\nMes: ");
        scanf("%i%*c", &novo->nascimento.mes);
        printf("\nAno: ");
        scanf("%i%*c", &novo->nascimento.ano);

        printf("\nData de emprestimo: ");
        printf("\nDia: ");
        scanf("%i%*c", &novo->emprestimo.data.dia);
        printf("Mes: ");
        scanf("%i%*c", &novo->emprestimo.data.mes);
        printf("Ano: ");
        scanf("%i%*c", &novo->emprestimo.data.ano);
        printf("\nValor do emprestimo: R$");
        scanf("%f%*c", &novo->emprestimo.valor);
        printf("\nQuantas parcelas: ");
        scanf("%i%*c", &novo->parcelas);
        
        novo->proximo = NULL;
    }
    else{
        printf("\nmemoria nao alocada!!\n");
    }

    if(*lista == NULL){
        *lista = novo;
    }
    else{
        aux = *lista;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}


void removercliente(cli **lista){
    cli *aux, *remover = NULL;
    int cpf;
    

    if(*lista){
        printf("Cpf do cliente que deseja excluir: ");
        scanf("%i%*c", &cpf);
        if((*lista)->cpf == cpf){
            remover = *lista;
            *lista = remover->proximo;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->cpf != cpf)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    else{
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    free(remover);
}


void editarcliente(cli **lista){
    cli *aux;
    int cpf;
    if(*lista == NULL){
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    else{
        aux = *lista;
        printf("Cpf do cliente que deseja editar: ");
        scanf("%i%*c", &cpf);
        
        if(aux->cpf == cpf){
            printf("\nNome: ");
        fgets(aux->nome, 1000, stdin);
        printf("Endereco: ");
        fgets(aux->endereco, 1000, stdin);
        printf("Cpf: ");
        scanf("%i%*c", &aux->cpf);

        printf("\nData de nascimento: ");
        printf("\nDia: ");
        scanf("%i%*c", &aux->nascimento.dia);
        printf("\nMes: ");
        scanf("%i%*c", &aux->nascimento.mes);
        printf("\nAno: ");
        scanf("%i%*c", &aux->nascimento.ano);

        printf("\nData de emprestimo: ");
        printf("\nDia: ");
        scanf("%i%*c", &aux->emprestimo.data.dia);
        printf("Mes: ");
        scanf("%i%*c", &aux->emprestimo.data.mes);
        printf("Ano: ");
        scanf("%i%*c", &aux->emprestimo.data.ano);
        printf("\nValor do emprestimo: R$");
        scanf("%f%*c", &aux->emprestimo.valor);
        printf("\nQuantas parcelas: ");
        scanf("%i%*c", &aux->parcelas);
        }
        else{
            while(aux->proximo != NULL){
                aux = aux->proximo;
                if(aux->cpf == cpf){
                    printf("Cpf do cliente que deseja editar: ");
                    scanf("%i%*c", &cpf);
        
                    if(aux->cpf == cpf){
                        printf("\nNome: ");
                        fgets(aux->nome, 1000, stdin);
                        printf("Endereco: ");
                        fgets(aux->endereco, 1000, stdin);
                        printf("Cpf: ");
                        scanf("%i%*c", &aux->cpf);

                        printf("\nData de nascimento: ");
                        printf("\nDia: ");
                        scanf("%i%*c", &aux->nascimento.dia);
                        printf("\nMes: ");
                        scanf("%i%*c", &aux->nascimento.mes);
                        printf("\nAno: ");
                        scanf("%i%*c", &aux->nascimento.ano);

                        printf("\nData de emprestimo: ");
                        printf("\nDia: ");
                        scanf("%i%*c", &aux->emprestimo.data.dia);
                        printf("Mes: ");
                        scanf("%i%*c", &aux->emprestimo.data.mes);
                        printf("Ano: ");
                        scanf("%i%*c", &aux->emprestimo.data.ano);
                        printf("\nValor do emprestimo: R$");
                        scanf("%f%*c", &aux->emprestimo.valor);
                        printf("\nQuantas parcelas: ");
                        scanf("%i%*c", &aux->parcelas);
                        break;
                    }
                }
            }
        }
    }
}


void imprimirtodos(cli *aux){
    if(aux == NULL){
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    else{
        printf("\n~~~~ CLIENTES ~~~~\n");
        while(aux){
            printf("[%i]%s", aux->cpf, aux->nome);
            aux = aux->proximo;
        }
    }
}


void imprimircliente(cli *cliente){
    cli *aux;
    aux = cliente;
    int cpf;

    if(cliente != NULL){
        printf("Cpf do cliente que deseja visualizar: ");
        scanf("%i%*c", &cpf);

        if(aux->cpf == cpf){
            printf(
                "\nNome: %s"
                "\nEndereco: %s"
                "\nCpf: %i"
                "\nData de nascimento: %i/%i/%i"
                "\nData do emprestimo: %i/%i/%i"
                "\nValor do emprestimo: %.2f"
                "\nNumero de parcelas: %i", aux->nome, aux->endereco, aux->cpf, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->emprestimo.data.mes, aux->emprestimo.data.mes, aux->emprestimo.data.ano, aux->emprestimo.valor, aux->parcelas
            );
        }
        else{
            while(aux->proximo != NULL){
                aux = aux->proximo;
                if(aux->cpf == cpf){
                    printf(
                        "\nNome: %s"
                        "\nEndereco: %s"
                        "\nCpf: %i"
                        "\nData de nascimento: %i/%i/%i"
                        "\nData do emprestimo: %i/%i/%i"
                        "\nValor do emprestimo: %.2f"
                        "\nNumero de parcelas: %i", aux->nome, aux->endereco, aux->cpf, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->emprestimo.data.mes, aux->emprestimo.data.mes, aux->emprestimo.data.ano, aux->emprestimo.valor, aux->parcelas
                    );
                    break;
                }
            }
        }

        
    }
    else{
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
}


int main(){
    cli *clientes = NULL;
    int r;

    while(r != 0){
        printf(
            "\n[1] Cadastrar cliente"
            "\n[2] Visualizar as informacoeses de um cliente"
            "\n[3] Editar as informacoes de um cliente"
            "\n[4] Cadastrar parcela paga"
            "\n[5] Cadastrar emprestimo."
            "\n[6] Excluir cliente"
            "\n[7] Ver todos os clientes cadastrados"
            "\n[0] Sair"
            "\nResposta: "
        );
        scanf("%i%*c", &r);
        if(r==0){break;}

        switch (r)
        {
        case 1:
            adicionarcliente(&clientes);
            break;
        case 2:
            imprimircliente(clientes);
            break;
        case 3:
            editarcliente(&clientes);
            break;
        case 6:
            removercliente(&clientes);
            break;
        case 7:
            imprimirtodos(clientes);
            break;
        default:
            printf("invalido");
            break;
        }
        
    }

    return 0;
}