#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct
{
    //nome
    char nome[50];
    //formas de contato
    char telefone[12];
    char tipocontato [20];
    char email[60];
    char redesocial[50];
    char tipoderede [20];
    //endereço
    char endereco[50];
    char bairro[30];
    char complemento [50];
 

} Agenda;

char continuar()//continuar criando contatos
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

int adicionarContato(Agenda **c, int quant, int tam)//adicionar contatos
{
    char op = 's';
    if (quant < tam)
    {   while ((quant < tam) && (op == 's')){
        Agenda *novo = malloc(sizeof(Agenda));
        printf("\nDigite o nome do contato a ser salvo:\n ");
        scanf("%[^\n]s", &novo->nome);
        fflush ( stdin );
        printf ("digite seu email\n");
        scanf ("%[^\n]s", &novo->email );
        fflush ( stdin );
        printf ("digite seu usuario em uma rede social de sua preferencia\n");
        scanf ("%[^\n]s", &novo->redesocial );
        fflush ( stdin );
         printf ("qual foi a rede social escolhida?\n");
        scanf ("%[^\n]s", &novo-> tipoderede);
        fflush( stdin);
        printf("\ndigite o seu telefone com DDD\n: ");
        scanf("%11[0123456789]s", &novo->telefone);
        fflush ( stdin);
        printf("o tipo de contato fornecido foi?\n pessoal, comercial ou outros?\n");
        scanf ("%[^\n]s", &novo-> tipocontato);
        fflush ( stdin);
        printf ("digite seu bairro\n");
        scanf ("%[^\n]s", &novo->bairro );
        fflush ( stdin );
        printf ("digite seu endereço\n");
        scanf ("%[^\n]s", &novo->endereco );
        fflush ( stdin );
        printf ("digite um complemento\n");
        scanf ("%[^\n]s", &novo->complemento );
        fflush ( stdin );
        c[quant] = novo;
        quant++;//acrecenta 1 contato a mais
         op =continuar();//chama a função que pergunta se deseja inserir novos contatos

    } 
   return; 
    } 
    
    
    else
    {
        printf("\n Lista cheia.\n");//caso o tam chegue ao maximo
        return 0;
    }
      op = continuar ();
}


int deleteContact(Agenda **c, int quant)
{
    int id;

    QntContatos(c, quant);//deletar contatos

    printf("\n\t Digite o número do usuário que você quer deletar: \n");
    scanf("%d", &id);
    getchar();
    id--;
    if (id >= 0 && id < quant)
    {
        free(c[id]); //evitar vazamento de memória
        if (id < quant - 1)
        {
            c[id] = c[quant - 1];
        }
        return -1;
    }
    else
    {
        printf("\n\t código errado;\n");
        return 0;
    }
}

void QntContatos(Agenda **c, int quant)//exibe contatos salvos
{
    int i;
    printf("\n Lista de contatos: \n");
    for (i = 0; i < quant; i++)
    {
        printf("\n\t%d = nome do contato: %s \t telefone: %s\t tipo de contato: %s\n\t email: %s\t usuario: %s\t rede social escolhida: %s\n\t endereco: %s\t bairro: %s\n\t complemento: %s  ",
            i + 1, c[i]->nome, c[i]->telefone,c[i]->tipocontato ,c[i]->email, c[i]->redesocial,c[i]->tipoderede ,c[i]->endereco, c[i]->bairro, c[i]->complemento);
            
    }
}

void Pesquisar(Agenda **c, int quant) //pesquisar um contato na agenda
{
    int i;
    char nomeBuscado[50];
    char nomeAgenda[50];

    printf("\n digite o nome a ser pesquisado: \n");
    setbuf(stdin, NULL);
    scanf("%s", &nomeBuscado);
    getchar();
    strlwr(nomeBuscado);
    for (i = 0; i <= quant; i++){
        strcpy(nomeAgenda, c[i]->nome);
        strlwr(nomeAgenda);
        if (strstr(nomeAgenda, nomeBuscado)){
            printf("\nO nome: %s foi encontrado com sucesso", c[i]->nome);
            printf("\n\t%d = nome do contato: %s \t telefone: %s\t tipo de contato: %s\n\t email: %s\t usuario: %s\t rede social escolhida: %s\n\t endereco: %s\t bairro: %s\n\t complemento: %s  ",
            i + 1, c[i]->nome, c[i]->telefone,c[i]->tipocontato ,c[i]->email, c[i]->redesocial,c[i]->tipoderede ,c[i]->endereco, c[i]->bairro, c[i]->complemento);//exibe as informações do contato
            break;
        }else{
            printf("\nnao tem resultados correspondentes.");
        }
    }
}

int main()
{
    system ("color 02");//definir a cor da agenda

    Agenda *contatos[500];
    char arquivo[] = ("agenda.txt");
    int opcao, tam = 500, quant = 0;//numero de contatos



    do
    {
        
        printf(" \n\t(0) - exit\n\t(1) - Cadastrar contato na agenda\n\t(2) - Remover contato\n\t(3)- Imprimir contatos\n\t(4)- Pesquisar contato\n\t\n\t(4)- Modificar contato\n\t");//exibir menu
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            quant += adicionarContato(contatos, quant, tam);//adicionar contato
            break;
        case 2:
            quant += deleteContact(contatos, quant);//deletar contato
            break;
        case 3:
            QntContatos(contatos, quant);//listar contatos
          
            break;
        case 4:
            Pesquisar(contatos, quant);//pesquisar contato
            break;

            case 5:
              break;

            case 0:
            printf("Adeus");
            break;

         default://para se o usuario digitar outra coisa
        printf("- Essa Opcao nao Existe.                 -\n");
        break;
        
        }
    } while (opcao != 0);//saair

    return 0;
}
