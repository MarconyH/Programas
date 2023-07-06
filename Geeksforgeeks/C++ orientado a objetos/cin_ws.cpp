// C++ Code to explain how "cin >> ws"
// discards the input buffer along with
// initial white spaces of string
 
#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    int a;
    string s;
     
    // Enter input from user -
    // 4 for example
    cin >> a;
     
    // Discards the input buffer and
    // initial white spaces of string
    cin >> ws;
     
    // Get input from user -
    // GeeksforGeeks for example
    getline(cin, s);
     
    // Prints 4 and GeeksforGeeks :
    // will execute print a and s
    cout << a << endl;
    cout << s << endl;
 
    return 0;
}