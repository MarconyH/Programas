import webbrowser
import pyautogui
import time

# URL da página web
url = "https://ava2.ifma.edu.br"

# Abre a página no navegador
webbrowser.open(url)

# Aguarda alguns segundos para a página carregar (ajuste conforme necessário)
time.sleep(3)

# Posiciona o cursor no campo de texto usando pyautogui
pyautogui.click(x=1000, y=100)

# Digita o nome de usuário usando pyautogui
pyautogui.write('20232T.I.CAX0050')

pyautogui.click(x=1200, y=100)
pyautogui.write('informatica')

pyautogui.click(x=1300, y=100)
