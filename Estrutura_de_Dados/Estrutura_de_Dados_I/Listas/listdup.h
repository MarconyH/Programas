#ifndef _LISTDUP_H
#define _LISTDUP_H

#include <iostream>
using namespace std;

class vehicle
{
  public:
  string name;
  int fabric_year;
  float buy_price;
  float sell_price;
  vehicle *next;
  vehicle *prev;

  void registrar()
  {
    cout << "Digite o nome do veiculo: " << endl;
    cin >> ws;
    getline(cin, this->name);
    
    cout << "Digite o ano de fabricacao do veiculo: " << endl;
    cin >> this->fabric_year;

    cout << "Digite o preco de compra: " << endl;
    cin >> this->buy_price;
    this->sell_price = this->buy_price * 1.20;

    this->next = NULL;
    this->prev = NULL;
  }

  void imprimir_info()
  {
    cout << "Nome: " << this->name << " || Preco de Venda: " << this->sell_price;
    cout << " || Ano de Fabricacao: " << this->fabric_year << endl;
  }
  
};

class group
{
  public:
  vehicle *a_venda;
  vehicle *vendido;

  void inicializar()
  {
    this->a_venda = NULL;
    this->vendido = NULL;
  }

  void menu()
  {
    cout << "************  MENU  ************" << endl;
    cout << "|\t 1 - Imprimir\t\t|" << endl;
    cout << "|\t 2 - Registrar\t\t|" << endl;
    cout << "|\t 3 - Venda\t\t|" << endl;
    cout << "|\t 4 - Busca\t\t|" << endl;
    cout << "|\t 5 - Lucro\t\t|" << endl;
    cout << "|\t 0 - Sair\t\t|" << endl;
  }
};

void inserir(vehicle **head)
{
  vehicle *novo = new vehicle;
  novo->registrar();
  
  if ((*head) == NULL)
  {
    (*head) = novo;
  }

  else
  {
    vehicle *aux = (*head);
    while(aux->next != NULL)
    {  
      if (novo->name < aux->name)
      {
        novo->next = aux;
        if (aux->prev = NULL)
        {
          (*head) = novo;
          novo->next->prev = novo;
        }

        else
        {
          aux->prev->next = novo;
          aux->prev = novo;
        }
      }
      aux = aux->next;
    }
  }
}

void imprimir(vehicle *head)
{
  while (head != NULL)
  {
    head->imprimir_info();
    head = head->next;
  }
  cout << "NULL" << endl;
}

void escolha(int opt, group sistema)
{
  switch (opt)
  {
  case 1:
    cout << "A venda: " << endl;
    imprimir(sistema.a_venda);
    
    cout << "Vendido: " << endl;
    imprimir(sistema.vendido);
    break;
  
  case 2:
    inserir(&(sistema.a_venda));
    break;
  
  case 3:
    break;
  
  case 4: 
    break;
  
  case 5:
    break;
  
  case 0:
    cout << "Encerrando programa...";
    break;

  default:
    break;
  }
}

#endif