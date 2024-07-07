/*  Atividade 1: desenvolver um sistema que costrua, a partir da raiz a árvore genealógicade uma família, 
armazenando o nome e idade de cada pessoa.*/
//Na aula o máximo serão 3 filhos
#include<stdio.h>
#include<stdlib.h>

typedef struct pessoa
{
    char nome[30];
    int idade;
    struct pessoa *prox;
}people;

typedef struct no
{
    people *pessoa;
    struct no *filho1;
    struct no *filho2;
    struct no *filho3;
}no;

void imprimir_arvore (no *root);

int main ()
{
    people p1, p2, p3;
    no n1, n2, n3;

    no *raiz = &n1;

    n1.pessoa = &p1;
    n2.pessoa = &p2;
    n3.pessoa = &p3;

    n1.filho1 = &n2;
    n1.filho2 = NULL;
    n1.filho3 = NULL;

    n2.filho1 = &n3;
    n2.filho2 = NULL;
    n2.filho3 = NULL;
    
    n3.filho1 = NULL;
    n3.filho2 = NULL;
    n3.filho3 = NULL;

    scanf("%s", n1.pessoa->nome);

    imprimir_arvore(raiz);

}



void imprimir_arvore (no *node)
{
    printf("%s -> %d", node->pessoa->nome, node->pessoa->idade);
}
