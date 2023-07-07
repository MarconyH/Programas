import customtkinter as ctk
from PIL import Image
import os
from Estrutura.class_ import *

#import tkinter module
import tkinter as tk

class LibraryApp_Bibliotecario:

    def __init__(self, usuario):
        # self.janela = ctk.CTk()
        # wlcm_scrn = tkinter.Toplevel()
        self.janela = tk.Toplevel()
         # Tamanho mínimo
        self.janela.geometry("700x400")
        # self.janela.geometry("18x13")

        self.janela.title("Biblioteca")
        self.usuario = usuario
        self.bibliotecario = Bibliotecarios(usuario)

        caminho_background= os.path.join(os.path.dirname(__file__), 'images/b.jpg')
        caminho= ctk.CTkImage(light_image=Image.open(caminho_background), size=(1600,900))

        ctk.CTkLabel(self.janela, text=None, image=caminho, bg_color="gray").place(x=0, y=0)

        #add book, remove _book,edit_book,numero_exemplar,remove_exemplar


        ctk.CTkLabel(self.janela, text=(f"Olá, {self.usuario[0][0]}"),corner_radius=20, font=("Times new roman", 70),fg_color="#000080",bg_color="#99CCFF",text_color="#99CCFF").pack(pady=20, padx=5)
        # ctk.CTkLabel(self.janela, text="Bem-Vindo de volta.",corner_radius=20, font=("cooper black", 70),fg_color="#000080",bg_color="#99CCFF",text_color="#99CCFF").pack(pady=20, padx=5)

        self.create_widgets()

        self.janela.mainloop()



    def menu2(self):
        janela = ctk.CTk()
         # Tamanho mínimo
         
        """
        janela.geometry("18x13")
        janela.title("Biblioteca")
        #add book, remove _book, edit_book,numero_exemplar,remove_exemplar
        nome_a_ser_decidido = "Marcocelo"

        ctk.CTkLabel(janela, text=(f"Olá,{nome_a_ser_decidido} bem-vindo ao acervo."),corner_radius=20, font=("Times new roman", 70),fg_color="#000080",bg_color="#99CCFF",text_color="#99CCFF").pack(pady=20, padx=5)
        """
        self.frame = ctk.CTkFrame(master=self.janela, width=700, height=200, fg_color="#99CCFF",bg_color="#000080", border_width=9, corner_radius=12, border_color="#000080")
        self.frame.place(x=50, y=140)
        img_path = os.path.join(os.path.dirname(__file__), "images/livro (1).png")
        img = ctk.CTkImage(light_image=Image.open(img_path), size=(170, 150))
        ctk.CTkLabel(self.janela, text=None, image=img, bg_color="#99CCFF").place(x=70, y=165)
        ctk.CTkLabel(self.janela, text="Adicionar um livro.", bg_color="#99CCFF", font=("cooper Black", 40),text_color="#000080").place(x=300, y=165)

        btn1 = ctk.CTkButton(self.janela, text="PRESSIONE", width=400, height=80, bg_color="#99CCFF", fg_color="#000080",font=("cooper black", 40),text_color="#99CCFF", command=self.ad_book)
        btn1.place(x=300, y=240)


        
        self.frame = ctk.CTkFrame(master=self.janela, width=700, height=200, fg_color="#99CCFF",bg_color="#000080", border_width=9, corner_radius=12, border_color="#000080")
        self.frame.place(x=800, y=140)

        img_path2 = os.path.join(os.path.dirname(__file__), "images/remover.png")
        img2 = ctk.CTkImage(light_image=Image.open(img_path2), size=(170, 150))
        ctk.CTkLabel(self.janela, text=None, image=img2, bg_color="#99CCFF").place(x=830, y=165)
        ctk.CTkLabel(self.janela, text="Remover um livro.", bg_color="#99CCFF", font=("cooper Black", 40),text_color="#000080").place(x=1070, y=165)

        btn = ctk.CTkButton(self.janela, text="PRESSIONE", width=400, height=80, bg_color="#99CCFF", fg_color="#000080",font=("cooper black", 40),text_color="#99CCFF", command=self.del_book)
        btn.place(x=1070, y=240)


        
        self.frame = ctk.CTkFrame(master=self.janela, width=700, height=200, fg_color="#99CCFF",bg_color="#000080", border_width=9, corner_radius=12, border_color="#000080")
        self.frame.place(x=50, y=360)

        img_path3 = os.path.join(os.path.dirname(__file__), "images/editar-informacao.png")
        img3 = ctk.CTkImage(light_image=Image.open(img_path3), size=(170, 150))
        ctk.CTkLabel(self.janela, text=None, image=img3, bg_color="#99CCFF").place(x=85, y=385)
        ctk.CTkLabel(self.janela, text="Editar um livro.", bg_color="#99CCFF", font=("cooper Black", 40),text_color="#000080").place(x=300, y=390)

        btn = ctk.CTkButton(self.janela, text="PRESSIONE", width=400, height=80, bg_color="#99CCFF", fg_color="#000080",font=("cooper black", 40),text_color="#99CCFF", command=self.edit_book)
        btn.place(x=300, y=450)


        
        self.frame = ctk.CTkFrame(master=self.janela, width=700, height=200, fg_color="#99CCFF",bg_color="#000080", border_width=9, corner_radius=12, border_color="#000080")
        self.frame.place(x=800, y=360)

        img_path4 = os.path.join(os.path.dirname(__file__), "images/pilha-de-livros.png")
        img4 = ctk.CTkImage(light_image=Image.open(img_path4), size=(170, 150))
        ctk.CTkLabel(self.janela, text=None, image=img4, bg_color="#99CCFF").place(x=830, y=385)
        ctk.CTkLabel(self.janela, text="Adiciona Exemplar.", bg_color="#99CCFF", font=("cooper Black", 40),text_color="#000080").place(x=1070, y=380)

        btn = ctk.CTkButton(self.janela, text=("PRESSIONE"), width=400, height=80, bg_color="#99CCFF",font=("cooper black",40),text_color="#99CCFF", fg_color="#000080", command=self.add_exemplares)
        btn.place(x=1070, y=450)




        self.frame = ctk.CTkFrame(master=self.janela, width=700, height=200,bg_color="#000080", fg_color="#99CCFF", border_width=9, corner_radius=12, border_color="#000080")
        self.frame.place(x=50, y=580)
        
        img_path5 = os.path.join(os.path.dirname(__file__), "images/remover (1).png")
        img5 = ctk.CTkImage(light_image=Image.open(img_path5), size=(170, 150))
        ctk.CTkLabel(self.janela, text=None, image=img5, bg_color="#99CCFF").place(x=70, y=600)
        ctk.CTkLabel(self.janela, text="Remover exemplares.", bg_color="#99CCFF", font=("cooper Black", 40),text_color="#000080").place(x=300, y=600)

        btn = ctk.CTkButton(self.janela, text="PRESSIONE", width=400, height=80, bg_color="#99CCFF",font=("cooper black",40), fg_color="#000080",text_color="#99CCFF",command=self.del_exemplares)
        btn.place(x=300, y= 670)




        self.frame = ctk.CTkFrame(master=self.janela, width=700, height=200,bg_color="#000080", fg_color="#99CCFF", border_width=9, corner_radius=12, border_color="#000080")
        self.frame.place(x=800, y=580)
        
        img_path5 = os.path.join(os.path.dirname(__file__), "images/sair.png")
        img5 = ctk.CTkImage(light_image=Image.open(img_path5), size=(160, 160))
        ctk.CTkLabel(self.janela, text=None, image=img5, bg_color="#99CCFF").place(x=830, y=600)
        ctk.CTkLabel(self.janela, text="Sair.", bg_color="#99CCFF", font=("cooper Black", 37),text_color="#000080").place(x=1070, y=590)

        btn = ctk.CTkButton(self.janela, text="PRESSIONE", width=400, height=80, bg_color="#99CCFF",font=("cooper black",40), fg_color="#000080",text_color="#99CCFF",command = self.create_widgets)
        btn.place(x=1070, y= 670)


        #janela.mainloop()






    def create_widgets(self):
        self.frame = ctk.CTkFrame(master=self.janela, width=600, height=150, fg_color="#99CCFF", bg_color="#000080", border_width=6, corner_radius=8, border_color="#000080")
        self.frame.place(x=45, y=130)

        img_path = os.path.join(os.path.dirname(__file__), "images/livraria-digital.png")
        img = ctk.CTkImage(light_image=Image.open(img_path), size=(150, 130))
        ctk.CTkLabel(self.janela, text=None, image=img, bg_color="#99CCFF").place(x=60, y=140)
        ctk.CTkLabel(self.janela, text="Emprestar um livro.", bg_color="#99CCFF", font=("cooper Black", 30), text_color="#000080").place(x=250, y=140)

        btn = ctk.CTkButton(self.janela, text="PRESSIONE", width=300, height=60, bg_color="#99CCFF", fg_color="#000080", font=("cooper black", 30), text_color="#99CCFF", command=self.novatela)
        btn.place(x=270, y=200)

        self.frame2 = ctk.CTkFrame(master=self.janela, width=600, height=150, fg_color="#99CCFF", bg_color="#000080", border_width=6, corner_radius=8, border_color="#000080")
        self.frame2.place(x=715, y=130)

        img_path2 = os.path.join(os.path.dirname(__file__), "images/devolver.png")
        img2 = ctk.CTkImage(light_image=Image.open(img_path2), size=(150, 130))
        ctk.CTkLabel(self.janela, text=None, image=img2, bg_color="#99CCFF").place(x=730, y=140)
        ctk.CTkLabel(self.janela, text="Devolver um livro.", bg_color="#99CCFF", font=("cooper Black", 30), text_color="#000080").place(x=980, y=140)

        btn2 = ctk.CTkButton(self.janela, text="PRESSIONE", width=300, height=60, bg_color="#99CCFF", fg_color="#000080", font=("cooper black", 30), text_color="#99CCFF", command=self.novatela2)
        btn2.place(x=980, y=200)

        self.frame3 = ctk.CTkFrame(master=self.janela, width=600, height=150, fg_color="#99CCFF", bg_color="#000080", border_width=6, corner_radius=8, border_color="#000080")
        self.frame3.place(x=45, y=325)

        img_path3 = os.path.join(os.path.dirname(__file__), "images/renovar.png")
        img3 = ctk.CTkImage(light_image=Image.open(img_path3), size=(150, 130))
        ctk.CTkLabel(self.janela, text=None, image=img3, bg_color="#99CCFF").place(x=60, y=335)
        ctk.CTkLabel(self.janela, text="Renovar Livro Atual.", bg_color="#99CCFF", font=("cooper Black", 30), text_color="#000080").place(x=250, y=355)

        btn3 = ctk.CTkButton(self.janela, text="PRESSIONE", width=300, height=60, bg_color="#99CCFF", fg_color="#000080", font=("cooper black", 30), text_color="#99CCFF", command=self.novatela0)
        btn3.place(x=260, y=400)

        self.frame4 = ctk.CTkFrame(master=self.janela, width=600, height=150, fg_color="#99CCFF", bg_color="#000080", border_width=6, corner_radius=8, border_color="#000080")
        self.frame4.place(x=715, y=325)

        img_path4 = os.path.join(os.path.dirname(__file__), "images/procurando.png")
        img4 = ctk.CTkImage(light_image=Image.open(img_path4), size=(150, 130))
        ctk.CTkLabel(self.janela, text=None, image=img4, bg_color="#99CCFF").place(x=730, y=335)
        ctk.CTkLabel(self.janela, text="Procurar um Livro.", bg_color="#99CCFF", font=("cooper Black", 30), text_color="#000080").place(x=980, y=355)

        btn4 = ctk.CTkButton(self.janela, text="PRESSIONE", width=300, height=60, bg_color="#99CCFF", font=("cooper black", 30), fg_color="#000080", text_color="#99CCFF", command=self.novatela3)
        btn4.place(x=980, y=400)

        self.frame5 = ctk.CTkFrame(master=self.janela, width=600, height=150, bg_color="#000080", fg_color="#99CCFF", border_width=6, corner_radius=8, border_color="#000080")
        self.frame5.place(x=380, y=520)

        img_path5 = os.path.join(os.path.dirname(__file__), "images/folheto.png")
        img5 = ctk.CTkImage(light_image=Image.open(img_path5), size=(150, 130))
        ctk.CTkLabel(self.janela, text=None, image=img5, bg_color="#99CCFF").place(x=420, y=530)
        ctk.CTkLabel(self.janela, text="Verificar Catálogo.", bg_color="#99CCFF", font=("cooper Black", 30), text_color="#000080").place(x=640, y=535)

        btn5 = ctk.CTkButton(self.janela, text="PRESSIONE", width=300, height=60, bg_color="#99CCFF", font=("cooper black", 30), fg_color="#000080", text_color="#99CCFF", command=self.novatela4)
        btn5.place(x=640, y=580)
        
        self.frame6 = ctk.CTkFrame(master=self.janela, width=700, height=200,bg_color="#000080", fg_color="#99CCFF", border_width=9, corner_radius=12, border_color="#000080")
        self.frame6.place(x=800, y=580)
        
        img_path6 = os.path.join(os.path.dirname(__file__), "images/bibliotecario.png")
        img6 = ctk.CTkImage(light_image=Image.open(img_path6), size=(160, 160))
        ctk.CTkLabel(self.janela, text=None, image=img6, bg_color="#99CCFF").place(x=830, y=600)
        ctk.CTkLabel(self.janela, text="Acessar Acervo da\n Biblioteca.", bg_color="#99CCFF", font=("cooper Black", 37),text_color="#000080").place(x=1070, y=590)

        btn6 = ctk.CTkButton(self.janela, text="PRESSIONE", width=400, height=80, bg_color="#99CCFF",font=("cooper black",40), fg_color="#000080",text_color="#99CCFF",command = self.menu2)
        btn6.place(x=1070, y= 670)

    
        
 
    # EMPRESTAR livro feito
    def novatela(self):
        janela2 = ctk.CTk(fg_color="#99CCFF")
        janela2.title("Escolhendo o livro")
        ctk.CTkLabel(janela2, text="Insira o ISBN do livro desejado:", font=("cooper black", 40),text_color="#000080").pack()
        entrada1 = ctk.CTkEntry(janela2, font=("arial bold", 30),width=200,height=60)
        entrada1.pack(pady=20, padx=5)

        def obter_texto():
            texto = entrada1.get()
            textao = self.bibliotecario.emprestimo(texto)

            #usem texto pra procurar o livro
            ctk.CTkLabel(janela2,text=textao, font=("cooper black",40),text_color="#000080").pack()
            btn.pack(pady=25, padx=5)

        btn = ctk.CTkButton(janela2, text="Obter Livro",font=("cooper black",40),text_color="#000080",width=200,height=60, command=obter_texto)
        btn.pack(pady= 25 ,padx= 5)



        def sair():
            janela2.destroy()
        
        btn = ctk.CTkButton(janela2, text="Sair",font=("cooper black",40),text_color="#000080",width=200,height=60,command=sair)
        
        janela2.mainloop()

    def novatela0(self):
        janela0 = ctk.CTk(fg_color="#99CCFF")
        janela0.title("Renovar Livro:")

        ctk.CTkLabel(janela0, text="Insira o ISBN:", font=("cooper black", 40),text_color="#000080").pack()
        entrada1 = ctk.CTkEntry(janela0, font=("arial bold", 30),width=200,height=60)
        entrada1.pack(pady=20, padx=5)

        ctk.CTkLabel(janela0, text="Insira o Código do livro:", font=("cooper black", 40),text_color="#000080").pack(pady=25, padx=5)
        entrada2 = ctk.CTkEntry(janela0, font=("arial bold", 30),width=200,height=60)
        entrada2.pack(pady=25, padx=5)

       

        def obter_texto():
                texto = entrada1.get()
                texto2 = entrada2.get()
                #usem texto pra procurar o livro
                ctk.CTkLabel(janela0,text=(f"O livro renovado foi:{texto}\n Codigo:{texto}\nISBN:{texto2}"),font=("cooper black",40),text_color="#000080").pack()
                btn.pack(pady=25, padx=5,)

        btn = ctk.CTkButton(janela0, text="Renovar Livro",font=("cooper black",40),text_color="#000080",width=200,height=60, command=obter_texto)
        btn.pack(pady= 25 ,padx= 5)
        
        def sair():
            janela0.destroy()
        
        btn = ctk.CTkButton(janela0, text="Sair",font=("cooper black",40),text_color="#000080",width=200,height=60,command=sair)
        

        janela0.mainloop()

    def novatela2(self):
        janela3 = ctk.CTk(fg_color="#99CCFF")
        janela3.title("Devolver Livro:")    
        ctk.CTkLabel(janela3, text="Insira o ISBN:", font=("cooper black", 40),text_color="#000080").pack()
        entrada1 = ctk.CTkEntry(janela3, font=("arial bold", 40),text_color="#000080",width=200,height=60)
        entrada1.pack(pady=20, padx=5)

        ctk.CTkLabel(janela3, text="Insira o Código do livro:", font=("cooper black", 40),text_color="#000080").pack(pady=25, padx=5)
        entrada2 = ctk.CTkEntry(janela3, font=("arial bold", 40),text_color="#000080",width=200,height=60)
        entrada2.pack(pady=20, padx=5)

       

        def obter_texto():
                texto = entrada1.get()
                texto2 = entrada2.get()
                #usem texto pra procurar o livro
                textao = self.bibliotecario.devolucao(texto2, texto)
                ctk.CTkLabel(janela3,text=textao,font=("cooper black",40),text_color="#000080").pack()

                # if 0:# aqui vc cria uma condicao pra imprimir a multa
                #     ctk.CTkLabel(janela3,text=(f"Devido ao seu atraso na entrega do livro por fazr pague a multa de:{texto}"),font=("cooper black",40),text_color="#000080").pack()
                # btn.pack(pady=25, padx=5)
        btn = ctk.CTkButton(janela3, text="Devolver Livro",font=("cooper black",40),text_color="#000080",width=200,height=60,command=obter_texto)
        btn.pack(pady= 25 ,padx= 5)
        
        def sair():
            janela3.destroy()
        
        btn = ctk.CTkButton(janela3, text="Sair",font=("cooper black",40),text_color="#000080",width=200,height=60,command=sair)
        

        janela3.mainloop()
        

        
        
        janela3.mainloop()

    def novatela3(self):
        janela4 = ctk.CTk(fg_color="#99CCFF")
        janela4.title("Procurar Livro:")
       
        menu = ctk.CTkLabel(janela4,text ="Pelo que voce esta buscando:",font=("cooper black",40),text_color="#000080").pack(pady=20,padx=5)
        menu = ctk.CTkLabel(janela4, text ="Escolha uma opção:",font=("cooper black",15)).pack()
        mes_var =ctk.StringVar(value="Escolha aqui:")

        entrada2 = ctk.CTkOptionMenu(janela4,
                  values=["Autor(a)","Titulo","Editora","Isbn"],
                  variable=mes_var,width=200,height=60,button_color="#000080",fg_color="#000080")
        entrada2.pack()
        

        ctk.CTkLabel(janela4, text="Insira a informação escolhida:", font=("cooper black", 40),text_color="#000080").pack(pady=25, padx=5)
        entrada1 = ctk.CTkEntry(janela4, font=("arial bold", 40),height=60,width=200)
        entrada1.pack(pady=10, padx=5)


        def obter_texto():
            
            texto = entrada1.get()
            texto2 = entrada2.get()#USEM ESSE AQUI PRA PROCURAR A CLASSE ESPECIFICA
            var = self.bibliotecario.pesquisa_livro(texto2, texto)
            

            # var = ["Percy Jackson", "O grande Gatsby", "Conde de monte cristo", "Jantar Secreto"]

            ctk.CTkLabel(janela4, text=(f"Esses foram os(as) {texto2}s encontrados:\n"), font=("cooper black", 30),text_color="#000080").pack()
#TODO
#Heitor, arruma aqui
            caixa_de_texto = ctk.CTkTextbox(janela4, width=250, height=180, font=("Arial", 30))
            caixa_de_texto.pack(pady=10, padx=5)
            var =["texto1","texto2"]
            for i in var:
                if i == texto:
                    caixa_de_texto.insert("end",i + "\n")
            btn.pack(pady=0, padx=0)

        btn = ctk.CTkButton(janela4, text="Buscar",font=("cooper black",40),text_color="#000080",width=200,height=60, command=obter_texto)
        btn.pack(pady= 10 ,padx=0)

        
        def sair():
            janela4.destroy()
        
        btn = ctk.CTkButton(janela4, text="Sair",font=("cooper black",40),text_color="#000080",width=200,height=60,command=sair)
        
        
        janela4.mainloop()

#catalogo
    def novatela4(self):
        janela4 = ctk.CTk(fg_color="#99CCFF")
        janela4.title("Catalogo da Biblioteca:")
        
        ctk.CTkLabel(janela4, text="Catalogo da Biblioteca:", font=("cooper black", 30),text_color="#000080").pack(pady=20, padx=5)
        
        tabview = ctk.CTkTabview(janela4,border_width=15,bg_color="#000080", width=600, height=500,border_color="#000080",fg_color="#99CCFF",segmented_button_fg_color="#000080")
        tabview.pack()
        
        aba_catalogo = tabview.add("Catalogo")
    
        #titulo autor editora ano isbn
        lista = self.bibliotecario.view_catalog()
        lista_titulos = []
        lista_autores = []
        lista_editora = []
        lista_ano = []
        lista_isbn = []
        if lista != []:
            lista_titulos = lista[0]
            lista_autores = lista[1]
            lista_editora = lista [2]
            lista_ano = lista[3]
            lista_isbn = lista[4]
        
        # Adicionando os títulos na coluna 1
        ctk.CTkLabel(aba_catalogo, text="TITULO:",font=("times new roman",20),text_color="#000080").grid(row=0, column=0)
        for i, titulo in enumerate(lista_titulos):
            ctk.CTkLabel(aba_catalogo, text=titulo,text_color="#000080").grid(row=i+2, column=0)
        
        # Adicionando os autores na coluna 2
        ctk.CTkLabel(aba_catalogo, text="AUTORES:   ",font=("times new roman",20),text_color="#000080").grid(row=0, column=1)
        for i, autor in enumerate(lista_autores):
            ctk.CTkLabel(aba_catalogo, text=autor,text_color="#000080").grid(row=i+2, column=1)

        # Adicionando as editoras na coluna 3
        ctk.CTkLabel(aba_catalogo, text="EDITORAS:  ",font=("times new roman",20),text_color="#000080").grid(row=0, column=2)
        for i, autor in enumerate(lista_editora):
            ctk.CTkLabel(aba_catalogo, text=autor,text_color="#000080").grid(row=i+2, column=2)

        # Adicionando o isbn na coluna 4
        ctk.CTkLabel(aba_catalogo, text="ISBN:  ",font=("times new roman",20),text_color="#000080").grid(row=0, column=3)
        for i, autor in enumerate(lista_isbn):
            ctk.CTkLabel(aba_catalogo, text=autor,text_color="#000080").grid(row=i+2, column=3)

        # Adicionando oano de lancamento na coluna 5
        ctk.CTkLabel(aba_catalogo, text="ANO DE LANÇAMENTO:",font=("times new roman",20),text_color="#000080").grid(row=0, column=4)
        for i, autor in enumerate(lista_ano):
            ctk.CTkLabel(aba_catalogo, text=autor,text_color="#000080").grid(row=i+2, column=4)

        def sair():
            janela4.destroy()
        
        btn = ctk.CTkButton(janela4, text="Sair",font=("cooper black",40),text_color="#000080",width=200,height=80,command=sair)
        btn.pack(pady=25, padx=5)

        janela4.mainloop()

#feito
    def ad_book(self):
            j = ctk.CTk(fg_color="#99CCFF")
            j.title("Biblioteca:")

            ctk.CTkLabel(j, text="Insira as informações do livro:", font=("cooper black", 40), text_color="#000080").grid(row=0, column=0, columnspan=2, pady=20, padx=5)

            ctk.CTkLabel(j, text="Título:", font=("cooper black", 40), text_color="#000080").grid(row=1, column=0, padx=10, pady=10)
            entrada_titulo = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada_titulo.grid(row=1, column=1, padx=10, pady=10)

            ctk.CTkLabel(j, text="Autor:", font=("cooper black", 40), text_color="#000080").grid(row=2, column=0, padx=10, pady=10)
            entrada_autor = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada_autor.grid(row=2, column=1, padx=10, pady=10)

            ctk.CTkLabel(j, text="ISBN:", font=("cooper black", 40), text_color="#000080").grid(row=3, column=0, padx=10, pady=10)
            entrada_isbn = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada_isbn.grid(row=3, column=1, padx=10, pady=10)

            ctk.CTkLabel(j, text="Data de Lançamento:", font=("cooper black", 40), text_color="#000080").grid(row=4, column=0, padx=10, pady=10)
            entrada_data = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada_data.grid(row=4, column=1, padx=10, pady=10)

            ctk.CTkLabel(j, text="Editora:", font=("cooper black", 40), text_color="#000080").grid(row=5, column=0, padx=10, pady=10)
            entrada_editora = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada_editora.grid(row=5, column=1, padx=10, pady=10)
            
            ctk.CTkLabel(j, text="Edição:", font=("cooper black", 40), text_color="#000080").grid(row=5, column=0, padx=10, pady=10)
            entrada_edicao = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada_edicao.grid(row=5, column=1, padx=10, pady=10)
            
            ctk.CTkLabel(j, text="Localização:", font=("cooper black", 40), text_color="#000080").grid(row=5, column=0, padx=10, pady=10)
            entrada_localizacao = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada_localizacao.grid(row=5, column=1, padx=10, pady=10)

            def obter_texto():
                autor = entrada_autor.get()
                data = entrada_data.get()
                titulo = entrada_titulo.get()
                editora = entrada_editora.get()
                isbn = entrada_isbn.get()
                edicao = entrada_edicao.get()
                localizacao = entrada_localizacao.get()
                textao = self.bibliotecario.add_books(titulo, autor, editora, edicao, data, isbn, localizacao)

                # ctk.CTkLabel(j, text="Obrigado por inserir um novo livro.", font=("cooper black", 40), text_color="#000080").grid(row=6, column=1, padx=10, pady=10)
                ctk.CTkLabel(j, text=textao, font=("cooper black", 40), text_color="#000080").grid(row=6, column=1, padx=10, pady=10)

            btn = ctk.CTkButton(j, text="Adicionar Livro", font=("cooper black", 40), text_color="#000080", width=200, height=60, command=obter_texto)
            btn.grid(row=7, column=1, padx=10, pady=10)

            def sair():
                j.destroy()

            btn_sair = ctk.CTkButton(j, text="Sair", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=sair)
            btn_sair.grid(row=8, column=1, padx=10, pady=10)

            j.mainloop()

    #deletar feito
    def del_book(self):
        j = ctk.CTk(fg_color="#99CCFF")
        j.title("Biblioteca:")

        ctk.CTkLabel(j, text="Insira a informação requisitada:", font=("cooper black", 40), text_color="#000080").grid(row=0, column=0, columnspan=2, pady=20, padx=5)

        ctk.CTkLabel(j, text="ISBN:", font=("cooper black", 40), text_color="#000080").grid(row=1, column=0, padx=10, pady=10)
        entrada_isbn = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
        entrada_isbn.grid(row=1, column=1, padx=10, pady=10)

        def obter_texto():
                isbn = entrada_isbn.get()
                texto = self.bibliotecario.remove_books(isbn)
                ctk.CTkLabel(j, text=texto, font=("cooper black", 40), text_color="#000080").grid(row=6, column=1, padx=10, pady=10)

        btn = ctk.CTkButton(j, text="Remover Livro", font=("cooper black", 40), text_color="#000080", width=200, height=60, command=obter_texto)
        btn.grid(row=7, column=1, padx=10, pady=10)

        def sair():
                j.destroy()

        btn_sair = ctk.CTkButton(j, text="Sair", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=sair)
        btn_sair.grid(row=8, column=1, padx=10, pady=10)

        j.mainloop()


    def del_exemplares(self):
        j = ctk.CTk(fg_color="#99CCFF")
        j.title("Biblioteca:")

        ctk.CTkLabel(j, text="Insira a informação requisitada:", font=("cooper black", 40), text_color="#000080").grid(row=0, column=0, columnspan=2, pady=20, padx=5)

        ctk.CTkLabel(j, text="ISBN:", font=("cooper black", 40), text_color="#000080").grid(row=1, column=0, padx=10, pady=10)
        entrada_isbn = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
        entrada_isbn.grid(row=1, column=1, padx=10, pady=10)

        def procurando_livro():
            isbn = entrada_isbn.get()

            examplarEs = self.bibliotecario.pesquisa_livro(isbn)

            if examplarEs != []:
                obter_texto()
            else:
                ctk.CTkLabel(j, text="Isbn Incorreto", font=("cooper black", 40), text_color="#000080").grid(row=8, column=2, columnspan=1, pady=20, padx=20)


        def obter_texto():
                isbn = entrada_isbn.get()
                def remove():
                    excluir = entrada.get()
                    text = self.bibliotecario.remove_exemplar(int(excluir), isbn)
                    nova_qnt = self.bibliotecario.quantidade_exemplares(isbn)
                    
                    ctk.CTkLabel(j, text=(f"{text}\nSobraram:{nova_qnt}"), font=("cooper black", 40), text_color="#000080").grid(row=11, column=0, columnspan=2, pady=20, padx=5)

                ctk.CTkLabel(j, text="Quantos exemplares\n serao excluidos.", font=("cooper black", 40), text_color="#000080").grid(row=9, column=0, padx=10, pady=10)
                entrada = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
                entrada.grid(row=9, column=1, padx=10, pady=10)
                
                
                btn_rem = ctk.CTkButton(j, text="Remover", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=remove)
                btn_rem.grid(row=10, column=1, padx=10, pady=10)


                btn_sair = ctk.CTkButton(j, text="Sair", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=sair)
                btn_sair.grid(row=12, column=1, padx=10, pady=10)




        
        
        btn = ctk.CTkButton(j, text="Remover Exemplar", font=("cooper black", 40), text_color="#000080", width=200, height=60, command=procurando_livro)
        btn.grid(row=7, column=1, padx=10, pady=10)



        def sair():
                j.destroy()


        j.mainloop()
        
    #feito
    def add_exemplares(self):
        j = ctk.CTk(fg_color="#99CCFF")
        j.title("Biblioteca:")

        def obter_texto():
            def remove():
                adicionar = int(entrada.get())
                textao = self.bibliotecario.numero_exemplares(adicionar, isbn)
                 # Valor da quantidade de exemplares
                
                ctk.CTkLabel(j, text=textao, font=("cooper black", 40), text_color="#000080").grid(row=11, column=0, columnspan=2, pady=20, padx=5)

            isbn = entrada_isbn.get()

            ctk.CTkLabel(j, text="Quantidade Exemplar:", font=("cooper black", 40), text_color="#000080").grid(row=9, column=0, padx=10, pady=10)
            entrada = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
            entrada.grid(row=9, column=1, padx=10, pady=10)

            btn_rem = ctk.CTkButton(j, text="Adicionar", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=remove)
            btn_rem.grid(row=10, column=1, padx=10, pady=10)

        def sair():
            j.destroy()

        def procurando_livro():
            isbn = entrada_isbn.get()

            examplarEs = self.bibliotecario.pesquisa_livro(isbn)

            if examplarEs != []:
                obter_texto()
            else:
                ctk.CTkLabel(j, text="Isbn Incorreto", font=("cooper black", 40), text_color="#000080").grid(row=8, column=1, columnspan=1, pady=10, padx=10)

                 
        ctk.CTkLabel(j, text="Insira a informação requisitada:", font=("cooper black", 40), text_color="#000080").grid(row=0, column=0, columnspan=2, pady=20, padx=5)

        ctk.CTkLabel(j, text="ISBN:", font=("cooper black", 40), text_color="#000080").grid(row=1, column=0, padx=10, pady=10)
        entrada_isbn = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
        entrada_isbn.grid(row=1, column=1, padx=10, pady=10)
        
        isbn = entrada_isbn.get()

       
        btn = ctk.CTkButton(j, text="Procurar Livro", font=("cooper black", 40), text_color="#000080", width=200, height=60, command=procurando_livro)
        btn.grid(row=7, column=1, padx=10, pady=10)
        

        btn_sair = ctk.CTkButton(j, text="Sair", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=sair)
        btn_sair.grid(row=12, column=1, padx=10, pady=10)
        

        j.mainloop()



#foi
    def edit_book(self):
        j = ctk.CTk(fg_color="#99CCFF")
        j.title("Biblioteca:")

        def obter_texto():
            isbn = entrada_isbn.get()
            # entrada_isbn.destroy()
            livro = self.bibliotecario.pesquisa_livro("Isbn", isbn)
            frame = ctk.CTkFrame(master=j, width=1000, height=1000, bg_color="#000080", fg_color="#99CCFF", border_width=9, corner_radius=12, border_color="#000080")
            frame.place(x=0, y=0)
            print(livro)
            if livro != []:
            
                #TODO 
                #Heitor, falta edicao e localizacao
                ctk.CTkLabel(frame, text=f"Livro encontrado: {livro[0][0]}", font=("cooper black", 40), text_color="#000080").grid(row=0, column=1, padx=10, pady=10)

                ctk.CTkLabel(frame, text="Insira as novas informações:", font=("cooper black", 40), text_color="#000080").grid(row=1, column=1, columnspan=2, pady=20, padx=5)

                ctk.CTkLabel(frame, text="Título:", font=("cooper black", 40), text_color="#000080").grid(row=2, column=0, padx=10, pady=10)
                entrada_titulo = ctk.CTkEntry(frame, font=("arial bold", 30), width=200, height=60)
                entrada_titulo.grid(row=2, column=1, padx=10, pady=10)

                ctk.CTkLabel(frame, text="Autor:", font=("cooper black", 40), text_color="#000080").grid(row=3, column=0, padx=10, pady=10)
                entrada_autor = ctk.CTkEntry(frame, font=("arial bold", 30), width=200, height=60)
                entrada_autor.grid(row=3, column=1, padx=10, pady=10)

                ctk.CTkLabel(frame, text="Data de Lançamento:", font=("cooper black", 40), text_color="#000080").grid(row=5, column=0, padx=10, pady=10)
                entrada_data = ctk.CTkEntry(frame, font=("arial bold", 30), width=200, height=60)
                entrada_data.grid(row=5, column=1, padx=10, pady=10)

                ctk.CTkLabel(frame, text="Editora:", font=("cooper black", 40), text_color="#000080").grid(row=6, column=0, padx=10, pady=10)
                entrada_editora = ctk.CTkEntry(frame, font=("arial bold", 30), width=200, height=60)
                entrada_editora.grid(row=6, column=1, padx=10, pady=10)
                
                ctk.CTkLabel(frame, text="Editora:", font=("cooper black", 40), text_color="#000080").grid(row=6, column=0, padx=10, pady=10)
                entrada_edicao = ctk.CTkEntry(frame, font=("arial bold", 30), width=200, height=60)
                entrada_edicao.grid(row=7, column=1, padx=10, pady=10)
                
                ctk.CTkLabel(frame, text="Editora:", font=("cooper black", 40), text_color="#000080").grid(row=6, column=0, padx=10, pady=10)
                entrada_localizacao = ctk.CTkEntry(frame, font=("arial bold", 30), width=200, height=60)
                entrada_localizacao.grid(row=8, column=1, padx=10, pady=10)
                

                def obter_novo():
                    autor = entrada_autor.get()
                    data = entrada_data.get()
                    titulo = entrada_titulo.get()
                    editora = entrada_editora.get()
                    edicao = entrada_edicao.get()
                    localizacao = entrada_localizacao.get()
                    self.bibliotecario.edit_books(isbn, autor, data, titulo, editora, edicao, localizacao)                
                    
                    ctk.CTkLabel(frame, text="Edição aplicada com sucesso", font=("cooper black", 40), text_color="#000080").grid(row=7, column=1, padx=10, pady=10)
                    
                    

                btn = ctk.CTkButton(frame, text="Adicionar Mudanças", font=("cooper black", 40), text_color="#000080", width=200, height=60, command=obter_novo)
                btn.grid(row=7, column=1, padx=10, pady=10)
                
                btn_sair = ctk.CTkButton(j, text="Sair", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=sair)
                btn_sair.grid(row=8, column=1, padx=10, pady=10)
            else:
                ctk.CTkLabel(frame, text=f"Livro não encontrado", font=("cooper black", 40), text_color="#000080").grid(row=0, column=1, padx=10, pady=10)

        def sair():
            j.destroy()

        ctk.CTkLabel(j, text="Indique o livro que será editado:", font=("cooper black", 40), text_color="#000080").grid(row=0, column=0, columnspan=2, pady=20, padx=5)

        ctk.CTkLabel(j, text="ISBN:", font=("cooper black", 40), text_color="#000080").grid(row=1, column=0, padx=10, pady=10)
        entrada_isbn = ctk.CTkEntry(j, font=("arial bold", 30), width=200, height=60)
        entrada_isbn.grid(row=1, column=1, padx=10, pady=10)

        btn = ctk.CTkButton(j, text="Buscar Livro", font=("cooper black", 40), text_color="#000080", width=200, height=60, command=obter_texto)
        btn.grid(row=7, column=1, padx=10, pady=10)

        btn_sair = ctk.CTkButton(j, text="Sair", font=("cooper black", 40), text_color="#000080", width=200, height=80, command=sair)
        btn_sair.grid(row=8, column=1, padx=10, pady=10)

        j.mainloop()

    






# if __name__ == "__main__":
#     app = LibraryApp("asfa")
