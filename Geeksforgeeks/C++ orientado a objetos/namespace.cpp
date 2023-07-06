#include <iostream>
using namespace std;

namespace ns1
{
    void display();
    class geek
    {
        public:
            void display();
    };
}

void ns1::display()
{
    cout << "É isso aí";
}

void ns1::geek::display()
{
    cout << "Eu acho né";
}

int main()
{
    ns1::geek obj;
    ns1::display();
    cout << ", ";
    obj.display();
    return 0;
}