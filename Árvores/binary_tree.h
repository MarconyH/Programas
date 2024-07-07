#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <time.h>
#include <string>
using namespace std;

class report
{
    public:
        float valor_to;
        int quant_to;
};

class date
{
    public:
        int dia;
        int mes;
        int ano;
        void imprimir()
        {
            if(this->dia < 10)
            {
                cout <<  "0" << this->dia << "/";
            }
            
            else
            {
                cout << this->dia << "/";
            }
            
            if (this->mes < 10)
            {
                cout << "0" << this->mes << "/";
            }
            
            else
            {
                cout << this->mes << "/";
            }
            cout << this->ano;
        }
};

class tree
{
    public:
        int localizador;
        date data;
        float preco;
        string destino;
        report relator;
        tree *direita;
        tree *esquerda;
        

        void relatorio(tree **arv, report *funcionapfv)
        {
            if(*arv != NULL)
            {
                relatorio(&((*arv)->esquerda), funcionapfv);
                relatorio(&((*arv)->direita), funcionapfv);
                funcionapfv->quant_to = funcionapfv->quant_to + 1;
                funcionapfv->valor_to = funcionapfv->valor_to + (*arv)->preco;
            }
        }

        void imprimir_info()
        {
            cout << endl << "Localizador: " << this->localizador << " Destino: " << this->destino << endl;
            cout << "Data: ";
            this->data.imprimir();
            cout << " Preco: " << this->preco << endl;
        }

        
};

class group
{
    public:
        tree *arv_brasil;
        tree *arv_arg;
        tree *arv_junta;

        void inicialize()
        {
            this->arv_brasil = NULL;
            this->arv_arg = NULL;
            this->arv_junta = NULL;
        }

        void menu()
        {
            cout << "************  MENU  ************" << endl;
            cout << "|\t 1 - Imprimir\t\t|" << endl;
            cout << "|\t 2 - Registrar\t\t|" << endl;
            cout << "|\t 3 - Busca\t\t|" << endl;
            cout << "|\t 4 - Relatorio\t\t|" << endl;
            cout << "|\t 5 - Virar Ano\t\t|" << endl;
            cout << "|\t 0 - Sair\t\t|" << endl;
        }

        void imprimir_tree(tree *arv, int cont)
        {
            if (arv != NULL)
            {
                imprimir_tree(arv->esquerda, cont+1);
                cout << endl;
                
                for (int i = 0; i < cont; i++)
                {
                    cout << "  ";
                }
                
                cout << "|";
                cout << arv->localizador << endl;
                imprimir_tree(arv->direita, cont+1);
            }
            
            else
            {
                return;
            }
        }

        void inserir(tree **arv)
        {
            cout << "Data: " << endl << "Dia: ";
            cin >> (*arv)->data.dia;
            
            cout << "Mes: ";
            cin >> (*arv)->data.mes;
            
            cout << "Ano: ";
            cin >> (*arv)->data.ano;
            
            cout << "Preco: ";
            cin >> (*arv)->preco;
            
            cout << "Destino: ";
            cin >> ws;
            getline(cin, (*arv)->destino);
        }

        void enfia(tree *novo, tree **arv)
        {
            if ((*arv) == NULL)
            {
                return;
            }
            
            if (novo->localizador < (*arv)->localizador)
            {
                if ((*arv)->esquerda == NULL)
                {
                    (*arv)->esquerda = novo;
                }
                
                else
                {
                    enfia(novo, &((*arv)->esquerda));
                }
            }
            
            else
            {
                if ((*arv)->direita == NULL)
                {
                    (*arv)->direita = novo;
                }
                
                else
                {
                    enfia(novo, &((*arv)->direita));
                }
            }
        }

        void registrar(tree **arv)
        {
            int localizador;
            localizador = rand();
            
            tree *novo = new tree;
            novo->direita = NULL;
            novo->esquerda = NULL;
            
            inserir(&novo);
            
            novo->localizador = localizador;
            cout << "Localizador: " << novo->localizador << endl;
            
            novo->relator.quant_to = 0;
            novo->relator.valor_to = 0;
            if (*arv == NULL)
            {
                *arv = novo;
            }
            else
            {
                enfia(novo, arv);
            }
        }

         void busca(string destino, tree *arv)
        {
            if(arv != NULL)
            {
                if (arv->esquerda != NULL)
                {
                    busca(destino, arv->esquerda);
                }
                
                if(destino = arv->destino)
                {
                    arv->imprimir_info();
                }
                
                if (arv->direita != NULL)
                {
                    busca(destino, arv->direita);
                }
            }
        }

        void enfia_junto(tree **funcione, tree *logo)
        {
            if (logo == NULL)
            {
                return;
            }
            
            if((*funcione)->localizador < logo->localizador)
            {
                enfia_junto(funcione, logo->esquerda);
            }

            enfia(logo, funcione);

            if ((*funcione)->localizador > logo->localizador)
            {
                enfia_junto(funcione, logo->direita);
            }
        }

        void juntar()
        {
            if (this->arv_junta == NULL)
            {
                this->arv_junta = this->arv_brasil;
            }
            
            else
            {
                enfia_junto(&(this->arv_junta), this->arv_brasil);
            }

            enfia_junto(&(this->arv_junta), this->arv_arg);
        }
};

#endif