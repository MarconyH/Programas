#include <iostream>

using namespace std;

int main()
{
	float primeiro_nume, soma, subt, multip, divi;
	int segundo_nume;
	cout << "Digite o primeiro número";
	cin >> primeiro_nume;
	cout << "Digite o segundo número que seja diferente de zero";
	cin >> segundo_nume;
	soma = primeiro_nume + segundo_nume;
	subt = primeiro_nume - segundo_nume;
	multip = primeiro_nume * segundo_nume;
	cout << "\n A soma é:" << soma;
	//trocado a frase "a subtração do primeiro número pelo primeiro número" por "a subtração do primeiro número pelo segundo número" 
	cout << "\n A subtração do primeiro número pelo segundo é: " << subt;
	cout << "\n Multiplicação: " << multip;
	if(segundo_nume == 0)
	{
		//um "\n" foi inserido já que a frase abaixo ficava junta com o resultado da multiplicação
		cout << "\nDigite o segundo número, que seja diferente de zero";
		cin >> segundo_nume;
		/*Tratando quando o cara digitar um número menor que zero*/
		while(segundo_nume == 0)
		{
			cout << "Digite um numero inteiro positivo ";
			cin >> segundo_nume;
		}
		divi = primeiro_nume/segundo_nume;
		cout << "\n A divisão do primeiro pelo segundo é: " << divi;
	}
	else
	{
		divi = primeiro_nume/segundo_nume;
		cout << "\n A divisão do primeiro pelo segundo é: " << divi;
	}
	return 0;
}
