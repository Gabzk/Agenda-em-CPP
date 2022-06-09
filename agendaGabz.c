#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define TAM_MAX_CONTATOS 500

// Enumerador definindo os tipos
enum tipoContato  {Comercial = 1, Fixo, Pessoal, Fax, Personalizado};
enum tipoRede     {Instagram = 1, Facebook, Twitter, Linkedin, Outros};
enum tipoEndereco {Alameda = 1, Avenida, Praca, Rua, Travessa};


// Registro definindo todas as informações que o contato vai salvar
typedef struct ficha
{
    char    nome[50];
    char    email[50];
    char    telefone[12];
    enum    tipoContato tpC;
    int     tipoCont;
    enum    tipoEndereco tpE;
    int     tipoEnd;
    char    endereco[50];
    char    bairro[30];
    int     numero;
    char    redeSocial[30];
    enum    tipoRede tpR;
    int     tipoR;
    char    contatoPersonalizado[15];
    char    redeSocialPersonalizada[15];

} cadastro;



FILE *agenda = NULL;
cadastro contatos[TAM_MAX_CONTATOS];



void menu(void);
void adicionar(void);
void listar(void);
char continuar();



int main()
{ 
    setlocale(LC_ALL, "Portuguese");
    system ("color 9F");
    menu();

    return 0;
}


void menu(void)
{   
    char opcao; // Variável de opção

    // Laço do menu do programa 
    while (opcao != 6)
    {
        system("cls");
        printf("\tAGENDA TELEFONICA\n"        );
        printf("\n ( 1 ) ADICIONAR CONTATO");
        printf("\n ( 2 ) MODIFICAR CONTATO");
        printf("\n ( 3 ) PESQUISAR CONTATO");
        printf("\n ( 4 ) EXCLUIR CONTATO");
        printf("\n ( 5 ) LISTAR CONTATOS");
        printf("\n ( 6 ) SAIR\n");

        opcao = getch();

        switch (opcao)
        {
            case '1':
                adicionar();
            break;
            
            case '2':

            break;

            case '3':

            break;

            case '4':
          
            break;

            case '5':
                system("cls");
                listar();
            break;

            case '6':
                system("cls");
                printf("Programa Encerrado");
                fclose(agenda);
            break;
            
            default:
                printf("\nOpção inválida. Digite novamente...");
                getch();
        }
    }

}

void adicionar(void)
{
    int nContatos = 0, gravar;
    char op = 's';

    agenda = fopen("agenda.csv", "a");
    if(agenda == NULL)
    {
        printf("\nErro ao abrir o arquivo. Encerrando programa...");
        getch();
        exit(1);
    }

    while((nContatos < TAM_MAX_CONTATOS) && (op == 's'))
    {
        system("cls");
        printf("Nome: ");
        scanf("%[^\n]s", contatos[nContatos].nome);
        fflush(stdin);

        printf("\nEmail: ");
        scanf("%[^\n]s", contatos[nContatos].email);
        fflush(stdin);

        printf("\nDDD e Telefone: ");
        scanf("%[^\n]s", contatos[nContatos].telefone);
        fflush(stdin);

        printf("\nTipo de contatos:\n( 1 ) Comercial\n( 2 ) Fixo\n( 3 ) Pessoal\n( 4 ) Fax\n( 5 ) Personalizado\n Sua escolha:");
        scanf("%i", &contatos[nContatos].tipoCont);
        fflush(stdin);

        if(contatos[nContatos].tipoCont == 5)
        {
            printf("\nDigite o tipo de contato: ");
            scanf ("%[^\n]s", contatos[nContatos].contatoPersonalizado);
            fflush(stdin);
        }

        printf("\nTipo do endereço:\n( 1 ) Alameda\n( 2 ) Avenida\n( 3 ) Praca\n( 4 ) Rua\n( 5 ) Travessa\n Sua escolha:");
        scanf("%i", &contatos[nContatos].tipoEnd);
        fflush(stdin);

        printf("\nEndereço: ");
        scanf("%[^\n]s", contatos[nContatos].endereco);
        fflush(stdin);

        printf("\nNumero: ");
        scanf("%i", &contatos[nContatos].numero);
        fflush(stdin);

        printf("\nBairro: ");
        scanf("%[^\n]s", contatos[nContatos].bairro);
        fflush(stdin);

        printf("\nTipo do Rede Social:\n( 1 ) Instagram\n( 2 ) Facebook\n( 3 ) Twitter\n( 4 ) Linkedin\n( 5 ) Personalizado\n Sua escolha:");
        scanf("%i", &contatos[nContatos].tipoR);
        fflush(stdin);

        if(contatos[nContatos].tipoR == 5)
        {
            printf("\nDigite o tipo de Rede Social: ");
            scanf ("%[^\n]s", contatos[nContatos].redeSocialPersonalizada);
            fflush(stdin);
        }

        printf("\nDigite o usuário: ");
        scanf("%[^\n]s", contatos[nContatos].redeSocial);
        fflush(stdin);

        gravar = fwrite(&contatos[nContatos], sizeof(contatos), 1, agenda);
        if(gravar == 1)
        {
            printf("\nContato salvo!");
        }
        else
        {
            printf("\nErro ao salvar contato.");
        }
        
        nContatos++;
        op = continuar();

        }
        
        fclose(agenda);
        getchar();
        printf("\nPressione Enter para continuar");
}


char continuar()
{
    char op;
    do
    {
        printf("\nDeseja continuar? (S OU N)");
        
        op = getch();
    } while (op != 's' && op != 'n');
    
    return op;
}


void listar(void)
{
    int i = 0, ler;

    agenda = fopen("agenda.csv", "r");
    if(agenda == NULL)
    {
        printf("Erro ao abrir arquivo. Encerrando programa...");
        getch();
        exit(1);
    }

    ler = fread(&contatos[i], sizeof(contatos), 1, agenda);
    while(ler == 1)
    { 
        printf("Contato %i\n\n", i);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Email: %s\n", contatos[i].email);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("Endereço: %s", contatos[i].endereco);
        printf("\tNúmero: %i", contatos[i].numero);
        printf("\tBairro: %s\n", contatos[i].bairro);
        printf("Rede social: %s", contatos[i].redeSocial);
        printf("\n\n");
        
        i++;
        ler = fread(&contatos[i], sizeof(contatos), 1, agenda);

    }
    getch();
}


char *obterNomeEndereco (enum tipoEndereco tpE)
{
    const char *nomeEndereco[] =
    {
        "Alameda", "Avenida", "Praça", "Rodovia", "Rua", "Travessa"
    };

    return ( nomeEndereco [tpE] );
}
