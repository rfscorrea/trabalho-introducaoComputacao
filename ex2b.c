int main(){
    int respostaMenu;
    int flag = 1;
    while(flag!=0){
        printf("[1]Cadastrar cliente\n"
        "[2]Visualizar as informacoees de um cliente\n"
        "[3]Editar as informacoes de um cliente\n"
        "[4]Cadastrar parcela paga\n"
        "[5]Cadastrar emprestimo.\n"
        "[6]Excluir cliente\n"
        "[7]Sair");
        scanf("%i", &respostaMenu);

        switch (respostaMenu){
        case 1:
            //CADASTRO
            break;
        case 2:
            print();
            break;
        case 3:
            //EDITAR
            break;
        case 4:
            //CADASTRAR PARCELA PAGA
            break;
        case 5:
            //CADASTRAR EMPRÉSTIMO
            break;
        case 6:
            //EXCLUIR CLIENTE
            break;
        case 7:
            flag = 0;
            break;
        }
    }
    return(0);
}