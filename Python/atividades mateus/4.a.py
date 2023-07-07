#Faça um programa que leia o horário(hora, minuto e segundo) de inicio e a duração, em
#segundos, de uma experiência biológica. O programa deve resultar com o novo horário
#(Hora, minuto e segundo) do término da mesma.

class Tempo: 
  h= int(input("Horas que começou: "))
  m= int(input("Miutos que começou: "))
  s= int(input("Segundos que começou: "))
hms = Tempo()

s= hms.h*3600
s= s + hms.m*60
s= hms.s + s
s= int(input("Tempo que a experiência durou(Segundos): ")) + s

h= s//3600
s= s%3600
m= s//60
s= s%60

print("Horas:",h,"Minutos:",m,"Segundos:",s)

#Feito.