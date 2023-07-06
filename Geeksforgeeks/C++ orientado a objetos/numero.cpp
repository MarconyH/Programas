#include <stdio.h>

int main ()
{
    long int num;
    printf("Digite um numero:\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        printf("%d ", i);
    }
    


    return 0;
}