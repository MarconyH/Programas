#ifndef _LISTv2_H
#define _LISTv2_H

#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class list
{
    public:
    string nome;
    int id;
    int quant;
    string tipo;
    list *prox;

void inserir_info()
{
    cout << "Digite o nome do produto:" << endl;
    cin >> ws;
    getline(cin, this->nome);
    
    cout << "Digite a quantidade em estoque:" << endl;
    cin >> this->quant;

    cout << "Digite o tipo (A = alimento, C = consumo, P = permanente):" << endl;
    cin >> ws;
    getline(cin, this->tipo);

    cout << "ID do produto:" << endl;
    this->id = rand();
    cout << this->id << endl;
}

void imprimir_info()
{
    cout << endl << "O Nome do produto: " << this->nome << endl;
    cout << "A Quantidade em Estoque: " << this->quant << endl;
    cout << "O Tipo do Produto: " << this->tipo << endl;
    cout << "O ID do produto: " << this->id << endl;
}

};

class tipo
{
    public:
    int a, c, p;
    int est_a, est_c, est_p;

void contagem(list *head)
{
    this->a = 0;
    this->c = 0;
    this->p = 0;

    this->est_a = 0;
    this->est_c = 0;
    this->est_p = 0;

    while (head != NULL)
    {
        if (strcmp(head->tipo.c_str(), "A") == 0 || strcmp(head->tipo.c_str(), "a") == 0)
        {
            this->a ++;
            this->est_a += head->quant;
        }

        if (strcmp(head->tipo.c_str(), "C") == 0 || strcmp(head->tipo.c_str(), "c") == 0)
        {
            this->c ++;
            this->est_c += head->quant;
        }
        
        if (strcmp(head->tipo.c_str(), "P") == 0 || strcmp(head->tipo.c_str(), "p") == 0)
        {
            this->p ++;
            this->est_p += head->quant;
        }
        
        head = head->prox;
    }
}
};

void inserir(list **head)
{
    list *novo = new list;
    novo->inserir_info();
    novo->prox = *head;
    *head = novo;
}

void imprimir(list *head)
{
    while (head != NULL)
    {
        head->imprimir_info();
        head = head->prox;
    }
    cout << endl << "Acabou :D" << endl;
}

list *busca(list *achou)
{
    if (achou == NULL)
    {
        cout << "Lista Vazia" << endl;
        return NULL;
    }
    
    string nome;
    cout << "Digite o nome do produto procurado: " << endl;
    cin >> ws;
    getline(cin, nome);

    while (strcmp(achou->nome.c_str(), nome.c_str()) != 0)
    {
        achou = achou->prox;
        if (achou == NULL)
        {
            cout << "Produto não encontrado" << endl;
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
    
    cout << "Produto encontrado: "<< endl;
    aux->imprimir_info();
    aux->inserir_info();
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
    
    cout << "Produto encontrado: " << endl;
    aux->imprimir_info();
    cout << "Digite a quantidade a ser alterada (numero negativo para subtrair e positivo para incrementar): ";
    cin >> quant;
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
        delete(aux);
        return;
    }
    
    while(aux2->prox != aux)
    {
        aux2 = aux2->prox;
    }

    aux2->prox = aux->prox;
    delete(aux);
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
    contado.contagem(head);
    
    dif = diferentes(contado);

    cout << "Existe(m) " << dif << " produto(s) com tipo(s) diferente(s)" << endl;
    cout << "Existe(m) " << contado.a << " do tipo A com " << contado.est_a << " no estoque" << endl;
    cout << "Existe(m) " << contado.c << " do tipo C com " << contado.est_c << " no estoque" << endl;
    cout << "Existe(m) " << contado.p << " do tipo P com " << contado.est_p << " no estoque" << endl;
    cout << "Quantidade total no estoque: " << contado.est_a+contado.est_c+contado.est_p << endl;
    
}

void menu()
{
    cout << endl << "|\t**********************************\t|" << endl;
    cout << "|\t\t\tMENU\t\t\t|" << endl;
    cout << "|\t1-Imprimir\t\t\t\t|" << endl;
    cout << "|\t2-Inserir\t\t\t\t|" << endl;
    cout << "|\t3-Atualizar\t\t\t\t|" << endl;
    cout << "|\t4-Excluir\t\t\t\t|" << endl;
    cout << "|\t5-Mudanca no Estoque\t\t\t|" << endl;
    cout << "|\t6-Relatorio\t\t\t\t|" << endl;
    cout << "|\t0-Sair\t\t\t\t\t|" << endl;
    cout << "|\t**********************************\t|" << endl;
    cout << "Digite a opcao desejada: " << endl;
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
        cout << "Encerrando programa...";
        break;

    default:
        cout << "Valor invalido" << endl;
        break;
    }
}

#endif
