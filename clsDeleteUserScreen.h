#pragma once


#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"

using namespace std;


class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintClient(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nAcc. Number : " << User.UserName;
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nPassword    : " << User.PinCode;
        cout << "\nPermission     : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:


    static void DeleteUser()
    {
        _DrawScreenHeader("\tSuprimer Utilisateur Fenetre");

        string UserName = "";


        cout << "\nS'il vous plaits entrez le nome d'utilisateur: ";
        UserName = clsInputValidation::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nCe nome pas trouve, Saisir un autre: ";
            UserName = clsInputValidation::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintClient(User);

        cout << "\nEtes-vous sur de vouloir supprimer ce client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (User.Delete())
            {

                cout << "\nUtilisateur supprime avec succes :-)\n";
                _PrintClient(User);

            }
            else
            {
                cout << "\nErreur : l''utilisateur n'a pas ete supprime\n";
            }
        }
    }

};

