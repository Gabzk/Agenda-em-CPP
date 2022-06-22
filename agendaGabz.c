#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define TAM_MAX_CONTATOS 500
#define agenda "agenda.csv"

// Criação de enumeradores para tipos
enum tipoContato  {Comercial = 0, Fixo, Pessoal, Fax, Personalizado};
enum tipoRede     {Instagram = 0, Facebook, Twitter, Linkedin, Outros};
enum tipoEndereco {Alameda = 0, Avenida, Praca, Rua, Travessa};

// Definição de registro de contato
typedef struct ficha
{  
    char    nome[50];
    char    email[50];
    char    telefone[12];
    char    endereco[50];
    char    bairro[30];
    char    redeSocial[30];
    char    numero[10];
    
    enum    tipoContato tpC;
    char    tpContato[15];
    enum    tipoEndereco tpEnd;
    char    tpEndereco[15];
    enum    tipoRede tpR;
    char    tpRede[15];

} tipoCadastro;

//Sub-Rotinas
void menu();
void lerArquivo();
void Incluir(void);
void Listar(void);
char continuar();
char *obterNomeContato ( enum tipoContato tpC );
char *obterNomeEndereco ( enum tipoEndereco tpEnd);
char *obterNomeRede ( enum tipoRede tpR );

int qntd = 0;
tipoCadastro pessoa[TAM_MAX_CONTATOS];

int main()
{
    setlocale(LC_ALL, "");
    lerArquivo();
    system("color 3");
    menu();
    return 0;
}

void menu()
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

        op = getch();

        switch (op)
        {
            case '1':
                Incluir();
            break;
            
            case '2':

            break;

            case '3':

            break;

            case '4':
          
            break;

            case '5':
                system("cls");
                Listar();
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

/*========  Incluir Contatos na Agenda  ===========*/
void Incluir(void)
{
    FILE *ptrAgenda = NULL;
    tipoCadastro pessoa;
    char op = 's'; 

    ptrAgenda = fopen(agenda, "a");

    if(qntd < TAM_MAX_CONTATOS)
    {
        while (op == 's')
        {
            system("cls"); // limpar tela

            
            printf("\n\tDigite o nome: ");
            scanf("%[^\n]s", pessoa.nome);
            fflush(stdin);
            
            
            printf("\n\tTipo de contatos:\n\t( 0 ) Comercial\n\t( 1 ) Fixo\n\t( 2 ) Pessoal\n\t( 3 ) Fax\n\t( 4 ) Personalizado\n\t Sua escolha:");
            scanf("%i", &pessoa.tpC);
            fflush(stdin);
            strcpy(pessoa.tpContato, obterNomeContato(pessoa.tpC));
            

            printf("\n\tDigite o telefone: ");
            scanf("%[^\n]s", pessoa.telefone);
            fflush(stdin);
            

            printf("\n\tDigite o Email: ");
            scanf("%[^\n]s", pessoa.email);
            fflush(stdin);
            

            printf("\n\tTipo do endereço:\n\t( 0 ) Alameda\n\t( 1 ) Avenida\n\t( 2 ) Praca\n\t( 3 ) Rua\n\t( 4 ) Travessa\n\t Sua escolha:");
            scanf("%i", &pessoa.tpEnd);
            fflush(stdin);
            strcpy(pessoa.tpEndereco, obterNomeEndereco(pessoa.tpEnd));
            

            printf("\n\tDigite o Endereço: ");
            scanf("%[^\n]s", pessoa.endereco);
            fflush(stdin);
            

            printf("\n\tDigite o Número: ");
            scanf("%[^\n]s", pessoa.numero);
            fflush(stdin);
        
            

            printf("\n\tDigite o Bairro: ");
            scanf("%[^\n]s", pessoa.bairro);
            fflush(stdin);
            

            printf("\n\tTipo do Rede Social:\n\t( 0 ) Instagram\n\t( 1 ) Facebook\n\t( 2 ) Twitter\n\t( 3 ) Linkedin\n\t( 4 ) Personalizado\n\t Sua escolha:");
            scanf("%i", &pessoa.tpR);
            fflush(stdin);
            strcpy(pessoa.tpRede, obterNomeRede(pessoa.tpR));
            

            printf("\n\tDigite a Rede social: ");
            scanf("%[^\n]s", pessoa.redeSocial);
            fflush(stdin);
        
            fprintf(ptrAgenda, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", pessoa.nome, pessoa.tpContato, pessoa.telefone,
            pessoa.tpEndereco, pessoa.endereco, pessoa.numero, pessoa.bairro, pessoa.tpRede, pessoa.redeSocial);

            printf("\n\tGravacao ok! ");
            fprintf(ptrAgenda, "\n");

            op = continuar();
            qntd++;
            fclose(ptrAgenda); //fecha o arquivo agenda.csv
        }
    }
    else
    {
        printf("AGENDA CHEIA...");
        getch();
    }
}

void lerArquivo()
{
    FILE *lerAgenda = NULL;
    lerAgenda = fopen(agenda, "a+");
    
    while(!feof(lerAgenda))
    {
        rewind(lerAgenda);

        fgets(pessoa[qntd].nome, 50, lerAgenda);
        fgets(pessoa[qntd].tpContato, 50, lerAgenda);
        fgets(pessoa[qntd].telefone, 50, lerAgenda);
        fgets(pessoa[qntd].tpEndereco, 50, lerAgenda);
        fgets(pessoa[qntd].endereco, 50, lerAgenda);
        fgets(pessoa[qntd].numero, 50, lerAgenda);
        fgets(pessoa[qntd].bairro, 50, lerAgenda);
        fgets(pessoa[qntd].tpRede, 50, lerAgenda);
        fgets(pessoa[qntd].redeSocial, 50, lerAgenda);
        qntd++;
    }

    fclose(lerAgenda);

}
/*================== Lista os contatos cadastrados ======================*/
void Listar(void)
{
    // Só um teste pra ver se exibe algo
    printf("%s", pessoa[qntd].nome);
    getch();


}

char *obterNomeContato ( enum tipoContato tpC )
{
    char *nomeContato[] =
    {
        "Comercial", "Fixo", "Pessoal", "Fax", "Personalizado"
    };

    return ( nomeContato [tpC]);
}

char *obterNomeEndereco ( enum tipoEndereco tpEnd)
{
    char *nomeEndereco[] =
    {
        "Al.", "Av.", "Pr.", "R.", "Tr."
    };

    return ( nomeEndereco [tpEnd] );
}

char *obterNomeRede ( enum tipoRede tpR )
{
    char *nomeRede[] =
    {
        "Instagram", "Facebook", "Twitter", "Linkedin", "Outros"
    };

    return ( nomeRede [tpR] );
}

char continuar()
{
    char op;
    do
    {
        printf("\n\tDeseja continuar? (S OU N)");
        
        op = tolower (getch());
    } while (op != 's' && op != 'n');
    
    return op;
}

