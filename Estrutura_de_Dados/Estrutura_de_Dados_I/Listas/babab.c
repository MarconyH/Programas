#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    int valor;
    struct celula *prox;
    //struct celula *ant;
}celula;

celula* adicionar(celula *head)
{
    int valor; 
    printf("poe algm numero.\n");
    scanf("%d", &valor);
    celula *novo=(celula *) malloc (sizeof(celula));
    novo->prox=head;
    novo->valor=valor;
    //head->ant=novo;
    //novo->ant=NULL;

    return novo;
}

void pasquim(celula *head)
{
    celula *aux=head;
    while (aux != NULL){
        printf("%d -> ", aux->valor);
        aux=aux->prox;
    }
    printf ("NULL\n");
} 

void menu(celula *head)
{

    int opcao;
    do{
    printf("--------------Menu--------------\n");
    printf("--------------1- Adicionar no Início--------------\n");
    printf("--------------2- Imprimir Lista--------------\n");
    printf("--------------0- Sair--------------\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        head=adicionar(head);
        break;
    case 2:
        pasquim(head);
        break;
    case 0:
        
        break;
    default:
        break;
    }
    }while (opcao!=0);
    
}

int main ()
{
    celula *head=(celula *)malloc(sizeof(celula));    
    head=NULL;
    menu(head);
    return 0;
}