#include <stdio.h>

int main(void) {
  float salario1;
  /*Números com vírgulas são representados com '.'
  1404,00 seria 1404.00. O salário deve ser definido pelo usuário,
  então não é necessário igualar o salario1 a nada*/
  salario1 = 1.404,00;
    printf("Antes do aumento o valor do salario era %f", salario1);
  scanf("%f",& salario1);
 float salario2;

  /*25% do salário seria salario1*0.25. Para que tenha um aumento de 25%
  salario2 deve ser igual a salari1+salario1*0.25*/
  salario2 = (salario1*0,25)/100;
  printf("O salario após o aumento é %f",salario2);
  return 0;
}