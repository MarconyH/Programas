import customtkinter as ctk
from PIL import Image
import os
from Estrutura.class_ import *

class LibraryApp:
    def __init__(self):
        self.janela = ctk.CTk()
        self.janela.maxsize(width=700, height=400)  # Tamanho máximo
        self.janela.minsize(width=700, height=400)  # Tamanho mínimo
        
        self.janela.geometry("700x400")
        self.janela.title("Biblioteca")

        ctk.CTkLabel(self.janela, text="Bem-Vindo de volta.", bg_color="transparent", font=("arial bold", 30)).pack(pady=20, padx=5)

        self.create_widgets()

        self.janela.mainloop()

    def create_widgets(self):
        self.frame = ctk.CTkFrame(master=self.janela, width=310, height=125, fg_color="gray", border_width=9, corner_radius=12)
        self.frame.place(x=25, y=55)

        img_path = os.path.join(os.path.dirname(__file__), "livro.png")
        img = ctk.CTkImage(light_image=Image.open(img_path), size=(100, 90))
        ctk.CTkLabel(self.janela, text='', image=img, bg_color="gray").place(x=45, y=65)
        ctk.CTkLabel(self.janela, text="Emprestar um livro.", bg_color="gray", font=("arial bold", 19)).place(x=153, y=70)

        btn = ctk.CTkButton(self.janela, text='', width=100, height=40, bg_color="gray", fg_color="#000", command=self.novatela)
        btn.place(x=215, y=120)

        self.frame = ctk.CTkFrame(master=self.janela, width=310, height=125, fg_color="gray", border_width=9, corner_radius=12)
        self.frame.place(x=25, y=220)

        img_path2 = os.path.join(os.path.dirname(__file__), "4989753.png")
        img2 = ctk.CTkImage(light_image=Image.open(img_path2), size=(100, 90))
        ctk.CTkLabel(self.janela, text='', image=img2, bg_color="gray").place(x=45, y=235)
        ctk.CTkLabel(self.janela, text="Devolver um livro.", bg_color="gray", font=("arial bold", 19)).place(x=150, y=230)

        btn = ctk.CTkButton(self.janela, text='', width=100, height=40, bg_color="gray", fg_color="#000", command=self.novatela)
        btn.place(x=215, y=285)

        self.frame = ctk.CTkFrame(master=self.janela, width=310, height=125, fg_color="gray", border_width=9, corner_radius=12)
        self.frame.place(x=375, y=55)

        img_path3 = os.path.join(os.path.dirname(__file__), "renew.png")
        img3 = ctk.CTkImage(light_image=Image.open(img_path3), size=(100, 90))
        ctk.CTkLabel(self.janela, text='', image=img3, bg_color="gray").place(x=395, y=70)
        ctk.CTkLabel(self.janela, text="Renovar Livro Atual.", bg_color="gray", font=("arial bold", 19)).place(x=500, y=70)

        btn = ctk.CTkButton(self.janela, text='', width=100, height=40, bg_color="gray", fg_color="#000", command=self.novatela)
        btn.place(x=570, y=115)

        self.frame = ctk.CTkFrame(master=self.janela, width=310, height=125, fg_color="gray", border_width=9, corner_radius=12)
        self.frame.place(x=375, y=220)

        img_path4 = os.path.join(os.path.dirname(__file__), "115730.png")
        img4 = ctk.CTkImage(light_image=Image.open(img_path4), size=(100, 90))
        ctk.CTkLabel(self.janela, text='', image=img4, bg_color="gray").place(x=400, y=235)
        ctk.CTkLabel(self.janela, text="Procurar um Livro.", bg_color="gray", font=("arial bold", 20)).place(x=500, y=235)

        btn = ctk.CTkButton(self.janela, text='', width=100, height=40, bg_color="gray", fg_color="#000", command=self.novatela)
        btn.place(x=570, y=285)

    def novatela(self):
        janela2 = ctk.CTk()
        janela2.title("Escolhendo o livro")
        ctk.CTkLabel(janela2, text="Que livro você vai escolher", font=("arial bold", 30)).pack(pady=20, padx=5)
        janela2.mainloop()

    def novatela0(self):
        janela0 = ctk.CTk()
        janela0.title("Escolhendo o livro")
        ctk.CTkLabel(janela0, text="Que livro você vai escolher", font=("arial bold", 30)).pack(pady=20, padx=5)
        janela0.mainloop()

    def novatela2(self):
        janela3 = ctk.CTk()
        janela3.title("Outra janela")
        ctk.CTkLabel(janela3, text="Esta é outra janela", font=("arial bold", 30)).pack(pady=20, padx=5)
        janela3.mainloop()

    def novatela3(self):
        janela4 = ctk.CTk()
        janela4.title("Mais uma janela")
        ctk.CTkLabel(janela4, text="Essa é mais uma janela", font=("arial bold", 30)).pack(pady=20, padx=5)
        janela4.mainloop()


if __name__ == "__main__":
    app = LibraryApp()
