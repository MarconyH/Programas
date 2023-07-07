import customtkinter as ctk
from tkinter import PhotoImage
import os
from Estrutura.class_ import *
# from Telinhas.menu_bibliotecario import *
from Telinhas.menu_bibliotecario import LibraryApp_Bibliotecario

path = os.path.join(os.path.dirname(__file__), 'images/login.png')

class App(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.configuracoes_da_janela_inicial()
        self.frame_login = None
        self.frame_rejeitado = None
        self.frame_cadastro = None
        self.tela_de_login()
        self.acesso = Login()

    # Configurar janela
    def configuracoes_da_janela_inicial(self):
        
        self.geometry("700x400")
        self.title("Bem-vindo à Biblioteca")
        self.resizable(False, False)  # Deixar tamanho fixo

    def login_button(self):
            matricula = self.matricula_login_entry.get()

            senha = self.senha_login_entry.get()

            ##acesso ilimitado
            matricula = "BB1"
            senha = "123"

            login = self.acesso.login_user(matricula, senha)

            


            if login[0] == -1:
                self.tela_rejeitado()
                
            elif login[0] == 0:
                print("Usuario")
                # app = LibraryApp(login[1])

            elif login[0] == 1:
                print("Bibliotecario")
                app = LibraryApp_Bibliotecario(login[1])
                

            
    def cadastro_button(self):
            matricula = self.matricula_cadastro_entry.get()
            nome = self.username_cadastro_entry.get()
            telefone = self.telefone_cadastro_entry.get()
            email =  self.email_cadastro_entry.get()
            senha = self.senha_cadastro_entry.get()
            
                        
            if matricula != None and nome != None and telefone != None and email != None and senha != None:
                dados = self.acesso.login_user(matricula, senha)
                if( dados[0] == -1):
                    print(matricula, nome, telefone, email, senha)
                    self.acesso.register_user(nome, matricula, telefone, email, senha) 
                    self.tela_de_login()

            else:
                self.tela_rejeitado()
             
            
    def tela_de_login(self):
        
        #limpar
        if self.frame_login:
            self.frame_login.place_forget()
        if self.frame_cadastro:
            self.frame_cadastro.place_forget()
        if self.frame_rejeitado:
            self.frame_rejeitado.place_forget()

        # Trabalhando com as imagens
        self.image = PhotoImage(file = path)
        self.resized_image = self.image.subsample(10, 10)
        self.image_label = ctk.CTkLabel(self, text= '',image = self.resized_image)
        self.image_label.grid(row=0, column=0, sticky="w", padx=10, pady=10)  # Align to the left
        
        # Titulo da imagem
        self.title_label = ctk.CTkLabel(self, text="Faça seu login ou cadastre-se \nem nossa plataforma", font=("Century Gothic bold", 18))
        self.title_label.grid(row=5, column=0, padx=10, pady=10)
        
        # Criar frame do formulario de login
        self.frame_login = ctk.CTkFrame(self, width=350, height=380)
        self.frame_login.place(x=350, y=10)
        
        #colocando widgets dentro do frame - formulario de login
        self.title_label = ctk.CTkLabel(self.frame_login, text="Faça o seu Login", font=("Century Gothic bold", 22))
        self.title_label.grid(row=0, column=0, padx=10, pady=10)
        
        self.matricula_login_entry = ctk.CTkEntry(self.frame_login, width=300, placeholder_text="Digite sua matrícula", font=("Century Gothic bold", 16), corner_radius=15 )
        self.matricula_login_entry.grid(row=1, column=0, padx=10, pady=10)
        
        self.senha_login_entry = ctk.CTkEntry(self.frame_login, width=300, placeholder_text="Digite sua senha", font=("Century Gothic bold", 16), corner_radius=15, show="\u25CF" )
        self.senha_login_entry.grid(row=2, column=0, padx=10, pady=10)
        
        self.title_label = ctk.CTkLabel(self.frame_login, text="Faça o seu Login", font=("Century Gothic bold", 22))
        self.title_label.grid(row=0, column=0, padx=10, pady=10)
        
        self.ver_senha = ctk.CTkCheckBox(self.frame_login, text="Clique aqui para mostrar Senha", font=("Century Gothic", 12), corner_radius=10)
        self.ver_senha.grid(row=3, column=0, padx=10, pady=10)
        
        self.butao_login = ctk.CTkButton(self.frame_login, width=300, text="Fazer Login", font=("Century Gothic bold", 16), corner_radius=15, command=self.login_button)
        self.butao_login.grid(row=4, column=0, padx=10, pady=10)
        
        self.span = ctk.CTkLabel(self.frame_login, text="Ainda não possui cadastro?", font=("Century Gothic", 12), fg_color="#333")
        self.span.grid(row=5, column=0, padx=10, pady=10)
        
        self.butao_cadastro = ctk.CTkButton(self.frame_login, width=300, fg_color="green", hover_color="#050", text="Fazer Cadastro", font=("Century Gothic bold", 16), corner_radius=15, command=self.tela_de_cadastro)
        self.butao_cadastro.grid(row=6, column=0, padx=10, pady=10)
        
    def tela_de_cadastro(self):
        
        # Limpar tela de login ao apertar botao cadastro
        if self.frame_login:
            self.frame_login.place_forget()
        if self.frame_cadastro:
            self.frame_cadastro.place_forget()
        if self.frame_rejeitado:
            self.frame_rejeitado.place_forget()
        
        # Criar frame do formulario de cadastro
        self.frame_cadastro = ctk.CTkFrame(self, width=350, height=380)
        self.frame_cadastro.place(x=350, y=10)
        
        # Criar tela de cadastro
        self.title_label = ctk.CTkLabel(self.frame_cadastro, text="Dados pessoais", font=("Century Gothic bold", 18),  anchor='w', justify='left')
        self.title_label.grid(row=1, column=0, padx=0, pady=0)
        
        self.username_cadastro_entry = ctk.CTkEntry(self.frame_cadastro, width=300, placeholder_text="Digite seu nome", font=("Century Gothic bold", 16), corner_radius=15 )
        self.username_cadastro_entry.grid(row=2, column=0, padx=10, pady=10)
        
        self.matricula_cadastro_entry = ctk.CTkEntry(self.frame_cadastro, width=300, placeholder_text="Digite sua matricula", font=("Century Gothic bold", 16), corner_radius=15)
        self.matricula_cadastro_entry.grid(row=3, column=0, padx=10, pady=10)

        self.senha_cadastro_entry = ctk.CTkEntry(self.frame_cadastro, width=300, placeholder_text="Digite sua Senha", font=("Century Gothic bold", 16), corner_radius=15 )
        self.senha_cadastro_entry.grid(row=4, column=0, padx=10, pady=10)
        
        self.title_label = ctk.CTkLabel(self.frame_cadastro, text="Contatos", font=("Century Gothic bold", 18))
        self.title_label.grid(row=5, column=0, padx=0, pady=0)
        
        self.telefone_cadastro_entry = ctk.CTkEntry(self.frame_cadastro, width=300, placeholder_text="Digite seu Telefone", font=("Century Gothic bold", 16), corner_radius=15 )
        self.telefone_cadastro_entry.grid(row=6, column=0, padx=10, pady=10)
        
        self.email_cadastro_entry = ctk.CTkEntry(self.frame_cadastro, width=300, placeholder_text="Digite seu Email", font=("Century Gothic bold", 16), corner_radius=15 )
        self.email_cadastro_entry.grid(row=7, column=0, padx=10, pady=10)

        self.butao_cadastro = ctk.CTkButton(self.frame_cadastro, width=300, fg_color="#444", hover_color="#333", text="Cadastrar", font=("Century Gothic bold", 16), corner_radius=15, command=self.cadastro_button)
        self.butao_cadastro.grid(row=8, column=0, padx=10, pady=10)  # Place on the left side with less padding

        self.voltar = ctk.CTkButton(self.frame_cadastro, width=300, fg_color="#444", hover_color="#333", text="Voltar ao login", font=("Century Gothic bold", 16), corner_radius=15, command=self.tela_de_login)
        self.voltar.grid(row=9, column=0, padx=10, pady=10)  # Place on the left side with less padding
    
    def tela_rejeitado(self):
        # Limpar tela de login ao apertar botao cadastro
        if self.frame_login:
            self.frame_login.place_forget()
        if self.frame_cadastro:
            self.frame_cadastro.place_forget()
        if self.frame_rejeitado:
            self.frame_rejeitado.place_forget()
        
        # Criar frame do formulario de cadastro
        self.frame_rejeitado = ctk.CTkFrame(self, width=350, height=380)
        self.frame_rejeitado.place(x=350, y=10)
        
        # Criar tela de cadastro
        self.title_label = ctk.CTkLabel(self.frame_rejeitado, text="Acesso Negado", font=("Century Gothic bold", 18),  anchor='w', justify='left')
        self.title_label.grid(row=1, column=0, padx=0, pady=0)
        
        #botoon = ctk.CTkButton(master=self.frame_login, text="LOGIN", width=300).place(x=25, y=285)

        self.butao_login = ctk.CTkButton(self.frame_rejeitado,   width=300, fg_color="#444", hover_color="#333", text="Voltar ao login", font=("Century Gothic bold", 16), corner_radius=15, command=self.tela_de_login)
        self.butao_login.grid(row=8, column=0, padx=10, pady=10)  # Place on the left side with less padding