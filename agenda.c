#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define TAM_MAX_CONTATOS 100

struct aniversario
{
    int dia;
    int mes;
    int ano;
};

struct endereco
{
    char rua[30];
    int numero;
    char bairro[30];
    char cidade[30];

};

struct telefone
{
    char ddd[3];
    char tel[9];
};

typedef struct ficha
{
    char nome[40];
    char email[40];
    struct telefone telefone;
    struct aniversario aniversario;
    struct endereco endereco;

} contato;

int main()
{
    contato contatos[TAM_MAX_CONTATOS];

    int op1, i = 0;

    do {
        system("cls");
        printf(" AGENDA TELEFONICA \n"        );
        printf("    ( 1 ) CADASTRAR CONTATO\n");
        printf("    ( 2 ) LISTAR CONTATOS\n"  );
        printf("    ( 3 ) EXCLUIR CONTATO\n"  );
        printf("    ( 4 ) SAIR\n"             );

        printf("\n ESCOLHA UMA OPCAO: "       );
        scanf ("%i", &op1);
        fflush(stdin);

        switch (op1)
        {
            case 1:
                
                printf("CONTATO: %i\n", i);

                printf("NOME: ");
                scanf ("%[^\n]s", contatos[i].nome);
                fflush(stdin);

                printf("EMAIL: ");
                scanf ("%[^\n]s", contatos[i].email);
                fflush(stdin);

                printf("DDD: ");
                scanf ("%[^\n]s", contatos[i].telefone.ddd);
                fflush(stdin);

                printf("TELEFONE: ");
                scanf ("%[^\n]s", contatos[i].telefone.tel);
                fflush(stdin);

                printf("ENDERECO: ");
                scanf ("%[^\n]s, %i, %[^\n]s, %[^\n]s", contatos[i].endereco.rua,
                contatos[i].endereco.numero, contatos[i].endereco.bairro, contatos[i].endereco.cidade);
                fflush(stdin);

                printf("ANIVERSARIO: ");
                scanf ("%i/%i/%i", &contatos[i].aniversario.dia, &contatos[i].aniversario.mes, &contatos[i].aniversario.ano);
                fflush(stdin);

                i++;
                
            break;
        }

    } while(op1 != 4);

    return 0;
}