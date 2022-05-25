#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TAM_MAX_CONTATOS 500

struct aniversario
{
    int dia;
    int mes;
    int ano;
};

struct telefone
{
    char ddd[3];
    char tel[9];
};

struct email
{
    char nomeEmail[30];
    char dominio[30];
};

typedef struct ficha
{
    char     nome[50];
    enum     tipoEndereco {Alameda = 1, Avenida, Praca, Rua, Travessa};
    char     endereco[50];
    unsigned int numero;
    struct   telefone tel;
    struct   email email;
    char     redeSocial[30];
    enum     tipoRede {Insta = 1, Facebook, Twitter, Linkedin, Outros};
    struct   aniversario aniversario;

} cadastro;

int main()
{
    cadastro contatos[TAM_MAX_CONTATOS];
    int op, i = 0;
    system ("color 9F");


    do 
    {
        system("cls");
        printf("\tAGENDA TELEFONICA\n"        );
        printf("\n ( 1 ) ADICIONAR CONTATO\n");
        printf("\n ( 2 ) MODIFICAR CONTATO\n");
        printf("\n ( 3 ) PESQUISAR CONTATO\n");
        printf("\n ( 4 ) EXCLUIR CONTATO\n");
        printf("\n ( 5 ) LISTAR CONTATOS\n");
        printf("\n ( 6 ) SAIR\n");

        printf("\n ESCOLHA UMA OPCAO: ");
        scanf ("%i", &op);
        fflush(stdin);

        switch (op)
        {
            case 1:
                printf("Nome: ");
                 
                
                break;
            
        }

    } while(op != 6);

    return 0;
}

void adicionarContato()
{
    
    
    
}
