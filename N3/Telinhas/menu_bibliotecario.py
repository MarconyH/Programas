import customtkinter as ctk
from PIL import Image
import os

class LibraryApp:
    def __init__(self):
        self.janela = ctk.CTk()
         # Tamanho mínimo
        self.janela.geometry("18x13")
        self.janela.title("Biblioteca")

        caminho_background= os.path.join(os.path.dirname(__file__), "b.jpg")
        caminho= ctk.CTkImage(light_image=Image.open(caminho_background), size=(1600,900))

        ctk.CTkLabel(self.janela, text=None, image=caminho, bg_color="gray").place(x=0, y=0)

        
        ctk.CTkLabel(self.janela, text="Bem-Vindo de volta.",corner_radius=20, font=("cooper black", 70),fg_color="#000080",bg_color="#99CCFF",text_color="#99CCFF").pack(pady=20, padx=5)

        self.create_widgets()

        self.janela.mainloop()

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



    def novatela(self):
        janela2 = ctk.CTk(fg_color="#99CCFF")
        janela2.title("Escolhendo o livro")
        ctk.CTkLabel(janela2, text="Insira o ISBN do livro desejado:", font=("cooper black", 40),text_color="#000080").pack()
        entrada1 = ctk.CTkEntry(janela2, font=("arial bold", 30),width=200,height=60)
        entrada1.pack(pady=20, padx=5)

        def obter_texto():
            texto = entrada1.get()
            #usem texto pra procurar o livro
            ctk.CTkLabel(janela2,text=(f"Obrigado por alugar {texto}\n Tenha uma excelente leitura"),font=("cooper black",40),text_color="#000080").pack()
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
                ctk.CTkLabel(janela3,text=(f"Obrigado por devolver:{texto}\n Esperamos que tenha aproveitado a sua leitura."),font=("cooper black",40),text_color="#000080").pack()

                if 0:# aqui vc cria uma condicao pra imprimir a multa
                    ctk.CTkLabel(janela3,text=(f"Devido ao seu atraso na entrega do livro por fazr pague a multa de:{texto}"),font=("cooper black",40),text_color="#000080").pack()
                btn.pack(pady=25, padx=5)
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
                  values=["Autor(a)","Titulo","Editora","Palavra-Chave"],
                  variable=mes_var,width=200,height=60,button_color="#000080",fg_color="#000080")
        entrada2.pack()


        ctk.CTkLabel(janela4, text="Insira a informação escolhida:", font=("cooper black", 40),text_color="#000080").pack(pady=25, padx=5)
        entrada1 = ctk.CTkEntry(janela4, font=("arial bold", 40),height=60,width=200)
        entrada1.pack(pady=10, padx=5)


        def obter_texto():
            texto = entrada1.get()
            texto2 = entrada2.get()#USEM ESSE AQUI PRA PROCURAR A CLASSE ESPECIFICA
            var = ["Percy Jackson", "O grande Gatsby", "Conde de monte cristo", "Jantar Secreto"]

            ctk.CTkLabel(janela4, text=(f"Esses foram os(as) {texto2}s encontrados:\n"), font=("cooper black", 30),text_color="#000080").pack()

            caixa_de_texto = ctk.CTkTextbox(janela4, width=250, height=180, font=("Arial", 30))
            caixa_de_texto.pack(pady=10, padx=5)

            for i in var:
                if i == texto:
                    caixa_de_texto.insert("end", i + "\n")
            btn.pack(pady=0, padx=0)

        btn = ctk.CTkButton(janela4, text="Buscar",font=("cooper black",40),text_color="#000080",width=200,height=60, command=obter_texto)
        btn.pack(pady= 10 ,padx=0)

        
        def sair():
            janela4.destroy()
        
        btn = ctk.CTkButton(janela4, text="Sair",font=("cooper black",40),text_color="#000080",width=200,height=60,command=sair)
        
        
        janela4.mainloop()


    def novatela4(self):
        janela4 = ctk.CTk(fg_color="#99CCFF")
        janela4.title("Catalogo da Biblioteca:")
        
        ctk.CTkLabel(janela4, text="Catalogo da Biblioteca:", font=("cooper black", 30),text_color="#000080").pack(pady=20, padx=5)
        
        tabview = ctk.CTkTabview(janela4,border_width=15,bg_color="#000080", width=600, height=500,border_color="#000080",fg_color="#99CCFF",segmented_button_fg_color="#000080")
        tabview.pack()
        
        aba_catalogo = tabview.add("Catalogo")
    
        #titulo autor editora ano isbn
        
        lista_titulos = ["Percy Jackson", "O grande Gatsby", "Conde de monte cristo", "Jantar Secreto"]
        lista_autores = ["Autor 1", "Autor 2", "Autor 3", "Autor 4"]
        lista_editora=["arqueiro","globo","arqueiro","globo"]
        lista_isbn=[123,456,789,102]
        lista_ano=[2001,2002,2003,2004]
        
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


if __name__ == "__main__":
    app = LibraryApp()
