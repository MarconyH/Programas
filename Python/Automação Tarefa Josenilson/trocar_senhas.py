import csv
import webbrowser
import webbrowser
import pyautogui
import time
import pyperclip

def adicionar_a_lista(matricula, nome, lista):
    # Nome do arquivo CSV correspondente à lista
    arquivo_csv = f"{lista}.csv"

    # Adicionar aluno ao arquivo CSV
    with open(arquivo_csv, mode='a', newline='', encoding='utf-8') as arquivo:
        escritor_csv = csv.writer(arquivo)
        escritor_csv.writerow([matricula, nome])

def abrir_link_no_navegador(matricula):
    # Construir o link com a matrícula fornecida
    link = f'https://suap.ifma.edu.br/edu/aluno/{matricula}/?tab=dados_pessoais'

    # Abrir o link no navegador
    webbrowser.open(link)
    
def main():
    # Nome do arquivo CSV
    nome_lista = "ListaAlunosCoroata"
    arquivo_csv = f"{nome_lista}.csv"

    # Lê os dados do arquivo CSV
    with open(arquivo_csv, mode='r', newline='') as arquivo:
        leitor_csv = csv.reader(arquivo)
        next(leitor_csv)  # Pula o cabeçalho

        # Loop através das linhas do arquivo CSV
        for linha in leitor_csv:
            matricula, codigo, nome = linha
            nome = nome.strip('"')

            # Construir o link e abrir no navegador
            abrir_link_no_navegador(codigo)
            
            mudou_senha = input("Já mudou a senha?")
            url = "https://ava2.ifma.edu.br"

            # Abre a página no navegador
            webbrowser.open(url)

            # Aguarda alguns segundos para a página carregar (ajuste conforme necessário)
            time.sleep(3)

            # Posiciona o cursor no campo de texto usando pyautogui
            pyautogui.click(x=1000, y=100)

            # Digita o nome de usuário usando pyautogui
            pyautogui.write(f'{codigo}')

            pyautogui.click(x=1200, y=100)
            pyautogui.write('informatica')

            pyautogui.click(x=1300, y=100)
            
            # Perguntar ao usuário em qual lista adicionar o aluno
            lista = input("Em qual lista você deseja adicionar o aluno? (1(email acad), 2(direto), 3(deu errado), ou nenhuma): ")

            # Adicionar aluno à lista correspondente
            if lista == '1':
                adicionar_a_lista(codigo, nome, f'email_acad{nome_lista}')
            elif lista == '2':
                adicionar_a_lista(codigo, nome, f'foi_direto_{nome_lista}')
            elif lista == '3':
                adicionar_a_lista(codigo, nome, f'deu_errado_{nome_lista}')
            else:
                print("Nenhuma ação realizada para esta lista.")
            pyperclip.copy("informatica")
            # Exibir a resposta do usuário
            print(f'O aluno com matrícula {codigo} e nome {nome} foi adicionado à Lista {lista}.')

if __name__ == "__main__":
    main()
