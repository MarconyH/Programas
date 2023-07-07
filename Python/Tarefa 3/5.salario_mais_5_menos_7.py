##Receba o salário-base de um funcionário. Calcule e imprima o salário a receber, sabendo-
##se que esse funcionário tem uma gratificação de 5% sobre o salário-base. Além disso,
##ele paga 7% de imposto sobre o salário-base.

salariobase= float(input("Informe seu sálario: "))
gratificacao= salariobase+salariobase*5/100
imposto= gratificacao-gratificacao*7/100

print("Seu salário:",imposto)

##Feito.