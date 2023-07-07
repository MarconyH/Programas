#ifndef LOGIN_REGISTRATION_H
#define LOGIN_REGISTRATION_H

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


void menu()
{
    cout << endl << "|\t**********************************\t|" << endl;
    cout << "|\t\t\tMENU\t\t\t|" << endl;
    cout << "|\t1-Login\t\t\t\t|" << endl;
    cout << "|\t2-Registrar\t\t\t\t|" << endl;
    cout << "|\t3-Esqueceu a Senha\t\t\t|" << endl;
    cout << "|\t0-Sair\t\t\t\t\t|" << endl;
    cout << "|\t**********************************\t|" << endl;
    cout << "Digite a opcao desejada: " << endl;
}




void choice(int opt)
{
    switch (opt)
    {
    case 1:
        login();
        break;
    
    case 2:
        registration();
        break;
    
    case 3:
        forgot_password();
        break;
    
    case 0:
        cout << "Encerrando programa...";
        break;

    default:
        cout << "Valor invalido" << endl;
        break;
    }
}

void login()
{

}

void registration()
{

}

void forgot_password()
{
    
}


#endif