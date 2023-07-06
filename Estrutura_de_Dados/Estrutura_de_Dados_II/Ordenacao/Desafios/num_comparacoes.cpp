#include <iostream>
#include <time.h>
using namespace std;

#define TAM1 15
#define TAM2 127
#define TAM3 32767

typedef struct
{
	int array_1[TAM1];
	int array_2[TAM2];
	int array_3[TAM3];
}ARRAY;

ARRAY *preencher(ARRAY *array)
{
	
	for(int i = 0; i < TAM1; i++)
	{
		
		array->array_1[i] = i;
		
	}

	for(int j = 0; j < TAM2; j++)
	{
		array->array_2[j] = j;
	
	}

	for(int k = 0; k < TAM3; k++)
	{
		array->array_3[k] = k;
		
	}

	return array;
}

void bagunca(ARRAY *array, int tam)
{
	int num1, num2, aux;
	switch(tam)
	{
		case TAM1:
			for(int i = 0; i < TAM1*2; i++)
			{
				num1 = rand() % TAM1;
				num2 = rand() % TAM1;
		
				aux = array->array_1[num1];
				array->array_1[num1] = array->array_1[num2];
				array->array_1[num2] = aux;
			}
			break;

		case TAM2:
			for(int i = 0; i < TAM2*2; i++)
			{
				num1 = rand() % TAM2;
				num2 = rand() % TAM2;

				aux = array->array_2[num1];
				array->array_2[num1] = array->array_2[num2];
				array->array_2[num2] = aux;
			}
			break;
	
		case TAM3:
			for(int i = 0; i < TAM3*2; i++)
			{
				num1 = rand() % TAM3;
				num2 = rand() % TAM3;

				aux = array->array_3[num1];
				array->array_3[num1] = array->array_3[num2];
				array->array_3[num2] = aux;
			}
			break;
	}
}



int main()
{
	int quantas_vezes;
	float comp_1 = 0;
	float comp_2 = 0;
	float comp_3 = 0;
	int cade1, cade2, cade3, repete = 0;
	srand(time(NULL));    
	ARRAY *array = new ARRAY[1];
	array = preencher(array);
	
	cout << "Digite a quantidade de vezes que o teste será feito: " << endl;
	cin >> quantas_vezes;

	while(repete < quantas_vezes)
	{
		bagunca(array, TAM1);
		cade1 = rand() % TAM1;
		
		for(int i = 0; i < TAM1; i++)
		{
			comp_1++;
			if(cade1 == array->array_1[i])
			{
				i = TAM1;
				break;
			}
		}
		repete++;
	}
	cout << "A média de comparações do primeiro array foi: " << comp_1/quantas_vezes << endl;
	repete = 0;

	while(repete <  quantas_vezes)
	{
		bagunca(array, TAM2);
		cade2 = rand() % TAM2;
		for(int i = 0; i < TAM2; i++)
		{
			comp_2++;
			if(cade2 == array->array_2[i])
			{
				i = TAM2;
				break;
			}

		}
		repete++;
	}
	cout << "A média de comparações do segundo array foi: " << comp_2/quantas_vezes << endl;
	repete = 0;

	while(repete < quantas_vezes)
	{
		bagunca(array, TAM3);
		cade3 = rand() % TAM3;
		for(int i = 0; i < TAM3; i++)
		{
			comp_3++;
			if(cade3 == array->array_3[i])
			{
				i = TAM3;
				break;
			}

		}
		repete++;
	}
	
	cout << "A média de comparações do terceiro array foi: " << comp_3/quantas_vezes << endl;
	return 0;
}
