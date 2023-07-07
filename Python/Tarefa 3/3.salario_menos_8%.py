##Uma empresa contrata um encanador a R$ 30,00 por dia. Faça um programa que solicite
##o número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser
##paga, sabendo-se que são descontandos 8% para imposto de renda.

diastrabalhados= int(input("Informe quantos dias você trabalhou: "))
quantiasemimposto= diastrabalhados*30
salario= quantiasemimposto-quantiasemimposto*8/100

print("Você recebeu:",salario)

##Feito.