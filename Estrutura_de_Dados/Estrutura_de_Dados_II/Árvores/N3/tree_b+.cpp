#include <iostream>
#include <time.h>
#include <string>
using namespace std;

#define N 5

class Date
{
	public:
		int day;
		int month;
		int year;

		Date() : day(0), month(0), year(0)
		{}
		
		void print()
		{
            		if(this->day < 10)
            		{
                		cout <<  "0" << this->day << "/";
            		}
            
            		else
            		{
                		cout << this->day << "/";
            		}
            
          		if (this->month < 10)
            		{
               			cout << "0" << this->month << "/";
            		}
            
           		else
            		{
                		cout << this->month << "/";
            		}
            		cout << this->year;
        	}

		void day_(int day)
		{
			this->day = day;
		}

		void month_(int month)
		{
			this->month = month;
		}

		void year_(int year)
		{
			this->year = year;
		}
};

class Medicine
{
	public:
		string bar_cod;
		string med_name;
		Date date;
		int quantity;
		float price;

		Medicine() : quantity(0), price(0){}

		void print()
		{
			cout << "Código de barra: ";
			cout << this->bar_cod << endl;
			cout << "Nome do medicamento: ";
			cout << this->med_name << endl;
			cout << "Data: ";
			date.print();
			cout << endl;
			cout << "Quantidade: ";
			cout << quantity << endl;
			cout << "Preço: ";
			cout << price << endl << endl;
		}

		void insert(string bar_cod, string med_name, int day, int month, int year, int quantity, float price)
		{
			this->bar_cod = bar_cod;
			this->med_name = med_name;
			this->date.day_(day);
			this->date.month_(month);
			this->date.year_(year);
			this->quantity = quantity;
			this->price = price;
		}

};

class Page
{
	public:
		int position;
		bool leaf;
		string codes[N-1];
		Page *father;
		Medicine *medicine[N-1];
		Page *children[N];
		Page *next;
	
		void initialize_codes()
		{
			for(int i = 0; i < N-1; i++)
			{
				this->codes[i] = '\0';
			}
		}

		void initialize_medicine()
		{
			for(int i = 0; i < N-1; i++)
			{
				this->medicine[i] = NULL;
			}
		}

		void initialize_children()
		{
			for(int i = 0; i < N; i++)
			{
				this->children[i] = NULL;
			}
		}
		
		Page() : position(0), leaf(true), father(NULL), next(NULL)
		{
			this->initialize_codes();
			this->initialize_medicine();
			this->initialize_children();
		}

		void print()
		{
			if(this == NULL)
			{
				return;
			}
			if(this->leaf)		
			{
				for(int i = 0; i < this->position; i++)
				{
					medicine[i]->print();
				}
				if(this->next != NULL)
				{
					this->next->print();
				}
			}

			else
			{
				this->children[0]->print();
			}
		}
};

Page *division(Page *page);
Medicine *search(Page *root, string bar_code);
Page *search_insert(Page *root, string bar_code);
bool sibling(Page *root);
int index_father(Page *father, Page *child);
void insert_father(Page **root, Page *page, Page *father);
void insert(Page **root, Medicine *medicine);
Medicine *generate();
void print_tree(Page *root, int tab = 0, string code = "");
void menu(Page **root);
void choice(Page **root, int option);

int main()
{
	srand(time(NULL));
	Page *root = NULL;
	Medicine *medicine;
	menu(&root);
	return 0;
}


Page *division(Page *page)
{
	int midle = (N-1)/2;
	Page *father = new Page;
	Page *right = new Page;

	father->children[0] = page;
	father->children[1] = right;

	right->next = page->next;
	page->next = right;
	int i;
	for(i = 0; i < (N-1) - (midle+1); i++)
	{
		right->medicine[i] = page->medicine[i + (midle+1)];
		right->children[i] = page->children[i + (midle+1)];
		right->position++;

		page->medicine[i+(midle+1)] = NULL;
		page->children[i+(midle+1)] = NULL;
		page->position--;
	}
	right->children[i] = page->children[i + (midle + 1)];
	page->children[i + (midle + 1)] = NULL;

	father->codes[0] = page->medicine[midle]->bar_cod;
	father->position++;

	father->father = page->father;
	page->father = father;
	right->father = father;


	father->leaf = false;
	if(page->leaf)
	{
		right->leaf = true;
	}

	return father;
}

Medicine *search(Page *root, string bar_code)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(!root->leaf)
	{
		for(int i = 0; i < root->position; i++)
		{
			if(bar_code <= root->codes[i])
			{
				return search(root->children[i], bar_code);
			}
		}
		return search(root->children[root->position], bar_code);
	}

	else
	{
		int i;
		for(i = root->position; root->medicine[i]->bar_cod != bar_code; i--)
		{
			if(i == 0)
			{
				break;
			}
		}
		if(root->medicine[i]->bar_cod == bar_code)
		{
			return root->medicine[i];
		}
		return NULL;
	}
}

Page *search_insert(Page *root, string bar_code)
{
	if(root == NULL)
	{
		return NULL;
	}
	int i;
	for(i = root->position-1; root->codes[i] > bar_code; i--){}
	
	if(root->leaf)
	{
		if(root->codes[i] == bar_code)
		{
			root->medicine[i]->quantity++;
			return NULL;
		}
		else
		{
			return root;
		}
	}
	else
	{
		return search_insert(root->children[i], bar_code);
	}

}

//irmão tem espaço
bool sibling(Page *root)
{
	if(root->next == NULL)
	{
		return false;
	}

	if(root->next->position < N-1 && root->next->father == root->father)
	{
		return true;
	}
	return false;
}

int index_father(Page *father, Page *child)
{
	for(int i = 0; i < father->position+1; i++)
	{
		if(father->children[i] == child)
		{
			//vai dar erro na inserção, tento acessar o codigo com esse index, mas codigo tem 1 numero a menos
			return i;
		}
	}
	return -1;
}

void insert_father(Page **root, Page *page, Page *father)
{
	if(*root == NULL)
	{
		return;
	}
	
	if(father == NULL)
	{
		*root = page;
		return;
	}

	//pai tem espaço
	if(father->position < N-1)
	{
		int i = father->position -1;
		while(i >= 0 && page->codes[0] < father->codes[i])
		{
			father->codes[i+1] = father->codes[i];
			if(i == father->position-1)
			{
				father->children[i+2] = father->children[i+1];
			}
			father->children[i+1] = father->children[i];
			i--;
		}
		father->codes[i+1] = page->codes[0];
		page->position++;
		
		father->children[i+1] = page->children[0];
		father->children[i+2] = page->children[1];
		return;	
	}

	//pai não tem espaço
	else
	{
		Page *grandpa = division(father);	
		insert_father(root, father, grandpa);
	}

}

void insert(Page **root, Medicine *medicine)
{
	if(*root == NULL)
	{
		*root = new Page;
		(*root)->medicine[0] = medicine;
		(*root)->codes[0] = medicine->bar_cod;
		(*root)->position++;
		return;
	}
	
	Page *page = search_insert(*root, medicine->bar_cod);
	if(page == NULL)
	{
		return;
	}	
	//se é igual, aumento a quantidade e retorno
	for(int i = 0; i < page->position; i++)
	{	
		cout << page->medicine[i]->bar_cod << endl;
		cout << medicine->bar_cod << endl;
		if(page->medicine[i]->bar_cod == medicine->bar_cod)
		{
			page->medicine[i]->quantity++;
			return;
		}
	}

	//se tem espaço
	if(page->position < N-1)
	{
		int i = page->position -1;
		while(i >= 0 && page->medicine[i]->bar_cod > medicine->bar_cod)
		{
			page->medicine[i+1] = page->medicine[i];
			i--;
		}
		page->medicine[i+1] = medicine;
		page->position++;
		return;
	}

	//não tem espaço
	else
	{
		//irmão com espaço
		if(sibling(*root))
		{
			//codigo medicina é imediatamente maior que pagina atual, será inserido no irmão
			int index = index_father(page->father, page);
			if(page->medicine[page->position-1]->bar_cod < medicine->bar_cod)
			{
				page->father->codes[index] = page->medicine[page->position-1]->bar_cod;
				insert(root, medicine);
				return;
			}
			
			else
			{
				Medicine *aux = page->medicine[page->position-1];
				page->position--;
				insert(root, medicine);
				page->father->codes[index] = page->medicine[page->position-1]->bar_cod;
				insert(root, aux);
				return;
			}

			
		}

		//irmão cheio
		else
		{
			Page *father = division(page);
			insert(&father, medicine);

			insert_father(root, father, father->father);
		}
	}
}

bool sibling_remove(Page *root)
{
	if(root->next != NULL && root->next->position > N/2 && root->father == root->next->father)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void sort(int i, Page *page)
{
	for(int j = i; j < page->position-1; j++)
	{
		page->medicine[j] = page->medicine[j+1];
		page->codes[j] = page->codes[j+1];
		page->medicine[j+1] = NULL;
		page->codes[j+1] = '\0';
	}
}

void remove(Page **root, Medicine *medicine)
{
	if(*root == NULL)
	{
		return;
	}

	Page *page = search_insert(*root, medicine->bar_cod);
	//1 - não encontrou elemento
	if(page == NULL)
	{
		return;
	}

	//2 - encontrou elemento
	for(int i = 0; i < page->position; i++)
	{
		if(page->medicine[i]->bar_cod == medicine->bar_cod)
		{
			page->medicine[i]->quantity--;
			if(page->medicine[i]->quantity == 0)
			{
				//2.1 - página está no tamanho mínimo
				if(page->position > N/2)
				{
					//2.1.1 - medicamento que vou retirar está no final
					if(i == page->position-1)
					{
						page->codes[i] = '\0';
						page->medicine[i] = NULL;
					}

					//2.1.2 - medicamento está em outra posição do vetor
					else
					{
						sort(i, page);
					}
					page->position--;
					return;
				}

				//2.2 - página não está no tamanho mínimo				
				else
				{
					//2.2.1 - irmão tem elementos sobrando
					if(sibling_remove(page))
					{
						Medicine *medicine_aux = page->next->medicine[0];
						sort(0, page->next);
						page->next->position--;

						int index = index_father(page->father, page);
						page->father->codes[i] = medicine_aux->bar_cod;
						insert(root, medicine_aux);
						remove(root, medicine);
						return;
					}

					//2.2.2 - irmão não tem elementos suficientes
					else
					{
						//2.2.2.1 - pai tem elementos sobrando
						if(page->father->position > N/2)
						{
							
							return;
						}

						//2.2.2.2 - pai está no tamanhoo mínimo
						else
						{
							
							return;
						}
					}
				}
			}	
		}
	}
}

Medicine *generate()
{
	char letter[27] = {"abcdefghijklmnopqrstuvwxyz"};
	string bar_cod = to_string(rand()%1000);
	string med_name = "";
	for(int i = 0; i < rand()%15; i++)
	{
		med_name += letter[rand()%26];
	}
       	int day = rand()%31;
	int month = rand()%13;
	int year = rand()%5000;
	int quantity = 5;
	float price = rand();
	Medicine *medicine = new Medicine;
	medicine->insert(bar_cod, med_name, day, month, year, quantity, price);
	return medicine;
}

void print_tree(Page *root, int tab, string code)
{
    if (root == NULL)return;

    for(int i = root->position; i>0; i--){
        print_tree(root->children[i], tab + 1, root->codes[0]);
    }
    for (int i = 0; i < tab; i++)
    {
        cout << "\t";
    }
    cout << "|";
    for (int i = 0; i <  root->position; i++) {
        cout << root->codes[i];
    }
    cout << "|" << endl;
    print_tree(root->children[0], tab + 1, root->codes[0]);

}

void menu(Page **root)
{
	int op = -1;
	while (op != 0)
	{
	
		cout <<" ***************************************" << endl;
		cout << "|\t\tMENU\t\t\t|" << endl;
		cout << "|\t\t\t\t\t|" << endl;
		cout << "|\t1 - Imprimir Árvore\t\t|" << endl;
		cout << "|\t2 - Adicionar Elemento\t\t|" << endl;
		cout << "|\t3 - Buscar Elemento\t\t|" << endl;
		cout << "|\t4 - Remover Elemento\t\t|" << endl;
		cout << "|\t5 - Gerar Elemento\t\t|" << endl;
		cout << "|\t6 - Imprimir Formatado\t\t|" << endl;
		cout << "|\t0 - Finalizar Programa\t\t|" << endl;
		cout <<" ***************************************" << endl;
		
		cin >> op;
		choice(root, op);
	}
}

void choice(Page **root, int option)
{
	switch(option)
	{
		case 1:
			try
			{
				(*root)->print();
			}
			catch(...)
			{
				cout << "Erro print" << endl;
			}
			break;	
		case 2:
			try
			{
				Medicine *medicine = new Medicine;
				string bar_cod;
				cout << "Digite o código de barras: " << endl;
				cin >> bar_cod;
			
				string med_name;
				cout << "Digite o nome do medicamento: "<< endl;
				cin >> med_name;

				int day;
				int month;
				int year;
				cout << "Digite o dia, mês e ano: " << endl;
				cin >> day;
				cin >> month;
				cin >> year;

				int quantity;
				cout << "Digite a quantidade de medicamentos: " << endl;
				cin >> quantity;

				float price;
				cout << "Digite o preço do medicmento: " << endl;
				cin >> price;
			
			

				medicine->insert(bar_cod, med_name, day, month, year, quantity, price);
				insert(root, medicine);              
			}
			catch(...)
			{
				cout << "Erro no adicionar" << endl;
			}
			break;
		case 3:
			try
			{
				string bar_code;
				cout << "Digite o código de barras que você está procurando: " << endl;
				cin >> bar_code;
				Medicine *medicine;
				medicine = search(*root, bar_code);
				medicine->print();
			}
			catch(...)
			{
				cout << "Erro na busca" << endl;
			}
			break;
		case 4:
			try
			{
				cout << "Digite o código de barra do elemento que você quer remover: " << endl;
				string bar_code;
				cin >> bar_code;
				//remove(root, bar_code);
			}
			catch(...)
			{
				cout << "Erro na remoção" << endl;
			}
			break;

		case 5:
			cout << "Digite quantos medicamentos você quer gerar: " << endl;
			int quantity;
			cin >> quantity;
			Medicine *medicine;
			for(int i = 0; i < quantity; i++)
			{
				medicine = generate();
				insert(root, medicine);
			}
			break;

		case 6:
			print_tree(*root);
			break;

		case 0:
			cout << "Finalizando" << endl;
			break;

		default:
			cout << "Valor inválido" << endl;
			break;
	}
}
