import mysql.connector
from abc import ABC, abstractclassmethod
#create
#comando para usuario -> comando = f'INSERT INTO {tabela} (nome, matricula, email, telefone, senha) VALUES ("{nome}", {matricula}, {email}, {telefone}, {senha})'

#read
# sql = "SELECT `id` FROM `funcionario` WHERE `cpf` = %s" 
# c.execute(sql, cpf)

#comando = f'SELECT * FROM vendas'

#usuario (nome, matricula, telefone, email, senha)
#bibliotecario (nome, matricula, telefone, email, senha)

#multas (usuario, valor_multa, nome_livro)

class Persistencia:
    @abstractclassmethod
    def add(self):...
    
    @abstractclassmethod
    def search(self):...

class Conexao:
    def __init__(self, table) -> None:
        self._data = table

    def _cnx(self):
        conexao = mysql.connector.connect(
            host='localhost',
            user='root',
            password='',
            database=f'biblioteca'
        )

        return conexao
    
    def _cmd(self, comando):

        try:
            conexao = self._cnx()
            cursor = conexao.cursor()

            cursor.execute(comando)
            conexao.commit() # edita o banco de dados

            cursor.close()
            conexao.close()
        except Exception:
            print("Erro cmd")
    
    @staticmethod
    def convert(resultado, i=-1):
        if i != -1:
            resultado[i] = list(resultado[i])
            return
        resultado = list(resultado)
        
    def _cmd_read(self, comando)->list:

        try:
            conexao = self._cnx()
            cursor = conexao.cursor()

            cursor.execute(comando)
            resultado = cursor.fetchall()

            cursor.close()
            conexao.close()
            print("aquiii", resultado)
            if resultado:
                for num in range(len(resultado)):
                    i = resultado[num]
                    if tuple == type(i):
                        self.convert(resultado, num)

            if type(resultado) == list:
                return resultado
            else:
                return []
        
        except Exception:
            raise Exception
    
class Cnx_usuario(Conexao, Persistencia):
    def __init__(self, table) -> None:
        super().__init__(table)

    def add(self, nome, matricula, email, telefone, senha):
        comando = f'INSERT INTO usuarios (nome, matricula, email, telefone, senha) VALUES ("{nome}", "{matricula}", "{email}", "{telefone}", "{senha}")'
        print(comando)
        self._cmd(comando)
    
    def read(self, matricula, senha):

        # try:

            # sql = "SELECT `id` FROM `funcionario` WHERE `cpf` = %s" 
            # c.execute(sql, cpf)
            comando = f'SELECT * FROM usuarios WHERE (matricula, senha) = ("{matricula}", "{senha}")'
            resultado = self._cmd_read(comando)

            return resultado
        
        # except Exception as error:
        #    print("ERROR in Z", error)
        #    return None

    def update(self, cod, change):
        
        try:
            # UPDATE
            comando = f'UPDATE usuarios SET valor = "{change}" WHERE matricula = "{cod}"'
            self._cmd(comando)

        except Exception:
            print("ERROR in Update")
        else:
            print("Update!")

class Cnx_bibliotecario(Cnx_usuario, Persistencia):

    def delete_ebook(self, cod):

        try:
            # DELETE

            comando = f'DELETE FROM usuarios WHERE matricula = "{cod}"'
            self._cmd(comando)

        except Exception:
            print("ERROR in Del")
        else:
            print('DEL')


class Cnx_livros(Conexao, Persistencia):
    
    def add(self, titulo, autor, editora, edicao, ano_publicacao, isbn, local):
        self._cmd(f'INSERT INTO livros (titulo, autor, editora, edicao, ano_publicao, isbn, localizacao) VALUES ("{titulo}", "{autor}", "{editora}", "{edicao}", "{ano_publicacao}", "{isbn}", "{local}")')
    
    def read(self):#retorna todos os livros em forma de lista
        return self._cmd_read('SELECT * FROM livros')
    
    def search_book(self, isbn): #retorna um livro
        return self._cmd_read(f'SELECT * FROM livros WHERE isbn = "{isbn}"')
    
    def search_book_titulo(self, titulo): #retorna um livro
        return self._cmd_read(f'SELECT * FROM livros WHERE titulo = "{titulo}"')
    
    def search_book_editora(self, editora): #retorna um livro
        return self._cmd_read(f'SELECT * FROM livros WHERE editora = "{editora}"')
    
    def search_book_autor(self, autor): #retorna um livro
        return self._cmd_read(f'SELECT * FROM livros WHERE autor = "{autor}"')
    
    def update(self, isbn, autor, data, titulo, editora, edicao, local):
        print(f'UPDATE exemplares SET (autor, data, titulo, editora, edicao, local)=("{autor}", "{data}", "{titulo}", "{editora}", "{edicao}", "{local}") WHERE isbn="{isbn}"')         
        self._cmd(f'UPDATE livros SET autor = "{autor}", ano_publicao = "{data}", titulo = "{titulo}", editora = "{editora}", edicao = "{edicao}", localizacao = "{local}" WHERE isbn="{isbn}"')

    def delete(self, isbn):
        self._cmd(f'DELETE FROM livros WHERE isbn="{isbn}"')

class Cnx_exemplares(Conexao, Persistencia):
    #exemplares (isbn, cod, disponivel)
    
    def add(self, cod:int, isbn:str, disponivel:bool = True):
        # if self._cmd_read(f'SELECT * FROM exemplares WHERE isbn = "{isbn}"') == None:
        #     disponivel = False
        
        if self._cmd_read(f'SELECT * FROM exemplares WHERE cod = "{cod}"') != []:
            print("Já existe um exemplar com este código")
            return
        
        self._cmd(f'INSERT INTO exemplares (cod, isbn, disponivel) VALUES ("{cod}", "{isbn}", "{disponivel}")')
        
    def read(self, isbn)->list:
        return self._cmd_read(f'SELECT * FROM exemplares WHERE isbn = "{isbn}"')
    
    def read_cod(self, cod, isbn)->list:
        return self._cmd_read(f'SELECT * FROM exemplares WHERE (cod, isbn) = ("{cod}", "{isbn}")')
    
    def search_status(self, isbn, disponivel = True)->list:
        return self._cmd_read(f'SELECT * FROM exemplares WHERE (isbn, disponivel) = ("{isbn}", "{disponivel}")')
        
    def mudar_status(self, cod, isbn):
        exemplar = self._cmd_read(f'SELECT * FROM exemplares WHERE (cod, isbn) = ("{cod}", "{isbn}")')
        print("erro", exemplar)
        exemplar[0][2] = not exemplar[0][2]
        print("error ", exemplar)
        self._cmd(f'UPDATE exemplares SET disponivel = {exemplar[0][2]} WHERE (cod, isbn) = ("{cod}", "{isbn}")')
    
    def delete(self, cod, isbn):
        self._cmd(f'DELETE FROM exemplares WHERE (cod, isbn)=("{cod}", "{isbn}")')
    
    def delete_all(self, isbn):
        self._cmd(f'DELETE FROM exemplares WHERE isbn="{isbn}"')

class Cnx_emprestimos(Conexao, Persistencia):
    # [cod, matricula, data_de_emprestimo, data_de_devolucao] #EMPRESTIMOS

    def add(self, isbn, cod, matricula, data_emprestimo, data_devolucao):
            self._cmd(f'INSERT INTO emprestimo (isbn, cod, matricula, data_emprestimo, data_devolucao) VALUES ("{isbn}", "{cod}", "{matricula}", "{data_emprestimo}", "{data_devolucao}")')
            
    ##o sistema só registra os empréstimo
    def read(self, matricula)->list:
        return self._cmd_read(f'SELECT * FROM emprestimo WHERE matricula="{matricula}"')
    
    
    def delete(self, cod, matricula):
        return self._cmd_read(f'DELETE FROM emprestimo WHERE (cod, matricula)=("{cod}", "{matricula}")')

class Cnx_reservas(Conexao, Persistencia):
    #reserva (nome_do_livro, matricula, data)
    def add(self, isbn, matricula, data):
        self._cmd(f'INSERT INTO reservas (isbn, matricula, data) VALUES ("{isbn}", "{matricula}", "{data}")')
    
    def read(self, isbn, matricula):
        return self._cmd_read(f'SELECT * FROM reservas WHERE (isbn, matricula) = ("{isbn}", "{matricula}")')
    
    def read_ebook(self, isbn)->list:
        return self._cmd_read(f'SELECT * FROM reservas WHERE isbn="{isbn}"')
    
    def delete(self, isbn, matricula):
        self._cmd(f'DELETE FROM reservas WHERE (isbn, matricula)=("{isbn}", "{matricula}")')
    
    def delete_all(self, isbn):
        self._cmd(f'DELETE FROM reservas WHERE isbn="{isbn}"')

class Cnx_multas(Conexao, Persistencia):
    #multas (matricula, valor_multa, nome_livro)
    def add(self, matricula, data_da_multa, isbn):
        self._cmd(f'INSERT INTO multas (matricula, data_da_multa, isbn) VALUES ("{matricula}", "{data_da_multa}", "{isbn}")')
    
    def read(self, matricula):
        return self._cmd_read(f'SELECT * FROM multas WHERE matricula="{matricula}"')
    
    def read_all(self)-> list:
        return self._cmd_read(f'SELECT * FROM multas')
    
    def delete(self, matricula):
        self._cmd(f'DELETE FROM multas WHERE matricula="{matricula}"')
