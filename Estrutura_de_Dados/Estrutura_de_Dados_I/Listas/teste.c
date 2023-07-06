#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int conteudo;
  struct No *prox;
}No;

void imprimir(No *head);
void listadecrescente(No *head, int tam);
int posicao(No *head, int conteudo, int contagem);
void localizar_trocar(No *head, int conteudo);

int main ()
{
  int tam, conteudo;
  No *head=(No *) malloc(sizeof(No));
  head->prox=NULL;
  printf("Digite aqui o tamanho da lista decrescente encadeada simples: \n");
  scanf("%d", &tam);
  listadecrescente(head, tam);
  imprimir(head);
  printf("Digite o conteudo da celula a ser trocada: \n");
  scanf("%d", &conteudo);
  localizar_trocar(head, conteudo);
  imprimir(head);
  return 0;
}


void localizar_trocar(No *head, int conteudo)
{
  No *g,*p=head->prox;
  if (p->conteudo!=conteudo)
  {
    localizar_trocar(p, conteudo);

  }
  else
  {
    g=p->prox;
    p->prox=g->prox;
    g->prox=head->prox;
    head->prox=g;
  }

}
int posicao(No *head, int conteudo, int contagem)
{
  No p;
  p.prox=head->prox;
  if (p.conteudo!=conteudo)
  {
    contagem++;
    posicao(p.prox, conteudo, contagem);
  }
  else{
  return contagem+1;}
}


void listadecrescente(No *head, int tam)
{
  No*novo=(No *) malloc(sizeof(No));
  
  if (tam>0)
  {
    novo->prox=head->prox;
    novo->conteudo=tam;
    head->prox=novo;
    listadecrescente(novo, (tam-1));
  }
  

}

void imprimir(No *head)
{
  No *p=head->prox;
  if (p->prox!=NULL)
  {
    printf("%d\n", p->conteudo);
    imprimir(p);
  }
  else{
    printf("%d\n", p->conteudo);
    printf("Final da lista\n");
  }

}