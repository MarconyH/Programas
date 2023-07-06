#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct tipo
{
    int a, c, p;
    int est_a, est_c, est_p;
}tipo;


typedef struct list
{
    char nome[30];
    int id;
    int quant;
    char tipo[2];
    struct list *prox;
}list;

void inserir_info(list **head)
{
    printf("Digite o nome do produto:\n");
    scanf(" %[^\n]", (*head)->nome);
    getchar();
    printf("Digite a quantidade em estoque:\n");
    scanf("%d", &((*head)->quant));
    printf("Digite o tipo (A = alimento, C = consumo, P = permanente):\n");
    scanf("%s", (*head)->tipo);
    printf("ID do produto:\n");
    (*head)->id = rand();
    printf("%d", (*head)->id);
}

void inserir(list **head)
{
    list *novo = (list *) malloc(sizeof(list));
    inserir_info(&novo);
    novo->prox = *head;
    *head = novo;
}

void imprimir_info(list *head)
{
    printf("\nO Nome do produto: %s\n", head->nome);
    printf("A Quantidade em Estoque: %d\n", head->quant);
    printf("O Tipo do Produto: %s\n", head->tipo);
    printf("O ID do produto: %d\n", head->id);
}

void imprimir(list *head)
{
    while (head != NULL)
    {
        imprimir_info(head);
        head = head->prox;
    }
    printf("\nAcabou :D\n");
}

list *busca(list *achou)
{
    if (achou == NULL)
    {
        printf("Lista Vazia");
        return NULL;
    }
    
    char nome[30];
    printf("Digite o nome do produto procurado:\n");
    scanf(" %[^\n]", nome);
    getchar();
    while (strcmp(achou->nome, nome) != 0)
    {
        achou = achou->prox;
        if (achou == NULL)
        {
            printf("Produto não encontrado");
            return NULL;
        }
    }
    return achou;
}

void atualizar(list *head)
{
    list *aux;
    aux = busca(head);
    
    if (aux == NULL)
    {
        return;
    }
    
    printf("Produto encontrado: \n");
    imprimir_info(aux);
    inserir_info(&aux);
}

void atualizar_merc(list **head)
{
    list *aux;
    int quant;
    aux = busca(*head);
    
    if (aux == NULL)
    {
        return;
    }
    
    printf("Produto encontrado: \n");
    imprimir_info(aux);
    printf("Digite a quantidade a ser alterada (numero negativo para subtrair e positivo para incrementar): ");
    scanf("%d", &quant);
    aux->quant += quant;
}

void excluir(list **head)
{
    list *aux, *aux2;
    aux = busca(*head);
    
    if (aux == NULL)
    {
        return;
    }
    
    aux2 = *head;
    
    if (aux2 == aux)
    {
        *head = aux->prox;
        free(aux);
        return;
    }
    
    while(aux2->prox != aux)
    {
        aux2 = aux2->prox;
    }

    aux2->prox = aux->prox;
    free(aux);
}

tipo contagem(list *head)
{
    tipo contando;
    contando.a = 0;
    contando.c = 0;
    contando.p = 0;

    contando.est_a = 0;
    contando.est_c = 0;
    contando.est_p = 0;

    while (head != NULL)
    {
        if (strcmp(head->tipo, "A") == 0 || strcmp(head->tipo, "a") == 0)
        {
            contando.a ++;
            contando.est_a += head->quant;
        }

        if (strcmp(head->tipo, "C") == 0 || strcmp(head->tipo, "c") == 0)
        {
            contando.c ++;
            contando.est_c += head->quant;
        }
        
        if (strcmp(head->tipo, "P") == 0 || strcmp(head->tipo, "p") == 0)
        {
            contando.p ++;
            contando.est_p += head->quant;
        }
        
        head = head->prox;
    }
    return contando;
}

int diferentes(tipo taquase)
{
    int dif = 0;
    if (taquase.a != 0)
    {
        dif++;
    }
    if(taquase.c != 0)
    {
        dif++;
    }
    if(taquase.p != 0)
    {
        dif++;
    }
    return dif;
}

void relatorio(list *head)
{
    tipo contado;
    int dif;
    contado = contagem(head);
    
    dif = diferentes(contado);

    printf("Existe(m) %d produto(s) com tipo(s) diferente(s)\n", dif);
    printf("Existe(m) %d do tipo A com %d no estoque\n", contado.a, contado.est_a);
    printf("Existe(m) %d do tipo C com %d no estoque\n", contado.c, contado.est_c);
    printf("Existe(m) %d do tipo P com %d no estoque\n", contado.p, contado.est_p);
    printf("Quantidade total no estoque: %d\n", contado.est_a+contado.est_c+contado.est_p);
    
}

void menu()
{
    printf("\n|\t**********************************\t|\n");
    printf("|\t\t\tMENU\t\t\t|\n");
    printf("|\t1-Imprimir\t\t\t\t|\n");
    printf("|\t2-Inserir\t\t\t\t|\n");
    printf("|\t3-Atualizar\t\t\t\t|\n");
    printf("|\t4-Excluir\t\t\t\t|\n");
    printf("|\t5-Mudanca no Estoque\t\t\t|\n");
    printf("|\t6-Relatorio\t\t\t\t|\n");
    printf("|\t0-Sair\t\t\t\t\t|\n");
    printf("|\t**********************************\t|\n");
    printf("Digite a opcao desejada: ");
}

void escolha(int opt, list **head)
{
    switch (opt)
    {
    case 1:
        imprimir(*head);
        break;
    
    case 2:
        inserir(head);
        break;
    
    case 3:
        atualizar(*head);
        break;
    
    case 4: 
        excluir(head);
        break;
    
    case 5:
        atualizar_merc(head);
        break;
    
    case 6:
        relatorio(*head);
        break;
    case 0:
        printf("Encerrando programa...");
        break;

    default:
        printf("Valor invalido\n");
        break;
    }
}

#endif
