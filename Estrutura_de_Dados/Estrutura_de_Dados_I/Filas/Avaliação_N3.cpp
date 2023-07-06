#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct queue
{
    char nome[30];
    char cpf[20];
    struct queue *prox;
}queue;

//FUNÇÕES

void menu (); 
void menu_prioridade();
void menu_imprimir();

void imprimir(queue *first);

void registrar(queue **first, queue **last);

int contagem(queue *first, char cpf[20], int teste);

int qual_proximo(queue *first1, queue *first2, queue *first3, int cont_urg, int cont_ele);

void next(queue **first, queue **last);

int onde_esta(int cont1, int cont2, int cont3);

void busca(queue *first1, queue *first2, queue *first3, char cpf[20]);

void relatorio(int cont[3]);

//FIM DAS FUNÇÕES E COMEÇO DO MAIN

int main ()
{
    int op, opimprimir, prioridade;
    int nextcont = 0;
    int contagem_total[3] = {0, 0, 0};
    char cpf[20];
    queue *first_emergencia = NULL;
    queue *first_urgencia = NULL;
    queue *first_eletiva = NULL;

    queue *last_emergencia = NULL;
    queue *last_urgencia = NULL;
    queue *last_eletiva = NULL;

    

    do
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1: //imprimir
            menu_imprimir();
            scanf("%d", &opimprimir);
            switch (opimprimir)
            {
            case 1:
                imprimir(first_emergencia);
                getchar();
                getchar();
                break;
            case 2:
                imprimir(first_urgencia);
                getchar();
                getchar();
                break;
            case 3:
                imprimir(first_eletiva);
                getchar();
                getchar();
                break;
            default:
                printf("Número inválido\n");
                getchar();
                getchar();
                break;
            }
            break;
        case 2: //registrar
            menu_prioridade();
            scanf("%d", &prioridade);
            switch (prioridade)
            {
            case 1:
                registrar(&first_emergencia, &last_emergencia);
                break;
            case 2:
                registrar(&first_urgencia, &last_urgencia);
                break;
            case 3:
                registrar(&first_eletiva, &last_eletiva);
                break;
            default:
                printf("Número inválido\n");
                break;
            }
            break;
        case 3: //next
            nextcont = qual_proximo(first_emergencia, first_urgencia, first_eletiva, contagem_total[1], contagem_total[2]);
            switch (nextcont)
            {
            case 1:
                next(&first_emergencia, &last_emergencia);
                contagem_total[0]++;
                break;
            case 2:
                next(&first_urgencia, &last_urgencia);
                contagem_total[1]++;
                break;
            case 3:
                next(&first_eletiva, &last_eletiva);
                contagem_total[2]++;
                break;
            default:
                break;
            }
            break;
        case 4: //busca
            printf("\nDigite um CPF para saber quantas pessoas existem na frente:\n");
            scanf("%s", cpf);
            busca(first_emergencia, first_urgencia, first_eletiva, cpf);
            break;
        case 5: //relatório
            relatorio(contagem_total);
            break;
        case 0: //sair
            break;
        default:
            break;
        }
        
    }while (op != 0);

    return 0;
}



void menu ()
{
    printf(" **************\t MENU  ***************\n");
    printf("|\t 1 - Imprimir\t\t\t|\n");
    printf("|\t 2 - Registrar\t\t\t|\n");
    printf("|\t 3 - Next\t\t\t|\n");
    printf("|\t 4 - Busca\t\t\t|\n");
    printf("|\t 5 - Relatório\t\t\t|\n");
    printf("|\t 0 - Sair \t\t\t|\n\n");
}

void menu_imprimir ()
{
    printf("\n\n ***** Qual fila você quer imprimir? *****\n");
    printf("|\t 1 - Emergência\t\t|\n");
    printf("|\t 2 - Urgência\t\t\t|\n");
    printf("|\t 3 - Eletiva\t\t\t|\n");
}

void menu_prioridade ()
{
    printf("\n\n *****\tQual a prioridade do paciente? *****\n");
    printf("|\t 1 - Emergência\t\t\t|\n");
    printf("|\t 2 - Urgência\t\t\t|\n");
    printf("|\t 3 - Eletiva\t\t\t|\n");
}



void imprimir(queue *first)
{
    if(first != NULL)
    {
        printf("Nome\tCPF\n%s\t%s\n\n", first->nome, first->cpf);
        imprimir(first->prox);
    }
    else
    {
        printf("NULL\n");
    }
}



void registrar(queue **first, queue **last)
{
    queue *novo = (queue *) malloc(sizeof(queue));
    if (*last == NULL)
    {
        *first = novo; 
    }
    else
    {
        
        (*last)->prox = novo;
    }
    novo->prox = NULL;
    *last = novo;
    printf("Digite o nome do paciente: \n");
    scanf("%s", novo->nome);
    printf("Digite o CPF do/a paciente: \n");
    scanf("%s", novo->cpf);
    printf("O/A paciente %s com o cpf %s foi registrado/a com sucesso!\n", novo->nome, novo->cpf);
    getchar();
    getchar();
}



int contagem(queue *first, char cpf[20], int teste)
{
    if(first != NULL)
    {
        int cont=0;
        while (first != NULL)
        {
            if (teste != 0)
            {
                if(strcmp(cpf, first->cpf) == 0)
                {
                    return ((cont+1)*(-1));
                }
            }
            
            first=first->prox;
            cont++;
        }
        return cont;
    }
    else
    {
        return 0;
    }

}



int qual_proximo(queue *first1, queue *first2, queue *first3, int cont_urg, int cont_ele)
{
    char v[10] = "funciona";
    if (contagem(first1, v, 0) != 0)
    {
        return 1;
    }
    else if (contagem(first2, v, 0) != 0)
    {
        if ((cont_urg % 3 != 0) || cont_urg==0)
        {
            return 2;
        }
        else if (cont_ele != 0)
        {
            if (cont_urg % cont_ele == 0)
            {
                return 2;
            }
            
        }
        
    }
    if(contagem(first3, v, 0) != 0)
    {
        return 3;
    }
    
}



void next(queue **first, queue **last)
{
    if(first != NULL)
    {
        printf("O próximo paciente a ser atendido será: \nNome: %s\nCPF: %s\n", (*first)->nome, (*first)->cpf);
        getchar();
        getchar();
        printf("\n");
        queue *aux=*first;
        if (*first == *last)
        {
            *first = NULL;
            *last = NULL;
        }
        else
        {
            *first = aux->prox;
        }
        free(aux);
    }
    else
    {
        printf("Não existem mais pacientes para atendimento!\n");
    }
}



int onde_esta(int cont1, int cont2, int cont3)
{
    if (cont1 < 0)
    {
        return 1;
    }
    else if (cont2 < 0)
    {
        return 2;
    }
    else if (cont3 < 0)
    {
        return 3;
    }
    else
    {
        return -1;
    }
}


void busca(queue *first1, queue *first2, queue *first3, char cpf[20])
{
    int cont[3], qual;
    int calc = 0;
    cont[0] = contagem(first1, cpf, 1);
    cont[1] = contagem(first2, cpf, 1);
    cont[2] = contagem(first3, cpf, 1);
    qual = onde_esta(cont[0], cont[1], cont[2]);
    switch (qual)
    {
    case 1:
        printf("Tem %d paciente(s) na frente do CPF %s\n", ((-1)*(cont[0])-1), cpf);
        break;
    case 2: 
        cont[1] = cont[1]*(-1);
        for (int i = 0; i < (cont[1]-1); i++)
        {
            calc++;
            if (calc%3==0 && cont[2] != 0)
            {
                calc++;
                cont[2]--;
            }
        }
        printf("Tem %d paciente(s) na frende do CPF %s\n", cont[0]+calc, cpf);
        break;
    case 3:
        cont[2] = cont[2]*(-1);
        for (int i = 0; i < cont[2]; i++)
        {
            if (cont[1] != 0)
            {
                if (cont[1]>3)
                {
                    cont[1] = cont[1]-3;
                    calc = calc +3;
                }
                else
                {
                    calc = calc + cont[1];
                    cont[1] = 0;
                }
            }
            calc++;
        }
        printf("Tem %d paciente(s) na frende do CPF %s\n", cont[0]+calc-1, cpf);
        break;
    case -1:
        printf("Não foi possível encontrar o CPF informado\n");        
        break;
    default:
        break;
    }
    getchar();
    getchar();
    
}



void relatorio(int cont[3])
{
    printf("A quantidade total de pessoas atendidos em situação de emergência foi: %d\n", cont[0]);
    printf("A quantidade total de pessoas atendidos em situação de urgência foi: %d\n", cont[1]);
    printf("A quantidade total de pessoas atendidos em situação de eletiva foi: %d\n", cont[2]);
}

