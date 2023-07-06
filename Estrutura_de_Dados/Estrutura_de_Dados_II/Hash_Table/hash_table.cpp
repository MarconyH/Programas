#include <iostream>
#include <time.h>
using namespace std;

//tabela hash
#define M 50

class Participant
{
	string name_;
	string job;
	float monthly_income;

	public:
		Participant() : monthly_income(0){}

		void cadastre(string name, string job, float monthly_income)
		{
			this->name_ = name;
			this->job = job;
			this->monthly_income = monthly_income;
		}

		void print()
		{
			cout << "Nome: " << this->name_ << endl;
			cout << "Cargo: " << this->job << endl;
			cout << "Renda Mensal: " << this->monthly_income << endl;
		}

		string name()
		{
			return this->name_;
		}
};

class HashTable
{
	int size;
	Participant *participants[M];
	int existents[M];
	int quantity;

	public:
		HashTable()
		{
			this->size = M;

			for(int i = 0; i < this->size; i++)
			{
				this->participants[i] = NULL;
				this->existents[i] = -1;
			}

			this->quantity = 0;
		}

		int hash(string name, int k = 0);

		void insert(Participant *participant);	
	
		int *prime(int number = 0, int position = -1, int quantity = 0, int *vector = NULL);

		void print();

		void search(string name);

		void raffle();
		
};


class Menu
{
	HashTable table;

	public:
		void menu()
		{
			cout << "************  MENU  ************" << endl;
			cout << "|\t 1 - Imprimir\t\t|" << endl;
			cout << "|\t 2 - Registrar\t\t|" << endl;
			cout << "|\t 3 - Busca\t\t|" << endl;
			cout << "|\t 4 - Sorteio\t\t|" << endl;
			cout << "|\t 0 - Sair\t\t|" << endl;
		}
	

		void option(int option)
		{

			switch(option)
			{
				case 1:
					this->table.print();
					break;
				
				case 2:
					try
					{
						Participant *participant;
						participant = new Participant;
						string name;
						string job;
						float income;
	

						cout << "Digite o seu nome: " << endl;
						cin >> name;
					
						cout << "Digite seu cargo: " << endl;
						cin >> job;
						
						cout << "Digite sua renda mensal: " << endl;
						cin >> income;
					
						participant->cadastre(name, job, income);
						this->table.insert(participant);
					}
					catch(...)
					{
						cout << "Erro registro" << endl;
					}
					break;
				case 3:
					try
					{
						string name__;
						cout << "Digite o nome que você está buscando: " << endl;
						cin >> name__;
						this->table.search(name__);
					}
					catch(...)
					{
						cout << "Erro busca" << endl;
					}
					break;
				//sorteio
				case 4:
					try
					{
						this->table.raffle();
					}
					catch(...)
					{
						cout << "Erro no sorteio" << endl;
					}
					break;

				case 0:
					cout << "Encerrando..." << endl;
					break;

				default:
					cout << "Opção Inválida" << endl;
					break;
			}		
		}
};

int main()
{
	Menu menu;
	int op = -1;
	while(op != 0)
	{
		menu.menu();
		cin >> op;
		menu.option(op);
	}

	return 0;
}


int HashTable::hash(string name, int k)
{
	int *vector = new int[2]; 
	vector = this->prime(size, -1, 2);
			
	int key = int(name[0]);
			
	for(int i = 1; name[i] != '\0'; i++)
	{
		key += key + int(name[i]);
	}

	return (key%vector[0] + k * key%vector[1])%50;
}

void HashTable::insert(Participant *participant)
{
	for(int i = 0; i < M; i++)
	{
		int index = this->hash(participant->name(), i);
				
		if(this->participants[index] == NULL)
		{
			this->participants[index] = participant;
			this->quantity++;
			this->existents[this->quantity-1] = index;
			if(index != this->size-1)
			{
				this->participants[this->size-1] = NULL;
			}
			cout << "Participante inserido com sucesso" << endl;
			return;
		}
		if(participant->name() == this->participants[index]->name())
		{
			cout << "Participante já está cadastrado" << endl;
			return;
		}
	}
	cout << "Participante não pôde ser inserido" << endl;
}

int *HashTable::prime(int number, int position, int quantity,int *vector) 
{
	int result = 0;	

	for(int i = 2; i <= number/2; i++)
	{
		if(number%i == 0)
		{
			result++;
			break;
		}
	}

	if(result == 0)
	{
		position++;
		quantity--;
		int *new_vector = new int[position+1];
		if(vector != NULL)
		{
			for(int i = position-1; i >= 0; i--)
			{
				new_vector[i] = vector[i];
			}
		}
		new_vector[position] = number;
		if(quantity > 0)
		{
			return prime(number-1, position, quantity, new_vector);
		}
		else
		{
			return new_vector;
		}
	}

	else
	{
		if(quantity > 0)
		{
			return prime(number-1, position, quantity, vector);
		}

		else
		{
			return vector;
		}
	}
}

void HashTable::print()
{
	for(int i = 0; i < size; i++)
	{
		if(this->participants[i] == NULL)
		{
			cout << i+1 << "- NULL" << endl;
		}
		else
		{
			string name = this->participants[i]->name();
			cout << i+1 << "- " << name << endl;
		}
	}
}

void HashTable::search(string name)
{
	for(int i = 0; i < M; i++)
	{
		int index = this->hash(name, i);
		if(this->participants[index] != NULL && this->participants[index]->name() == name)
		{
			participants[index]->print();
			return;
		}
	}
	cout << "Participante não encontrado" << endl;
}

void HashTable::raffle()
{
	srand(time(NULL));
	if(this->quantity < 10)
	{
		cout << "Não existem pessoas suficientes para o sorteio" << endl;
		return;
	}	
	else
	{
		cout << "Os participantes que foram sorteados:" << endl;
		int *aux = new int[this->quantity];
		for(int i = 0; i < this->quantity; i++)
		{
			aux[i] = this->existents[i];	
		}

		int choosed = 0;
		int choose;
		while(choosed < 10)
		{
			choose = rand()%quantity;
			if(aux[choose] == -1)
			{
				continue;
			}
			else
			{
				this->participants[aux[choose]]->print();
				cout << endl;
				aux[choose] = -1;
				choosed++;
			}
		}
		
	}
}

