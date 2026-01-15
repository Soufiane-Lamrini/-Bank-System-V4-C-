#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"


class clsFindUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.PinCode;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tTrouve Utilisateur");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsString::Trim(clsInputValidation::ReadString());

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nNom d'utilisateur pas trouve, Saisir un autre: ";
            UserName = clsString::Trim(clsInputValidation::ReadString());
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            cout << "\nUtilisateur trouve :-)\n";
        }
        else
        {
            cout << "\nUtilisateur pas trouve :-(\n";
        }
        _PrintUser(User);

        
    };

};

