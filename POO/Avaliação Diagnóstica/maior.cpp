#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Digite dois números: " << endl;
    cin >> num1;
    cin >> num2;
    if (num1 > num2)
    {
        cout << num1 << " é maior que " << num2 << endl;
    }
    else if(num2 > num1)
    {
        cout << num2 << " é maior que " << num1 << endl;
    }
    else
    {
        cout << "Os números são iguais" << endl;
    }
    return 0;
}