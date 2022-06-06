#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_MAX_NOME_ARQUIVO 100
#define TAM_MAX_DADOS        200

//TIPO DE VARIAVEL DO REGISTRO
typedef struct registro
{
    char nome [100] ;
    int tendereco;
    char endereco [100];
    int numero;
    int tcontato;
    char contato [12];
    char email [100];
    int trede;
    char redes_sociais1 [100];

}VRegistro;

enum tipo_endereco {Alameda, Avenida, Praca, Rua, Travessa} tendereco;
enum tipo_contato {celular, comercial, fixo, pessoal, fax, personalizado} tcontato;
enum tipo_redessociais {Instagram, Facebook, Linkedin, Outros} trede;


// DECLARANDO SUB-ROTINAS
int AdicionarContato (VRegistro registro[], int i);

//FUNÇÃO PRINCIPAL
int main (int argc, char*argv ){
setlocale (LC_ALL,""); 
system ("color 8F");

// DECLARANDO VARIAVEIS E VETORES

VRegistro registro [3];
int opcao=0, i=0;
const char *nomesTipoEndereco[] = { "Alameda", "Avenida", "Pra�a", "Rua", "Travessa" };
char nomeArquivo [ TAM_MAX_NOME_ARQUIVO ];


//PONTEIRO PARA REGISTRO
FILE *ptrArquivo = NULL;
ptrArquivo = fopen ( "registro.txt", "r" );


//TESTE DE FUNCIONALIDADE
if ( ptrArquivo == NULL ){
    printf ( "Nao foi possivel criar o arquivo.\n" );
    printf ( "Finaliando execucao...\n" );
    exit ( 0 );
    }


//VARIAVEIS QUE SERAO REGISTRADA DENTRO DO ARQUIVO
char dados [ TAM_MAX_DADOS ];
int  contMsg = 1;
int  tamMsg = 0;


//MENU DA AGENDA
printf ("\n\t ######## AGENDA ######## \n");
printf ("\t -- ESCOLHA UMA OPCAO -- \n\n");
printf ("\t 1 - ADICIONAR CONTATO \n");
printf ("\t 2 - ALTERAR CONTATO \n");
printf ("\t 3 - CONSULTAR CONTATO \n");
printf ("\t 4 - DELETAR CONTATO \n");
printf ("\t 5 - LISTAR CONTATOS \n");
printf ("\t 6 - SAIR \n");
printf("\n Opcao: ");
scanf ("%d", &opcao);

    switch (opcao)
        {
        case(1):
            i = AdicionarContato(registro, i); 
            printf("%d",i);
            break;

        default:
            break;
        }

    return 0;
}


int AdicionarContato (VRegistro registro[], int i){

    printf("\n\tPREENCHA OS CAMPOS A SEGUIR: \n");
    printf("\n\tNome:");
    fflush(stdin);
    scanf("%s",&registro[i].nome);
    printf("\n\tTipo de endereco: \n\t( 0 )-Alameda \n\t( 1 )-Avenida \n\t( 2 )-Praca \n\t( 3 )-Rua \n\t( 4 )-Travessa");
    printf("\n\tOpcao: ");
    fflush(stdin);
    scanf("%s",&registro[i].tendereco);
    printf("\n\tEndereco:");
    fflush(stdin);
    scanf("%s",&registro[i].endereco);
    printf("\n\tNumero:");
    fflush(stdin);
    scanf("%s",&registro[i].numero);
    printf("\n\tTipo de contato: \n\t( 0 )-Celular \n\t( 1 )-Comercial \n\t( 2 )-Fixo \n\t( 3 )-Pessoal \n\t( 4 )-Fax \n\t( 5 )-Personalizado");
    printf("\n\tOpcao: ");
    fflush(stdin);
    scanf("%s",&registro[i].tcontato);
    printf("\n\tTelefone para contato:");
    fflush(stdin);
    scanf("%s",&registro[i].contato);
    printf("\n\tEmail:");
    fflush(stdin);
    scanf("%s",&registro[i].email);
    printf("\n\tTipo de rede social: \n\t( 0 )-Instagram \n\t( 1 )-Facebook \n\t( 2 )-Linkedin \n\t( 3 )-Outros");
    printf("\n\tOpcao: ");
    fflush(stdin);
    scanf("%s",&registro[i].trede);
    printf("\n\tRede Social:");
    fflush(stdin);
    scanf("%s",&registro[i].redes_sociais1);

    return i=i+1;
}
