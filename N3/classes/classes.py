from persistencia import*


class Pessoas:
    def __init__(self)->None:
        self.__pessoa= {}

    def add():
        pass

    def find():
        pass

class Usuario_comum(Pessoas):
    pass


class Livros:
    def __init__(self)->None:
        self.__livros= {}

    def add():
        pass

    def find():
        pass


class geral():
    
    def cadastro_usu():
        pass

    def catalogo_livros():
        pass

    def emprestimo_livro():
        pass

    def reserva_livro():
        pass

    def devolucao_livro():
        pass

    def renovacao_emprestimos():
        pass

    def pesquisa_livro():
        pass

    def controle_multas():
        pass

class Bibliotecario(geral, BaseDAO):
    
    def add():
        pass

    def remocao():
        pass

    def update():
        pass

    def edite():
        pass

class Menu:


    def register(self)->None:
        pass
    
    def login(self)->None:
        # nivel de acesso 1 = usuario comum
        # nivel de acesso 2 = bibliotecario
        pass

