#include "listsimp.h"


void impr_simp(simp *head)
{
    printf("Lista\n");
    while(head != NULL)
    {
        printf("%d -> ", head->c);
        head=head->p;
    }
    
}

int main()
{
    simp *head = NULL;

    menu_simp();
    return 0;
}