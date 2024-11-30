#include "binary_tree.h"

bool Tree::leaf()
{
    return this->left == NULL && this->right == NULL;
}

void Tree::print_table(string path)
{
    if (leaf())
    {
        cout << this->value << " - " << path << endl;
        ofstream new_file;
        new_file.open("Table.txt", ios::app);
        new_file << this->value << " - " << path << endl;
        new_file.close();
        return;
    }

    if (this->left)
    {
        this->left->print_table(path + "0");
    }

    if (this->right)
    {
        this->right->print_table(path + "1");
    }
}

void Tree::print(int aux)
{
    if (this != NULL)
    {
        this->left->print(aux + 1);
        cout << endl;

        for (int i = 0; i < aux; i++)
        {
            cout << "  ";
        }

        cout << "|";
        cout << this->value << endl;
        this->right->print(aux + 1);
    }

    else
    {
        return;
    }
}

void Tree::fuse(Tree *first_tree, Tree *second_tree)
{
    this->left = first_tree;
    this->right = second_tree;
}

void Tree::decode_text(string *encoded_text)
{
    Tree *current_node = this;

    for (int i = 0; i < encoded_text->length(); i++)
    {
        if (current_node->leaf())
        {
            cout << current_node->value;
            current_node = this;
        }

        if ((*encoded_text)[i] == '1')
        {
            current_node = current_node->right;
        }
        else if ((*encoded_text)[i] == '0')
        {
            current_node = current_node->left;
        }
    }

    if (current_node->leaf())
    {
        cout << current_node->value;
    }
}

Tree::Tree(string value)
{
    this->value = value;
    this->right = NULL;
    this->left = NULL;
}