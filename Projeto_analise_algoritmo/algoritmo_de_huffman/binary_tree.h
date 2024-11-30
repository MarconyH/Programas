#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <fstream>

using namespace std;

class Tree
{
    private:
        string value;
        Tree *right;
        Tree *left;
        bool leaf();
    public:
        Tree(string value = "\0");
        void print(int aux = 0);
        void fuse(Tree *first_tree, Tree *second_tree);
        void print_table(string path = "");
        void decode_text(string *encoded_text);
        
};
#endif