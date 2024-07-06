#include <iostream>
#include <time.h>
using namespace std;

void fill(int *v, int tam);
void sort_aluno(int *v, int tam);
void sort(int *v, int tam);
void print(int *v, int tam);


int main()
{
	int tam, tempo;
	float diferenca;
	srand(time(NULL));
	cout << "Digite o tamanho do vetor" << endl;
	cin >> tam;
	int *v = new int[tam];
	fill(v, tam);
	cout << "Este é o vetor desordenado" << endl;
	print(v, tam);
	tempo = clock();
	sort_aluno(v, tam);
	cout << "Este é o vetor ordenado" << endl;
	print(v, tam);
	diferenca = float((clock() - tempo)/CLOCKS_PER_SEC);
	cout << diferenca;
	return 0;
}

void fill(int *v, int tam)
{
	for(int i = 0; i < tam; i++)
	{
		v[i] = rand() % 10;
	}
}

void sort_aluno(int *v, int tam)
{
	int aux;
	for(int i = 1; i < tam; i++)
	{
		for(int j = 0; j < tam; j++)
		{
			if(v[j] > v[j+1])
			{	
				aux =v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}
void sort(int *v, int tam)
{
	int aux;
	int troca = 0;
	for(int i = 1; i < tam; i++)
	{
		for(int j = 0; j < tam - i; j++)
		{
			if(v[j] > v[j+1])
			{	
				troca++;
				aux =v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}	
		if(troca == 0)
		{
			break;
		}
		troca = 0;
	}
}

void print(int *v, int tam)
{
	for(int i = 0; i < tam; i++)
	{
		cout << v[i] << " ";
	}
	cout << "Fim" << endl;
}
