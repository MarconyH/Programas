#include <iostream>

using namespace std;

enum Color
{
	RED;
	BLACK;
};

class Node
{
	public:
		Node *left = NULL;
		Node *right = NULL;
		Node *father = NULL;
		int num = 0;
		Color color= RED;
};

int height(Node *root, int size = 0);
void insert(Node *root = NULL, Node *new_node = NULL);
void gen_node(Node *node);
int balancing(Node *node);

int main()
{

	return 0;
}

void gen_node(Node *node)
{
	cout << "Digite o número: ";
	cin >> node->num;
	cout << endl;
}

int height(Node *root, int size)
{
	if(root == NULL)
	{
		return 1;
	}

	int right = 0;
	int left = 0;
	if(root->color == BLACK)
	{
		right = 1;
		left = 1;
	}

	right += height(root->right, size+1);
	left += height(root->left, size+1);

	if(right > left)
	{
		return right;
	}

	return left;
}

void rotation(Node *node)
{
	if(node->father->color == BLACK && node->color == RED)
	{
		return;
	}
	
	if(node->father->father->right->color == RED && node->father->father->left->color == RED)
	{
		node->father->father->right->color = BLACK;
		node->father->father->left->color = BLACK;
		node->father->father->color = RED;
		return
	}		

	if(node->father)
}

void insert(Node **root, Node *new_node)
{
	if(*root == NULL)
	{
		if(new_node == NULL)
		{
			new_node = new Node;
		}

		root = new Node*;
		gen_node(new_node);
		*root = new_node;
		*root->color = BLACK;
	}

	if(new_node == NULL)
	{
		new_node = new Node;
		gen_node(new_node);
	}

	if(*root->num > new_node->num)
	{
		if(*root->left != NULL)
		{
			insert(root, new_node->left);
		}

		else
		{
			*root->left = new_node;
			balancing(new_node);			
		}
	}

	else
	{
		if(*root->right != NULL)
		{
			insert(root, new_node->right);
		}

		else
		{
			*root->right = new_node;
			balancing(new_node);
		}
	}
}


