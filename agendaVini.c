#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>      
#include <locale.h>

#define MAX 250
#define DADOS 200
#define agenda "Agenda.csv"



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


//SUB-ROTINAS
void criarContato();
void inserirContato(contatos contato);
void salvarContato(contatos contato, FILE *arq);
void carregarAgenda();
void mostrarContato(int i);
void listarContatos();
int compararLetras();
void procurarContato();
void editarContato ();
void deletarContato();


static int qtd = 0;     // variavel que conta a quantidade de contatos incritos
contatos vetorContatos[MAX];


int main(void){

carregarAgenda();

system("cls");
system("COLOR 8F");

int op=0;

do{
system("cls");

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
            fflush(stdin);
            criarContato();
            break;
        
            case(2):
            system("cls");
            fflush(stdin);
            editarContato();

            break;

            case(3):
            system("cls");
            fflush(stdin);
            procurarContato(); 
            break;

            case(4):
            system("cls");
            fflush(stdin);
            deletarContato(); 
            break;

            case(5):
            system("cls");
            fflush(stdin);
            carregarAgenda();
            listarContatos(); 
            break;

            case(6):
            system("cls");
            printf("\n\t Encerrando...");
            exit(1);

            default:
            printf("\n Operacao INVALIDA!");
            break;
        }
    }
    while(op);
    return 0;
}

void carregarAgenda (){

    FILE *arq = fopen(agenda, "r");

    qtd = 0;
	
	if(!arq == NULL){
		rewind(arq);			
		
		while(!feof(arq)){      //feof diz quando o arquivo chega ao fim.
			fgets(vetorContatos[qtd].nome, 50, arq);
			if(strcmp(vetorContatos[qtd].nome, "") > 0){ 
				fgets(&vetorContatos[qtd].tendereco, 10, arq);
				fgets(vetorContatos[qtd].endereco, 50, arq);
                fgets(&vetorContatos[qtd].numero, 20, arq);
                fgets(&vetorContatos[qtd].tcontato, 10, arq);
                fgets(vetorContatos[qtd].contato, 50, arq);
                fgets(vetorContatos[qtd].email, 50, arq);
                fgets(&vetorContatos[qtd].trede, 10, arq);
                fgets(vetorContatos[qtd].redes_sociais1, 50, arq);
				qtd++;
                
			}
		}		
	}
    else{
		printf("ERRO ao carregar agenda!.\n");
	}

    fclose(arq);
}

void criarContato (){

contatos contato;

    if(qtd < MAX){

        printf("\n\tPREENCHA OS CAMPOS A SEGUIR: \n");
        
        printf("\n\tNome:");
        fflush(stdin);
        fgets(contato.nome,50,stdin);
        
        printf("\n\tTipo de endereco: \n\t( 0 )-Alameda \n\t( 1 )-Avenida \n\t( 2 )-Praca \n\t( 3 )-Rua \n\t( 4 )-Travessa \n\t Opcao: ");
        fflush(stdin);
        scanf("%i",&contato.tendereco);
        
        printf("\n\tEndereco:");
        fflush(stdin);
        fgets(contato.endereco,50,stdin);

        printf("\n\tNumero:");
        fflush(stdin);
        scanf("%i",&contato.numero);
        
        printf("\n\tTipo de contato: \n\t( 0 )-Celular \n\t( 1 )-Comercial \n\t( 2 )-Fixo \n\t( 3 )-Pessoal \n\t( 4 )-Fax \n\t( 5 )-Personalizado");
        
        printf("\n\tOpcao: ");
        fflush(stdin);
        scanf("%i",&contato.tcontato);
        
        printf("\n\tTelefone para contato:");
        fflush(stdin);
        fgets(contato.contato,12,stdin);
        
        printf("\n\tEmail:");
        fflush(stdin);
        fgets(contato.email,50,stdin);
        
        printf("\n\tTipo de rede social: \n\t( 0 )-Instagram \n\t( 1 )-Facebook \n\t( 2 )-Linkedin \n\t( 3 )-Outros");
        
        printf("\n\tOpcao: ");
        fflush(stdin);
        scanf("%i",&contato.trede);
        
        printf("\n\tRede Social:");
        fflush(stdin);
        fgets(contato.redes_sociais1,50,stdin);

    inserirContato(contato);
    }else{
    printf("\n\t Memoria insuficiente! ");
}
}

void inserirContato(contatos contato){

    FILE *arq = fopen (agenda, "a+");
	
	if(arq == NULL){                             // Teste para ver se o arquivo abriu corretamente
        printf("Erro ao abrir o arquivo!");     // Mensagem exibida se o arquivo der erro
        getchar();                             // Eseprando resposta do usario para sair do programa
        exit(1);
    }
    else{
		salvarContato(contato, arq);
		vetorContatos[qtd] = contato;
		qtd++;
	}
    
	fclose(arq);
	

}

void salvarContato(contatos contato, FILE *arq){

    fprintf(arq,contato.nome);
    fprintf(arq,"%i\n",contato.tendereco);
    fprintf(arq,contato.endereco);
    fprintf(arq,"%i\n",contato.numero);
    fprintf(arq,"%i\n",contato.tcontato);
    fprintf(arq,contato.contato);
    fprintf(arq,contato.email);
    fprintf(arq,"%i\n",contato.trede);
    fprintf(arq,contato.redes_sociais1);

}

void mostrarContato(int i){
	
    printf("\n\t CONTATO: %i", i+1);

	printf("\n\n\t Nome: %s", vetorContatos[i].nome);
	printf("\t Tipo de endereco: %s", &vetorContatos[i].tendereco);
	printf("\t Endereco: %s", vetorContatos[i].endereco);
    printf("\t Numero: %s", &vetorContatos[i].numero);
    printf("\t Tipo de contato: %s", &vetorContatos[i].tcontato);
    printf("\t Contato: %s", vetorContatos[i].contato);
    printf("\t Email: %s", vetorContatos[i].email);
    printf("\t Tipo de rede: %s", &vetorContatos[i].trede);
    printf("\t Rede social: %s", vetorContatos[i].redes_sociais1);

}

void listarContatos(){
    
	printf("\n\t LISTA DE CONTATOS\n");
	
	for(int i=0; i<qtd; i++){
		mostrarContato(i);
		printf("\t -------- PAGINA %i--------- \n", i);
        system("pause");
	}
	
}

int compararLetras(char *a, char *b, int i, int limite){

    if(a[i] == b[i]){
        i++;
        if(i < limite){
            return compararLetras(a, b, i, limite);
        }else{
            return 1;
        }
    }else{
        return 0;
    }

}

void procurarContato(){

    char nome[51] = {""};
    

    printf("\n\t -- PROCURAR CONTATO -- \n");
    printf("\n\t Digite o nome do contato a ser procurado: ");
    fgets(nome, 50, stdin);
    fflush(stdin);

    int limite = strlen(nome);
    limite --;

    system("cls");
    printf("\n\t RESULTADO: \n");

    for(int i = 0; i < qtd; i++){
        if(strlen (vetorContatos[i].nome) >= limite){
            if(compararLetras(nome, vetorContatos[i].nome, 0, limite) == 1){
                
                mostrarContato(i);
                printf("\n\t -------------------- \n");
                system("pause");
            }
        }
    }
}

void editarContato (){

    int selecionado = -1, op = 0;   // o -1 serve para desfazer a formatacao de exibicao em mostrarContatos 

    printf("\n\t Digite numero (id) do contato: ");
    scanf("%i", &selecionado);

    if(selecionado > 0){
        if(selecionado <= MAX){
            selecionado --;
            printf("\n\t Contato selecionado: %s \n", vetorContatos[selecionado].nome);
            system("pause");
        }else{
            printf("\n\t Esse contato nao existe!");
        }
    }

}

void deletarContato (){

    int selecionado = -1, op = 0;   // o -1 serve para desfazer a formatacao de exibicao em mostrarContatos 

    printf("\n\t Digite numero (id) do contato: ");
    scanf("%i", &selecionado);

    if(selecionado > 0){
        if(selecionado <= MAX){
            selecionado --;
            printf("\n\t Contato selecionado: %s \n", vetorContatos[selecionado].nome);
            system("pause");
        }else{
            printf("\n\t Esse contato nao existe!");
        }
    }
}
