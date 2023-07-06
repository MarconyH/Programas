#include <iostream>
#include <time.h>

using namespace std;

class date
{
    public:
        int day;
        int month;
        int year;
        void print_date()
        {
            if(this->day < 10)
            {
                cout <<  "0" << this->day << "/";
            }
            
            else
            {
                cout << this->day << "/";
            }
            
            if (this->month < 10)
            {
                cout << "0" << this->month << "/";
            }
            
            else
            {
                cout << this->month << "/";
            }
            cout << this->year;
        }

	int sum()
	{
		int sum_day = this->day + this->month*30 + this->year*365;
		return sum_day;	
	}
};

class content
{
	public:
		float num;
		string name;
		string cpf;
		int age;
		date birth;
		char v[55] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ \0"};
		char in[12] = {"0123456789\0"};
		int identifier = -1;
};

class tree
{
	public:
		content data;
		tree *left = NULL;
		tree *right = NULL;
};

void insert_gen(content *data);
void random_gen(content *data);

void print_tree(tree *root, int counter = 0);
void print_tree_bf(tree *root, int counter = 0);

void insert(tree **root, int cod = 0, tree *new_element = NULL);

tree *bigger(tree *root);
tree *smaller(tree *root);

float *sum(tree *root, float node[2]);
float average(float sum_tree, int size);

tree *search_node(tree *root, int num = -1);
int tall(tree *root, int size = 0);
int balancing_factor(tree *root);

tree *search_father_node(tree *root, int num = -1);
void switch_node(tree **root, tree *node_1, tree *node_2);

void left_simple_rotation(tree **root, tree *node, int verification = 0);
void right_simple_rotation(tree **root, tree *node, int verification = 0);

void right_double_rotation(tree **root, tree *node);
void left_double_rotation(tree **root, tree *node);

void balancing(tree **root, tree *node);

void menu(tree **root);
void choice(int op, tree **root);

int main()
{
	tree *root = NULL;
	srand(time(NULL));

	menu(&root);

	return 0;
}

void insert_gen(content *data)
{
	cout << "Digite o seu número: "; 
	cin >> data->num;

	cout << "Digite o seu nome: ";
	cin >> data->name;

	cout << "Digite o seu CPF: ";
	cin >> data->cpf;

	cout << "Digite a sua idade: ";
	cin >> data->age;

	cout << "Digite a data do seu nascimento: " << endl;

	cout << "Dia: ";
	cin >> data->birth.day;
	cout << "Mês: ";
	cin >> data->birth.month;
	cout << "Ano: ";
	cin >> data->birth.year;
	
}

void random_gen(content *data)
{
	int execution = rand()%17;
	execution += 4;
	char *name = new char[execution+1];	
	for(int i = 0; i < execution; i++)
	{
		name[i] = data->v[rand()%54];
	}
	data->name = name;
	delete name;

	char in[12];
	for(int i = 0; i < 11; i++)
	{
		in[i] = data->in[rand()%10];
	}
	data->cpf = in;
	
	data->num = rand()%1001;

	data->age = rand()%101;

	data->birth.day = rand()%31;
	data->birth.month = rand()%13;
	data->birth.year = rand()%2024;
}

void print_tree(tree *root, int counter)
{
	if (root != NULL)
        {
	        print_tree(root->left, counter+1);
        	cout << endl;
                
	        for (int i = 0; i < counter; i++)
       		{
	        	cout << "  ";
       		}
                
	        cout << "|";
        	cout << "Num: " << root->data.num << endl;
      	 	print_tree(root->right, counter+1);
        }
            
        else
      	{
              	return;
     	}
}

void print_tree_bf(tree *root, int counter)
{
	if (root != NULL)
        {
	        print_tree_bf(root->left, counter+1);
        	cout << endl;
                
	        for (int i = 0; i < counter; i++)
       		{
	        	cout << "  ";
       		}
                
	        cout << "|";
        	cout << "FB: " << balancing_factor(root) << endl;
      	 	print_tree_bf(root->right, counter+1);
        }
            
        else
      	{
              	return;
     	}
}

void insert(tree **root, int cod, tree *new_element)
{ 

	if(*root == NULL)
	{
		root = new tree*;
		if(cod == 0)
		{
			insert_gen(&((*root)->data));
		}

		if(cod == 1)
		{
			random_gen(&((*root)->data));
		}
	}

	if(new_element == NULL)
	{
		new_element = new tree;
		if(cod == 0)
		{
			insert_gen(&new_element->data);
		}

		if(cod ==1)
		{
			random_gen(&new_element->data);
		}
	}

	if((*root)->data.num > new_element->data.num)
	{

		if((*root)->left != NULL)
		{
			insert(&((*root)->left), 0, new_element);
		}

		else
		{
			(*root)->left = new_element;
			return;
		}
	}

	else
	{
		if((*root)->right != NULL)
		{
			insert(&((*root)->right), 0, new_element);
		}

		else
		{
			(*root)->right = new_element;
			return;
		}
	}
}

tree *bigger(tree *root)
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

tree *smaller(tree *root)
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

float *sum(tree *root, float node[2])
{
	if(root == NULL)
	{
		return NULL;
	}
	
	node[0] = root->data.num; //Conteúdo
	node[1] = 1; //Tamanho
	
	if(root->left != NULL)
	{
		float *left = sum(root->left, node);
		node[0] += left[0];
		node[1] += left[1];
	}

	if(root->right != NULL)
	{
		float *right = sum(root->right, node);
		node[0] += right[0];
		node[1] += right[1];
	}

	return node;
}

float average(float sum_tree, int size)
{
	return sum_tree/size;
}

tree *search_node(tree *root, int num)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(num == -1)
	{
		cout << "Digite o número procurado: ";
		cin >> num;
	}

	if(root->data.num < num)
	{
		if(root->right != NULL)
		{
			return search_node(root->right, num);
		}
	}

	else if(root->data.num > num)
	{
		if(root->left != NULL)
		{
			return search_node(root->left, num);
		}
	}

	else
	{
		return root;
	}	
}

tree *search_father_node(tree *root, int num)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(num == -1)
	{
		cout << "Digite o número procurado: ";
		cin >> num;
	}

	if(root->right != NULL && root->right->data.num == num)
	{
		root->data.identifier = 1;
		return root;
	}

	if(root->left != NULL && root->left->data.num == num)
	{
		root->data.identifier = 0;
		return root;
	}

	if(root->data.num < num)
	{
		return search_father_node(root->right, num);
	}

	else
	{
		return search_father_node(root->left, num);
	}	
}

int tall(tree *root, int size)
{
	if(root == NULL)
	{
		return 0;
	}
	
	int right = 1;
	right += tall(root->right, size+1);
	int left = 1;
	left += tall(root->left, size+1);

	if(right > left)
	{
		return right;
	}

	else
	{
		return left;
	}
}

int balancing_factor(tree *root)
{
	if(root == NULL)
	{
		return 0;
	}

	return tall(root->left) - tall(root->right);
}

void switch_node(tree **root, tree *node_1, tree *node_2)
{
	if(*root == NULL || node_1 == NULL || node_2 == NULL)
	{
		return;
	}

	if(node_1 == node_2)
	{
		tree *aux = node_1->left;
		node_1->left = node_1->right;
		node_1->right = aux;
		return;
	}

	if(*root == node_1)
	{
		if(node_2->data.identifier == 0)
		{
			*root = node_2->left;
			node_2->left = node_1;		
		}

		else
		{
			*root = node_2->right;
			node_2->right = node_1;
		}
		return;
	}

	if(*root == node_2)
	{
		if(node_1->data.identifier == 0)
		{
			*root = node_1->left;
			node_1->left = node_2;		
		}

		else
		{
			*root = node_1->right;
			node_1->right = node_2;
		}
		return;
	}

	if(node_1->data.identifier == 0)
	{
		tree *aux = node_1->left;
		if(node_2->data.identifier == 0)
		{
			node_1->left = node_2->left;
			node_2->left = aux;
		}

		else
		{
			node_1->left = node_2->right;
			node_2->right = aux;
		}
		return;
	}

	else
	{
		tree *aux = node_1->right;
		if(node_2->data.identifier == 0)
		{
			node_1->right = node_2->left;
			node_2->left = aux;
		}

		else
		{
			node_1->right = node_2->right;
			node_2->right = aux;
		}
		return;
	}

}

void left_simple_rotation(tree **root, tree *node, int verification)
{
	tree *child = node->right;
	if(child == NULL)
	{
		cout << "Erro na Rotação" << endl;
		return;
	}
	
	tree *left_child = child->left;
	node->right = left_child;
	child->left = node;

	tree *father = search_father_node(*root, node->data.num);
	if(father == NULL)
	{
		*root = child;
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
}

void right_simple_rotation(tree **root, tree *node, int verification)
{
	tree *child = node->left;
	if(child == NULL)
	{
		cout << "Erro na Rotação" << endl;
		return;
	}
	
	tree *right_child = child->right;
	node->left = right_child;
	child->right = node;

	tree *father = search_father_node(*root, node->data.num);
	if(father == NULL)
	{
		*root = child;
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
}

void right_double_rotation(tree **root, tree *node)
{
	if(node->left == NULL)
	{
		cout << "Erro na Rotação" << endl;
		return;
	}	

	left_simple_rotation(root, node->left, 1);
	right_simple_rotation(root, node);
}

void left_double_rotation(tree **root, tree *node)
{
	if(node->right == NULL)
	{
		cout << "Erro na Rotação" << endl;
		return;
	}	

	right_simple_rotation(root, node->right, 1);
	left_simple_rotation(root, node);
}

void balancing(tree **root, tree *node)
{
	if(node == NULL)
	{
		return;
	}

	if(balancing_factor(node) <= -2) //rotação para esquerda
	{
		if(balancing_factor(node->right) < 1) //rotação simples
		{
			left_simple_rotation(root, node);
		}

		else //rotação dupla
		{
			left_double_rotation(root, node);
		}
	}

	if(balancing_factor(node) >= 2) //rotação para direita
	{
		if(balancing_factor(node->left) > -1) //rotação simples
		{
			right_simple_rotation(root, node);
		}

		else //rotação dupla
		{
			right_double_rotation(root, node);
		}
	}
}

void menu(tree **root)
{
	int op;
	do
	{
		cout <<" ***************************************" << endl;
		cout << "|\t\tMENU\t\t\t|" << endl;
		cout << "|\t\t\t\t\t|" << endl;
		cout << "|\t1 - Adicionar Elemento\t\t|" << endl;
		cout << "|\t2 - Aleatorizar Elementos\t|" << endl;
		cout << "|\t3 - Imprimir Árvore\t\t|" << endl;
		cout << "|\t4 - Imprimir Maior Elemento\t|" << endl;
		cout << "|\t5 - Imprimir Menor Elemento\t|" << endl;
		cout << "|\t6 - Imprimir Média dos Elementos|" << endl;
		cout << "|\t7 - Imprimir Altura de um Nó\t|" << endl;
		cout << "|\t8 - Balancear Elemento\t\t|" << endl;
		cout << "|\t9 - Imprimir FB Árvore\t\t|" << endl;
		cout << "|\t10 - Fator de Balanceamento\t|" << endl;
		cout << "|\t0 - Finalizar Vendas\t\t|" << endl;
		cout <<" ***************************************" << endl;
	
		cin >> op;
		
		choice(op, root);
	}while(op != 0);
}

void choice(int op, tree **root)
{
	switch(op)
	{
		case 1:
			if(*root == NULL)
			{
				*root = new tree;
				insert_gen(&(*root)->data);
				break;
			}
			insert(root);
			break;
			
		case 2:
			cout << "Digite quantos elementos você quer adicionar: ";
			int quantity;
			cin >> quantity;
			for(int i = 0; i < quantity; i++)
			{
				if(*root == NULL)
				{
					*root = new tree;
					random_gen(&(*root)->data);
					i++;
				}
				insert(root, 1);
			}
			break;
			
		case 3:
			print_tree(*root);	
			break;
			
		case 4:
			tree *bigger_node;
			bigger_node = bigger(*root);
			if(bigger_node != NULL)
			{
				cout << bigger_node->data.num << endl;
			}

			else
			{
				cout << "Árvore vazia" << endl;
			}
			break;
			
		case 5:
			tree *smaller_node; 
			smaller_node = smaller(*root);
			if(smaller_node != NULL)
			{
				cout << smaller_node->data.num << endl;
			}

			else
			{
				cout << "Árvore vazia" << endl;
			}
			break;

		case 6:
			float *elements;
		        elements = new float[2];
			elements[0] = 0;
			elements[1] = 0;
			elements = sum(*root, elements);
		
			if(elements != NULL)
			{
				cout << average(elements[0], elements[1]) << endl;
			}
			
			else
			{
				cout << "Árvore vazia" << endl;
			}
			delete elements;
			break;

		case 7:
			int tall_tree;
			tall_tree = tall(search_node(*root));
			cout << tall_tree-1 << endl;
			break;

		case 8:
			balancing(root, search_node(*root));
			break;
		
		case 9:
			print_tree_bf(*root);
			break;

		case 10:
			tree *node;
			node = search_node(*root);
			cout << "Fator de Balanceamento: " << balancing_factor(node) << endl;
			break;

		case 0:
			cout << "Encerrando Programa...";
			break;

		default:
			cout << "Valor Inválido" << endl;
			break;

	}		
}

