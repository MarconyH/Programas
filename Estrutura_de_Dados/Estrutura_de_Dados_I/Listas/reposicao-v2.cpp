// Só pra garantir que não copiei de ninguém

#include "list_v2.h"


int main()
{
    list *head = NULL;
    int opt;
    srand(time(NULL));
    
    do
    {
        menu();
        cin >> opt;
        
        if (cin.fail())
        {
            opt = -1;
            cin.clear();
        }
        cin.ignore();

        escolha(opt, &head);
    } while (opt != 0);
    
    return 0;
}
