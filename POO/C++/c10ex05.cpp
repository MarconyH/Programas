//c10ex05.cpp

#include <iostream>
#include <iomanip>

using namespace std;

class TALUNO
{
	public:
		string NOME;
		float CMEDIA();
		float PEGANOTA(int POS);
		void POENOTA(float NT, int POS);
		float PEGAMEDIA();
	private:
		float NOTA[4];
		float MEDIA;
}ALUNO;

float TALUNO::CMEDIA()
{
	MEDIA = 0;
	for(int i = 0; i < 4; i++)
	{
		MEDIA += NOTA[i];
	}
	MEDIA /= 4;
	return MEDIA;
}

float TALUNO::PEGANOTA(int POS)
{
	return NOTA[POS];
}

void TALUNO::POENOTA(float NT, int POS)
{
	NOTA[POS] = NT;
	return;
}

float TALUNO::PEGAMEDIA()
{
	return MEDIA;
}

int main()
{
	cout << setprecision(2);
	cout << setiosflags(ios::fixed);
	
	float NT = 0;
	//Rotina para entrada de dados
	
	cout << "Cadastro de aluno" << endl << endl << endl;

	cout << "Informe o nome: ";
	cin >> ALUNO.NOME;
	cout << endl;

	cout << "Informe as notas: " << endl << endl;
	for(int i = 0; i < 4; i++)
	{
		cout << "Digite a nota " << i+1 << ": ";
		cin >> NT;
		ALUNO.POENOTA(NT, i);
	}

	cout << endl;
	ALUNO.CMEDIA();

	//Apresentação dos dados
	
	cout << endl;
	cout << "Relatório" << endl;
	cout << endl;
	cout << "Nome: " << ALUNO.NOME << endl << endl;

	for(int i = 0; i < 4; i++)
	{
		cout << "Nota " << i+1 << ": " << ALUNO.PEGANOTA(i) << endl;
	}
	cout << endl;
	cout << "Média: " << ALUNO.PEGAMEDIA() << endl;
	cout << endl;
	return 0;
}
