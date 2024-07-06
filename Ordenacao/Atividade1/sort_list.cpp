//sort_list.cpp

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

typedef struct LIST
{
	string nome;
	string comp;
	struct LIST *prox;
}LIST;

int tam = 0;

LIST *head;

int caso_base();

void bubble_sort();
void selection_sort();
void insertion_sort();

void imprimir();
void inserir();
void embaralhar(LIST *node);

void menu();
void escolha(int op);


int main()
{
	head = NULL;
	srand(time(NULL));
	menu();
	return 0;
}

int caso_base()
{
	//Casos base, lista não tem elementos ou tem apenas 1 elemento
	if(tam == 0 || tam == 1)
	{
		cout << "Lista não precisa ser ordenada" << endl << endl;
		return 0;
	}

	//Outro caso base, lista tem 2 elementos
	else if(tam == 2)
	{
		LIST *aux = head->prox;
		if(head->comp > aux->comp)
		{
			head->prox = aux->prox;
			aux->prox = head;
			head = aux;

		}
		return 0;
	}

	else
	{
		return 1;
	}


}

void bubble_sort()
{
	int base = caso_base();

	if(base == 0)
	{
		return;
	}

	LIST *aux, *ant, *ant_ant;

	//Variável troca para otimização
	int troca = 0;

	//Bubble sort
	for(int i = 1; i < tam; i++)
	{
		ant = head->prox;
		aux = head->prox->prox;
		ant_ant = head;
	
		//Troca do primeiro elemento
		if(ant_ant->comp > ant->comp)
		{
			ant_ant->prox = ant->prox;
			ant->prox = ant_ant;
			ant_ant = ant;
			ant = ant_ant->prox;
			head = ant_ant;
		}
		
		//Troca dos elementos restantes
		for(int j = 0; j < tam - i; j++)
		{
			if(ant->comp > aux->comp)
			{
				ant->prox = aux->prox;
				aux->prox = ant;
				ant_ant->prox = aux;
				ant = aux;
				aux = ant->prox;
				troca++;
			}
			
			//Atualização das variváveis 
			ant_ant = ant_ant->prox;
			ant = ant->prox;
			if(aux->prox != NULL)
			{
				aux = aux->prox;
			}
			else
			{
				break;
			}

		}

		//Se nenhuma troca tiver sido realizada a lista já está ordenada
		if(troca == 0)
		{
			return;
		}
		troca = 0;
	}
}

void selection_sort()
{
	int base = caso_base();

	if(base == 0)
	{
		return;
	}

	//Declaração das variáveis
	LIST *aux, *menor, *ant_menor, *head_temp;
	aux = head;
	head_temp = head;
	
	//Selection sort
	for(int i = 1; i < tam; i++)
	{
		for(int j = 0; j < tam - i; j++)
		{
			if(aux->comp > aux->prox->comp)
			{
				ant_menor = aux;
				menor = aux->prox;
			}
			aux = aux->prox;
		}

		//Depois de encontrar o menor elemento, este elemento deve ser o head
		if(i == 1)
		{
			head = menor;
		}

		/*Utilizando head temporário para que o mesmo elemento não seja
		  usado 2 vezes
		 */
		if(head_temp != menor)
		{
			ant_menor->prox = menor->prox;

			//Código não será executado apenas na primeira iteração
			if(i != 1)
			{
				menor->prox = head_temp->prox;
				head_temp->prox = menor;
			}

			//Será executado apenas na primeira iteração
			else
			{
				menor->prox = head_temp;
			}
			head_temp = menor;
			aux = menor->prox;
		}
		else
		{
			head_temp = head_temp->prox;
		}
		
	}
}


void insertion_sort()
{
	int base = caso_base();

    if (base == 0)
    {
        return;
    }

	//Variável que vai ser usada para comparação e sua anterior
    LIST *aux, *ant;

	// Variável que vai percorrer a lista e sua anterior
	LIST *head_temp, *ant_head_temp;

    aux = head->prox;
    ant = head;
    
	//Insertion sort
	while (aux != NULL)
	{
		head_temp = head;
		ant_head_temp = NULL;

		//Procurando elemento menor ou igual ao aux
		while (head_temp != aux && head_temp->comp <= aux->comp)
		{
			ant_head_temp = head_temp;
			head_temp = head_temp->prox;
		}

		/*Se a variável que percorre a lista for a mesma que é usada para comparação
		ela já está na posição correta*/
		if (head_temp != aux)
		{
			ant->prox = aux->prox;

			if (ant_head_temp != NULL)
			{
				aux->prox = head_temp;
				ant_head_temp->prox = aux;
			}
			
			else
			{
				aux->prox = head;
                head = aux;
			}
			aux = ant->prox;
		}
		else
		{
			ant = aux;
			aux = aux->prox;
		}
	}
	

	/*
	for(int i = 0; i < tam; i++)
	{
		ant_head_temp = head;
		head_temp = head;

		for(int j = 0; j < tam-i; j++)
		{
			if(aux->comp <= head_temp->comp && aux != head_temp)
			{
				ant->prox = aux->prox;
				aux->prox = head_temp;
				if(head_temp == head)
				{
					head = aux;
				}
				else
				{
					ant_head_temp->prox = aux;
				}
				
				break;
			}
			ant_head_temp = head_temp;
			head_temp = head_temp->prox;
		}
		ant = aux;
		aux = ant->prox;
	}*/
}

void embaralhar()
{
	LIST *aux = head;
	LIST **v = new LIST*[tam];
	int num1, num2;

	//Preenche um vetor com todos os elementos da lista
	for(int i = 0; i < tam; i++)
	{
		v[i] = aux;
		aux = aux->prox;
	}
	
	/*Escolhe números aleatórios dentro do tamanho do vetor e faz a troca dos 
	elementos na posição dos números aleatórios*/
	for(int i = 0; i < tam*2; i++)
	{
		num1 = rand() % tam;
		num2 = rand() % tam;
		
		while (num1 == num2)
		{
			num2 = rand()%tam;
		}
		

		aux = v[num1];
		v[num1] = v[num2];
		v[num2] = aux;
	}

	//Atualiza a posição dos elementos na lista
	for (int i = 0; i < tam-1; i++)
	{
		v[i]->prox = v[i+1];
	}

	//Atualiza o head para a primeira posição do vetor
	head = v[0];

	//Faz com que a última posição do vetor aponte para NULL
	v[tam-1]->prox = NULL;

	delete [] v;
}

//Rotina de entrada de dados
void inserir()
{
	
	LIST *novo = new LIST[1];
	cout << "Digite o nome: ";
	cin >> novo->nome;
	
	//Cópia do nome 
	novo->comp = novo->nome;
	

	//Cópia do nome fica em minúsculo para comparações
	for(char&c : novo->comp)
	{
		c = tolower(c);
	}
	
	novo->prox = head;
	head = novo;

	//Atualiza o tamanho da lista
	tam++;
}

//Rotina de saída de dados
void imprimir()
{
	cout << endl << endl;
	LIST *node = head;
	while(node != NULL)
	{
		cout << node->nome << " -> ";
		node = node->prox;
	}
	cout << "NULL" << endl;

	cout << "Aperte qualquer tecla para continuar... ";
	getchar();
	getchar();
	cout << endl;
}

//Menu visível pelo usuário
void menu()
{
	int op;
	do
	{
		cout <<" ***************************************" << endl;
		cout << "|\t\tMENU\t\t\t|" << endl;
		cout << "|\t\t\t\t\t|" << endl;
		cout << "|\t1 - Inserir Elemento\t\t|" << endl;
		cout << "|\t2 - Imprimir Lista\t\t|" << endl;
		cout << "|\t3 - Embaralhar Lista\t\t|" << endl;
		cout << "|\t4 - Bubble Sort\t\t\t|" << endl;
		cout << "|\t5 - Selection Sort\t\t|" << endl;
		cout << "|\t6 - Insertion Sort\t\t|" << endl;
		cout << "|\t0 - Fechar Programa\t\t|" << endl;
		cout <<" ***************************************" << endl;
	
		cin >> op;
		
		escolha(op);
	}while(op != 0);
}

//Funcionamento interno do menu
void escolha(int op)
{
	switch(op)
	{
		case 1:
			inserir();
			break;
		
		case 2:
			imprimir();
			break;
		
		case 3:
			embaralhar();
			break;

		case 4:
			bubble_sort();
			break;
		
		case 5:
			selection_sort();
			break;
		
		case 6:
			insertion_sort();
			break;
		case 0:
			cout << "Encerrando Programa...";
			break;
		default:
			cout << "Valor Inválido" << endl;
			cout << "Digite um valor que esteja no menu" << endl;
	}
}