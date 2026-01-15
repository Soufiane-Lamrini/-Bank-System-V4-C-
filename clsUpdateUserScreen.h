#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"


class clsUpdateUserScreen : protected clsScreen
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

        cout << "\nAjouter nouveau client? ";
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

        cout << "\nAcces a voir l'historique de connexion? ";
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {
            Permission += clsUser::enPermissions::pManageUsers;
        }

        return Permission;
    }

public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tMettre a jour les infos d'utilisateur");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsString::Trim(clsInputValidation::ReadString());

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nNom d'utilisateur pas trouve, Saisir un autre: ";
            UserName = clsString::Trim(clsInputValidation::ReadString());
        }

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);
        cout << "\Etes-vous sure pour modifier ce utilisateur o/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {

            cout << "\n\nMettre a jour utilisateur:";
            cout << "\n____________________________\n";

            _ReadUserInfo(User);

            clsUser::enSaveResults SaveResult;

            SaveResult = User.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSaveSucceeded:
            {
                cout << "\nUtilisateur mettre a jour avec succes :-)\n";
                _PrintUser(User);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError L'utilisateur n'a pas pu etre enregistre car son champ est vide.";
                break;

            }
            }
        }
        else {
            cout << "\nMise à jour annulée.\n";
            return;
        }
    };

};

