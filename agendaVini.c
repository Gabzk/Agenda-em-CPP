#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>      
#include <locale.h>

#define MAX 100
#define DADOS 200

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

}contatos;

enum tipo_endereco {Alameda, Avenida, Praca, Rua, Travessa} tendereco;
enum tipo_contato {celular, comercial, fixo, pessoal, fax, personalizado} tcontato;
enum tipo_redessociais {Instagram, Facebook, Linkedin, Outros} trede;

// VARIÁVEIS GLOBAIS
static int qtd = 0;     // qtd é uma variavel do tipo estatica que conta a quantidade de contatos incritos
contatos max[MAX];      // agora max[100] é um vetor do tipo contatos definido com o typedef
FILE *arq;              // ponteiro 

// DECLARANDO SUB-ROTINAS
void Menu();
void AdicionarContato (void);
char AdicionarOutro ();
void AlterarContato ();

//FUNÇÃO PRINCIPAL
int main (){
setlocale (LC_ALL,""); 
system ("color 8F");

/*const char *nomesTipoEndereco[] = { "Alameda", "Avenida", "Pra�a", "Rua", "Travessa" };
char nomeArquivo [ MAX ];   
*/

//VARIAVEIS QUE SERAO REGISTRADA DENTRO DO ARQUIVO

int  contMsg = 1;
int  tamMsg = 0;

Menu();


    return 0;
}

void Menu (){

system("cls");

//DECLARANDO VARIAVEIS E VETORES
int op=0;

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
scanf ("%d", &op);

    switch (op)
        {
        case(1):
            system("cls");
            AdicionarContato(); 
            Menu();
            break;
        
        case(2):
            system("cls");
            AlterarContato(); 
            Menu();
            break;

        case(6):
        system("cls");
        printf("Encerrando...");
        exit(1);

        default:
        printf("\n Operacao INVALIDA!");
            break;
        }

}

void AdicionarContato (void){

    char dados [ DADOS];
    int cont = 0;   //contador
    int retorno;    //retorno seve para definir se fwrite funcionou
    char opcao = 's';  //opcao para saber se vai AddMais()

    arq = fopen("agenda.csv", "a"); //Abrindo/ criando arquivo se ele não existir 


    if(arq == NULL){                             // Teste para ver se o arquivo abriu corretamente
        printf("Erro ao abrir o arquivo!");     // Mensagem exibida se o arquivo der erro
        getchar();                             // Eseprando resposta do usario para sair do programa
        exit(1);
    }



    while ((cont < MAX) && (opcao == 's'))
    {

        printf("\n\tPREENCHA OS CAMPOS A SEGUIR: \n");
        
        printf("\n\tNome:");
        fflush(stdin);
        gets(max[cont].nome);
        
        printf("\n\tTipo de endereco: \n\t( 0 )-Alameda \n\t( 1 )-Avenida \n\t( 2 )-Praca \n\t( 3 )-Rua \n\t( 4 )-Travessa \n\t Opcao: ");
        fflush(stdin);
        gets(&max[cont].tendereco);
        
        printf("\n\tEndereco:");
        fflush(stdin);
        gets(max[cont].endereco);
        
        printf("\n\tNumero:");
        fflush(stdin);
        gets(&max[cont].numero);
        
        printf("\n\tTipo de contato: \n\t( 0 )-Celular \n\t( 1 )-Comercial \n\t( 2 )-Fixo \n\t( 3 )-Pessoal \n\t( 4 )-Fax \n\t( 5 )-Personalizado");
        
        printf("\n\tOpcao: ");
        fflush(stdin);
        gets(&max[cont].tcontato);
        
        printf("\n\tTelefone para contato:");
        fflush(stdin);
        gets(max[cont].contato);
        
        printf("\n\tEmail:");
        fflush(stdin);
        gets(max[cont].email);
        
        printf("\n\tTipo de rede social: \n\t( 0 )-Instagram \n\t( 1 )-Facebook \n\t( 2 )-Linkedin \n\t( 3 )-Outros");
        
        printf("\n\tOpcao: ");
        fflush(stdin);
        gets(&max[cont].trede);
        
        printf("\n\tRede Social:");
        fflush(stdin);
        gets(max[cont].redes_sociais1);


    retorno = fwrite (&max[cont], sizeof(contatos) ,1,arq);

    if (retorno == 1) {
               printf("\n");
           }
           cont++;                         //enquanto cont for menor que o tamanho definido adiciona mais um contato
           opcao = AdicionarOutro();      //chama a função que pergunta se deseja inserir outros contatos
           qtd++;                        //acrecenta 1 contato a mais a variavel global
     }
     fclose (arq);  //fecha o arquivo agenda.txt

}

char AdicionarOutro (){

char opcao;    

do {
    printf ("\n Deseja adicionar outro contato? s/n");
    opcao = getchar();
    printf("\n");
} while (opcao != 's' && opcao != 'n');

    return opcao;

}

void AlterarContato (){


}
