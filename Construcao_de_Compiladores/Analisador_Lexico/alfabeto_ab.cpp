#define TAMANHO 30

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <cctype>

using namespace std;

class LeitorDeArquivosTexto
{
    ifstream file;
    bool opened_file = false;
    char *buffer;
    int position;
    int buffer_atual;
    int iniciolexema;
    string lexema;

    void initialize_buffer()
    {
        this->buffer_atual = 2;
        this->iniciolexema = 0;
        this->lexema = "";
        this->buffer = new char[TAMANHO*2];
        this->position = 0;
        preencher_buffer(1);
    }

    void increment_position()
    {
        this->position++;
        if(this->position == TAMANHO)
        {
            preencher_buffer(2);
        }
        else if(this->position == TAMANHO * 2)
        {
            preencher_buffer(1);
            this->position = 0;
        }
    }

    void preencher_buffer(int number)
    {
        int i = 0;
        if(number == 2)
        {
            i = TAMANHO;
        }
        if((this->buffer_atual == 2 && number == 1) || (this->buffer_atual == 1 && number == 2))
        {
            if(this->buffer_atual == 2 && number == 1)
            {
                this->buffer_atual = 1;
            }
            else
            {
                this->buffer_atual = 2;
            }
            for(i = i; i < TAMANHO * number; i++)
            {
                if(this->opened_file)
                {
                    char caractere;
                    if(this->file.get(caractere))
                    {
                        this->buffer[i] = caractere;
                    }
                    else
                    {
                        this->buffer[i] = EOF;
                        break;
                    }
                }
                else
                {
                    cout << "Arquivo Não Aberto" << endl;
                    this->buffer[i] = EOF;
                    return;
                }
                
            }
        }
    }

    public:
        LeitorDeArquivosTexto(string caminho_arquivo)
        {
            this->file.open(caminho_arquivo);
            this->opened_file = true;
            this->initialize_buffer();
        }
        
        char lerbuffer()
        {
            char carac = this->buffer[this->position];
            //cout << *this;
            this->increment_position();
            return carac;
        }

        char lerProximoCaractere()
        {
            char c = this->lerbuffer();
            this->lexema += c;
            return c;
        }

        void retroceder()
        {
            this->position--;
            this->lexema.pop_back();
            if (this->position == -1)
            {
                this->position = TAMANHO * 2 - 1;
            }
        }

        void zerar()
        {
            this->position = this->iniciolexema;
            this->lexema = "";
        }

        void confirmar()
        {
            this->iniciolexema = this->position;
            this->lexema = "";
        }

        string get_lexema()
        {
            return this->lexema;
        }

        void set_iniciolexema(int value)
        {
            this->iniciolexema = value;
        }

        int get_iniciolexema()
        {
            return this->iniciolexema;
        }

        int get_position()
        {
            return this->position;
        }

        int get_iniciolexema_const() const
        {
            return this->iniciolexema;
        }

        int get_position_const() const
        {
            return this->position;
        }

        char *get_buffer() const
        {
            return this->buffer;
        }


};

class Token
{
    public:
        string nome;
        string lexema;
        Token(string nome, string lexema)
        {
            this->nome = nome;
            this->lexema = lexema;  
        }


};

ostream& operator<<(ostream &strm, const Token &token)
{
    return strm << "<" << token.nome << "," << token.lexema << ">";
    //"<" << token.nome << "," << token.lexema
}

ostream& operator<<(ostream &strm, const LeitorDeArquivosTexto &token)
{
    strm << "Buffer:[";
    const char *buffer = token.get_buffer();
    for(int i = 0; i < strlen(buffer); i++)
    {
        char c = buffer[i];
        
        if(c == '\n' || c == ' ' || c == '\t')
        {
            strm << ' '; 
        }
        else
        {
            strm << c;
        }
    }
    strm << "]\n";
    for(int i = 0; i < TAMANHO * 2; i++)
    {
        if(i == token.get_iniciolexema_const() && i == token.get_position_const())
        {
            strm << "%";
        }
        else if(i == token.get_iniciolexema_const())
        {
            strm << "^";
        }
        else if(i == token.get_position_const())
        {
            strm << "*";
        }
        else
        {
            strm << " ";
        }
    }
    return strm;
}

class AlgumaLexico
{
    LeitorDeArquivosTexto *ldat;
    public:
        AlgumaLexico(string arquivo)
        {
            this->ldat = new LeitorDeArquivosTexto(arquivo);
        }
        Token *proximoToken()
        {
            Token *proximo = NULL;
            Espaco();
            ldat->confirmar();
            proximo = fim();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            proximo = Cadeia();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            cout << "Erro léxico!" << endl;
            cout << *ldat;
            return NULL;
        }
    private:
        void Espaco()
        {
            char c;
            while(true)
            {
                c = this->ldat->lerProximoCaractere();
                if (c == ' ' || c == '\n' || c == '\t')
                {
                    continue;
                }
                else
                {
                    this->ldat->retroceder();
                    return;
                }
            }
    
        }

        Token *Cadeia()
        {
            char c;
            c = this->ldat->lerProximoCaractere();
            while (c == 'a' || c == 'b')
            {
                if(c == 'b')
                {
                    c = this->ldat->lerProximoCaractere();
                    if(c == 'a')
                    {
                        c = this->ldat->lerProximoCaractere();
                        if(c == 'b')
                        {
                            c = this->ldat->lerProximoCaractere();
                            if(c == ' ' || c == '\n' || c == '\t' || c == EOF)
                            {
                                this->ldat->retroceder();
                                return new Token("Cadeia", this->ldat->get_lexema());
                            }
                            else
                            {
                                this->ldat->retroceder();
                                this->ldat->retroceder();
                                continue;
                            }
                        }
                    }
                }
                else
                {
                    c = this->ldat->lerProximoCaractere();
                }
            }
            return NULL;
        }

        Token *fim()
        {
            char c = ldat->lerProximoCaractere();
            if (c == EOF) 
            {
                return new Token("Fim", "Fim");
            }
            return NULL;
        }
};

int main()
{
    AlgumaLexico *lex = new AlgumaLexico("/home/marcony/Programas/Construcao_de_Compiladores/Analisador_Lexico/Lexama_ab.txt");
    Token *t = NULL;
    t = lex->proximoToken();
    while(t->nome != "Fim")
    {
        cout << *t;
        t = lex->proximoToken();
    }

    return 0;
}
