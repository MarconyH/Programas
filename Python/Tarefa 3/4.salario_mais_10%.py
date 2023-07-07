##Faça um programa que leia o valor da hora de trabalho (em reais) e número de horas
##trabalhadas no mês. Imprima o valor a ser pago ao funcionário, adicionando 10% sobre
##o valor calculado.

hdetrabalho= float(input("Quanto você recebe por hora: " ))
htrabalhadas= float(input("Quantas horas você trabalhou: "))
salariosem10= hdetrabalho*htrabalhadas
salario= salariosem10+salariosem10*10/100

print ("Você receberá:",salario)

##Feito.