#include <stdio.h>

int diaria , final , desconto, dias , salario;

int main(void) {
  dias = 0;
  printf("Entre com os dias trabalhados.\n", dias);
  scanf("%i",& dias);
  diaria = 30;
  salario = diaria * dias;
  printf("O calculo do salario antes do desconto é %i.\n",salario);
  desconto = (salario * 0.08)/100;
  final = salario - desconto;
  printf("O salario final com desconto é %i",final);
  
  return 0;
}