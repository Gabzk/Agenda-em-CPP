#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define TAM_MAX_CONTATOS 500

// Criação de enumeradores para tipos
enum tipoContato  {Comercial = 0, Fixo, Pessoal, Fax, Personalizado};
enum tipoRede     {Instagram = 0, Facebook, Twitter, Linkedin, Outros};
enum tipoEndereco {Alameda = 0, Avenida, Praca, Rua, Travessa};

// Definição de registro de contato
typedef struct agenda
{  
    char    nome[50];
    char    email[50];
    char    telefone[12];
    char    endereco[50];
    char    bairro[30];
    char    redeSocial[30];
    int     numero;
    enum    tipoContato tpC;
    enum    tipoEndereco tpEnd;
    enum    tipoRede tpR;
} tipoCadastro;

//Declaração prévia das sub-rotinas
void menu(void);
void adicionar(void);
void listar(void);
char *obterNomeContato ( enum tipoContato tpC );
char *obterNomeEndereco ( enum tipoEndereco tpEnd);
char *obterNomeRede ( enum tipoRede tpR );
char continuar(void);

//Variáveis Globais
FILE *ptrAgenda = NULL;
tipoCadastro contato[TAM_MAX_CONTATOS];
unsigned nContatos = 0;

int main()
{
    setlocale (LC_ALL , "" );
    system("color 3");
    menu();

    return 0;
}

void menu(void)
{   
    char op; // Variável de opção

    // Laço do menu do programa 
    while (op != '6')
    {
        system("cls");
        printf("\tAGENDA TELEFONICA\n"        );
        printf("\n ( 1 ) ADICIONAR CONTATO");
        printf("\n ( 2 ) MODIFICAR CONTATO");
        printf("\n ( 3 ) PESQUISAR CONTATO");
        printf("\n ( 4 ) EXCLUIR CONTATO");
        printf("\n ( 5 ) LISTAR CONTATOS");
        printf("\n ( 6 ) SAIR\n");

        op = tolower (getch()) ;

        switch (op)
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
                listar();
            break;

            case '6':
                system("cls");
                printf("\n\tPrograma Encerrado...\n");
            break;
            
            default:
                printf("\nOpção inválida. Digite novamente...");
                getch();
            break;
        }
    }

}

void adicionar(void)
{
    char op = 's';

    if(nContatos < TAM_MAX_CONTATOS)
    {
        while(op == 's')
        {
            system("cls");

            ptrAgenda = fopen("agenda.txt", "a");

            if(ptrAgenda == NULL)
            {
                printf("Erro ao abrir arquivo. Finalizando Programa...");
                exit(0);
            }

            printf("Nome: ");
            fflush(stdin);
            scanf("%[^\n]s", contato[nContatos].nome);

            printf("Email: ");
            fflush(stdin);
            scanf("%[^\n]s", contato[nContatos].email);

            printf("\nTipo de contatos:\n( 0 ) Comercial\n( 1 ) Fixo\n( 2 ) Pessoal\n( 3 ) Fax\n( 4 ) Personalizado\n Sua escolha:");
            fflush(stdin);
            scanf("%i", &contato[nContatos].tpC );

            printf("\nDDD e Telefone: ");
            fflush(stdin);
            scanf("%[^\n]s", contato[nContatos].telefone);

            printf("\nTipo do endereço:\n( 0 ) Alameda\n( 1 ) Avenida\n( 2 ) Praca\n( 3 ) Rua\n( 4 ) Travessa\n Sua escolha:");
            fflush(stdin);
            scanf("%i", &contato[nContatos].tpEnd);

            printf("\nEndereço: ");
            fflush(stdin);
            scanf("%[^\n]s", contato[nContatos].endereco);

            printf("Numero: ");
            fflush(stdin);
            scanf("%i", &contato[nContatos].numero);

            printf("Bairro: ");
            fflush(stdin);
            scanf("%[^\n]s", contato[nContatos].bairro);

            printf("\nTipo do Rede Social:\n( 0 ) Instagram\n( 1 ) Facebook\n( 2 ) Twitter\n( 3 ) Linkedin\n( 4 ) Personalizado\n Sua escolha:");
            fflush(stdin);
            scanf("%i", &contato[nContatos].tpR);

            printf("\nDigite o usuário: ");
            fflush(stdin);
            scanf("%[^\n]s", contato[nContatos].redeSocial);

            fprintf(ptrAgenda, "%s; %s; %i; %s; %i; %s; %i; %s; %i; %s\n", 
                contato[nContatos].nome, contato[nContatos].email, contato[nContatos].tpC,
                contato[nContatos].telefone, contato[nContatos].tpEnd, contato[nContatos].endereco,
                contato[nContatos].numero, contato[nContatos].bairro, contato[nContatos].tpR,
                contato[nContatos].redeSocial);

            fclose(ptrAgenda);
            ptrAgenda = NULL;

            nContatos++;
            op = continuar();
        }
    }
    else
    {
        printf("\n\tAgenda cheia...");
        getch();
    }
}

void listar(void)
{
    system("cls");
    ptrAgenda = fopen("agenda.txt", "r");
    
    for(int i = 0; i < 10 ; i++)
    {
        fscanf(ptrAgenda, "%s; %s; %i; %s; %i; %s; %i; %s; %i; %s", contato[i].nome, contato[i].email, &contato[i].tpC,
                contato[i].telefone, &contato[i].tpEnd, contato[i].endereco,
                &contato[i].numero, contato[i].bairro, &contato[i].tpR,
                contato[i].redeSocial);
            
        printf("Contato %i\n\n", i);
        printf("Nome: %s\n", contato[i].nome);
        printf("Email: %s\n", contato[i].email);
        printf("Telefone: %s\tTipo: %s\n", contato[i].telefone, obterNomeContato(contato[i].tpC));
        printf("Endereço: %s %s", obterNomeEndereco(contato[i].tpEnd), contato[i].endereco);
        printf("\tNúmero: %i", contato[i].numero);
        printf("\tBairro: %s\n", contato[i].bairro);
        printf("%s: %s",obterNomeRede(contato[i].tpR), contato[i].redeSocial);

        printf("\n\n");
    }
    getch();
}

char *obterNomeContato ( enum tipoContato tpC )
{
    const char *nomeContato[] =
    {
        "Comercial", "Fixo", "Pessoal", "Fax", "Personalizado"
    };

    return ( nomeContato [tpC]);
}

char *obterNomeEndereco ( enum tipoEndereco tpEnd)
{
    const char *nomeEndereco[] =
    {
        "Al.", "Av.", "Pr.", "R.", "Tr."
    };

    return ( nomeEndereco [tpEnd] );
}

char *obterNomeRede ( enum tipoRede tpR )
{
    const char *nomeRede[] =
    {
        "Instagram", "Facebook", "Twitter", "Linkedin", "Outros"
    };

    return ( nomeRede [tpR] );
}

char continuar(void)
{
    char op;
    do
    {
        printf("\nDeseja continuar? (S OU N)");
        
        op = tolower (getch());
    } while (op != 's' && op != 'n');
    
    return op;
}
