#include <iostream>
#include <time.h>

using namespace std;

void fill(int *v, int tam);
void sort(int *v, int tam);
void print(int *v, int tam);

int main()
{
	int tam;
	srand(time(NULL));

	//Rotina de entrada de dados
	cout << "Digite o tamanho do vetor: " << endl;
	cin >> tam;
	cout << endl;
	
	//Rotina de processamento e saída de dados
	int *v = new int[tam];
	fill(v, tam);
	
	cout << "Este é o vetor desordenado: " << endl;
	print(v, tam);
	cout << endl;

	sort(v, tam);

	cout << "Este é o vetor ordenado: " << endl;
	print(v, tam);
	cout << endl;

	return 0;
}

void fill(int *v, int tam)
{
	for(int i = 0; i < tam; i++)
	{
		v[i] = rand()%tam;
	}	
}

void sort(int *v, int tam)
{
	int aux;
	for(int i = 1; i < tam; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] <= v[j])
			{
				aux = v[i];		
				for(int k = i; k > j; k--)
				{
					v[k] = v[k-1];
				}
				v[j] = aux;
				break;
			}
		}
	}
}

void print(int *v, int tam)
{
	cout << "[";
	for(int i = 0; i < tam; i++)
	{
		cout << v[i] ;
		if(i < tam-1)
		{
			cout << " ";
		}
	}
	cout << "]" << endl;
}
