#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:

    static  void PrintUsersRecordLine(clsUser Users)
    {  
        cout << setw(8) << left << "" << "| " << setw(19) << left << Users.UserName;
        cout << "| " << setw(25) << left << Users.FullName();
        cout << "| " << setw(12) << left << Users.Phone;
        cout << "| " << setw(20) << left << Users.Email;
        cout << "| " << setw(10) << left << Users.PinCode;
        cout << "| " << setw(12) << left << Users.Permissions;

    }

public:


    static void ShowClientsList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t Liste d'utilisateur";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") user(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(19) << "Nome d'utilisateur";
        cout << "| " << left << setw(20) << "Nome Complet";
        cout << "| " << left << setw(12) << "Tele";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << " Code Pin";
        cout << "| " << left << setw(12) << "Solde";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tAucun client disponible dans le systeme !";
        }
        else
        {
            for (clsUser Users : vUsers)
            {
                PrintUsersRecordLine(Users);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

