#include <stdio.h>
#include <string.h>
#define X 1000


// struct para datas
typedef struct data{
    int dia, mes, ano;
}data;


// struct para emprestimos
typedef struct emprestimos{
    float valor;
    data data;
}emp;


// struct para info do cliente
typedef struct informacoescliente{
    char nome[X];
    int cpf;
    char endereco[X];
    data nascimento;
    emp emprestimo;
    int parcelas;

}info;


// funcao que cadastra cliente e retorna valor do tipo info
info cdtcliente(char nome[X], int cpf, char endereco[X], data nascimento, emp emprestimo){
    info cliente;

    strcpy(cliente.nome, nome);
    strcpy(cliente.endereco, endereco);
    cliente.cpf = cpf;
    cliente.nascimento.dia = nascimento.dia;
    cliente.nascimento.mes = nascimento.mes;
    cliente.nascimento.ano = nascimento.ano;
    cliente.emprestimo.valor = emprestimo.valor;
    cliente.emprestimo.data.dia = emprestimo.data.dia;
    cliente.emprestimo.data.mes = emprestimo.data.mes;
    cliente.emprestimo.data.ano = emprestimo.data.ano;

    return cliente;
}


// funcao que cadastra emprestimo e retorna valor do tipo emp
emp cdtemprestimo(float valor, data data){
    emp emprestimo;

    emprestimo.valor = valor;
    emprestimo.data = data;

    return emprestimo;
}


info clientes[X];
int main(){
    int i = 0;
    data nascimento;
    emp emp;
    char nome[X], endereco[X];
    int cpf;
    int c, r;
    while(1==1){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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

        switch(r){
            case 1:
                printf("\n~~~~~~~~~~~~~~~~ CADASTRO ~~~~~~~~~~~~~~~~");
                printf("\nNome: ");
                fgets(nome, X, stdin);
                printf("CPF: ");
                scanf("%i%*c", &cpf); 
                if(cpf==0){printf("\ncpf '0' invalido!!!\n"); break;}
                printf("Endereco: ");
                fgets(endereco, X, stdin);

                printf("\nDATA DE NASCIMENTO:");
                printf("\nDia: ");
                scanf("%i%*c", &nascimento.dia);
                printf("Mes: ");
                scanf("%i%*c", &nascimento.mes);
                printf("Ano: ");
                scanf("%i%*c", &nascimento.ano);

                printf("\nDATA DO EMPRESTIMO: ");
                printf("\nDia: ");
                scanf("%i%*c", &emp.data.dia);
                printf("Mes: ");
                scanf("%i%*c", &emp.data.mes);
                printf("Ano: ");
                scanf("%i%*c", &emp.data.ano);

                printf("\nValor do emprestimo: R$");
                scanf("%f%*c", &emp.valor);
                

                clientes[i] = cdtcliente(nome, cpf, endereco, nascimento, emp);
                i++;
                break;
            case 2:
                printf("Qual cliente visualizar?: ");
                scanf("%i%*c", &c);
                if(clientes[c].cpf == 0){printf("\n~~~~ CLIENTE NAO CADASTRADO ~~~~\n"); break;}
                
                printf("\n~~~~~~~~~~~~~~~ CLIENTE INFOS ~~~~~~~~~~~~~~");
                printf(
                    "\nNome: %s"
                    "Endereco: %s"
                    "CPF: %i"
                    "\nData de Nascimento: %i/%i/%i"
                    "\nValor do emprestimo: R$%.2f"
                    "\nData do emprestimo: %i/%i/%i\n", clientes[c].nome, clientes[c].endereco, clientes[c].cpf, clientes[c].nascimento.dia, clientes[c].nascimento.mes, clientes[c].nascimento.ano, clientes[c].emprestimo.valor, clientes[c].emprestimo.data.dia, clientes[c].emprestimo.data.mes, clientes[c].emprestimo.data.ano
                );
            
                break;
            case 3:
                printf("Qual cliente editar?: ");
                scanf("%i%*c", &c);
                
                printf("\n~~~~~~~~~~~~~ EDITANDO CLIENTE ~~~~~~~~~~~~~~");
                printf(
                    "\nO que vai editar?"
                    "\n[1]Nome"
                    "\n[2]Endereco"
                    "\n[3]CPF"
                    "\n[4]Data de nascimento"
                    "\n[0]Sair"
                    "\nResposta: "
                );
                scanf("%i%*c", &r); 
                if(r==0){break;}
                switch(r){
                    case 1:
                        printf("Novo nome: ");
                        fgets(clientes[c].nome, X, stdin);
                        break;
                    case 2:
                        printf("Novo endereco: ");
                        fgets(clientes[c].endereco, X, stdin);
                        break;
                    case 3:
                        printf("Novo CPF: ");
                        scanf("%i%*c", &clientes[c].cpf);
                        break;
                    case 4:
                        printf("\nNova data de nascimento: ");
                        printf("\nDia: ");
                        scanf("%i%*c", &clientes[c].nascimento.dia);
                        printf("Mes: ");
                        scanf("%i%*c", &clientes[c].nascimento.mes);
                        printf("Ano: ");
                        scanf("%i%*c", &clientes[c].nascimento.ano);
                        break;
                    default:
                        printf("~~~~ INVALIDO!!! ~~~~");
                        break;
                    }
                break;
            case 4:

                break;
            case 5:
                printf("\nPara qual cliente cadastrar emprestimo?: ");
                scanf("%i%*c", &c);
                printf("\n~~~~~~~~~~~ CADASTRAR EMPRESTIMO ~~~~~~~~~~~");
                if(clientes[c].cpf == 0){printf("Cliente nao cadastrado!!!"); break;}

                printf("\nDATA DO EMPRESTIMO: ");
                printf("\nDia: ");
                scanf("%i%*c", &clientes[c].emprestimo.data.dia);
                printf("Mes: ");
                scanf("%i%*c", &clientes[c].emprestimo.data.mes);
                printf("Ano: ");
                scanf("%i%*c", &clientes[c].emprestimo.data.ano);

                printf("\nValor do emprestimo: R$");
                scanf("%f%*c", &clientes[c].emprestimo.valor);

                break;
            case 6:
                printf("\nQual cliente excluir?: ");
                scanf("%i%*c", &c);
                strcpy(clientes[c].nome, "");
                strcpy(clientes[c].endereco, "");
                clientes[c].emprestimo.

                break;
            case 7:
                printf("\n~~~~~~~~~~~ CLIENTES CADASTRADOS ~~~~~~~~~~~\n");
                for(c=0; c<=X; c++){
                    if(clientes[c].cpf == 0){break;}
                    printf("[%i]%s", c, clientes[c].nome);
                }
                break;
            default:
                printf("~~~~ VALOR INVALIDO!!! ~~~~");
        }
    }

    return 0;
}