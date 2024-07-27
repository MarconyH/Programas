import json
import matplotlib.pyplot as plt
import os
import subprocess

# Caminho para o arquivo JSON
arquivo_json = '/home/marcony/Documents/Programas/Programacao_Funcional/N2/dados.json'

caminho_script_shell = '/home/marcony/Documents/Programas/Programacao_Funcional/N2/execute.sh'

# Função para ler dados do arquivo JSON
def ler_dados_json(arquivo):
    if not os.path.exists(arquivo):
        raise FileNotFoundError(f"O arquivo {arquivo} não foi encontrado.")
    with open(arquivo, 'r') as f:
        dados = json.load(f)
    return dados

subprocess.run([caminho_script_shell])

# Carregar dados do arquivo JSON
dados_json = ler_dados_json(arquivo_json)

# Função para converter string de tempo em segundos
def converter_tempo(tempo_str):
    return float(tempo_str.replace('s', ''))

# Extrair valores de x (quantidade de elementos) e y (tempos de merge sort e selection sort)
x = [dado["quantidade_elementos"] for dado in dados_json]
y_merge_sort = [converter_tempo(dado["tempo_merge_sort"]) for dado in dados_json]
y_selection_sort = [converter_tempo(dado["tempo_selection_sort"]) for dado in dados_json]

# Criar gráfico de linha
plt.plot(x, y_merge_sort, label='Merge Sort')
plt.plot(x, y_selection_sort, label='Selection Sort')

# Adicionar título e rótulos aos eixos
plt.title('Comparação de Tempos de Execução')
plt.xlabel('Quantidade de Elementos')
plt.ylabel('Tempo de Execução (s)')
plt.legend()

# Exibir o gráfico
plt.show()