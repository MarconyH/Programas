#include <iostream>
#include <string.h>
#include <time.h>

typedef struct passagem
{
    int localizador;
    int dia, mes, ano;
    int preco;
    char destino[15];
    struct passagem *esq;
    struct passagem *dir;

} Passageiro;

typedef struct Arvore
{
    Passageiro *raizargentina;
    Passageiro *raizbrasil;
    Passageiro *raizz;
} Arvore;

Arvore *cria_arvore()
{
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    if (arv != NULL)
    {
        arv->raizbrasil = NULL;
        arv->raizargentina = NULL;
        arv->raizz = NULL;
    }
    return arv;
}




void imprimir(Passageiro *raiz, int nivel)
{
    if (raiz == NULL)
    {
        return;
    }
    imprimir(raiz->esq, nivel + 1);
    for (int i = 0; i < nivel; i++){      
       printf("    ");     }
    printf("↼⁠|%d|\n", raiz->localizador);
    imprimir(raiz->dir, nivel + 1);
}




void inserir(Passageiro *&arv, Passageiro *&complicado ,int pais){
 
    Passageiro* novo = (Passageiro*) malloc(sizeof(Passageiro));
 
    Passageiro* pikachu = (Passageiro*) malloc(sizeof(Passageiro));
 
    if (pais == 1){
        strcpy(novo->destino, "Brasil");
        strcpy(pikachu->destino, "Brasil");
    } else if (pais == 2){
        strcpy(novo->destino, "Argentina");
        strcpy(pikachu->destino, "Argentin");
    }
      
    novo->localizador = rand() % 100;
      pikachu->localizador=novo->localizador;
    printf("\nInsira Dia\n");
    scanf("%d", &novo->dia);
      pikachu->dia=novo->dia;
    printf("\nInsira Mes\n");
    scanf("%d", &novo->mes);
      pikachu->mes=novo->mes;
    printf("\nInsira Ano\n");
    scanf("%d", &novo->ano);
      pikachu->ano=novo->ano;
    printf("\nPreço pago\n");
    scanf("%d", &novo->preco);
      pikachu->preco=novo->preco;
    novo->esq = NULL;
      pikachu->esq=NULL;
    novo->dir = NULL;
      pikachu->dir=NULL;
    
   
    if (arv == NULL) {
        arv = novo;
    } else {
        Passageiro *cur = arv;
        Passageiro *prev = NULL;
        while (cur != NULL) {
            prev = cur;
            if (novo->localizador < cur->localizador) {
                cur = cur->esq;
            } else {
                cur = cur->dir;
            }
        }
        if (novo->localizador < prev->localizador) {
            prev->esq = novo;
        } else {
            prev->dir = novo;
        }
    }
 
 if (complicado == NULL) {
        complicado = pikachu;
    } else {
        Passageiro *cur = complicado;
        Passageiro *prev = NULL;
        while (cur != NULL) {
            prev = cur;
            if (pikachu->localizador < cur->localizador) {
                cur = cur->esq;
            } else {
                cur = cur->dir;
            }
        }
        if (pikachu->localizador < prev->localizador) {
            prev->esq = pikachu;
        } else {
            prev->dir = pikachu;
        }
    }
 
    printf("\nNumero inserido na arvore!");
}




    
    
    
void busca(Passageiro *raiz, int nivel)
{
    if (raiz == NULL)
    {
        return;
    }
    busca(raiz->esq, nivel + 1);

    printf("\nLocalizador:%d\n", raiz->localizador);
    printf("Data:%d/%d/%d\n ", raiz->dia, raiz->mes, raiz->ano);
    printf("Preço:%d\n", raiz->preco);
    printf("Destino:%s\n ", raiz->destino);

    busca(raiz->dir, nivel + 1);
}

int soma(Passageiro *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return raiz->preco + soma(raiz->esq) + soma(raiz->dir);
}

int quantas(Passageiro *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return 1 + quantas(raiz->esq) + quantas(raiz->dir);
}

void thanos(Passageiro *&estalo){
 
    if (estalo == NULL) {
        return;
    }
 
    thanos(estalo->esq);
    thanos(estalo->dir);
    free(estalo);
    estalo = NULL;
}

int main()
{
    Arvore *arv = cria_arvore();
    srand(time(NULL));
    int opc;
    int opc2;
    char opcpais[15];
    int nivel = 1;
    int a = 0, b = 0;
    while (opc != 29052004)
    {
        printf("\n1-Comprar Passagem\n2-Imprimir Passagens \n3-Buscar Passagem \n4-Relatorio Unitario\n5-Relatorio Geral do Ano.\n0-Sair\n");
        printf("\n\tInforme a Opcao: \n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:

            printf("Para onde voce vai.\n1-Brasil\n2-Argentina. \n");

            int opcao;

            scanf("%d", &opcao);

            if (opcao == 1)
            {
                inserir(arv->raizbrasil, arv->raizz,opcao);
 
            }
            else if (opcao == 2)
            {
                inserir(arv->raizargentina, arv->raizz, opcao);
                
            }
            
            else
            {
                printf("\n\tNAO TEM PASSAGEM PRA OUTRO LUGAR ,AQUI SÓ É BRASIL E ARGENTINA EU SEI É UM PESSIMO NEGOCIO MAS FAZER O QUE.\n");
            }
            break;

        default:
            printf("\n\tOpcao Invalida!\n");
            break;

        case 2:
            printf("Que lista quer imprimir:\n1-Brasil\n2-Argentina\n");
            scanf("%d", &opc2);
            if (opc2 == 1)
            {
                imprimir(arv->raizbrasil, nivel);
            }
            else if (opc2 == 2)
            {
                imprimir(arv->raizargentina, nivel);
            }
            break;
        case 3:
            printf("Quem voce busca?\n");
            scanf("%s", opcpais);

            if (strcmp(opcpais, "brasil") == 0 || strcmp(opcpais, "Brasil") == 0)
            {
                busca(arv->raizbrasil, nivel);
            }

            if (strcmp(opcpais, "argentina") == 0 || strcmp(opcpais, "Argentina") == 0)
            {
                busca(arv->raizargentina, nivel);
            }
            break;
        case 4:

            a = soma(arv->raizbrasil);
            printf("Soma Brasil:%d\n", a);
            a = 0;
            b = quantas(arv->raizbrasil);
            printf("Foram Vendidas no Brasil:%d\n", b);
            b = 0;
            a = soma(arv->raizargentina);
            printf("Soma Argentina:%d\n", a);
            b = quantas(arv->raizargentina);
            printf("Foram Vendidas na Argentinal:%d\n", b);

            break;

        case 5:
            printf("Lista Geral:\n");
            imprimir(arv->raizz, nivel);
            printf("Passageiros:\n");
            busca(arv->raizz, nivel);
            
            thanos(arv->raizbrasil);
            thanos(arv->raizargentina);
            break;

        case 0:
            opc = 29052004;
            break;
        }
    }

    printf("       ＼⁠(⁠^⁠o⁠^⁠)⁠／\n→⁠⁠→ ATÉ A PROXIMA ←⁠⁠←\n       ＼⁠(⁠^⁠o⁠^⁠)⁠／");
    return 0;
}