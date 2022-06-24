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
void carregarAgenda();
void salvarContato(contatos contato, FILE *arq);
void inserirContato(contatos contato);
void criarContato();
void mostrarContato(int i);
void listarContatos();
int compararLetras();
void procurarContato();
void editarContato ();
void deletarContato();
char continuar();


static int qtd = 0;     // VARIÁVEL QUE CONTA QUANTIDADE DE CONTATOS INSCRITOS
contatos vetorContatos[MAX]; // VARIÁVEL DE CONTATOS


int main(void)
{

    carregarAgenda();

    system("cls");
    system("COLOR 8F");

    char op; // VARIÁVEL DE OPÇÃO.

    do
    {
        system("cls"); // COMANDO PARA LIMPAR A TELA.

        //MENU DA AGENDA.
        printf ("\n\t ######## AGENDA ######## \n");
        printf ("\t -- ESCOLHA UMA OPCAO -- \n\n");
        printf ("\t 1 - ADICIONAR CONTATO \n");
        printf ("\t 2 - ALTERAR CONTATO \n");
        printf ("\t 3 - CONSULTAR CONTATO \n");
        printf ("\t 4 - DELETAR CONTATO \n");
        printf ("\t 5 - LISTAR CONTATOS \n");
        printf ("\t 6 - SAIR \n");
        
        op = getch();

        // SWITCH CASE PARA OPÇÕES DO MENU.
        switch (op) 
        {
            // CRIAR CONTATO.
            case '1': 
            fflush(stdin);
            criarContato();
            break;
            
            // EDITAR CONTATO.
            case '2':
            system("cls");
            fflush(stdin);
            editarContato();
            break;

            // PESQUISAR CONTATO.
            case '3':
            system("cls");
            fflush(stdin);
            procurarContato(); 
            break;

            // DELETAR CONTATO.
            case '4':
            system("cls");
            fflush(stdin);
            deletarContato(); 
            break;

            // LISTAR CONTATO.
            case '5':
            system("cls");
            fflush(stdin);
            listarContatos(); 
            break;

            // ENCERRAR PROGRAMA.
            case '6':
            system("cls");
            printf("\n\tPrograma Encerrado...!\n");
            break;

            // OPERAÇÃO INVÁLIDA.
            default:
            printf("\n\tOpcao invalida. Digite novamente...");
            op = getch();
            break;

        }
    } while(op != '6'); // Condição para o loop continuar
        

    return 0;
}

/* -------- SUB-ROTINA DE CARREGAMENTO DOS CONTATO DO ARQUIVO --------*/
void carregarAgenda ()
{
    
    FILE *arq = fopen(agenda, "r"); // ABERTURA DO ARQUIVO.

    qtd = 0; // VARIÁVEL DE CONTAGEM.
	
	if(!arq == NULL)
    {
		rewind(arq); // COMANDO PARA IR ATÉ O INÍCIO DO ARQUIVO			
		
		while(!feof(arq)) //FEOF DIZ QUANDO O ARQUIVO CHEGA AO FIM.
        {
        	fgets(vetorContatos[qtd].nome, 50, arq);

			if(strcmp(vetorContatos[qtd].nome, "") > 0) // VERIFICAÇÃO SE O CONTATO DO INDICE ATUAL NÃO ESTÁ VÁZIO
            { 
                // CARREGAMENTO DOS DADOS DO ARQUIVO PARA A VARIÁVEL
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
    
    else
    {
		printf("ERRO ao carregar agenda!.\n");
	}

    fclose(arq); // FECHAMENTO DO ARQUIVO
}

/* -------- SUB-ROTINA DE CRIAÇÃO DE NOVOS CONTATOS --------*/
void criarContato (){

    contatos contato; // VARIÁVEL DE CONTATO
    char op = 's'; // VARIÁVEL DE OPÇÃO

    
    if(qtd < MAX) // VERIFICAÇÃO SE A AGENDA ESTÁ CHEIA
    {
        while(op == 's') 
        {
            system("cls");
            printf("\n\tPREENCHA OS CAMPOS A SEGUIR: \n");
            
            printf("\n\tNome:");
            fflush(stdin);
            fgets(contato.nome,50,stdin);
            
            printf("\n\tTipo de endereco: \n\t( 0 ) Alameda \n\t( 1 ) Avenida \n\t( 2 ) Praca \n\t( 3 ) Rua \n\t( 4 ) Travessa \n\t Opcao: ");
            fflush(stdin);
            scanf("%i",&contato.tendereco);
            
            printf("\n\tEndereco:");
            fflush(stdin);
            fgets(contato.endereco,50,stdin);

            printf("\n\tNumero:");
            fflush(stdin);
            scanf("%i",&contato.numero);
            
            printf("\n\tTipo de contato: \n\t( 0 ) Celular \n\t( 1 ) Comercial \n\t( 2 ) Fixo \n\t( 3 ) Pessoal \n\t( 4 ) Fax \n\t( 5 ) Personalizado");
            
            printf("\n\tOpcao: ");
            fflush(stdin);
            scanf("%i",&contato.tcontato);
            
            printf("\n\tTelefone para contato:");
            fflush(stdin);
            fgets(contato.contato,12,stdin);
            
            printf("\n\tEmail:");
            fflush(stdin);
            fgets(contato.email,50,stdin);
            
            printf("\n\tTipo de rede social: \n\t( 0 ) Instagram \n\t( 1 ) Facebook \n\t( 2 ) Linkedin \n\t( 3 ) Outros");
            
            printf("\n\tOpcao: ");
            fflush(stdin);
            scanf("%i",&contato.trede);
            
            printf("\n\tRede Social:");
            fflush(stdin);
            fgets(contato.redes_sociais1,50,stdin);

            inserirContato(contato); // CHAMADA DE SUB-ROTINA DE INSERÇÃO
            op = continuar();
        }
    }
    else
    {
        printf("\n\t MEMÓRIA INSUFICIENTE...!");
    }
}

/* -------- SUB-ROTINA DE INSERÇÃO DE CONTATO --------*/
void inserirContato(contatos contato)
{
    FILE *arq = fopen (agenda, "a+");
	
	if(arq == NULL)     // Teste para ver se o arquivo abriu corretamente
    {                             
        printf("Erro ao abrir o arquivo!");     // Mensagem exibida se o arquivo der erro
        getchar();                             // Eseprando resposta do usario para sair do programa
        exit(1);
    }
    else
    {
		salvarContato(contato, arq);    // Chamada de sub-rotina para salvar o contato
		vetorContatos[qtd] = contato;
		qtd++;
	}
    
	fclose(arq); // Fechamento do arquivo
	

}

/* -------- SUB-ROTINA DE GRAVAÇÃO DE CONTATOS --------*/
void salvarContato(contatos contato, FILE *arq)
{
    // Todas as partes da struct sendo imprimidas no arquivo
    fprintf(arq,contato.nome); // fprint é a funçãa que imprime algo no arquivo
    fprintf(arq,"%i\n",contato.tendereco);
    fprintf(arq,contato.endereco);
    fprintf(arq,"%i\n",contato.numero);
    fprintf(arq,"%i\n",contato.tcontato);
    fprintf(arq,contato.contato);
    fprintf(arq,contato.email);
    fprintf(arq,"%i\n",contato.trede);
    fprintf(arq,contato.redes_sociais1);
}


/* -------- SUB-ROTINA DE EDIÇÃO DE CONTATOS --------*/
void editarContato ()
{
    FILE *arq = fopen(agenda,"r+"); // leitura da agenda

    int opcao = 0;
    int selecionado, op = 0;   // o 1 serve para desfazer a formatacao de exibicao em mostrarContatos 
    contatos editado;          // contato auxiliar para edição

    printf("\n\t Digite numero (id) do contato: "); // Escolha de qual contato editar
    fflush(stdin);
    scanf("%i", &selecionado);

    if(selecionado < MAX) // Verificando se o número digitado não é maior que o limite
    {
        printf("\n\t Contato selecionado: %s \n", vetorContatos[selecionado].nome);
        mostrarContato(selecionado); // Sub-rotina que exibe o contato selecionado
        printf("\n\t ----------------------- \n");

        printf("\n\t EDITAR CONTATO \n");
        printf("\n \t NOVO Nome: ");
        fflush(stdin);

        fgets(editado.nome, 50, stdin);
        if(editado.nome>1)
        {
            strcpy(vetorContatos[selecionado].nome, editado.nome); // comando que copia as informações do contato auxiliar para o antigo
        }

        printf("\n\t NOVO Tipo de Endereco: ");
        fflush(stdin);
        scanf("%i",&editado.tendereco);

        if(editado.tendereco>1)
        {
            strcpy(&vetorContatos[selecionado].tendereco, &editado.tendereco);
        }
        
        printf("\n \t NOVO Endereco: ");
        fflush(stdin);
        fgets(editado.endereco, 50, stdin);

        if(editado.endereco>1)
        {
            strcpy(vetorContatos[selecionado].endereco, editado.endereco);
        }

    
        printf("\n\t NOVO Numero da residencia: ");
        fflush(stdin);
        scanf("%i",&editado.numero);

        if(editado.numero>1)
        {
            strcpy(&vetorContatos[selecionado].numero, &editado.numero);
        }

        printf("\n\t NOVO Tipo de contato: ");
        fflush(stdin);
        scanf("%i",&editado.tcontato);
        if(editado.tcontato>1)
        {
            strcpy(&vetorContatos[selecionado].tcontato, &editado.tcontato);
        } 
    
        printf("\n \t NOVO Numero para contato: ");
        fflush(stdin);
        fgets(editado.contato, 50, stdin);

        if(editado.contato>1)
        {
            strcpy(vetorContatos[selecionado].contato, editado.contato);
        }


        printf("\n \t NOVO Email: ");
        fflush(stdin);
        fgets(editado.email, 50, stdin);
        if(editado.email>1)
        {
            strcpy(vetorContatos[selecionado].email, editado.email);
        }


        printf("\n \t NOVO Tipo de rede social: ");
        fflush(stdin);
        scanf("%i",&editado.trede);

        if(editado.trede>1)
        {
            strcpy(&vetorContatos[selecionado].trede, &editado.trede);
        }

        printf("\n \t NOVA Rede social: ");
        fflush(stdin);
        fgets(editado.redes_sociais1, 50, stdin);

        if(editado.redes_sociais1>1)
        {
            strcpy(vetorContatos[selecionado].redes_sociais1, editado.redes_sociais1);
        }



    }
    else
    {
        printf("\n\t Esse valor ultrapassa a quantidade de contatos da Agenda! \n");
    }
        
    getch();
    fflush(stdin);
    fclose(arq); // Fechamento do arquivo
}

/* -------- SUB-ROTINA DE EXIBIÇÃO DE CONTATO --------*/
void mostrarContato(int i)
{
    // Printf's exibindo as variáveis do contato com as informações
    printf("\n\t CONTATO: %i", i);
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

/* -------- SUB-ROTINA DE EXIBIÇÃO DE CONTATO -------- */
void listarContatos()
{
	printf("\n\t LISTA DE CONTATOS\n");
	
    // Laço de listagem de contatos
	for(int i=0; i<qtd; i++){
		mostrarContato(i); // Sub-Rotina de exibição
		printf("\t -------- PAGINA %i--------- \n", i);
        system("pause"); 
	}

}

/* -------- SUB-ROTINA DE COMPARAÇÃO --------*/
int compararLetras(char *a, char *b, int i, int limite)
{
    if(a[i] == b[i])
    {
        i++;
        if(i < limite)
        {
            return compararLetras(a, b, i, limite);
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

/* -------- SUB-ROTINA DE BUSCA --------*/
void procurarContato()
{

    char nome[51] = {""}; // Variável que vai obter o nome do contato a ser buscado
    

    printf("\n\t -- PROCURAR CONTATO -- \n");
    printf("\n\t Digite o nome do contato a ser procurado: ");
    fgets(nome, 50, stdin); // Digitação do contato a ser buscado
    fflush(stdin);

    int limite = strlen(nome); 
    limite --;

    system("cls");
    printf("\n\t RESULTADO: \n");

    for(int i = 0; i < qtd; i++)
    {
        if(strlen (vetorContatos[i].nome) >= limite)
        {
            if(compararLetras(nome, vetorContatos[i].nome, 0, limite) == 1)
            {
                mostrarContato(i);
                printf("\n\t -------------------- \n");
                system("pause");
            }
        }
    }
}

/* -------- SUB-ROTINA DE DELETAMENTO --------*/
void deletarContato ()
{
    int selecionado = 0, op = 0;   // O 1 serve para desfazer a formatação de exibição em mostrarContatos()

    printf("\n\t Digite numero (id) do contato: ");
    scanf("%i", &selecionado); // Recebimento do id digitado para seleção de contato

    if(selecionado > 0) // Verificação se contato é válido
    {
        if(selecionado <= MAX) // Verificação se contato é válido
        {
            selecionado --;
            printf("\n\t Contato selecionado: %s \n", vetorContatos[selecionado].nome);
            system("pause");
        }
        else
        {
            printf("\n\t Esse contato nao existe!");
        }
    }
}

/* -------- SUB-ROTINA DE PERGUNTA DE CONTINUAÇÃO --------*/
char continuar()
{
    char op; // Variável de opção
    
    // Laço para perguntar se quer continuar
    do
    {
        printf("\n\tDeseja continuar? (S OU N)");
        
        op = tolower (getch()); // Recebimento da resposta convertendo em caixa baixa para evitar erros
    } while (op != 's' && op != 'n');
    
    return op; // Retorno da resposta
}
