#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsInputValidation.h"

using namespace std;


class clsManageUserScreen : protected clsScreen
{
private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _ReadManageUserMenueOptions()
    {
        cout << setw(37) << left << "" << "Choisissez ce que vous voulez faire? [1 a 6] ";
        short Choice = clsInputValidation::ReadNumberBetween("Entrez un nombre entre 1 et 6? ", 1, 6);
        return Choice;
    };

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsUsersListScreen::ShowClientsList();

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::DeleteUser();
    }
    
    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:


    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pManageUsers))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Menu Gerer Utilisateur \n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List des utilisateur.\n";
        cout << setw(37) << left << "" << "\t[2] Ajouter Nouvaeu utilisateur.\n";
        cout << setw(37) << left << "" << "\t[3] Supprimer utilisateur.\n";
        cout << setw(37) << left << "" << "\t[4] Mettre a jour l'utilisateur.\n";
        cout << setw(37) << left << "" << "\t[5] Trouver un utilisateur.\n";
        cout << setw(37) << left << "" << "\t[6] Menu principale.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUserMenueOptions());
    }


};

