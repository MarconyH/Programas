#ifndef _LISTCIRC_H
#define _LISTCIRC_H

#include <stdlib.h>
#include <stdio.h>


void menu()
{
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
        break;
      default:
        printf("Opção inválida\n");
        break;
    }

  }while (opt!=0);
}



#endif