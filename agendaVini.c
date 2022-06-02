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
    enum tipo_endereco {Alameda, Avenida, Praca, Rua, Travessa} tendereco;
    char endereco [100];
    int numero;
    enum tipo_contato {celular, comercial, fixo, pessoal, fax, personalizado};
    char telefone [12];
    char email [100];
    char redes_sociais1 [100];
    enum tipo_redessociais {Instagram, Facebook, Linkedin, Outros};
    

}VRegistro;
int AdicionarContato (VRegistro registro[], int i);


int main (int argc, char*argv ){


// DECLARANDO VARIAVEIS E VETORES
setlocale (LC_ALL,""); 
VRegistro registro [3];
int opcao, i=0;
const char *nomesTipoEndereco[] = { "Alameda", "Avenida", "Pra�a", "Rua", "Travessa" };
char nomeArquivo [ TAM_MAX_NOME_ARQUIVO ];


//PONTEIRO PARA REGISTRO
FILE *ptrArquivo = NULL;
ptrArquivo = fopen ( "registro.txt", "w" );


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

/*do
    {
        strcpy ( dados, "" );
        printf ( "Msg. %02i: ", contMsg++ );
        fflush ( stdin );
        scanf  ( "%[^\n]s", dados );

        tamMsg = strlen ( dados );
        if ( tamMsg > 0 )
        {
            fprintf ( ptrArquivo, "%s\n", dados );
        }
    } while ( tamMsg > 0 );

printf ( "\nVoc� teclou <ENTER> com mensagem vazia, finalizando...\n" );
printf ( "Fechando o arquivo: %s.\n", nomeArquivo );

fclose ( ptrArquivo );
ptrArquivo = NULL;*/

do
{
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
            break;

        default:
            break;
        }
    }
while (i++);

    return 0;
}
int AdicionarContato (VRegistro registro[], int i){

    printf("\nPREENCHA OS CAMPOS A SEGUIR: \n");
    printf("\nNome:");
    fflush(stdin);
    scanf("%s",registro[i].nome);
    printf("\nEndereco:");
    fflush(stdin);
    scanf("%s",registro[i].endereco);
    printf("\nNumero:");
    fflush(stdin);
    scanf("%s",registro[i].numero);
    printf("\nEmail:");
    fflush(stdin);
    scanf("%s",registro[i].email);
    printf("\nRede Social:");
    fflush(stdin);
    scanf("%s",registro[i].redes_sociais1);

    return i++;
}