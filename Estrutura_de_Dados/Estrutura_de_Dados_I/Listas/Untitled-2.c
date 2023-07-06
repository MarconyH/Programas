#include <stdlib.h>
#include <stdio.h>

typedef struct circulo{
int v;
struct circulo *p;
//int qnt=0;
}lista;

lista * criar(lista *head){
    int sla;
    lista *novo = (lista *) malloc(sizeof(lista));
    lista *corre=head;
    printf("Dá aí:\n");
    scanf("%d", &sla);
    novo->v=sla;
    if(head == NULL)
    {
        head = novo;
        novo -> p = head;
        //head -> qnt++;
    }
    else
    {
        //head -> qnt++;
        novo -> p = head;
        while (corre->p!=head)
        {
            corre=corre->p;
        }
        corre->p=novo;
    }
    return novo;
}

void imprimir(lista *head) {
  lista *aux = head;
  if (aux != NULL) {
    while (aux->p != head) {
      printf("%d -> ", aux->v);
      aux = aux->p;
    }
    printf("%d -> ", aux->v);
  }
  printf("HEAD\n");
}

int main(){
    lista *head=NULL;
    head = criar(head); 
    head = criar(head);
    head = criar(head);
    imprimir(head);

    return 0;
} 