#include "login_registration.h"


int main ()
{
    int opt;

    do
    {
        menu();
        cin >> opt;

        if (cin.fail())
        {
            opt = -1;
            cin.clear();
        }
        cin.ignore;

        choice(opt);
    } while (opt != 0);
    


    return 0;
}