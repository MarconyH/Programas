#include <stdio.h>

int main(void) {
 float w1,w2,w3;
  //Para calcular 46% a operação deve ser número*46/100 ou número*0.46
  //Não se usa vírgula para números decimais, apenas '.'
  w1 = (780.000 * 0,46)/100;
  printf("O valor recebido pelo primeiro ganhador foi %f.\n",w1);
  //Não se usa vírgula e o cálculo seria número*32/100 ou número*0.32
  w2 = (780.000 * 0,32)/100;
  printf("O valor recebido pelo segundo ganhador foi %f.\n",w2);
  //w3 seria número-(w1+w2). Ou seja o restante do valor
  w3 = w1 - w2;
  printf("O valor pelo terceiro ganhador foi %f.\n",w3);
  return 0;
}