#include <iostream>

using namespace std;

class date
{
    public:
        int dia;
        int mes;
        int ano;
		int comp;
		void comp_calc()
		{
			this->comp = this->dia + this->mes * 30 + this->ano * 365;
		}

        void print()
        {
            if(this->dia < 10)
            {
                cout << "0" << this->dia << "/";
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

	void colect()
	{
		cout << "Dia: ";
		cin >> this->dia;
		cout << "Mês: ";
		cin >> this->mes;
		cout << "Ano: ";
		cin >> this->ano;
		this->comp_calc();
	}
};


class ticket
{
	public:
		string cpf;
		string nome;
		date data;
		ticket *next = NULL;

		void colect()
		{
			cout << "Digite seu CPF: ";
			cin >> this->cpf;
			cout << "Digite seu nome: ";
			cin >> this->nome;
			cout << "Digite a data do evento: ";
			this->data.colect();
		}

		void print()
		{
			cout << "CPF: " << this->cpf << endl;
			cout << "Nome: " << this->nome << endl;
			cout << "Data: ";
			this->data.print();
			cout << endl << endl;
		}
};

class list
{
	public:
		ticket *head = NULL;
		ticket *tail = NULL;
		int tam = 0;
		int data_sort = 0;
		void print()
		{
			ticket *aux = this->head;
			while(aux != NULL)
			{
				aux->print();
				aux = aux->next;
			}
		}
};

list *event = NULL;


int search_insert(string cpf, date data);
void search();
int base_case();
void insertion_sort(ticket *new_tick);
void insert();
ticket *remove(ticket *prev, ticket *aux, list *aux_place);
void quick_sort(list *sort);

void menu();
void choice(int op);

int main()
{
	menu();
	return 0;
}


int search_insert(string cpf, date data)
{
	if(event == NULL)
	{
		return 1;
	}
	if(event->tam == 0)
	{
		return 1;
	}
	
	ticket *aux = event->head;
	data.comp_calc();
	while(aux != NULL)
	{
		aux->data.comp_calc();
		if(aux->cpf == cpf && aux->data.comp == data.comp)
		{
			cout << "Já existe um ingresso com este cpf para esta data: " << endl;
			aux->print();
			return 0;
		}
		aux = aux->next;
	}

	return 1;
}

void search()
{
	if(event == NULL)
	{
		cout << "Não existem ingressos cadastrados" << endl;
		return;
	}

	cout << "Digite o CPF que está cadastrado nos ingressos: ";
	string cpf;
	cin >> cpf;

	ticket *aux = event->head;
	cout << "Os ingressos cadastrados neste CPF foram: " << endl;
	while(aux != NULL)
	{
		if(aux->cpf == cpf)
		{
			aux->print();
			aux = aux->next;
		}
		else 
		{
			aux = aux->next;
		}
	}
	cout << "NULL" << endl;
}

int base_case(ticket *new_tick)
{
	if(event == NULL)
	{
		event = new list;
	}

	int tam = event->tam;

	if(tam == 0)
	{
		event->head = new_tick;
		event->tail = new_tick;
		event->tam++;
		return 0;
	}

	if(tam == 1)
	{
		if(event->head->cpf < new_tick->cpf)
		{
			event->head->next = new_tick;
			new_tick->next = NULL;
			event->tail = new_tick;
		}

		else
		{
			new_tick->next = event->head;
			event->tail = event->head;
			event->head = new_tick;
			event->tail->next = NULL;
		}
		event->tam++;
		return 0;
	}
	
	return 1;
}

void insertion_sort(ticket *new_tick)
{

	if(event == NULL)
	{
		return;
	}

	ticket *head_temp, *prev_head_temp;
	int test = 0;
	head_temp = event->head;
	prev_head_temp = NULL;

	while(head_temp != NULL)
	{
		if(new_tick == NULL)
		{
			break;
		}
		if(head_temp->cpf > new_tick->cpf)
		{
			if(prev_head_temp != NULL)
			{
				new_tick->next = head_temp;
				prev_head_temp->next = new_tick;
			}	

			else
			{
				new_tick->next = head_temp;
				event->head = new_tick;
			}
			event->tam++;
			test = 1;
			break;
		}
		prev_head_temp = head_temp;
		head_temp = head_temp->next;
	}

	if(test == 0 && new_tick != NULL)
	{
		prev_head_temp->next = new_tick;
		event->tail = new_tick;
		event->tam++;
	}

	head_temp = event->head;
	prev_head_temp = NULL;

	if(event->data_sort == 1)
	{

		ticket *aux, *prev;

		aux = head_temp->next;
		prev = head_temp;

		while(aux != NULL)
		{
			head_temp = event->head;
			prev_head_temp = NULL;

			while(head_temp != aux && head_temp->cpf <= aux->cpf)
			{
				prev_head_temp = head_temp;
				head_temp = head_temp->next;
			}

			if(head_temp != aux)
			{
				prev->next = aux->next;
				
				if(prev_head_temp != NULL)
				{
					aux->next = head_temp;
					prev_head_temp->next = aux;
				}

				else
				{
					aux->next = event->head;
					event->head = aux;
				}
				aux = prev->next;
			}
			else
			{
				prev = aux;
				aux = aux->next;
			}
		}

		event->data_sort = 0;
	}

	
}

void insert()
{
	ticket *new_tick = new ticket;
	new_tick->colect();
	int comp = search_insert(new_tick->cpf, new_tick->data);

	if(comp == 1)
	{
		comp = base_case(new_tick);
		if(comp == 1)
		{
			insertion_sort(new_tick);
			cout << "Ingresso cadastrado" << endl;
			return;
		}
		cout << "Ingresso cadastrado" << endl;
		return;
	}

	return;
		
}

ticket *remove(ticket *prev, ticket *aux, list *aux_place)
{
	if(aux_place == NULL || aux == NULL)
	{
		return NULL;
	}

	if(aux_place->tam == 0)
	{
		return NULL;
	}

	if(aux_place->tam == 1)
	{
		aux_place->tail = NULL;
		aux_place->head = NULL;
		aux_place->tam--;
		aux->next = NULL;
		return aux;
	}

	if(prev == NULL)
	{
		aux_place->tam--;
		aux_place->head = aux->next;
		aux->next = NULL;
		return aux;
	}

	if(aux->next == NULL)
	{
		prev->next = NULL;
		aux_place->tail = prev;
		aux_place->tam--;
		return aux;
	}
	
	prev->next = aux->next;
	aux->next = NULL;
	aux_place->tam--;

	return aux;
}

void quick_sort(list *sort)
{
	if(sort == NULL)
	{
		return;
	}

	if(sort->tam == 0 || sort->tam == 1)
	{
		return;
	}

	int half_tam = sort->tam/2;
	ticket *pivot = sort->head;
	ticket *prev_pivot = NULL;

	for(int i = 0; i < half_tam; i++)
	{
		prev_pivot = pivot;
		pivot = pivot->next;
	}

	list *smaller = new list;
	list *bigger = new list;

	smaller->tam = 0;
	bigger->tam = 0;

	ticket *aux = sort->head;
	ticket *insert = NULL;
	ticket *remove_element = NULL;
	ticket *prev = NULL;

	while(aux != NULL)
	{
		
		if(aux == pivot)
		{
			prev = aux;
			aux = aux->next;
			continue;
		}

		if(aux->data.comp < pivot->data.comp)
		{
			remove_element = aux;	
			aux = aux->next;
			insert = remove(prev, remove_element, sort);
			
		
			if(smaller->tam == 0)
			{
				smaller->head = insert;
				smaller->tail = insert;
			}		

			else
			{
				smaller->tail->next = insert;
				smaller->tail = insert;	
			}
			smaller->tam++;
		}

		else
		{
			remove_element = aux;
			aux = aux->next;
			insert = remove(prev, remove_element, sort);
			

			if(bigger->tam == 0)
			{
				bigger->head = insert;
				bigger->tail = insert;				
			}
			
			else
			{
				bigger->tail->next = insert;
				bigger->tail = insert;
			}
			bigger->tam++;
		}
		if(prev != NULL)
		{
			prev = prev->next;
		}
	}

	quick_sort(smaller);
  	if(smaller->tam != 0)
  	{
		smaller->tail->next = sort->head;
		sort->tam += smaller->tam;
		sort->head = smaller->head;
  	}
  
	quick_sort(bigger);
	if(bigger->tam != 0)
  	{
    	sort->tail->next = bigger->head;
		sort->tam += bigger->tam;
		sort->tail = bigger->tail;
  	}
	smaller->head = NULL;
	smaller->tail = NULL;
	
	delete smaller;

	bigger->head = NULL;
	bigger->tail = NULL;

	delete bigger;
	
	event->data_sort = 1;
}

void ls
()
{
	int op;
	do
	{
		cout <<" ***************************************" << endl;
		cout << "|\t\tMENU\t\t\t|" << endl;
		cout << "|\t\t\t\t\t|" << endl;
		cout << "|\t1 - Comprar Novo Ingresso\t|" << endl;
		cout << "|\t2 - Buscar Ingressos\t\t|" << endl;
		cout << "|\t3 - Imprimir Ingressos\t\t|" << endl;
		cout << "|\t4 - Ordenar por Data\t\t|" << endl;
		cout << "|\t0 - Finalizar Vendas\t\t|" << endl;
		cout <<" ***************************************" << endl;
	
		cin >> op;
		
		choice(op);
	}while(op != 0);
}

void choice(int op)
{
	switch(op)
	{
		case 1:
			insert();
			break;
		
		case 2:
		
			insertion_sort(NULL);
			search();
			break;
		
		case 3:
			if(event != NULL)
			{
				event->print();
			}
			else
			{
				cout << "Lista não existe" << endl;
			}
			
			break;

		case 4:
			quick_sort(event);
			if(event != NULL)
			{
				ticket *aux = event->head;
				ticket *prev = NULL;
				date comp_print;
				
				int cont = 0;
				while (aux != NULL)
				{
					if(prev == NULL)
					{
						prev = aux;
						aux = aux->next;
						cont++;
						continue;
					}
					if(aux->data.comp == prev->data.comp)
					{
						cont++;
					}

					else
					{
						comp_print = prev->data;
						cout << "Na data ";
						comp_print.print();
						cout << " existem ";
						cout << cont << " ingressos cadastrados" << endl;
						
						cont = 1;
					}
					prev = aux;
					aux = aux->next;
					
				}

				if (prev != NULL) 
				{
					comp_print = prev->data;
					cout << "Na data ";
					comp_print.print();
					cout << " existem ";
					cout << cont << " ingressos cadastrados" << endl;
				}
			}

			else
			{
				cout << "Lista não existe" << endl;
			}
			
			break;

		case 0:
			cout << "Encerrando Programa...";
			break;
			
		default:
			cout << "Valor Inválido" << endl;
	}
}