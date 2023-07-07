'''import datetime 
import csv
name_file = 'escala.csv'
data = datetime.date.today()



sem = ('segunda', 'terça', 'Quarta', 'quinta', 'sexta', 'Sábado', 'Domingo')

data.day += 5

print(data)

while data.month == mes:
    num = data.weekday()
    try:
        with open(name_file, 'w', new_line = '') as csvfile:
            if num == 2 or num >= 5:
                

    except Exception as erro:
        print(f'Erro: {erro}')  
    
    finally:
        data.day += 1

name_file = 'escala.csv'
try:
    
        

except Exception as erro:
    print(f'Erro: {erro}')
'''

from collections import defaultdict

def distribuir_pessoas(pessoas):
    dias_semana = ['domingo', 'quarta', 'sabado']
    pessoas_por_dia = {'domingo': 4, 'quarta': 4, 'sabado': 6}
    distribuicao = defaultdict(list)

    for dia in dias_semana:
        pessoas_disponiveis = list(pessoas)
        for _ in range(pessoas_por_dia[dia]):
            if pessoas_disponiveis:
                pessoa = pessoas_disponiveis.pop(0)
                distribuicao[dia].append(pessoa)
            else:
                break

    return dict(distribuicao)

# Exemplo de uso
pessoas = ['Alice', 'Bob', 'Carol', 'Dave', 'Eve', 'Frank', 'Grace', 'Henry', 'Ivy', 'Jack', 'Karen', 'Larry']
distribuicao = distribuir_pessoas(pessoas)

for dia, pessoas_trabalhando in distribuicao.items():
    print(f'No dia {dia}, as seguintes pessoas trabalharão: {", ".join(pessoas_trabalhando)}')
