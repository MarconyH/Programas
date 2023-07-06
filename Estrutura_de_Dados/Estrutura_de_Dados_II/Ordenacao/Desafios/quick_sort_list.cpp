#include <iostream>
#include <time.h>

using namespace std;

typedef struct node
{
	int cont;
	struct node *next = NULL;
	struct node *prev = NULL;
}node;

node *head = NULL;
int scale = 0;

void receive_data(node *new_node);
void insert_first(int n = 20);
void sort(node *aux);
void fill();
void shuffle();
void print();
void menu();
void choice(int op);

int main()
{
	srand(time(NULL));
	menu();
}

void receive_data(node *new_node)
{
	cout << "Digite o valor do novo elemento: " << endl;
	cin >> new_node->cont;
}

void insert_first(int n)
{
	node *new_node = new node;
	if(n == 20)
	{
		receive_data(new_node);
		scale++;
	}

	else
	{
		new_node->cont = n;
		scale++;
	}

	if(head == NULL)
	{
		head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}

	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		new_node->prev = NULL;
	}
}

node *remove(node *head_aux)
{
	node *aux = head_aux;
	if(aux == NULL)
	{
		return NULL;
	}

	if(aux->prev == NULL)
	{
		aux->next->prev = NULL;
		head_aux = aux_next;
		aux->next = NULL;
		return aux;	
	}

	if(aux->next == NULL)
	{
		aux->prev->prov = NULL;
		aux->prev = NULL;
		return aux;
	}

	aux->prev->next = aux->next;
	aux->next->prev = aux->prev;
	aux->next = NULL;
	aux->prev = NULL;
	return aux;
}

void sort(node *aux, size)
{
	int half_size = size/2;

	node *start = aux;

	for(int i = 0; i < half_size; i++)
	{
		aux = aux->next;
	}

	node *pivot = aux;

	node *smaller = NULL;
	node *bigger = NULL;
	node *head_smaller = NULL;
	node *head_bigger = NULL;

	node *new_node;

	while(start != NULL)
	{
		if(start->cont < pivot)
		{
			new_node = remove(start);
			if(smaller == NULL)
			{
				smaller = new_node;
				head_smaller = new_node;
			}
			else
			{
				smaller->next = new_node;
				new_node->prev = smaller;
				smaller = smaller->next;
			}
		}
		
		else
		{	
			new_node = remove(start);
			if(bigger == NULL)
			{
				bigger = new_node;
				head_bigger = new_node;
			}
			else
			{
				bigger->next = new_node;
				new_node->prev = bigger;
				bigger = bigger->next;
			}
		}
	}

	sort(head_smaller);
	sort(head_bigger);
	smaller = head_smaller;
	while(smaller != NULL);


}

void fill()
{
	cout << "Digite a quantidade de novos elementos: " << endl;
	int quant;
	int num;
	cin >> quant;
	for(int i = 0; i < quant; i++)
	{
		num = rand()%11;
		insert_first(num);
	}
}

void shuffle()
{
	node *aux = head;
	node **v = new node*[scale];
	int num1, num2;

	//Preenche um vetor com todos os elementos da lista
	for(int i = 0; i < scale; i++)
	{
		v[i] = aux;
		aux = aux->next;
	}
	
	/*Escolhe números aleatórios dentro do tamanho do vetor e faz a troca dos 
	elementos na posição dos números aleatórios*/
	for(int i = 0; i < scale*2; i++)
	{
		num1 = rand() % scale;
		num2 = rand() % scale;
		
		while (num1 == num2)
		{
			num2 = rand()%scale;
		}
		

		aux = v[num1];
		v[num1] = v[num2];
		v[num2] = aux;
	}

	//Atualiza a posição dos elementos na lista
	for (int i = 0; i < scale-1; i++)
	{
		v[i]->next = v[i+1];
		v[i+1]->prev = v[i]; 
	}

	//Atualiza o head para a primeira posição do vetor
	head = v[0];
	head->prev = NULL;

	//Faz com que a última posição do vetor aponte para NULL
	v[scale-1]->next = NULL;

	delete [] v;
}

void menu()
{
	int op;
	do
	{
		cout <<" ***************************************" << endl;
		cout << "|\t\tMENU\t\t\t|" << endl;
		cout << "|\t\t\t\t\t|" << endl;
		cout << "|\t1 - Inserir Elemento\t\t|" << endl;
		cout << "|\t2 - Gerar Aleatoriamente\t|" << endl;
		cout << "|\t3 - Imprimir Lista\t\t|" << endl;
		cout << "|\t4 - Embaralhar Lista\t\t|" << endl;
		cout << "|\t5 - Quick Sort\t\t\t|" << endl;
		cout << "|\t0 - Fechar Programa\t\t|" << endl;
		cout <<" ***************************************" << endl;
	
		cin >> op;
		
		choice(op);
	}while(op != 0);
}

void print()
{
	node *aux = head;
	while(aux != NULL)
	{
		cout << aux->cont << " -> ";
		aux = aux->next;
	}
	cout << "NULL" << endl;
}

void choice(int op)
{
	switch(op)
	{
		case 1:
			insert_first();
			break;
		
		case 2:
			fill();
			break;
		
		case 3:
			print();
			break;
		
		case 4:
			shuffle();
			break;

		case 5:
			sort(head);
			break;
		case 0:
			cout << "Encerrando Programa...";
			break;
		default:
			cout << "Valor Inválido";
	}
}

