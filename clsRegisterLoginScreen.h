#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"


using namespace std;


class clsRegisterLoginScreen : protected clsScreen
{
private:

    static void PrintLoginRecordLine(clsUser::stLoginRegister LoginRegister)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << LoginRegister.DateTime;
        cout << "| " << setw(25) << left << LoginRegister.UserName;
        cout << "| " << setw(20) << left << LoginRegister.Password;
        cout << "| " << setw(12) << left << LoginRegister.Permission;

    };

public:


    static void ShowLoginRegisterList()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsUser::stLoginRegister> vLoginRegister = clsUser::_LoadLoginRegisterDataFromFile();

        string Title = "\t Liste de connexion enregistrer";
        string SubTitle = "\t    (" + to_string(vLoginRegister.size()) + ") connexion(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "La Date";
        cout << "| " << left << setw(25) << "Nom d'utilisateur";
        cout << "| " << left << setw(20) << "Mot de passe";
        cout << "| " << left << setw(12) << "Permission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



        if (vLoginRegister.size() == 0)
        {
            cout << "\t\t\t\tAucun connexion disponible dans le systeme !";
        }
        else
        {
            for (clsUser::stLoginRegister Login : vLoginRegister)
            {
                PrintLoginRecordLine(Login);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    };


};

