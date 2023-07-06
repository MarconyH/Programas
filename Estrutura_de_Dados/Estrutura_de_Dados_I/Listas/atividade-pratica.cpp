#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
  char nome[30];
  float n1;
  float n2;
  float n3;
  struct lista *prox;
}Aluno;

void filtro_recuperacao(Aluno *p){
  float media;
  Aluno *uhuu=p;
  while (p!=NULL)
  {
    media=(p->n1+p->n2+p->n3)/3;
    if (media>=7)
    {
      if (uhuu==p)
      {
        uhuu=p->prox;
        free(p);
        p=uhuu;
      }
      
    }
    
    
  }

}

void aluno_maior_media(Aluno *p) {
  char nome[20];
  float media=0, maior=0;
  Aluno *corre=p;
  while (p != NULL)
  {
    media=(p->n1+p->n2+p->n3)/3;
    if (media>=maior)
    {
      maior=media;
      strcpy(nome, p->nome);
    }
    p=p->prox;
  }
  p=corre;
  while(strcmp(p->nome, nome) != 0 )
  {
    p=p->prox;
  }
  printf("O aluno com maior média é: %s\nCom as notas:\n%.2f\n%.2f\n%.2f", p->nome, p->n1, p->n2, p->n3);
}

void alunos_recuperacao(Aluno *p) {
  float media;
  printf("Os seguintes alunos estão de recuperação: \n");
  while (p != NULL)
  {
    media=(p->n1+p->n2+p->n3)/3;
    if (media<7)
    {
      printf("%s\n", p->nome);
    }
    p=p->prox;
  }
}

Aluno* adiciona_aluno(Aluno *p) {

  Aluno *novo=(Aluno*)malloc(sizeof(Aluno));

  printf("Digite o nome do aluno: ");
  scanf("%s",&novo->nome);

  printf("Digite a 1ª nota do aluno: ");
  scanf("%f",&novo->n1);

  printf("Digite a 2ª nota do aluno: ");
  scanf("%f",&novo->n2);

  printf("Digite a 3ª nota do aluno: ");
  scanf("%f",&novo->n3);

  novo->prox=p;

  return novo;
}

void imprimir(Aluno *p){
  printf("Lista de alunos:\n");
  while(p!=NULL){
    printf("%s(%.1f,%.1f,%.1f) --> ", p->nome,p->n1,p->n2,p->n3);
    p=p->prox;
  }
  printf("NULL\n");
}

void desaloca_lista(Aluno* p){
  Aluno *prox = p;
  while (p != NULL) {
    prox = p->prox;
    free(p);
    p = prox;
  }
}

int main(int argc, char **argv) {

  Aluno* cabeca = NULL;

  int opt=0;
  do{
    if(opt!=0){
      printf("\nAperte Enter para continuar\n");
      getchar();
      getchar();
    }
    printf("\n|\t**********************************\t|\n");
    printf("|\t\t\tMENU\t\t\t|\n");
    printf("|\t1-Adicionar aluno\t\t\t|\n");
    printf("|\t2-Imprimir lista\t\t\t|\n");
    printf("|\t3-Imprimir aluno com maior média\t|\n");
    printf("|\t4-Imprimir alunos de recuperação\t|\n");
    printf("|\t5-Remover alunos aprovados\t|\n");
    printf("|\t0-Sair\t\t\t\t\t|\n");
    printf("|\t**********************************\t|\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opt);
    printf("\n");
    switch (opt) {
      case 1:
        cabeca=adiciona_aluno(cabeca);
        break;
      case 2:
        imprimir(cabeca);
        break;
      case 3:
        aluno_maior_media(cabeca);
        break;
      case 4:
        alunos_recuperacao(cabeca);
        break;
      case 5:
        filtro_recuperacao(cabeca);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida\n");
        break;
    }

  }while (opt!=0);

  desaloca_lista(cabeca);

  return 0;
}
