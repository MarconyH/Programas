#define TAMANHO 30

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <cctype>

using namespace std;


const string TipoToken[] = {
    "PCDeclaracoes", "PCAlgoritmo", "PCInteiro", "PCReal", "PCAtribuir", "PCA", "PCLer",
    "PCImprimir", "PCSe", "PCEntao", "PCEnquanto", "PCInicio", "PCFim",
    "OpAritMult", "OpAritDiv", "OpAritSoma", "OpAritSub",
    "OpRelMenor", "OpRelMenorIgual", "OpRelMaiorIgual",
    "OpRelMaior", "OpRelIgual", "OpRelDif",
    "OpBoolE", "OpBoolOu",
    "Delim", "AbrePar", "FechaPar", "Var", "NumInt", "NumReal", "Cadeia", "Fim", "Null",
};

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
            EspacoComentario();
            ldat->confirmar();
            proximo = fim();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            proximo = PalavraChave();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            proximo = variavel();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            proximo = numeros();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            proximo = OpArit();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            proximo = OpRel();
            if (proximo == NULL) {
                ldat->zerar();
            } else {
                ldat->confirmar();
                return proximo;
            }
            proximo = Delim();
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
        void EspacoComentario()
        {
            char c;
            while(true)
            {
                c = this->ldat->lerProximoCaractere();
                if (c == ' ' || c == '\n' || c == '\t' || c == '%')
                {
                    if (c != '%')
                    {
                        continue;
                    }
                    else
                    {
                        while (c != '\n')
                        {
                            c = this->ldat->lerProximoCaractere();
                        }
                        return;
                    }
                }
                else
                {
                    this->ldat->retroceder();
                    return;
                }
            }
    
        }

        Token *OpArit()
        {
            char c;
            c = this->ldat->lerProximoCaractere();
            if(c == '*')
            {
                return new Token("OpAritMult", ldat->get_lexema());
            }
            else if(c == '+')
            {
                return new Token("OpAritSoma", ldat->get_lexema());
            }
            else if(c == '-')
            {
                return new Token("OpAritSub", ldat->get_lexema());
            }
            else if(c == '/')
            {
                return new Token("OpAritDiv", ldat->get_lexema());
            }
            else if(c == '(')
            {
                return new Token("AbrePar", ldat->get_lexema());
            }
            else if(c == ')')
            {
                return new Token("FechaPar", ldat->get_lexema());
            }
            else
            {
                this->ldat->retroceder();
                return NULL;
            }
        }

        Token *OpRel()
        {
            char c;
            c = this->ldat->lerProximoCaractere();
            if(c == '=')
            {
                return new Token("OpRelIgual", this->ldat->get_lexema());
            }
            else if(c == '>')
            {
                c = this->ldat->lerProximoCaractere();
                if(c == '=')
                {
                    return new Token("OpRelMaiorIgual", this->ldat->get_lexema());
                }
                else
                {
                    ldat->retroceder();
                    return new Token("OpRelMaior", this->ldat->get_lexema());
                }
            }
            else if(c == '<')
            {
                c = this->ldat->lerProximoCaractere();
                if(c == '>')
                {
                    return new Token("OpRelDif", this->ldat->get_lexema());
                }
                else if(c == '=')
                {
                    return new Token("OpRelMenorIgual", this->ldat->get_lexema());
                }
                else
                {
                    this->ldat->retroceder();
                    return new Token("OpRelMenor", this->ldat->get_lexema());
                }
            }
            else
            {
                this->ldat->retroceder();
                return NULL;
            }
        }

        Token *Delim()
        {
            char c;
            c = this->ldat->lerProximoCaractere();
            if(c == ':')
            {
                return new Token("Delim", this->ldat->get_lexema());
            }
            else
            {
                return NULL;
            }
        }

        Token *numeros()
        {
            char c;
            {
                c = this->ldat->lerProximoCaractere();
                if(isdigit(c) != 0)
                {
                    while (isdigit(c) != 0)
                    {
                        c = this->ldat->lerProximoCaractere();
                    }
                    if(c == '.')
                    {
                        c = this->ldat->lerProximoCaractere();
                        if(isdigit(c) == 0)
                        {
                            this->ldat->retroceder();
                            this->ldat->retroceder();
                            return new Token("NumInt", this->ldat->get_lexema());
                        }
                        while(isdigit(c) != 0);
                        {
                            c = this->ldat->lerProximoCaractere();
                        }
                        this->ldat->retroceder();
                        return new Token("NumReal", this->ldat->get_lexema());
                    }
                    else
                    {
                        this->ldat->retroceder();
                        return new Token("NumInt", this->ldat->get_lexema());
                    }
                    
                }
                else
                {
                    this->ldat->retroceder();
                    return NULL;
                }
            }
        }

        Token *variavel()
        {
            char c;
            while(true)
            {
                c = this->ldat->lerProximoCaractere();
                if(isalpha(c) != 0)
                {
                    while(isalpha(c) != 0 || isdigit(c) != 0)
                    {
                        c = this->ldat->lerProximoCaractere();
                    }
                    this->ldat->retroceder();
                    return new Token("Var", this->ldat->get_lexema());
                }
                else
                {
                    this->ldat->retroceder();
                    return NULL;
                }
            }
        }

        Token *Cadeia()
        {
            char c;
            c = this->ldat->lerProximoCaractere();
            if(c == '\'')
            {
                while (c != '\'' && c != '\n')
                {
                    c = this->ldat->lerProximoCaractere();
                }
                if(c == '\'')
                {
                    return new Token("Cadeia", this->ldat->get_lexema());
                }
                else
                {
                    return NULL;
                }
                
            }
            else
            {
                this->ldat->retroceder();
                return NULL;
            }
        }

        Token *PalavraChave()
        {
            char c;
            while(true)
            {
                c = this->ldat->lerProximoCaractere();
                if (isalpha(c) == 0)
                {
                    this->ldat->retroceder();
                    string lexema = this->ldat->get_lexema();
                    if(lexema == "DECLARACOES")
                    {
                        return new Token("PCDeclaracoes", lexema);
                    }
                    else if(lexema == "ALGORITMO")
                    {
                        return new Token("PCAlgoritmo", lexema);
                    }
                    else if(lexema == "INT")
                    {
                        return new Token("PCInteiro", lexema);
                    }
                    else if(lexema == "REAL")
                    {
                        return new Token("PCReal", lexema);
                    }
                    else if(lexema == "ATRIBUIR")
                    {
                        return new Token("PCAtribuir", lexema);
                    }
                    else if(lexema == "A")
                    {
                        return new Token("PCA", lexema);
                    }
                    else if(lexema == "LER")
                    {
                        return new Token("PCLer", lexema);
                    }
                    else if(lexema == "IMPRIMIR")
                    {
                        return new Token("PCImprimir", lexema);
                    }
                    else if(lexema == "SE")
                    {
                        return new Token("PCSe", lexema);
                    }
                    else if(lexema == "ENTAO")
                    {
                        return new Token("PCEntao", lexema);
                    }
                    else if(lexema == "ENQUANTO")
                    {
                        return new Token("PCEnquanto", lexema);
                    }
                    else if(lexema == "INICIO")
                    {
                        return new Token("PCInicio", lexema);
                    }
                    else if(lexema == "FIM")
                    {
                        return new Token("PCFim", lexema);
                    }
                    else if(lexema == "E")
                    {
                        return new Token("OpBoolE", lexema);
                    }
                    else if(lexema == "OU")
                    {
                        return new Token("OpBoolOu", lexema);
                    }
                    else
                    {
                        return NULL;
                    }
                }
            }
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
    AlgumaLexico *lex = new AlgumaLexico("/home/marcony/Programas/Construcao_de_Compiladores/Analisador_Lexico/AlgumaLex.txt");
    Token *t = NULL;
    t = lex->proximoToken();
    while(t->nome != "Fim")
    {
        cout << *t;
        t = lex->proximoToken();
    }

    return 0;
}
