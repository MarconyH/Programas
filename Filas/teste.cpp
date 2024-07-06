#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct registro
{
    char nome[30];
    char cpf[15];
    char prioridade[10];
    struct registro *prox;
} Paciente;

typedef struct
{
    Paciente *emergencia;
    Paciente *urgencia;
    Paciente *eletivo;
} Filas;

Filas *criarFilas()
{ 
    Filas *novafila = (Filas *)malloc(sizeof(Filas));
    novafila->emergencia = NULL;
    novafila->urgencia = NULL;
    novafila->eletivo = NULL;

    return novafila;
}

void infoPaciente(Paciente **pac)
{
    printf("\nNome: ");
    scanf("%s", (*pac)->nome);
    printf("CPF: ");
    scanf("%s", (*pac)->cpf);
}

void imprimir(Paciente *pac)
{
    printf("\nNome:%s\n", pac->nome);
    printf("CPF:%s\n", pac->cpf);
    printf("Nivel:%s\n", pac->prioridade);
}

Paciente *registrar()
{

    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));

    infoPaciente(&novo);

    novo->prox = NULL;

    return novo;
}

void enfileirar(Paciente **fila, Paciente *registrado)
{
    if (*fila == NULL)
    {
        *fila = registrado;
    }
    else
    {
        Paciente *aux = *fila;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = registrado;
    }
}

Paciente *remover(Paciente **fila)
{
    Paciente *rem = *fila;
    *fila = rem->prox;
    rem->prox = NULL;
    return rem;
}

Paciente *next(Filas *fila)
{
    static int cont = 0;

    if (fila->emergencia != NULL)
    {
        return remover(&(fila)->emergencia); 
    }

    if (cont != 3 && fila->urgencia != NULL)
    {
        cont++;
        return remover(&(fila)->urgencia);
    }

    if (fila->eletivo != NULL)
    {
        cont = 0;
        return remover(&(fila)->eletivo); 
    }
}

void imprimirFila(Paciente *fila)
{
    while (fila != NULL)
    {
        imprimir(fila);
        fila = fila->prox;
    }
}

void menu(Filas *filas)
{
    Paciente *novo;
    int opc;

        printf("\nNivel de Prioridade:\n");
        printf("\n1-Emergencia\n");
        printf("2-Urgencia\n");
        printf("3-Eletivo\n");

        printf("\nInforme a Opcao: ");
        scanf("%d", &opc);
      
    while (1)
    {

        switch (opc)
        {
        case 1:

            novo = registrar();
            strcpy(novo->prioridade, "Emergencia");
            enfileirar(&(filas)->emergencia, novo);

            return;
        case 2:

            novo = registrar();
            strcpy(novo->prioridade, "Urgencia");
            enfileirar(&(filas)->urgencia, novo);

            return;
        case 3:
            novo = registrar();
            strcpy(novo->prioridade, "Eletivo");
            enfileirar(&(filas)->eletivo, novo);

            return;
        default:
            printf("\n\tOpcao Invalida!\n");
            return;
            
        }
    }
}

int busca(Filas * fila , char buscocpf[15]){
    
    Paciente * emergencia= fila->emergencia;
    Paciente * urgencia= fila-> urgencia;
    Paciente * eletivo= fila-> eletivo;
    
    
    int contador_principal= 0, contador_auxiliar = 0;
    while(emergencia != NULL)
    {    contador_principal++;
        if(strcmp(emergencia->cpf, buscocpf) == 0){
    
         return contador_principal - 1; 
        }
       emergencia=emergencia->prox;
    }

while (urgencia != NULL || eletivo != NULL ){
    if (contador_auxiliar != 3 && urgencia != NULL)
    {
        contador_principal++;
        contador_auxiliar++;
         
          if(strcmp(urgencia->cpf, buscocpf) ==  0){
        
        return  contador_principal-1;
    }
        urgencia=urgencia->prox;
    }
    if (eletivo != NULL)
    {
        contador_auxiliar = 0;
        contador_principal++;
   
         
        if(strcmp(eletivo->cpf, buscocpf) == 0){
            return contador_principal-1;
        }
        eletivo=eletivo->prox;
        }}
        return -1;
        }
    
    
    void relatorio(Paciente *pac, int *quant_emerg, int *quant_urgen, int *quant_elet){

    if(strcmp(pac->prioridade, "Emergencia") == 0){
        *quant_emerg += 1;
        return;
    }

    if(strcmp(pac->prioridade, "Urgencia") == 0){
        *quant_urgen += 1;
        return;
    }

    if(strcmp(pac->prioridade, "Eletivo") == 0){
        *quant_elet += 1;
        return;
    }
}


int main()
{
    
    Filas *fila = criarFilas();
    Paciente *vou_atender;
    Paciente *novopaciente;
    int opc;
    int opc2;
    int opcao3;
   char buscocpf[15];
    int quantidade;
    int emergencia = 0, urgencia = 0, eletivo=0;
    
    while (opc!=0)   {
        
 printf("\n1-Cadastrar Paciente\n2-ImprimirPacientes\n3-Proximo Paciente a ser Atendido\n4-Buscar CPF.\n5-Relatorio.\n0-Sair\n");
        printf("\n\tInforme a Opcao: ");
        scanf("%d", &opc);
        switch (opc){
        case 1:
            menu(fila);

            break;
        case 2:         
                imprimirFila(fila->emergencia);
                imprimirFila(fila->urgencia);
                imprimirFila(fila->eletivo);
                break;

   
      case 3:
      
      
     if(fila->emergencia==NULL || fila->urgencia==NULL || fila->eletivo){
       
        vou_atender=next(fila);
     
      printf("\nO doutor esta te esperando:%s\n",vou_atender->nome);
      printf("Nivel de Prioridade:%s\n",vou_atender->prioridade);
      
      relatorio(vou_atender, &emergencia , &urgencia ,&eletivo);
      
      free(vou_atender);
      
      break;
        }
       case 4: 
       printf("Qual Cpf voce busca:  ");
       scanf("%s",buscocpf);
            
         quantidade =  busca(fila , buscocpf);
           if (quantidade < 0)
           {
                printf("CPF não encontrado\n");
           }
           else
           {
                printf("Tem um total de %d pessoas na sua frente.\n", quantidade);
           }
        break;
                 
       
       case 5:
       
         printf("\nRelatorio:\n");
            printf("\nEmergencia: %d\n", emergencia);
            printf("Urgencia: %d\n", urgencia);
            printf("Eletivo: %d\n", eletivo);

            break;
            
            
        default:
            printf("\n\tOpcao Invalida!\n");
            break;
      
    }}

    return 0;
  }