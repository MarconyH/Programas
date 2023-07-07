#include <iostream>
using namespace std;

int main()
{
    int n, pos = 0;
    cout << "Digite um número inteiro positivo: " << endl;
    cin >> n;
    while(pos <= n)
    {
        cout << pos << " ";
        pos+=2;
    }
    return 0;
}