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
    enum     tipoRede {Instagram = 1, Facebook, Twitter, Linkedin, Outros};
    struct   aniversario aniversario;
    enum     tipoContato {Celular = 1, Comercial, Fixo, Pessoal, Fax, Personalizado};
    char     contatoPersonalizado[15];
    char     redeSocialPersonalizada[15];


} cadastro;

int main()
{
    cadastro contatos[TAM_MAX_CONTATOS];
    system ("color 9F");
    int op, i = 0, tipoEnd[TAM_MAX_CONTATOS], tipoCont[TAM_MAX_CONTATOS], tipoSocial[TAM_MAX_CONTATOS];


    do 
    {
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
            case 1:
                i++;
                system("cls");

                printf("Nome: ");
                scanf("%[^\n]s", contatos[i].nome);
                fflush(stdin);

                printf("Email: ");
                scanf("%[^@]s", contatos[i].email.nomeEmail);     
                scanf("%[^\n]s", contatos[i].email.dominio);
                fflush(stdin);

                system("cls");
                printf("Tipo de endereco\n( 1 ) Alameda\n( 2 ) Avenida\n( 3 ) Praca\n( 4 ) Rua\n( 5 ) Travessa");
                printf("\nSua escolha: ");
                scanf("%i", &tipoEnd[i]);
                fflush(stdin);

                printf("\nEndereco: ");
                scanf("%[^\n]s", contatos[i].endereco);
                fflush(stdin);

                printf("\nNumero do endereco: ");
                scanf("%i", &contatos[i].numero);
                fflush(stdin);

                system("cls");
                printf("DDD: ");
                scanf("%[^\n]s", contatos[i].tel.ddd);
                fflush(stdin);

                printf("Telefone: ");
                scanf("%[^\n]s", contatos[i].tel.tel);
                fflush(stdin);

                printf("\nTipo de contato\n( 1 ) Celular\n( 2 ) Comercial\n( 3 ) Fixo\n( 4 ) Pessoal\n( 5 ) Fax\n( 6 ) Personalizado");
                printf("\nSua escolha: ");
                scanf("%i", &tipoCont[i]);
                fflush(stdin);

                if(tipoCont[i] == 6)
                {
                    printf("\nDigite o tipo de contato:");
                    scanf("%[^\n]s", contatos[i].contatoPersonalizado);
                    fflush(stdin);
                }

                system("cls");
                printf("Rede social: ");
                scanf("%[^\n]s", contatos[i].redeSocial);
                fflush(stdin);

                printf("\nTipo de rede social\n( 1 ) Instagram\n( 2 ) Facebook \n( 3 ) Twitter\n( 4 ) Linkedin\n( 5 ) Outros\n");
                printf("\nSua escolha: ");
                scanf("%i", &tipoSocial[i]);
                fflush(stdin);
                            
                if(tipoSocial[i] == 5)
                {
                    printf("\nDigite a rede social: ");
                    scanf("%[^\n]s", contatos[i].redeSocialPersonalizada);
                    fflush(stdin);
                }

                printf("\nPressione enter para continuar...");
                getchar();
                
                break;
            
            case 5:

                system("cls");

                if(i == 0)
                {  
                    printf("Nenhum contato cadastrado\n");
                }

                else
                {
                    for(int j = 1; j <= i; j++)
                    {
                        printf("Contato: %i\n", j);
                        printf("Nome: %s\n", contatos[j].nome);

                        printf("Email: %s%s\n", contatos[j].email.nomeEmail, contatos[j].email.dominio);
                        printf("Endereco: ");
                        switch(tipoEnd[j])

                        {
                            case Alameda:
                                printf("Alameda %s, %i\n", contatos[j].endereco, contatos[j].numero);
                            break;
                            
                            case Avenida:
                                printf("Avenida %s, %i\n", contatos[j].endereco, contatos[j].numero);
                            break;

                            case Praca:
                                printf("Praca %s, %i\n", contatos[j].endereco, contatos[j].numero);
                            break;

                            case Rua:
                                printf("Rua %s, %i\n", contatos[j].endereco, contatos[j].numero);
                            break;

                            case Travessa:
                                printf("Travessa %s, %i\n", contatos[j].endereco, contatos[j].numero);
                            break;
                        }
                        
                        printf("Telefone: (%s) %s\n", contatos[j].tel.ddd, contatos[j].tel.tel);
                        
                        switch(tipoCont[j])
                        {
                            case Celular:
                                printf("Tipo de contato: Celular\n");
                            break;
                            
                            case Comercial:
                                printf("Tipo de contato: Comercial\n");
                            break;

                            case Fixo:
                                printf("Tipo de contato: Fixo\n");
                            break;

                            case Pessoal:
                                printf("Tipo de contato: Pessoal\n");
                            break;

                            case Personalizado:
                                printf("Tipo de contato: %s\n", contatos[i].contatoPersonalizado);
                            break;
                        }
                        
                        switch (tipoSocial[j])
                        {
                        case Instagram:
                            printf("Instagram: %s\n", contatos[j].redeSocial);
                            break;
                        
                        case Facebook:
                            printf("Facebook: %s\n", contatos[j].redeSocial);
                            break;

                        case Twitter:
                            printf("Twitter: %s\n", contatos[j].redeSocial);
                            break;

                        case Linkedin:
                            printf("Linkedin: %s\n", contatos[j].redeSocial);
                            break;
                        case Outros:
                            printf("%s: %s\n", contatos[j].redeSocialPersonalizada, contatos[j].redeSocial);
                            break;
                        }
                    }
                }
                printf("\nPressione enter para continuar...");
                getchar();
                
            break;
        }

    } while(op != 6);

    return 0;
}

