//c10ex02.cpp
#include <iostream>

using namespace std;

class TALUNO
{
	public:
	string NOME;
	float NOTA[4];
	float MEDIA;
	float CMEDIA()
	{
		MEDIA = 0;
		for(int i = 0; i < 4; i++)
		{
			MEDIA += NOTA[i];
		}
		MEDIA /= 4;
	}
}ALUNO;

int main()
{
	cout << "Cadastro dos alunos" << endl << endl << endl;

	cout << "Informe o nome: ";
	cin >> ALUNO.NOME;
	cout << endl;

	cout << "Informe as notas: " << endl << endl;
	for(int i = 1; i <= 4; i++)
	{
		cout << "Nota " << i << ": ";
		cin >> ALUNO.NOTA[i-1];
		cout << endl;
	}	
	
	ALUNO.CMEDIA();
	
	cout << "Relatório" << endl << endl;
	cout << "Nome: " << ALUNO.NOME << endl << endl;
	cout << "Notas: " << endl;

	for(int i = 0; i < 4; i++)
	{
		cout << "Nota " << i+1 << ": " << ALUNO.NOTA[i] << endl;
	}

	cout << "Média: " << ALUNO.MEDIA << endl;
	
	return 0;
}
