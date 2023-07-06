#include "listdup.h"

int main()
{
    int opt;
    group sistema;
    sistema.inicializar();
    do
    {
        sistema.menu();
        cin >> opt;
        escolha(opt, sistema);
    } while (opt != 0);
    
        
}