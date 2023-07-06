#include "binary_tree.h"

/* Código feito tentando usar comandos de programação orientada a objetos para ter certeza
que ninguém irá pensar que foi copiado
*/


void escolha(int qual, group *galera);

int main ()
{
    int op;
    group arvores;
    arvores.inicialize();
    string slasofunciona;
    srand(time(NULL));
    
    do
    {
        arvores.menu();
        cin >> op;

        //testa se o valor inserido vai exibir uma falha, quando uma letra é inserida no op por exemplo
        //retorna "true"ou "false"
        if (cin.fail())
        {
            op = -1;
            //limpa a falha do cin
            cin.clear();
        }
        //limpa o buffer de entrada
        cin.ignore();

        switch (op)
        {
        case 1:
            if(arvores.arv_junta == NULL)
            {
                cout << "Arvore Brasil: " << endl;
                arvores.imprimir_tree(arvores.arv_brasil, 0);
                
                cout << "Arvore Argentina: " << endl;
                arvores.imprimir_tree(arvores.arv_arg, 0);
            }
            
            else
            {
                cout << "Arvore Brasil: " << endl;
                arvores.imprimir_tree(arvores.arv_brasil, 0);
                
                cout << "Arvore Argentina: " << endl;
                arvores.imprimir_tree(arvores.arv_arg, 0);
                
                cout << "Arvore dos Anos Passados: " << endl;
                arvores.imprimir_tree(arvores.arv_junta, 0);
            }
            
            break;
            
        case 2:
            int qual;
                cout << "1 - Passageiro do Brasil" << endl;
                cout << "2 - Passageiro da Argentina" << endl;
                cin >> qual;
                escolha(qual, &arvores);
            break;

        case 3:
            cout << "Digite o destino: ";
            cin >> ws;
            getline(cin, slasofunciona);
            
            cout << "Brasil: " << endl;
            arvores.busca(slasofunciona, arvores.arv_brasil);
            
            cout << "Argentina: " << endl;
            arvores.busca(slasofunciona, arvores.arv_arg);
            
            cout << "Passagens de anos passados: " << endl;
            arvores.busca(slasofunciona, arvores.arv_junta);
            break;
            
        case 4:
            cout << "Brasil: " << endl;
            if(arvores.arv_brasil != NULL)
            {
                arvores.arv_brasil->relatorio(&(arvores.arv_brasil), &(arvores.arv_brasil->relator));            
                cout << "Quantidade total de passagens vendidas: " <<arvores.arv_brasil->relator.quant_to << endl;
                cout << "Valor total arrecadado: " << arvores.arv_brasil->relator.valor_to << endl;
                arvores.arv_brasil->relator.quant_to = 0;
                arvores.arv_brasil->relator.valor_to = 0;
            }
            
            else
            {
                cout << "NULL" << endl;
            }

            cout << "Argentina: " << endl;
            if(arvores.arv_arg != NULL)
            {
                arvores.arv_arg->relatorio(&(arvores.arv_arg), &(arvores.arv_arg->relator));
                cout << "Quantidade total de passagens vendidas: " <<arvores.arv_arg->relator.quant_to << endl;
                cout << "Valor total arrecadado: " << arvores.arv_arg->relator.valor_to << endl;
                arvores.arv_arg->relator.quant_to = 0;
                arvores.arv_arg->relator.valor_to = 0;
            }

            else 
            {
                cout << "NULL" << endl;
            }
            break;
            
        case 5:
            arvores.juntar();
            arvores.arv_brasil = NULL;
            arvores.arv_arg = NULL;
            break;
        case 0:
            cout << "Encerrando programa...";
            break;
        default:
            cout << "Opcao Invalida" << endl;
            break;            
        }
    } while (op != 0);
    
    
    
    return 0;
}


void escolha(int qual, group *galera)
{
    switch (qual)
    {
    case 1:
        galera->registrar(&(galera->arv_brasil));
        break;
    case 2:
        galera->registrar(&(galera->arv_arg));
        break;
    default:
        break;
    }
}