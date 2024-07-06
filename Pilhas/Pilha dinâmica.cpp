#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
    int cont;
    struct stack *prox;
}stack;

void imprimir (stack *top);
void menu (stack **top);
void opcao(stack **top);
void inicia(stack **top);
int vazia(stack *top);
void aloca(stack **top);
void libera (stack **top);


int main ()
{
    stack *top;
    inicia(&top);
    menu(&top);
}

void imprimir (stack *top)
{
    int teste=vazia(top);
    while ( teste != 0)
    {
        printf("%d -> ", top->cont);
        top=top->prox;
        teste = vazia(top);
    }
    printf("NULL\n");
}

void menu (stack **top)
{
    printf(" **************\t MENU  ***************\n");
    printf("|\t 1 - Imprimir\t\t\t|\n");
    printf("|\t 2 - Empilhar (push)\t\t|\n");
    printf("|\t 3 - Desempilhar (pop)\t\t|\n");
    printf("|\t 4 - Consultar (top)\t\t|\n");
    printf("|\t 5 - Esvaziar (empty)\t\t|\n");
    printf("|\t 0 - Sair \t\t\t|\n");
    opcao(top);
}

void opcao(stack **top)
{
    int op;
    printf("Digite a opção desejada: \n");
    scanf("%d", &op);
    
    switch (op)
    {
        case 1:
            imprimir(*top);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 0:
            printf("Encerrando programa...\n");
            return;
        default:
            break;
    }
    printf("Pressione qualuqer tecla para continuar: \n");
    getchar();
    getchar();
    menu(top);
}

void inicia (stack **top)
{
    *top=NULL;
}

int vazia(stack *top)
{
    if (top==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void aloca(stack **top)
{
    stack *novo=(stack *)  malloc(sizeof(stack));
    novo->prox = *top;
    *top = novo;
    printf("Digite o número desejado: \n");
    scanf("%d", &novo->cont);
}

void libera (stack **top)
{
    stack *temp = *top;
    *top=(*top)->prox;
    free(temp);
}

