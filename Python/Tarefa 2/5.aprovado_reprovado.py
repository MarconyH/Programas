##Faça um programa para a leitura de duas notas parciais de um aluno. O programa deve calcular a média alcançada por aluno e apresentar:
##°A mensagem "Aprovado", se a média alcançada for maior ou igual a sete;
##°A mensagem "Reprovado", se a média for menor que sete;
##°A mensagem "Aprovado com Distinção", se a média for igual a dez.

not1= float(input("1ª Nota:"))
not2= float(input("2ª Nota:"))

media= (not1 + not2)/2
print ("Média:",media)

if media==10:
    print ("Aprovado com Distinção.")
elif media<10 and media>=7:
    print ("Aprovado.")
else:
    print ("Reprovado")

##Feito.