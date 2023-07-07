import sys
from PyQt5 import QtWidgets, QtGui

class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()

        # Cria o dicionário para armazenar os produtos adicionados pelo usuário
        self.produtos = {}

        # Cria o dicionário para armazenar os dados dos produtos alugados
        self.produtos_alugados = {}

        # Cria o menu e os itens de menu
        self.menu = self.menuBar()
        self.file_menu = self.menu.addMenu("Arquivo")
        self.search_product_action = QtWidgets.QAction("Pesquisar produto", self)
        self.add_product_action = QtWidgets.QAction("Adicionar produto", self)
        self.rented_products_action = QtWidgets.QAction("Produtos alugados", self)
        self.exit_action = QtWidgets.QAction("Sair", self)
        self.file_menu.addAction(self.search_product_action)
        self.file_menu.addAction(self.add_product_action)
        self.file_menu.addAction(self.rented_products_action)
        self.file_menu.addSeparator()
        self.file_menu.addAction(self.exit_action)

        # Cria um widget central e o adiciona à janela principal
        self.central_widget = QtWidgets.QWidget()
        self.setCentralWidget(self.central_widget)
        self.central_layout = QtWidgets.QVBoxLayout()
        self.central_widget.setLayout(self.central_layout)

        # Conecta os sinais de ação de menu aos métodos de tratamento de eventos
        self.search_product_action.triggered.connect(self.show_search_product_window)
        self.add_product_action.triggered.connect(self.show_add_product_window)
        self.rented_products_action.triggered.connect(self.show_rented_products_window)
        self.exit_action.triggered.connect(self.exit_program)
        self.show()

    def exit_program(self):
        sys.exit()


    def show_add_product_window(self):
        # Cria uma nova janela para adicionar produto
        add_product_window = QtWidgets.QWidget()
        add_product_window.setWindowTitle("Adicionar produto")

        # Cria um layout vertical para a janela
        add_product_layout = QtWidgets.QVBoxLayout()
        add_product_window.setLayout(add_product_layout)

        # Adiciona um rótulo e um campo de texto para o nome do produto
        self.product_name_label = QtWidgets.QLabel("Nome do produto:")
        self.product_name_field = QtWidgets.QLineEdit()
        add_product_layout.addWidget(self.product_name_label)
        add_product_layout.addWidget(self.product_name_field)

        # Adiciona um botão para adicionar o produto
        self.add_product_confirm_button = QtWidgets.QPushButton("Adicionar")
        add_product_layout.addWidget(self.add_product_confirm_button)

        # Conecta o sinal de clique do botão de adição ao método de tratamento de eventos
        self.add_product_confirm_button.clicked.connect(self.add_product)

        # Adiciona um botão para voltar para o menu principal
        self.back_button = QtWidgets.QPushButton("Voltar")
        self.back_button.clicked.connect(add_product_window.close)
        add_product_layout.addWidget(self.back_button)

        # Mostra a janela
        add_product_window.exec_()



    def add_product(self):
        # Obtém o nome do produto inserido pelo usuário
        product_name = self.product_name_field.text()

        # Adiciona o produto à lista de produtos
        self.products.append(product_name)

        # Exibe uma mensagem de confirmação
        QtWidgets.QMessageBox.information(self, "Adicionar produto", f"Produto {product_name} adicionado com sucesso")

    def show_search_product_window(self):
        # Cria uma nova janela para pesquisar produto
        search_product_window = QtWidgets.QWidget()
        search_product_window.setWindowTitle("Pesquisar produto")

        # Cria um layout vertical para a janela
        search_product_layout = QtWidgets.QVBoxLayout()
        search_product_window.setLayout(search_product_layout)

        # Adiciona um rótulo e um campo de texto para o nome do produto
        self.product_name_label = QtWidgets.QLabel("Nome do produto:")
        self.product_name_field = QtWidgets.QLineEdit()
        search_product_layout.addWidget(self.product_name_label)
        search_product_layout.addWidget(self.product_name_field)

        # Adiciona um botão para pesquisar o produto
        self.search_product_confirm_button = QtWidgets.QPushButton("Pesquisar")
        search_product_layout.addWidget(self.search_product_confirm_button)

        # Conecta o sinal de clique do botão de pesquisa ao método de tratamento de eventos
        self.search_product_confirm_button.clicked.connect(self.search_product)

        # Adiciona um botão para voltar para o menu principal
        self.back_button = QtWidgets.QPushButton("Voltar")
        self.back_button.clicked.connect(search_product_window.close)
        search_product_layout.addWidget(self.back_button)

        # Mostra a janela
        search_product_window.show()

    def search_product(self):
        # Obtém o nome do produto do campo de texto
        product_name = self.product_name_field.text()

        # Verifica se o produto está na lista de produtos
        if product_name in self.products:
            QtWidgets.QMessageBox.information(self, "Pesquisar produto", f"Produto {product_name} encontrado na lista de produtos")
        else:
            QtWidgets.QMessageBox.warning(self, "Pesquisar produto", f"Produto {product_name} não encontrado na lista de produtos")

app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
window.show()
sys.exit(app.exec_())


