#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Aluno
{
    int matricula;
    char nome[100];
    char dataDeNascimento[100];
    struct Aluno *prx;

} * inicio;

void inserirAluno(int matricula, char *nome, char *dataDeNascimento)
{

    struct Aluno *p = (struct Aluno *)malloc(sizeof(struct Aluno));
    p->matricula = matricula;
    strcpy(p->nome, nome);
    strcpy(p->dataDeNascimento, dataDeNascimento);
    p->prx = NULL;

    if (inicio == NULL)
    {
        inicio = p;
    }
    else
    {
        p->prx = inicio;
        inicio = p;
    }
}

void pesquisarAluno(int matricula)
{
    struct Aluno *p = inicio;
    while (p != NULL)
    {
        if (p->matricula == matricula)
        {
            printf("Matricula: %d\n", p->matricula);
            printf("Nome: %s\n", p->nome);
            printf("Data de nascimento: %s\n", p->dataDeNascimento);
            return;
        }
        p = p->prx;
    }
    printf("A matricula do aluno %d nao foi encontrada!\n", matricula);
}

void atualizarAluno(int matricula)
{

    struct Aluno *p = inicio;
    while (p != NULL)
    {

        if (p->matricula == matricula)
        {
            printf("A matricula com numero %d foi encontrada!\n", matricula);
            printf("Nome do aluno: ");
            scanf("%s", p->nome);
            printf("Data de nascimento: ");
            scanf("%s", p->dataDeNascimento);
            printf("Atualizado com sucesso!\n");
            return;
        }
        p = p->prx;
    }
    printf("Aluno com a matricula %d não foi encontrado!\n", matricula);
}

void deletarAluno(int matricula)
{
    struct Aluno *p1 = inicio;
    struct Aluno *p2 = inicio;
    while (p1 != NULL)
    {

        if (p1->matricula == matricula)
        {

             printf("A matricula com numero %d foi encontrada!\n", matricula);

            if (p1 == p2)
            {
                inicio = inicio->prx;
                free(p1);
            }
            else
            {
                p2->prx = p1->prx;
                free(p1);
            }

            printf("Aluno deletado com sucesso !!!\n");
            return;
        }
        p2 = p1;
        p1 = p1->prx;
    }
    printf("Aluno com a matricula %d nao foi encontrado !!!\n", matricula);
}
void mostrarDetalhesDosAlunos()
{
    struct Aluno *p = inicio;
    while (p != NULL)
    {

        printf("Matricula: %d\n", p->matricula);
        printf("nome: %s\n", p->nome);
        printf("Data de nascimento: %s\n", p->dataDeNascimento);
        p = p->prx;
    }
}
int main()
{
    inicio = NULL;
    int escolha;
    int matricula;
    char dataDeNascimento[100];
    char nome[100];
    printf("1 Para adicionar um aluno\n2 Para atualizar os dados de um aluno\n3 Para deletar um aluno\n4 Para pesquisar um aluno\n5 Para mostrar todos alunos cadastrados");
    do
    {
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("Matricula: ");
            scanf("%d", &matricula);
            printf("Nome: ");
            scanf("%s", nome);
            printf("Data de nascimento: ");
            scanf("%s", dataDeNascimento);
            inserirAluno(matricula, nome, dataDeNascimento);
            break;
        case 2:
            printf("Adicione o numero da matricula para atualizar os dados do aluno: ");
            scanf("%d", &matricula);
            atualizarAluno(matricula);
            break;
        case 3:
            printf("Adicione o numero da matricula para deletar o aluno desejado: ");
            scanf("%d", &matricula);
            deletarAluno(matricula);
            break;
        case 4:
            printf("Adicione o numero da matricula para encontrar o aluno desejado: ");
            scanf("%d", &matricula);
            pesquisarAluno(matricula);
            break;
        case 5:
            mostrarDetalhesDosAlunos();
            break;
        }

    } while (escolha != 0);
}