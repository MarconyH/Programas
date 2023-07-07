//c10ex03.cpp

#include <iostream>
#include <string>

using namespace std;

class TSALA
{
	public:
		int SALA;
};

class TALUNO: public TSALA
{
	public:
		string NOME;
		float NOTA[4];
		float MEDIA;
		float CMEDIA();
}ALUNO;

float TALUNO::CMEDIA()
{
	MEDIA = 0;
	for(int i = 0; i < 4; i++)
	{
		MEDIA += ALUNO.NOTA[i];
	}
	MEDIA /= 4;
	return MEDIA;
}

int main()
{

	cout << "Cadastro de aluno " << endl << endl << endl;

	cout << "Informe o nome: " << endl;
	cin >> ALUNO.NOME;
	cout << endl;
	
	cout << "Informe a sala: " << endl;
	cin >> ALUNO.SALA;
	cout << endl;

	cout << "Informe as notas: " << endl << endl;
	for (int i = 0; i < 4; i++)
	{	
		cin >> ALUNO.NOTA[i];
	}
	ALUNO.CMEDIA();

	cout << endl;
	cout << "Relatório" << endl;
	cout << endl;

	cout << "Nome: " << ALUNO.NOME << endl;
       	cout << endl;
	
	cout << "Sala: " << ALUNO.SALA << endl;
	cout << endl;

	cout << "Média: " << ALUNO.MEDIA << endl;
	cout << endl;
	return 0;
}

