#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsLogTransferScreen.h"
#include "clsInputValidation.h"


using namespace std;


class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransfer, eShowTransferLog = 5, eShowMainMenue = 6
    };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choisissez ce que vous voulez faire? [1 a 4] ";
        short Choice = clsInputValidation::ReadNumberBetween("Entrez un nombre entre 1 et 4? ", 1, 5);
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen()
    {
        clsLogTransferScreen::ShowLoginRegisterList();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
        }
        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
        } 
        case enTransactionsMenueOptions::eShowTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:

    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }
            
        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Retirer.\n";
        cout << setw(37) << left << "" << "\t[3] Total des soldes.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] List des transferes .\n";
        cout << setw(37) << left << "" << "\t[6] Menu Principale.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());

    }
};

