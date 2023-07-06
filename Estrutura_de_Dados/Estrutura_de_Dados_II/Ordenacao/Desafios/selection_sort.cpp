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
	int *v = new int[tam];

	//Rotina de processamento e saída de dados
	fill(v, tam);
	cout << "Este é o vetor desordenado: " << endl;
	print(v, tam);
	
	sort(v, tam);

	cout << "Este é o vetor ordenado: " << endl;
	print(v, tam);
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
	int maior = 0;
	int aux;
	for(int i = 1; i < tam; i++)
	{
		for(int j = tam - i; j >= 0; j--)
		{
			if(v[maior] < v[j])
			{
				maior = j;
			}
		}
		if(maior != tam-i)
		{
			aux = v[maior];
			v[maior] = v[tam-i];
			v[tam-i] = aux;
		}
		maior = 0;
	}
}

void print(int *v, int tam)
{	
	cout << "[ ";
	for(int i = 0; i < tam; i++)
	{
		cout << v[i] << " ";
	}
	cout << "]";
	cout << endl;
}
