#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"


class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidation::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidation::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidation::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidation::ReadString();

        cout << "\nEnter Password: ";
        User.PinCode = clsInputValidation::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

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

    static int _ReadPermissionsToSet()
    {
        int Permission = 0;
        char Answer = 'n';

        cout << "\nSouhaitez-vous accorder un acces complet ? o/n ?";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            return -1;
        }
        cout << "\nSouhaitez-vous donner acces a : \n";
        cout << "\nAfficher Client List? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pListClients;
        }

        cout << "\njouter nouveau client? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nSupprimer Client? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pDeleteClient;
        } 
        
        cout << "\nMettre a jour les info d'un Client? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pUpdateClients;
        } 
        
        cout << "\nTrouve un Client? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pFindClient;
        }
        
        cout << "\nAcces a transaction menu? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pTranactions;
        }

        cout << "\nAcces a gere utilisateur menu? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nAcces a voir l'hitorique de connexion? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pLoginRegister;
        }

        return Permission;
    }

    public:

        static void ShowAddNewUserScreen()
        {
            _DrawScreenHeader("\t Add New User Screen");

            string UserName = "";

            cout << "\nPlease Enter UserName: ";
            UserName = clsInputValidation::ReadString();
            while (clsUser::IsUserExist(UserName))
            {
                cout << "\nUserName Is Already Used, Choose another one: ";
                UserName = clsInputValidation::ReadString();
            }

            clsUser NewUser = clsUser::GetAddNewClientObject(UserName);

            _ReadUserInfo(NewUser);

            clsUser::enSaveResults SaveResult;

            SaveResult = NewUser.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSaveSucceeded:
            {
                cout << "\nUtilisateur ajoutee avec succes :-)\n";
                _PrintUser(NewUser);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError L'utilisateur n'a pas pu etre enregistre car son champ est vide.";
                break;

            }
            case clsUser::enSaveResults::svFaildAccountNumberExists:
            {
                cout << "\nErreur : l’utilisateur n’a pas pu etre enregistre car le nom d’utilisateur est deja utilise !\n";
                break;

            }
            }


        }

};

