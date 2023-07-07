#include <iostream>
using namespace std;

int main()
{
    cout << "Os 5 primeiros múltiplos de 3: " << endl;
    for (int i = 3; i <= 5*3; i+=3)
    {
        cout << i << " ";
    }
    
    return 0;
}