#include "list.h"


int main()
{
    list *head = NULL;
    int opt;
    srand(time(NULL));
    
    do
    {
        menu();
        scanf("%d", &opt);
        escolha(opt, &head);
    } while (opt != 0);
    
    return 0;
}