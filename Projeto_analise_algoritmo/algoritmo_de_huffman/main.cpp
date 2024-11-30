#include "binary_tree.h"

void sort(int *v, Tree **s, int tam)
{
    int aux;
    Tree *aux2;
    for (int i = 1; i < tam; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] <= v[j])
            {
                aux = v[i];
                aux2 = s[i];
                for (int k = i; k > j; k--)
                {
                    v[k] = v[k - 1];
                    s[k] = s[k - 1];
                }
                v[j] = aux;
                s[j] = aux2;
                break;
            }
        }
    }
}

void sort(int *v, string *s, int tam)
{
    int aux;
    string aux2;
    for (int i = 1; i < tam; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] <= v[j])
            {
                aux = v[i];
                aux2 = (*s)[i];
                for (int k = i; k > j; k--)
                {
                    v[k] = v[k - 1];
                    (*s)[k] = (*s)[k - 1];
                }
                v[j] = aux;
                (*s).replace(j, 1, aux2);
                break;
            }
        }
    }
}

string *sort_character(string *text, int *v)
{
    int size = 0;
    int pos = -1;
    string *character = new string;
    for (int i = 0; i < (*text).length(); i++)
    {
        pos = (*character).rfind((*text)[i]);
        if (pos != -1)
        {
            v[pos]++;
        }
        else
        {
            if ((*character).empty())
            {
                (*character).push_back((*text)[i]);
                v[size] = 1;
                size++;
                continue;
            }
            (*character).push_back((*text)[i]);
            v[size] = 1;
            size++;
        }
    }
    return character;
}

int *frequency_table(string *character, int *v)
{
    int size = (*character).length();
    int *frequency = new int[size];
    for (int i = 0; i < size; i++)
    {
        frequency[i] = v[i];
    }
    sort(frequency, character, size);

    for (int i = 0; i < size; i++)
    {
        cout << (*character)[i] << " - " << frequency[i] << endl;
    }
    return frequency;
}

Tree **convert(string *character)
{
    int size = (*character).length();
    Tree **vector = new Tree *[size];
    for (int i = 0; i < size; i++)
    {
        vector[i] = new Tree(string(1, (*character)[i]));
    }
    return vector;
}

void encode_text(string text) {
    ifstream new_file_read("Table.txt");
    ofstream encoded_file("EncodedText.txt", ios::trunc);

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        string line;

        new_file_read.clear();
        new_file_read.seekg(0, ios::beg);

        while (getline(new_file_read, line)) {
            if (!line.empty() && line[0] == ch) {
                string code = line.substr(4);
                encoded_file << code; 
                break;
            }
        }

    }

    new_file_read.close();
    encoded_file.close();
}

int main()
{
    string text;
    if (text.empty())
    {
        cout << "Digite o texto a ser comprimido" << endl;
        cin >> text;
    }
    ofstream new_file;
    new_file.open("Text.txt");
    new_file << text;
    new_file.close();

    int v[(text).length()];

    string *character = sort_character(&text, v);
    Tree **vector;
    int *frequency = frequency_table(character, v);
    int size = character->length();
    vector = convert(character);
    Tree *new_tree;
    for (int i = 0; i < size - 1; i++)
    {
        new_tree = new Tree("N" + to_string(i));
        new_tree->fuse(vector[i], vector[i + 1]);
        vector[i] = NULL;
        vector[i + 1] = new_tree;
        frequency[i + 1] += frequency[i];
        frequency[i] = 0;
        sort(frequency, vector, character->length());
    }
    new_tree->print();

    new_file.open("Table.txt", ios::trunc);
    new_file.close();
    
    new_tree->print_table();
    encode_text(text);

    ifstream new_file_read;
    new_file_read.open("EncodedText.txt");
    string encoded_text;
    new_file_read >> encoded_text;
    new_tree->decode_text(&encoded_text);
    cout << endl;

    return 0;
}