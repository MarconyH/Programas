#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Digite um número inteiro: " << endl;
    cin >> num;
    if (num%2 == 0)
    {
        cout << "O número é par" << endl;
    }
    else
    {
        cout << "O número é ímpar" << endl;
    }
    
    
    return 0;
}