## coletar dados


class Comum:
    def _catalogo_livro():
        pass
    
    def _pesquisa_livros():
        pass

    def _controle_multas():
        #lista de multas, não complique
        pass
    def _emprestimo_livro():
        pass

    def _reserva_livro():
        pass

    def _devolucao_livros():
        pass

    def _renovacao_emprestimo():
        pass

    def pag_usuario(self, scree):
        print(scree)
        op = input()
        if '1' in op:
            self._catalogo_livro()
        if '2' in op:
            self._pesquisa_livros()
        if '3' in op:
            self._controle_multas()
        if '4' in op:
            self._emprestimo_livro()
        if '5' in op:
            self._reserva_livro()
        if '6' in op:
            self._devolucao_livros()
        if '7' in op:
            self._renovacao_emprestimo()
        



class Usuario(Comum):
    pass


class Bibliotecario(Comum, Base_DAO):


    def _add():
        pass
    def _atualizao():
        pass
    def _editar():
        pass
    def _remocao():
        pass
    def pag_bibliotecario(self):
        scree = """
            Add livro
            Remover livro 
            Atualizar Livro
            Editar Informações do Livro
        """
        print(scree)
### apartir daqui não sei como associar bibliotecario/usuario 


class Page_1:


    def Login():
        pass

    def Cadastro():
        pass

