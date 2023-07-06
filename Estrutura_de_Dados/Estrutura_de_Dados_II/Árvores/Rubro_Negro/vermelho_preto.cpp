#include <iostream>

using namespace std;

enum Color
{
	RED,
	BLACK
};

enum Side
{
	ROOT,
	RIGHT,
	LEFT
};

class Node
{
	public:
		Node *left = NULL;
		Node *right = NULL;
		Node *father = NULL;
		int num = -1;
		Color color = RED;
		Side side = ROOT;
};

Node *smaller(Node *root);
Node *bigger(Node *root);
int height(Node *root, int size = 0);
void insert(Node **root, Node *new_node = NULL);
Node *search_node(Node *root, int num);
void erase_node(Node **node);
void remove_node(Node **root, Node *Node);
Node* gen_node(int num = -1);
void insert_test(Node **root, Node *node);
void print_tree(Node *root, int counter = 0);
int balancing_factor(Node *root);
void balancing_tree(Node **root, Node *node);
void test(Node **root, Node *node);


void left_simple_rotation(Node **root, Node *node, int verification = 0);
void right_simple_rotation(Node **root, Node *node, int verification = 0);
void left_double_rotation(Node **root, Node *node);
void right_double_rotation(Node **root, Node *node);
void menu(Node **root);
void choice(Node **root, int op);

int main()
{
	Node *root = NULL;
	menu(&root);
	return 0;
}

int balancing_factor(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	return height(root->left) - height(root->right);
}

void balancing_tree(Node **root, Node *node)
{
	if(*root == NULL)
	{
		return;
	}
	
	insert_test(root, node);
	balancing_tree(root, (*root)->right);
	balancing_tree(root, (*root)->left);
}

Node *smaller(Node *root)
{
	if(root == NULL)
	{
		return NULL;
	}	
	
	if(root->left != NULL)
	{
		return smaller(root->left);
	}

	else
	{
		return root;
	}
}

Node *bigger(Node *root)
{
	if(root == NULL)
	{
		return NULL;
	}	
	
	if(root->right != NULL)
	{
		return bigger(root->right);
	}

	else
	{
		return root;
	}
}

void erase_node(Node **node)
{
	if((*node)->side == RIGHT)
	{
		(*node)->father->right = NULL;
	}
	if((*node)->side == LEFT)
	{
		(*node)->father->left = NULL;
	}
	(*node)->father = NULL;
	(*node)->right = NULL;
	(*node)->left = NULL;
	(*node)->num = -1;
}

void remove_node(Node **root, Node *node)
{
	if (*root == NULL || node == NULL)
	{
		return;
	}

	//Node *substitute = smaller(node->right);
	Node *substitute =  bigger(node->left);
	if(node->color == RED && node->father != NULL)
	{
		if(node->side == LEFT)
		{
			if(substitute != NULL)
			{
				substitute->father = node->father;

				substitute->left = node->left;
				substitute->right = node->right;
			}
			node->father->left = substitute;
		}
		else if(node->side == RIGHT)
		{
			if(substitute != NULL)
			{
				/* code */
			}
			node->father->right = substitute;
			
		}
		erase_node(&node);
		delete(node);
		return;
	}

	if(node->color == BLACK)
	{
		if (node->father == NULL)
		{
			if(substitute != NULL)
			{
				substitute->color = node->color;
				substitute->side = ROOT;
				substitute->left = (*root)->left;
				substitute->father->left = substitute->right;
				substitute->father = NULL;
			}

			else
			{
				if((*root)->left != NULL)
				{
					(*root)->left->father = NULL;
					(*root)->left->side = ROOT;
					(*root) = (*root)->left;
				}
			}

			(*root) = substitute;
			delete(node);
			return;
		}
		
		//no preto e irmao preto
		if(node->father->right->color == BLACK && node->father->left->color == BLACK)
		{
			if(node->side == RIGHT)
			{
				if(node->father->left->left == NULL && node->father->left->right == NULL)
				{
					node->father->color = BLACK;
					node->father->left->color = RED;
					node->father->right = substitute;
					if(substitute != NULL)
					{
						substitute->color = node->color;
						substitute->father = node->father;
						substitute->side = node->side;
					}
					erase_node(&node);
					delete(node);
					return;
				}

				if((node->father->left->right == NULL && node->father->left->left != NULL && node->father->left->left->color == RED))
				{
					node->father->color = BLACK;
					node->father->left->color = RED;
					node->father->right = substitute;
					if(substitute != NULL)
					{
						substitute->color = node->color;
						substitute->father = node->father;
						substitute->side = node->side;
					}
					/*
					right_simple_rotation(root, node->father);
					node->father->left->left->color = BLACK;*/
					erase_node(&node);
					delete (node);
					return;
				}

				if(node->father->left->left == NULL && node->father->left->right != NULL && node->father->left->right->color == RED)
				{
					node->father->color = BLACK;
					node->father->left->right->color = RED;
					node->father->right = substitute;
					if(substitute != NULL)
					{
						substitute->color = node->color;
						substitute->father = node->father;
						substitute->side = node->side;
					}
					erase_node(&node);
					delete (node);
					return;
				} 
			}

			if(node->side == LEFT)
			{
				if(node->father->right->left == NULL && node->father->right->right == NULL)
				{
					node->father->color = BLACK;
					node->father->right->color = RED;
					node->father->right = substitute;
					if(substitute != NULL)
					{
						substitute->color = node->color;
						substitute->father = node->father;
						substitute->side = node->side;
					}
					erase_node(&node);
					delete(node);
					return;
				} 

				if(node->father->right->right == NULL && node->father->right->left != NULL && node->father->right->left->color == RED)
				{
					node->father->color = BLACK;
					node->father->right->color = RED;
					node->father->right = substitute;
					if(substitute != NULL)
					{
						substitute->color = node->color;
						substitute->father = node->father;
						substitute->side = node->side;
					}
					erase_node(&node);
					delete (node);
					return;
				}

				if(node->father->right->left == NULL && node->father->right->right != NULL && node->father->right->left->color == RED)
				{
					node->father->color = BLACK;
					node->father->right->color = RED;
					node->father->right = substitute;
					if(substitute != NULL)
					{
						substitute->color = node->color;
						substitute->father = node->father;
						substitute->side = node->side;
					}
					erase_node(&node);
					delete (node);
					return;
				}
			}
			
		}
		if(node->father->left->color == BLACK && node->father->right->color == RED)
		{
			node->father->left = substitute;
			right_simple_rotation(root, node->father);
			
			if (substitute != NULL)
			{
				substitute->color = node->color;
				substitute->father = node->father;
				substitute->side = node->side;
			}
			erase_node(&node);
			delete(node);
			return;
		}

		if(node->father->left->color == RED && node->father->right->color == BLACK)
		{
			left_simple_rotation(root, node->father);
			node->father->left = substitute;
			if (substitute != NULL)
			{
				substitute->color = node->color;
				substitute->father = node->father;
				substitute->side = node->side;
			}
			erase_node(&node);
			delete(node);
			return;
		}
	}
}

Node *search_node(Node *root, int num)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(root->num < num)
	{
		return search_node(root->right, num);
	}

	else if(root->num > num)
	{
		return search_node(root->left, num);
	}

	else
	{
		return root;
	}
	
	
}

void print_tree(Node *root, int counter)
{
	if(root == NULL)
	{
		return;
	}
	print_tree(root->left, counter+1);
	cout << endl;

	for(int i = 0; i < counter; i++)
	{
		cout << "  ";
	}

	cout << "|";
	cout << "Num: " << root->num << " C: ";
	if(root->color == BLACK)
	{
		cout << "BK";
	}
	else if(root->color == RED)
	{
		cout << "RD";
	}
	cout << endl;
	print_tree(root->right, counter+1);
}

Node* gen_node(int num)
{	
	Node *node = new Node;
	if(num != -1)
	{
		node->num = num;
		return node;
	}
	cout << "Digite o número: ";
	cin >> node->num;
	cout << endl;
	return node;
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

//verification para testar se é uma rotação dupla ou simples
void left_simple_rotation(Node **root, Node *node, int verification)
{
	Node *child = node->right;
	if(child == NULL)
	{
		cout << "Erro na rotação SE" << endl;
		return;
	}
	node->right->color = BLACK;
	node->color = RED;

	Node *left_child = child->left;
	node->right = left_child;
	
	if(left_child != NULL)
	{
		left_child->father = child;
		left_child->side = RIGHT;
	}
	
	child->left = node;

	Node *father = node->father;
	if(father == NULL)
	{
		*root = child;
		(*root)->side = ROOT;
		(*root)->father = NULL;
		(*root)->color = BLACK;
		node->father = child;
		if(node->father->left == node)
		{
			node->side = LEFT;
		}
		else
		{
			node->side = RIGHT;
		}
		return;
	}
	
	else
	{
		if(verification == 1)
		{
			father->left = child;
		}
		else
		{
			father->right = child;
		}
	}

	//mudar lado e pai do nó e do filho
	child->father = node->father;
	node->father = child;

	child->side = node->side;
	node->side = LEFT;
}

//verication para testar se é uma rotação dupla ou simples
void right_simple_rotation(Node **root, Node *node, int verification)
{
	Node *child = node->left;
	if(child == NULL)
	{
		cout << "Erro na rotação SD" << endl;
		return;
	}
	node->left->color = BLACK;
	node->color = RED;

	Node *right_child = child->right;
	node->left = right_child;
	
	
	if(right_child != NULL)
	{
		right_child->father = child;
		right_child->side = LEFT;
	}
	
	child->right = node;

	Node *father = node->father;
	if(father == NULL)
	{
		*root = child;
		(*root)->father = NULL;
		(*root)->side = ROOT;
		(*root)->color = BLACK;
		node->father = child;
		if(node->father->left == node)
		{
			node->side = LEFT;
		}
		else
		{
			node->side = RIGHT;
		}
		return;
	}

	else
	{
		if(verification == 1)
		{
			father->right = child;
		}
		else
		{
			father->left = child;
		}
	}
	
	//mudar lado e pai do nó e do filho
	child->father = node->father;
	node->father = child;

	child->side = node->side;
	node->side = RIGHT;
}

void right_double_rotation(Node **root, Node *node)
{
	if(node->left == NULL)
	{
		cout << "Erro na Rotação DD" << endl;
		return;
	}

	left_simple_rotation(root, node->left, 1);
	right_simple_rotation(root, node);
}

void left_double_rotation(Node **root, Node *node)
{
	if(node->right == NULL)
	{
		cout << "Erro na Rotação DE" << endl;
		return;
	}

	right_simple_rotation(root, node->right, 1);
	left_simple_rotation(root, node);
}

void insert_test(Node **root, Node *node)
{
	if(node == NULL || *root == NULL) 
	{
		return;
	}

	if((*root)->color == RED || node->father == NULL)
	{
		(*root)->color = BLACK;
		return;
	}
	//pai é preto
	if(node->father->color == BLACK)
	{
		return;
	}
	//pai e tio são vermelhos
	
	if(node->father->father->right != NULL && node->father->father->right->color == RED)
	{
		
		if(node->father->father->left != NULL && node->father->father->left->color == RED)
		{
			node->father->father->color = RED;
			node->father->father->right->color = BLACK;
			node->father->father->left->color = BLACK;
			return;
		}
	}
	//se pai for vermelho e tio for preto	
	if(node->father->color == RED && (node->father->father->right == NULL || node->father->father->left == NULL || node->father->father->right->color == BLACK || node->father->father->left->color == BLACK))
	{
		if(node->side == LEFT)
		{
			if(node->father->side == LEFT)
			{
				right_simple_rotation(root, node->father->father);
				return;
			}

			if(node->father->side == RIGHT)
			{
				left_double_rotation(root, node->father->father);
				return;
			}
		}

		if(node->side == RIGHT)
		{
			if(node->father->side == RIGHT)
			{
				left_simple_rotation(root, node->father->father);
				return;
			}

			if(node->father->side == LEFT)
			{
				right_double_rotation(root, node->father->father);

				return;
			}
		}
	}
}

void insert(Node **root, Node *new_node)
{
	if(new_node == NULL || *root == NULL)
	{
		return;
	}

	if((*root)->num > new_node->num)
	{
		if((*root)->left != NULL)
		{
			insert(&((*root)->left), new_node);
		}

		else
		{
			(*root)->left = new_node;
			new_node->side = LEFT;
			new_node->father = (*root);
		}
	}

	else
	{
		if((*root)->right != NULL)
		{
			insert(&((*root)->right), new_node);
		}

		else
		{
			(*root)->right = new_node;
			new_node->side = RIGHT;
			new_node->father = (*root);
		}
	}
}

void test(Node **root, Node *node)
{
	if(node == NULL)
	{
		return;
	}

	if(node->color == RED)
	{
		insert_test(root, node);
	}

	test(root, node->left);
	test(root, node->right);
}

void choice(Node **root, int op)
{
	switch (op)
	{
	case 1:
		print_tree(*root);
		break;
	case 2:
		Node *new_node;
		new_node = gen_node();
		if (*root == NULL)
		{
			*root = new_node;
		}
		else
		{
			insert(root, new_node);
		}
		//print antes do balanceamento
		print_tree(*root);
		insert_test(root, new_node);
		test(root, *root);
		break;
	case 3:
		int num;
		cout << "Digite o número do elemento que você quer remover: " << endl;
		cin >> num;
		Node *node;
		node = search_node(*root, num);
		Node *father;
		father = node->father;
		remove_node(root, node);
		break;
	case 0:
		cout << "Encerrando..." << endl;
		break;
	default:
		cout << "Número inválido" << endl;
		break;
	}
}

void menu(Node **root)
{
	int op = -1;
	while (op != 0)
	{
	
		cout <<" ***************************************" << endl;
		cout << "|\t\tMENU\t\t\t|" << endl;
		cout << "|\t\t\t\t\t|" << endl;
		cout << "|\t1 - Imprimir Árvore\t\t|" << endl;
		cout << "|\t2 - Adicionar Elemento\t\t|" << endl;
		cout << "|\t3 - Remover Elemento\t\t|" << endl;
		cout << "|\t0 - Finalizar Programa\t\t|" << endl;
		cout <<" ***************************************" << endl;
		
		cin >> op;
		choice(root, op);
	}
}


