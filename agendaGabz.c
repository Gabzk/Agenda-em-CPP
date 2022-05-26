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
    enum     tipoEndereco tpE;
    char     endereco[50];
    char     bairro[30];
    unsigned int numero;
    char     redeSocial[30];
    enum     tipoRede tpR;
    char     contatoPersonalizado[15];
    char     redeSocialPersonalizada[15];
} cadastro;

int main()
{
    cadastro contatos[TAM_MAX_CONTATOS];
    
    system ("color 9F"); // Definindo cor do programa

    // Variáves inteiras de auxílio
    int op, i = 0; 
   


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
        scanf ("%i", &op);
        fflush(stdin);

        switch (op)
        {
            // Case responsável pela inclusão de um novo contato
            case 1:
                
                
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

    } while(op != 6);

    return 0;
}


