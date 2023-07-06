#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct celula
{
    int cont;
    struct celula *prox;
}celula;

typedef struct celula_dupla
{
    int cont;
    struct celula_dupla *prox, *ant;
}celula_dupla;

void imprimir(celula *head);
void criar(celula *head, int tam);
void remover_prim(celula *head);
int contar(celula *head);
void dividir_meio(celula *head, celula *head2);
void juntar(celula *head, celula *head2);
void criar_dupla(celula_dupla *head, int tam);
void imprimir_contra(celula_dupla *head);

int main ()
{
    int tam;
    celula_dupla *head=(celula_dupla *) malloc(sizeof(celula_dupla));
    head->prox=NULL;
    head->ant=NULL;
    printf("Digite o tamanho da lista: \n");
    scanf("%d", &tam);
    criar_dupla(head, tam);
    imprimir_contra(head);
    
    return 0;
}

void imprimir(celula *head)
{
    if (head->prox!=NULL)
    {
        printf("--------------Imprimindo Lista--------------\n");
        celula *prox=head->prox;
        while (prox->prox!=head->prox)
        {
        printf("%d\n", prox->cont);
        prox=prox->prox;
        }
        printf("%d\n", prox->cont);
        printf("--------------Impressão Finalizada--------------\n\n");
    }
    else
    {
        printf("A lista está vazia\n");
    }
}

void criar(celula *head, int tam)
{
    celula *uhuu=head;
    while(tam>0)
    {
        celula *novo=(celula *) malloc(sizeof(celula));
        uhuu->prox=novo;
        novo->cont=tam;
        novo->prox=head->prox;
        uhuu=uhuu->prox;
        tam--;   
    }
}

void remover_prim(celula *head)
{
    celula *corre=head->prox;
    if(corre->prox!=head->prox)
    {
        while (corre->prox!=head->prox)
        {
            corre=corre->prox;
        }
        head->prox=head->prox->prox;
        free(corre->prox);
        corre->prox=head->prox;
    }
    else
    {
        head->prox=NULL;
    }
}

int contar(celula *head)
{
    int i;
    if(head->prox!=NULL)
    {
        i=1;
        celula *cont=head->prox;
        while (cont->prox!=head->prox)
        {   
            cont=cont->prox;
            i++;
        }
    }
    else
    {
        i=0;
    }
    return i;
}

void dividir_meio(celula *head, celula *head2)
{
    if(head->prox!=NULL)
    {
        celula *corre=head;
        int tam=floor((contar(head))/2);
        if (tam>=1)
        {
        for (int i = 0; i < tam; i++)
        {
            corre=corre->prox;
        }
        head2->prox=corre->prox;
        corre->prox=head->prox;
        corre=head2->prox;
        while (corre->prox!=head->prox)
        {
            corre=corre->prox;
        }
        corre->prox=head2->prox;
        }
    }
}

void juntar(celula *head, celula *head2)
{
    celula *corre=head->prox;
    while (corre->prox!=head->prox)
    {
        corre=corre->prox;
    }
    corre->prox=head2->prox;
    while (corre->prox->prox!=head2->prox)
    {
        corre=corre->prox;
    }
    corre->prox->prox=head->prox;
    free(head2);
}

void criar_dupla(celula_dupla *head, int tam)
{
    celula_dupla *corre,*uhuu=head;
    for (int i = 0; i < tam; tam--)
    {
        celula_dupla *novo=(celula_dupla *) malloc(sizeof(celula_dupla));
        uhuu->prox=novo;
        corre=uhuu;
        novo->cont=tam;
        novo->prox=uhuu->prox;
        while (corre->prox->prox!=novo)
        {
            corre=corre->prox;
        }
        novo->ant=corre->prox;
        uhuu=uhuu->prox;
        corre=corre->prox;
    }
    
}

void imprimir_contra(celula_dupla *head)
{
    if (head->prox!=NULL)
    {
        printf("--------------Imprimindo Lista--------------\n");
        celula_dupla *prox=head->prox;
        while (prox->ant!=head->prox)
        {
        printf("%d\n", prox->cont);
        prox=prox->ant;
        }
        printf("%d\n", prox->cont);
        printf("--------------Impressão Finalizada--------------\n\n");
    }
    else
    {
        printf("A lista está vazia\n");
    }
}
