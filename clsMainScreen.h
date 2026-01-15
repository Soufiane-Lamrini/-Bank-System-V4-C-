#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "clsRegisterLoginScreen.h"
#include "clsCurrencyScreen.h"
#include "clsGlobal.h"
#include <iomanip>

using namespace std;


class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOption
    {

        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eShowRegisterLogin = 8, eShowCurrencyMenue = 9, eExit = 10

    };

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choisissez ce que vous voulez faire? [1 a 10] ";
		short Choice = clsInputValidation::ReadNumberBetween("Entrez un nombre entre 1 et 10? ", 1, 10);
		return Choice;
	}

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClient();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUserScreen::ShowManageUsersMenue();
    }

    static void _ShowRegisterLoginScreen()
    {
        clsRegisterLoginScreen::ShowLoginRegisterList();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _ShowCurrencyMenueScreen()
    {
        clsCurrencyScreen::ShowCurrencyMenue();
    }

    static void _PerformanceMainMenueOption(enMainMenueOption MainMenueOption)
    {

        switch (MainMenueOption)
        {
        case enMainMenueOption::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        }
        case enMainMenueOption::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowRegisterLogin:
        {
            system("cls");
            _ShowRegisterLoginScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowCurrencyMenue:
        {
            system("cls");
            _ShowCurrencyMenueScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eExit:
        {
            system("cls");
            _Logout();
            break;
        }
        }
    }


    public:

        static void ShowMainMenue()
        {

            system("cls");
            _DrawScreenHeader("\t\tEcran principal");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMenu principal\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Afficher la liste des clients.\n";
            cout << setw(37) << left << "" << "\t[2] Ajouter un nouveau client.\n";
            cout << setw(37) << left << "" << "\t[3] Supprimer le client.\n";
            cout << setw(37) << left << "" << "\t[4] Mettre a jour les infos client.\n";
            cout << setw(37) << left << "" << "\t[5] Trouver un client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Gerer les utilisateurs.\n";
            cout << setw(37) << left << "" << "\t[8] Register Login.\n";
            cout << setw(37) << left << "" << "\t[9] Afficher l'ecran de devise.\n";
            cout << setw(37) << left << "" << "\t[10] Deconnexion.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerformanceMainMenueOption((enMainMenueOption)_ReadMainMenueOption());
        }

};

