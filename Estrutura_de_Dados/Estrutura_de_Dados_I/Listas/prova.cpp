#include "list.h"

//revend *procur_preco()

void venda (list **vender, list **vendido)
{
    list *head=*vender;
    
    int negociar, valor, busca;
    printf("Você quer buscar o carro por\n1-nome\n2-ano\n3-preço\n");
    scanf("%d", &busca);
    switch (busca)
    {
    case 1:
        char nome[30];
        printf("Digite o nome do carro que você quer vender:\n");
        scanf("%s", nome);
        while (strcmp(head->nome, nome)!=0)
        {
            head=head->prox;
            if (head==NULL)
            {
                printf("Nome não encontrado\n");
                return;
            }
        }
        break;
    case 2:
        head=procur_ano(head);
        break;
    case 3:
        break;
    default:
        break;
    }

    
    printf("Você quer negociar o preço? O valor atual é: %.2f\nDigite '1' para sim ou qualquer outro valor para não\n", head->venda);
    scanf("%d", &negociar);
    if (negociar==1)
    {
        do
        {
            printf("Digite o novo valor para venda:\n");
            scanf("%d", &valor);
            if (valor < head->compra)
            {
                printf("O valor inserido é menor do que o valor de compra\n");
            }
        }while (valor < head->compra);
        printf("O valor agora é: %.2f", head->venda = valor);
    }
    
    if (head->prox!=NULL && head->ant!=NULL)
    {
        list *aux=head;
        head->prox->ant=head->ant;
        head->ant->prox=head->prox;
        *vender=head->prox;
        head->prox=*vendido;
        *vendido=head;
        if (head->prox!=NULL)
        {
            head->prox->ant=head;
        }
        head->ant=NULL;
        
        
        
    }
    
    
    
    


}

int main ()
{ 
    list *a_venda = NULL;
    list *vendidos = NULL;


    int opt=0;
  do{
    if(opt!=0){
      printf("\nAperte Enter para continuar\n");
      getchar();
      getchar();
    }
    printf("\n|\t**********************************\t|\n");
    printf("|\t\t\tMENU\t\t\t|\n");
    printf("|\t1-Adicionar Carro à Venda\t\t|\n");
    printf("|\t2-Imprimir Carros à Venda\t\t|\n");
    printf("|\t3-Procurar por Preço\t\t\t|\n");
    printf("|\t4-Procurar por Ano\t\t\t|\n");
    printf("|\t5-Vender um Carro\t\t\t|\n");
    printf("|\t6-Imprimir Carros Vendidos\t\t|\n");
    printf("|\t0-Sair\t\t\t\t\t|\n");
    printf("|\t**********************************\t|\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opt);
    printf("\n");
    switch (opt) {
      case 1:
        adicionar_a_venda(&a_venda);
        break;
      case 2:
        imprimir(a_venda);
        break;
      case 3:
        
        break;
      case 4:
        procur_ano(a_venda);
        break;
      case 5:
        venda(&a_venda, &vendidos);
        break;
      case 6:
        imprimir(vendidos);  
        break;
      case 0:
        break;
      default:
        printf("Opção inválida\n");
        break;
    }

  }while (opt!=0);



}