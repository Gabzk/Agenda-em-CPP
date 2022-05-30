#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TAM_MAX_CONTATOS 500

// Enumerador definindo os tipos
enum tipoContato  {Comercial = 1, Fixo, Pessoal, Fax, Personalizado};
enum tipoRede     {Instagram = 1, Facebook, Twitter, Linkedin, Outros};
enum tipoEndereco {Alameda = 1, Avenida, Praca, Rua, Travessa};


// Registro definindo todas as informações que o contato vai salvar
typedef struct ficha
{
    char     nome[50];
    char     email[50];
    char     telefone[12];
    enum     tipoContato tpC;
    int      tipoCont;
    enum     tipoEndereco tpE;
    int      tipoEnd;
    char     endereco[50];
    char     bairro[30];
    unsigned int numero;
    char     redeSocial[30];
    enum     tipoRede tpR;
    int      tipoR;
    char     contatoPersonalizado[15];
    char     redeSocialPersonalizada[15];
} cadastro;

void adicionar();
void listar();

int main()
{
    cadastro contatos[TAM_MAX_CONTATOS];
    cadastro *ptrContatos;

    ptrContatos = &contatos[TAM_MAX_CONTATOS];
    
    system ("color 9F"); // Definindo cor do programa

    // Variáves inteiras de auxílio
    int opcao, indice = 0; 
   


    do
    {
        // Menu do programa
        system("cls");
        printf("\tAGENDA TELEFONICA\n"        );
        printf("\n ( 1 ) ADICIONAR CONTATO");
        printf("\n ( 2 ) MODIFICAR CONTATO");
        printf("\n ( 3 ) PESQUISAR CONTATO");
        printf("\n ( 4 ) EXCLUIR CONTATO");
        printf("\n ( 5 ) LISTAR CONTATOS");
        printf("\n ( 6 ) SAIR");

        printf("\n\n ESCOLHA UMA OPCAO: ");
        scanf ("%i", &opcao);
        fflush(stdin);

        switch (opcao)
        {
            // Case responsável pela inclusão de um novo contato
            case 1:

                indice++;
                adicionar(ptrContatos[indice]);
                
                break;
            
            case 2:


                break;

            case 3:



                break;
            // Case responsável por excluir um contato
            case 4:



                break;

            // Case responsável pela listagem de todos os contatos
            case 5:
                
                break;

            case 6:


                break;

            default:



                break;
        }

    } while(opcao != 6);

    return 0;
}

void adicionar(cadastro contatos)
{
    printf("Nome: ");
    scanf("%[^\n]", contatos.nome);
    fflush(stdin);

    printf("\nEmail: ");
    scanf("%[^\n]", contatos.email);
    fflush(stdin);

    printf("\nDDD e Telefone: ");
    scanf("%[^\n]", contatos.telefone);
    fflush(stdin);

    printf("\nTipo de contatos:\n( 1 ) Comercial\n( 2 ) Fixo\n( 3 ) Pessoal\n( 4 ) Fax\n( 5 ) Personalizado\n Sua escolha:");
    scanf("%i", &contatos.tipoCont);
    contatos.tpC = contatos.tipoCont;
    fflush(stdin);

    if(contatos.tpC == 5)
    {
        printf("\nDigite o tipo de contato: ");
        scanf ("%[^\n]", contatos.contatoPersonalizado);
        fflush(stdin);
    }

    printf("\nTipo do endereço:\n( 1 ) Alameda\n( 2 ) Avenida\n( 3 ) Praca\n( 4 ) Rua\n( 5 ) Travessa\n Sua escolha:");
    scanf("%i", &contatos.tpE);
    fflush(stdin);

    printf("\nEndereço: ");
    scanf("%[^\n]", contatos.endereco);
    fflush(stdin);

    printf("\nNumero: ");
    scanf("%i", &contatos.numero);
    fflush(stdin);

    printf("\nBairro: ");
    scanf("%[^\n]", contatos.bairro);
    fflush(stdin);

    printf("\nTipo do Rede Social:\n( 1 ) Instagram\n( 2 ) Facebook\n( 3 ) Twitter\n( 4 ) Linkedin\n( 5 ) Personalizado\n Sua escolha:");
    scanf("%i", &contatos.tpR);
    fflush(stdin);

    if(contatos.tpR == 5)
    {
        printf("\nDigite o tipo de Rede Social: ");
        scanf ("%[^\n]", contatos.redeSocialPersonalizada);
        fflush(stdin);
    }   


}

/*void listar(cadastro contatos[TAM_MAX_CONTATOS], int i)
{
    if( i == 0 )
    {
        printf("Nenhum contato cadastrado...");
    }

    else
    {
    
        for(int j = 1; j <= i; j++)
        {
            printf("Nome: %s", contatos[j].nome);
    
            printf("Email: %s", contatos[j].email);
            
            switch (contatos[j].tpC)
            {
                case Comercial:
                    
                    printf("Tipo de contato: Comercial\nTelefone: %s", contatos[j].telefone);

                    break;

                case Fixo:
                    
                    printf("Tipo de contato: Fixo\nTelefone: %s", contatos[j].telefone);

                    break;

                case Pessoal:
                    
                    printf("Tipo de contato: Pessoal\nTelefone: %s", contatos[j].telefone);

                    break;

                case Fax:
                    
                    printf("Tipo de contato: Fax\nTelefone: %s", contatos[j].telefone);

                    break;

                case Personalizado:
                    
                    printf("Tipo de contato: %s\nTelefone: %s", contatos[j].contatoPersonalizado, contatos[j].telefone);

                    break;    
                
            }

            switch (contatos[j].tpE)
            {
                case Alameda:
                    
                    printf("Alameda %s, %i, %s", contatos[j].endereco, contatos[j].numero, contatos[j].bairro);

                    break;
                
                case Avenida:
                    
                    printf("Avenida %s, %i, %s", contatos[j].endereco, contatos[j].numero, contatos[j].bairro);

                    break;

                case Rua:
                    
                    printf("Rua %s, %i, %s", contatos[j].endereco, contatos[j].numero, contatos[j].bairro);

                    break;

                case Travessa:
                    
                    printf("Travessa %s, %i, %s", contatos[j].endereco, contatos[j].numero, contatos[j].bairro);

                    break;
                
                case Praca:
                    
                    printf("Praca %s, %i, %s", contatos[j].endereco, contatos[j].numero, contatos[j].bairro);

                    break;
            }

            switch (contatos[j].tpR)
            {
                case Instagram:
                    printf("Instagram: %s", contatos[j].redeSocial);
                    break;
                
                case Facebook:
                    printf("Facebook: %s", contatos[j].redeSocial);
                    break;
                
                case Twitter:
                    printf("Twitter: %s", contatos[j].redeSocial);
                    break;
                
                case Linkedin:
                    printf("Linkedin: %s", contatos[j].redeSocial);
                    break;
                
                case Outros:
                    printf("%s: %s", contatos[j].redeSocialPersonalizada, contatos[j].redeSocial);
                    break;
            }
 
        }

    }
    

}
*/
