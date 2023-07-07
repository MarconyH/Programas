#include <iostream>
using namespace std;

int main()
{
    int n, imp = 1;
    cout << "Digite quantos números ímpares você quer: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << imp << " ";
        imp+=2;
    }
    
    return 0;
}