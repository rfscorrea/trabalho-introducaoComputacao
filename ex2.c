#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////// structs //////////////////////////////

typedef struct data{
    int dia, mes, ano;
}dt;


typedef struct emprestimo{
    float valor;
    dt data;
}emp;


typedef struct endereco{
    char rua[100];
    int numero;
    char cep[100];
    char bairro[100];
    char cidade[100];
    char estado[3];
}end;


typedef struct informacoescliente{
    char nome[1000];
    int cpf;
    end endereco;
    dt nascimento;
    emp emprestimo;
    int parcelas;
    int parcelaspagas;
    struct informacoescliente *proximo;
}cli;


////////////////////////////// funcoes //////////////////////////////

void adicionarcliente(cli **lista){
    cli *novo = malloc(sizeof(cli));
    cli *aux;
    
    if(novo){
        printf("\nNome: ");
        fgets(novo->nome, 1000, stdin);
        printf("CPF: ");
        scanf("%i%*c", &novo->cpf);
        printf("\n~~~~ Endereco ~~~~");
        printf("\nRua: ");
        fgets(novo->endereco.rua, 100, stdin);
        printf("Numero: ");
        scanf("%i%*c", &novo->endereco.numero);
        printf("Bairro: ");
        fgets(novo->endereco.bairro, 100, stdin);
        printf("CEP: ");
        fgets(novo->endereco.cep, 100, stdin);
        printf("Cidade: ");
        fgets(novo->endereco.cidade, 100, stdin);
        printf("Estado (2 letras): ");
        fgets(novo->endereco.estado, 100, stdin);
        printf("\n~~~~ Data de nascimento ~~~~");
        printf("\nDia: ");
        scanf("%i%*c", &novo->nascimento.dia);
        printf("Mes: ");
        scanf("%i%*c", &novo->nascimento.mes);
        printf("Ano: ");
        scanf("%i%*c", &novo->nascimento.ano);
        
        novo->emprestimo.data.dia = 0;
        novo->emprestimo.data.mes = 0;
        novo->emprestimo.data.ano = 0;
        novo->emprestimo.valor = 0;
        novo->parcelas = 0;
        novo->parcelaspagas = 0;
        novo->proximo = NULL;
    }
    else{
        exit(0);
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
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    free(remover);
}


void editarcliente(cli **lista){
    cli *aux;
    int cpf;
    if(*lista == NULL){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    else{
        aux = *lista;
        printf("Cpf do cliente que deseja editar: ");
        scanf("%i%*c", &cpf);
        
        if(aux->cpf == cpf){
            printf("\nNome: ");
            fgets(aux->nome, 1000, stdin);
            printf("\n~~~~ Endereco ~~~~");
            printf("\nRua: ");
            fgets(aux->endereco.rua, 100, stdin);
            printf("\nNumero: ");
            scanf("%i%*c", &aux->endereco.numero);
            printf("\nBairro: ");
            fgets(aux->endereco.bairro, 100, stdin);
            printf("\nCEP: ");
            fgets(aux->endereco.cep, 100, stdin);
            printf("\nCidade: ");
            fgets(aux->endereco.cidade, 100, stdin);
            printf("\nEstado (2 letras): ");
            fgets(aux->endereco.estado, 100, stdin);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Cpf: ");
            scanf("%i%*c", &aux->cpf);

            printf("\n~~~~ Data de nascimento ~~~~");
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
                        printf("\n~~~~ Endereco ~~~~");
                        printf("\nRua: ");
                        fgets(aux->endereco.rua, 100, stdin);
                        printf("\nNumero: ");
                        scanf("%i%*c", &aux->endereco.numero);
                        printf("\nBairro: ");
                        fgets(aux->endereco.bairro, 100, stdin);
                        printf("\nCEP: ");
                        fgets(aux->endereco.cep, 100, stdin);
                        printf("\nCidade: ");
                        fgets(aux->endereco.cidade, 100, stdin);
                        printf("\nEstado (2 letras): ");
                        fgets(aux->endereco.estado, 100, stdin);
                        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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


void verparcelas(cli *lista){
    cli *aux = lista;
    cli *aux2;
    int dia, mes, ano;
    int i, j = 1;
    
    dia = aux->emprestimo.data.dia;
    mes = aux->emprestimo.data.mes;
    ano = aux->emprestimo.data.ano;

    for(i = 1 + aux->parcelaspagas; i <= aux->parcelas; i++){
    
        if(mes>=12){
            mes = 1; 
            ano++;
        }
        else{
            mes++;
        }

        printf("\n[%i]parcela 'EM ABERTO' vencimento:  %i/%i/%i", i, dia, mes, ano);
    }
    printf("\n");
}


void cadastrarparcelapaga(cli **lista){
    dt data;
    cli *aux;
    int cpf;

    if(*lista == NULL){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    else{
        aux = *lista;
        printf("Cpf do cliente: ");
        scanf("%i%*c", &cpf);
        
        if(aux->cpf == cpf){
            aux->parcelaspagas += 1;
        }
        else{
            while(aux->proximo != NULL){
                aux = aux->proximo;
                if(aux->cpf == cpf){
                    printf("Cpf do cliente que deseja editar: ");
                    scanf("%i%*c", &cpf);
        
                    if(aux->cpf == cpf){
                        aux->parcelaspagas += 1;
                        break;
                    }
                }
            }
        }
    }
}


void imprimirtodos(cli *aux){
    if(aux == NULL){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    else{
        printf("\n~~~~~~~~~~~ CLIENTES ~~~~~~~~~~~\n");
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
    float valor;
    int dia, mes, ano, i;

    if(cliente != NULL){
        printf("Cpf do cliente que deseja visualizar: ");
        scanf("%i%*c", &cpf);

        if(aux->cpf == cpf){
            printf("\n~~~~~ INFORMACOES DO CLIENTE ~~~~\n");
            printf(
                "Nome: %s"
                "Cpf: %i"
                "\nData de nascimento: %i/%i/%i"
                "\n~~ Endereco ~~\n"
                "Rua: %s"
                "Numero: %i\n"
                "Bairro: %s"
                "Cidade: %s"
                "Estado: %s"
                "CEP: %s", 
                aux->nome, aux->cpf, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano, aux->endereco.rua, aux->endereco.numero,aux->endereco.bairro, aux->endereco.cidade, aux->endereco.estado,aux->endereco.cep, aux->cpf, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano
            );
            if(aux->parcelaspagas != aux->parcelas){
                valor = aux->emprestimo.valor / aux->parcelas;
                printf("~~~~~~~~ EMPRESTIMO ~~~~~~~~");
                printf(
                    "\nData do emprestimo: %i/%i/%i"
                    "\nValor do emprestimo: %.2f"
                    "\nNumero de parcelas: %i parcelas de R$%.2f\n", 
                    aux->emprestimo.data.mes, aux->emprestimo.data.mes, aux->emprestimo.data.ano, aux->emprestimo.valor, aux->parcelas, valor
                );
            }

            verparcelas(cliente);
        }
        else{
            while(aux->proximo != NULL){
                aux = aux->proximo;
                if(aux->cpf == cpf){
                    printf("\n~~~~~ INFORMACOES DO CLIENTE ~~~~\n");
                    printf(
                        "Nome: %s"
                        "Endereco:\nRua %s, %i - %s, %s-%s\nCEP: %s"
                        "Cpf: %i"
                        "\nData de nascimento: %i/%i/%i", 
                        aux->nome, aux->endereco.rua, aux->endereco.numero,aux->endereco.bairro, aux->endereco.cidade, aux->endereco.estado,aux->endereco.cep, aux->cpf, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano
                    );
                    if(aux->parcelaspagas != aux->parcelas){
                        valor = aux->emprestimo.valor / aux->parcelas;
                        printf("~~~~~~~~ EMPRESTIMO ~~~~~~~~");
                        printf(
                            "\nData do emprestimo: %i/%i/%i"
                            "\nValor do emprestimo: %.2f"
                            "\nNumero de parcelas: %i parcelas de R$%.2f\n", 
                            aux->emprestimo.data.mes, aux->emprestimo.data.mes, aux->emprestimo.data.ano, aux->emprestimo.valor, aux->parcelas, valor
                        );
                    }

                    verparcelas(cliente);
                    break;
                }
            }
        }

        
    }
    else{
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
}


void cadastraremprestimo(cli **lista){
    cli *aux;
    int cpf;
    if(*lista == NULL){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nNENHUM CLIENTE CADASTRADO!!!\n");
    }
    else{
        aux = *lista;
        printf("Cpf do cliente: ");
        scanf("%i%*c", &cpf);
        if(aux->cpf == cpf){
            if(aux->parcelaspagas == aux->parcelas){
                aux->parcelaspagas = 0;
                printf("\nData de emprestimo: ");
                printf("\nDia: ");
                scanf("%i%*c", &aux->emprestimo.data.dia);
                printf("Mes: ");
                scanf("%i%*c", &aux->emprestimo.data.mes);
                printf("Ano: ");
                scanf("%i%*c", &aux->emprestimo.data.ano);
                printf("\nValor do emprestimo: R$");
                scanf("%f%*c", &aux->emprestimo.valor);
                printf("\nQuantas parcelas (maximo 12): ");
                scanf("%i%*c", &aux->parcelas);
            }
            else{
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\nAINDA HA PARCELAS EM ABERTO NESSE CPF\n");
            }
        }
        else{
            while(aux->proximo != NULL){
                aux = aux->proximo;
                if(aux->cpf == cpf){
                    printf("Cpf do cliente: ");
                    scanf("%i%*c", &cpf);
                    if(aux->cpf == cpf){
                        if(aux->parcelaspagas == aux->parcelas){
                            aux->parcelaspagas = 0;
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
                        else{printf("\nAINDA HA PARCELAS EM ABERTO\n");}
                        break;
                    }
                }
            }
        }
    }
}


////////////////////////////// main //////////////////////////////

int main(){
    cli *clientes = NULL;
    int r;      // resposta do usuario

    while(r != 0){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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
        case 4:
            cadastrarparcelapaga(&clientes);
            break;
        case 5:
            cadastraremprestimo(&clientes);
            break;
        case 6:
            removercliente(&clientes);
            break;
        case 7:
            imprimirtodos(clientes);
            break;
        default:
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("OPCAO INVALIDA\n");
            break;
        }
        
    }

    return 0;
}