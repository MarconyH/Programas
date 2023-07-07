from abc import ABCMeta
#from persistencia import*
from conexao.conexao import *
#from conexao import Conexao
#from conexao.conexao import Cnx_usuario
#from conexao.conexao import Cnx_bibliotecario
#from conexao.conexao import Cnx_livros
#from conexao.conexao import Cnx_exemplares
#from conexao.conexao import Cnx_emprestimos
#from conexao.conexao import Cnx_reservas
#from conexao.conexao import Cnx_multas
from datetime import date
##NÃO TEVE JEITO, COLOQUEI PRA FAZER AS COISAS E DEPOIS INSERIR O LOGIN

data_hoje = date.today()
data_comp = data_hoje.day + data_hoje.month*30 + data_hoje.year*365
data_hoje_bonitinha = data_hoje.strftime('%d/%m/%Y')

data = '01/02/2022'
'''
[nome1, status1, cod1, nome2, status2, cod2]
[(nome1, status1, cod1), (nome2, status2, cod2)]
'''

dia = int(data[:2])
month = int(data[3:5])
year = int(data[6:10])

class Pessoa(): 
    def __init__(self, usuario) -> None:
        self._conx_usu = Cnx_usuario('usuarios')
        self._conx_livros = Cnx_livros('livros')
        self._conx_exemplares = Cnx_exemplares('exemplares')
        self._conx_emprestimos = Cnx_emprestimos('emprestimos')
        self._conx_reservas = Cnx_reservas('reservas')
        self._conx_multas = Cnx_multas('multas')
        self.__nome = usuario[0][0]
        self.__matricula = usuario[0][1]
        self.__telefone = usuario[0][2]
        self.__email = usuario[0][3]
        self.__senha = usuario[0][4]

    @property
    def nome(self):
        return self.__nome
    
    @property
    def matricula(self):
        return self.__matricula

    @property
    def telefone(self):
        return self.__telefone
    
    @property
    def email(self):
        return self.__email
    
    @property
    def senha(self):
        return self.__senha
    
class Usuarios_comuns(Pessoa):
    def __init__(self, dados) -> None:
        super().__init__(dados)

    def view_catalog(self):
        #[titulo, autor, editora, ano_publicao, isbn] #LIVRO
        #pode exestir livro sem exemplares disponivel, ja q tem uma q nao sai da biblioteca
        resultado = self._conx_livros.read()
        if resultado != []:
            titulos = []
            autores = []
            editora = []
            isbn = []
            ano = []
            for i in resultado:
                titulos.append(i[0])
                autores.append(i[1])
                editora.append(i[2])
                ano.append(i[4])
                isbn.append(i[5])
            return [titulos, autores, editora, ano, isbn]
        return []
        
    
    @staticmethod
    def converter(day)->str:
        year = day//365
        day = day%365
        month = day//30
        day = day%30
        
        if day < 10:
            day = f'0{day}'
        if month < 10:
            month = f'0{month}'
            
        return f'{day}/{month}/{year}'
    
    #feito, eu acho
    def emprestimo(self, isbn:str) -> str:
        #[nome_do_livro, data_de_emprestimo, data_de_devolucao] #EMPRESTIMOS
        livro = self._conx_livros.search_book(isbn)
        #[titulo, autor, editora, ano_publicao, isbn] #LIVRO
        #[nome_do_livro, matricula, data_de_emprestimo, data_de_devolucao] #EMPRESTIMOS
        #[isbn, cod, status] #EXEMPLARES

        #modifiquei aqui
        global data_hoje_bonitinha 
        data_emprestimo = data_hoje_bonitinha
        global data_comp
    
        data_comp = data_comp + 7
        
        data_devolucao = self.converter(data_comp)

        if livro != []:
            multas = self._conx_multas.read(self.matricula)
            if multas:
                return f'Multa Existente! Sua multa termina no dia: {multas[0][1]}'
                
            
            exemplar = self._conx_exemplares.search_status(isbn)
            if exemplar != []:
                # exemplar = exemplar[0] 
                    quant = self._conx_exemplares.read(isbn)
                    if not quant: return 'Não tem Exemplares Disponível'
                    reserva = self._conx_reservas.read_ebook(exemplar[0][0])

                    if reserva != []:
                        if len(quant) < len(reserva):
                            for i in reserva:

                                if self.matricula in i:
                                    self._conx_exemplares.mudar_status(exemplar[0][1], isbn)
                                    self._conx_emprestimos.add(livro[0][4], exemplar[0][1], self.matricula, data_emprestimo, data_devolucao)
                                    self._conx_reservas.delete(exemplar[0][0], self.matricula)
                                    return f'Empréstimo Realizado {exemplar[0][1]}'
                                    
                            
                            return'Possui reserva'
                    self._conx_exemplares.mudar_status(exemplar[0][1], isbn)
                    self._conx_emprestimos.add(livro[0][5], exemplar[0][1], self.matricula, data_emprestimo, data_devolucao)

                    
                    return f'Realizado Empréstimo, Código do livro {exemplar[0][1]}'
            
            return'Não tem Exemplar Disponível'
        return'Não tem o livro Disponível'
    
    def reserva(self, isbn:str, data:str):
        # DATE – Uma data de 01/01/1000 a 31/12/9999,
        livro = self._conx_livros.search_book(isbn)
        if livro:
            exemplar = self._conx_exemplares.search_status(isbn)
            if exemplar:
                #login
                self._conx_reservas.add(isbn, self.matricula, data)
                print('Reservado')
            else:
                print("Não Existe Exemplar Dispoível")


    def devolucao(self, cod_exempl:str, isbn:str):

        # emprestimos = self._conx_emprestimos.read(cod_exempl)
        emprestimos = self._conx_emprestimos.read(self.matricula)
        texto = ''
        global data_comp
        if emprestimos != []: 
            
            for i in emprestimos:
                
                if i[0] == cod_exempl:
                    data = i[4]
                    try: 
                        dia = int(data[:2])
                        month = int(data[3:5])
                        year = int(data[6:10])
                        conv = dia + month*30 + year*365

                        if data_comp > conv:
                            texto += f'Multa ao usuário da matrícula {self.matricula}'
                            data_multa = self.converter((data_comp - conv)*2)
                            texto += f'\nSem direito de pegar emprestado um livro, pode pegar dia: {data_multa}'
                            # CADASTRAR MULTA 
                            self._conx_multas.add(self.matricula, data_multa, isbn)
                        else:
                            texto += 'Livro Devolvido '
                        self._conx_exemplares.mudar_status(cod_exempl, isbn)
                        self._conx_emprestimos.delete(cod_exempl, self.matricula)
                        reserva = self._conx_reservas.read_ebook(isbn)
                        
                        if reserva != []:
                            pass
                            # texto += f'\nUsuario da Matricula: {reserva[1]} Reservou'
                            ##precisa fazer algo a mais?
                        
                        return texto
                        
                    except Exception as erro:
                        print('Error: ', erro)
        return 'Sem Emprestimo com esse código'    

        # self._conx_exemplares.mudar_status(cod_exempl, isbn)
        # print('saiu 2')
        
        # reservou = self._conx_reservas.read(cod_exempl, self.matricula)
        # print('sem erro')
        # if reservou : 
        #     print('reservou acbou')
        #     self._conx_reservas.delete(isbn, self.matricula)
    
    #quantidade de reserva com quantidade de livros
    def renovacao(self, isbn, cod):
        livro = self._conx_livros.search_book(isbn)

        if livro:

            exemplares = self._conx_exemplares.read(isbn)
            if not exemplares:  return
            exemplar = self._conx_exemplares.read_cod(cod, isbn)
            if not exemplar: return

            status = self._conx_reservas.read_ebook(isbn)

            if not status or len(status) < len(exemplares):

                empt = self._conx_emprestimos.read(isbn)
                if empt: 
                    cod = empt[0]
                    matricula = empt[1]
                    data_empresti = empt[2]
                    conv = int(empt[3][:2]) + int(empt[3][3:5])*30 + int(empt[3][6:10])*365

                    data_devo = self.converter(conv+3)

                    # self.devolucao(empt[0], empt[1], empt[2], empt[3])
                    self.devolucao(empt[0], empt[2], empt[3])
                    # self.emprestimo(cod, data_empresti, data_devo)
                    self.emprestimo(cod)
                    

            else:
                print('Existe Reserva')
    
    #TODO
    #pesquisa por titulo, autor, editora e palavras chave
    #resultado deve ter informações relevantes sobre o livro, como disponibilidade e localização
    def pesquisa(self, isbn):
        livro = self._conx_livros.search_book(isbn)
        if livro != []:
            status = self._conx_exemplares.search_status(isbn)

            print(f'Titulo: {livro[0]} Autor : {livro[1]} Editora: {livro[2]} Ano de Publicação: {livro[3]} Isbn: {4}', end='')
            if status:
                print(' Status: Disponível')
            else:
                print(' Status: Indisponível')
        else:
            print('Não Existe o Livro')
    
    def quantidade_exemplares(self, isbn):
        exemplares = self._conx_exemplares.read(isbn)
        return len(exemplares)
        
    
    def controle_multa(self):
        hoje = date.today()
        hoje_em_dia = data_hoje.day + data_hoje.month*30 + data_hoje.year*365
        data_hoje_bonitinha = hoje.strftime('%d/%m/%Y')

        list_multas = self._conx_multas.read_all()
        global data_comp

        if list_multas:
            for i in list_multas:
                data = i[1]
                dia = int(data[:2])
                month = int(data[3:5])
                year = int(data[6:10])
                conv = dia + month*30 + year*365

                if conv < data_comp:
                    self._conx_multas.delete(i[0])

# class Bibliotecarios(Pessoa): -> mudei isso 

class Bibliotecarios(Usuarios_comuns):

    def __init__(self, dados) -> None:
        super().__init__(dados)
        
    def add_books(self, titulo, autor, editora, edicao, ano_publicacao, isbn, localizacao ):
        find = self._conx_livros.search_book(isbn)

        if not find:
            self._conx_livros.add(titulo, autor, editora, edicao, ano_publicacao, isbn, localizacao)

    def remove_books(self, isbn) -> str:
        o_livro = self._conx_livros.search_book(isbn)
        if o_livro != []:
            exemplares = self._conx_exemplares.read(isbn)
            ignora = 0
            if exemplares != []:
                for i in exemplares:
                # [isbn, cod, status] #EXEMPLARES
                    if ignora >= 1:
                        if False == i[2]:
                            return "Existe exemplares desse livro em uso"
                    ignora+=1
            self._conx_livros.delete(isbn)
            self._conx_exemplares.delete_all(isbn)
            self._conx_reservas.delete_all(isbn)
            return "Removido."
        
        return "Livro Inexistente"

    def edit_books(self, isbn, autor, data, titulo, editora, edicao, local): 
        self._conx_livros.update(isbn, autor, data, titulo, editora, edicao, local)
    
    def pesquisa_livro(self,opc:str, inform):
        pesq = []

        if opc == "Autor(a)":
            pesq = self._conx_livros.search_book_autor(inform)

        elif opc == "Titulo":
            pesq = self._conx_livros.search_book_titulo(inform)
            
        elif opc == "Editora":
            pesq = self._conx_livros.search_book_editora(inform)

        elif opc == "Isbn":
            print("ESCOLHIDO")
            pesq = self._conx_livros.search_book(inform)
            print(pesq)
        print(pesq)

        return pesq
        
    def numero_exemplares(self, quant, isbn):
        o_livro = self._conx_livros.search_book(isbn)

        if o_livro != []:

            lista_exemplar = self._conx_exemplares.read(isbn)

            tam = 0
            if lista_exemplar != []:
                tam = (len(lista_exemplar[0]) + 1) + 1
                print("TAM1-> ", tam)

            tam_novo=tam+(int(quant))
            print("tam_novo->", tam_novo)

            for i in range(tam, tam_novo):
                self._conx_exemplares.add(i, isbn)

            return f"{quant} Exemplares Adicionado."

        return 'Não Existe Este Livro.'
            
    def remove_exemplar(self, number, isbn):
        texto = ''
        for i in range(int(number)):
            exemplar = self._conx_exemplares.search_status(isbn)
            if exemplar != []:
                print("cod", exemplar[0][1])
                self._conx_exemplares.delete(exemplar[0][1], isbn)
            else:
                texto = "Não Foi Possível Remover Todos os Exemplares\n->Alguns Estão em Uso."

        texto += "Exemplares excluídos com sucesso"
        return texto
    
    #criei essa aqui, não sei se a de cima é chamada em outro quanto
    # def remove_exemplar_quantidade(self, cod, isbn):
    #     exemplarEs = self._conx_exemplares.read_cod(cod, isbn)
        
    #     if(cod > )
    #     for i 
    #     if self._conx_exemplares.read_cod(cod, isbn)[2]:
    #         self._conx_exemplares.delete(cod, isbn)
        
    #     if self._conx_exemplares.read(isbn):
    #         return

    #     self._conx_reservas.delete_all(isbn)
            

class Livros:
    def __init__(self, titulo:str, autor:str, editora:str, ano_publicacao:str, isbn:str)->None:
        self.__titulo = titulo
        self.__autor = autor
        self.__editora = editora
        self.__ano_publicacao = ano_publicacao
        self.__isbn = isbn

class Exemplar:
    def __init__(self, livro):
        self.livro = livro
        self.status = True
        self.data_devolucao = None

class Login:
    def __init__(self):
        self._conx_usu = Cnx_usuario('usuarios')

    def register_user(self, nome:str, matricula:str,telefone, email , senha:str):
        #[nome, matricula, telefone, email, senha] #USUARIO
        ver = self._conx_usu.read(matricula, senha)
        
        if ver == []:
            self._conx_usu.add(nome, matricula, telefone, email, senha)
    
    def login_user(self, matricula:str, senha:str)->tuple:
        ver = self._conx_usu.read(matricula, senha)
        if ver:
            if ver[0][4] == senha:
                if matricula[0] == "B" and matricula[1] == "B":
                    return (1, ver)
                else:
                    return (0, ver)
        
        return (-1, ver)
