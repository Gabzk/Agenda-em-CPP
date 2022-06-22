#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

enum tipoendereco{alameda=1, avenida, praca, rua, travessa};
enum tipocontato{pessoal=1, comercial, fixo, fax, personalizado};
enum tiporedesocial{linkedin=1, instagram, twitter, facebook, outros};

typedef struct
{
    //aniversario nome
    char nome[50];
    int bd;
    char bdm[10];
    //formas de contato
    char telefone[12];
    char email[60];
    char redesocial[50];
    enum tipocontato tpctt;                                             
    enum tiporedesocial tprd;
    //endereço
    char endereco[50];
    char bairro[30];
    char complemento [50];
    int numero;
    int cep; 
    enum tipoendereco tpEnd;    
  
} Agenda;

int adicionarContato(Agenda **c, int quant, int tam)
{
    if (quant < tam)
    {
        Agenda *novo = malloc(sizeof(Agenda));
        printf("\nDigite o nome do contato a ser salvo:\n ");
        scanf("%[^\n]s", &novo->nome);
        fflush ( stdin );
        printf ("digite seu email\n");
        scanf ("%[^\n]s", &novo->email );
        fflush ( stdin );
        printf ("escolha uma rede social de sua preferencia\n (1)-linkedin\n (2)-instagram\n (3)-twitter\n (4)-Facebook\n (5)-Outros\n");
        scanf ("%i", &novo-> tprd);
        fflush( stdin);
        printf ("digite seu usuario nesta rede\n");
        scanf ("%[^\n]s", &novo->redesocial );
        fflush ( stdin );
        printf("\ndigite o seu telefone com DDD\n: ");
        fflush ( stdin );
        scanf("%11[0123456789]s", &novo->telefone);
        fflush ( stdin);
        printf("o tipo de contato fornecido foi\n (1)-pessoal\n (2)-comercial\n (3)-fixo\n (4)-fax\n (5)-outros\n");
        scanf ("%i", &novo-> tpctt);
        fflush ( stdin);
        printf ("voce mora em uma\n (1)-alameda\n (2)-avenida\n (3)-praca\n (4)-rua\n (5)-travessa\n ");
        scanf ("%i", &novo-> tprd);
        fflush ( stdin);
        printf ("digite seu endereço\n");
        scanf ("%[^\n]s", &novo->endereco );
        fflush ( stdin );
        printf ("digite seu bairro\n");
        scanf ("%[^\n]s", &novo->bairro );
        fflush ( stdin );
        printf ("digite o numero de sua residencia\n");
        scanf ("%[^\n]s", &novo->numero );
        fflush ( stdin );
        printf ("digite o cep de sua regiao\n");
        scanf ("%[^\n]s", &novo->cep );
        fflush ( stdin );
        printf ("digite um complemento\n");
        scanf ("%[^\n]s", &novo->complemento );
        fflush ( stdin );
        printf("\nDigite o dia do seu aniversário ");
        fflush ( stdin );
        scanf("%d", &novo->bd);
        printf("\n digite o mês do seu nascimento: ");
        fflush ( stdin );
        scanf("%s", &novo->bdm);
        c[quant] = novo;
        return 1;
    }
    else
    {
        printf("\n Lista cheia.\n");
        return 0;
    }
}
char *obterNomeContato ( enum tipocontato tpctt )//organizar enum
{
    const char *nomeContato[] =
    {
        "Comercial", "Fixo", "Pessoal", "Fax", "Personalizado"
    };

    return ( nomeContato [tpctt]);
}

char *obterNomeEndereco ( enum tipoendereco tpEnd)//enum
{
    const char *nomeEndereco[] =
    {
        "Al.", "Av.", "Pr.", "R.", "Tr."
    };

    return ( nomeEndereco [tpEnd] );
}

char *obterNomeRede ( enum tiporedesocial tprd)//enum
{
    const char *nomeRede[] =
    {
        "Instagram", "Facebook", "Twitter", "Linkedin", "Outros"
    };

    return ( nomeRede [tprd] );
}

int deleteContact(Agenda **c, int quant)
{
    int id;

    QntContatos(c, quant);

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

void QntContatos(Agenda **c, int quant)
{
    int i;

    printf("\n Lista de contatos: \n");
    for (i = 0; i < quant; i++)
    {/*
        printf("\t%d = aniversário: %2d de %s\t nome do contato: %s \t telefone: %s\t tipo de contato: %s\n ",
            i + 1, c[i]->bd, c[i]->bdm, c[i]->nome, c[i]->telefone,c[i]->tpctt, c[i]->email,
             c[i]->redesocial, c[i]->tprd, c[i]->tpEnd, c[i]->endereco, c[i]->bairro, c[i]->numero, c[i]->cep, c[i]->complemento );
             //refazer comando acima  
             \\o problema é que não está reconhecendo os enums e dá erro na exibição, agora refiz sem os enums
*/
        printf("\t%d = nome do contato: %s \t  aniversário: %2d de %s\t telefone: %s\n\t email: %s\t usuario: %s\n\t endereco: %s\t bairro: %s\t n*: %d\t cep: %d\n\t complemento: %s  ",
            i + 1, c[i]->nome, c[i]->bd, c[i]->bdm, c[i]->telefone, c[i]->email, c[i]->redesocial, c[i]->endereco, c[i]->bairro, c[i]->numero, c[i]->cep, c[i]->complemento);
    }
}
//funções para teste//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*

void ordenarContatos( contato usuario[], int nContatos)//organizar em ordem alfabética
{
    int comp;
    contato secundaria;

    for (int i = 0; i < nContatos; i++)
    {
        for (int j = i+1; j < nContatos; j++)
        {
            comp = strcmp(usuario[i]->nome, usuario[j]->nome);
            if (comp>0){
                secundaria = usuario[i];
                usuario[i] = usuario[j];
                usuario[j] = secundaria;
            }
    }
    
}

}

void gravarArquivo(contato usuario[], int nContatos){ //cria o arquivo

           // Criação do Arquivo e abertura do arquivo
       
        FILE *ptrArquivo = NULL;

        //trocado de a para w por que a apenas adiciona contato por contato
        // porem DA erro quando tentamos excluir entao o melhor é deixar w
        ptrArquivo = fopen ("agendinha-da-depressaum.txt", "w");

            if(ptrArquivo == NULL){
                printf("ALGO DEU ERRADO PATRÃO..\n");
                exit(0);
            }

        for(int l = 0; l < nContatos; l++)
            {
                fprintf(ptrArquivo, "%s;%s;%s;%s;%s;\n", 
                usuario[l].nome_contato,
                usuario[l].endereco,
                usuario[l].telefone,
                usuario[l].email,
                usuario[l].rede_social );
            }
        
        fclose(ptrArquivo);
        ptrArquivo = NULL;
}

int lerArquivo(contato usuario[]){ //ler o arquivo criado

        // Leitura do arquivo já criado

        char *token;
        char linhazinha[200];

        int i = 0;
        FILE *ptrArquivo = NULL;
        ptrArquivo = fopen ("agendinha-da-depressaum.txt", "r");
        if(ptrArquivo == NULL){
            printf("ALGO DEU ERRADO PATRÃO..");
            return 0;
        }


    while( (fgets(linhazinha, sizeof(linhazinha), ptrArquivo) ) != NULL){

        token = strtok(linhazinha, ";");

        strcpy(usuario[i].nome_contato, token);

        token = strtok(NULL, ";");

        strcpy(usuario[i].endereco, token);

        token = strtok(NULL, ";");

        strcpy(usuario[i].telefone, token);

        token = strtok(NULL, ";");

        strcpy(usuario[i].email, token);        

        token = strtok(NULL, ";");

        strcpy(usuario[i].rede_social, token);      

        i++;
    }

        fclose(ptrArquivo);
        ptrArquivo = NULL;

        return i;
*/

//aqui volta o codigo////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Pesquisar(int quant, Agenda **c)
{
    int i;
    char nomeBuscado[30];

    printf("\n digite o nome a ser pesquisado: \n");
    scanf("%s", &nomeBuscado);
    getchar();

    for (i = 0; i < quant; i++)
    {
        if (strcmp(nomeBuscado, c[i]->nome) == 0)
        {
            printf("o nome: %s foi encontrado com sucesso", c[i]->nome);
        }
        else
        {
            printf("o nome não foi encontrado");
        }
    }
}

int main()
{
    system ("color 02");//definir a cor da agenda

    Agenda *contatos[500];
    char arquivo[] = ("agenda.txt");
    int opcao, tam = 500, quant = 0;




    do
    {
        printf(" \n\t0 - exit\n\t1 - Cadastrar contato na agenda\n\t2 - Remover contato\n\t3- Imprimir contatos\n\t4- Pesquisar contato\n\t");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            quant += adicionarContato(contatos, quant, tam);
            break;
        case 2:
            quant += deleteContact(contatos, quant);
            break;
        case 3:
            QntContatos(contatos, quant);
            break;
        case 4:
            Pesquisar(contatos, quant);
            break;

         default:
        printf("------------------------------------------\n");
        printf("- Essa Opcao nao Existe.                 -\n");
        printf("------------------------------------------\n");
        break;
        }
    } while (opcao != 0);

    return 0;
}
