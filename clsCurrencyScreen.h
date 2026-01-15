#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidation.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrency.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalucatorScreen.h"

using namespace std;


class clsCurrencyScreen : protected clsScreen
{
private:
    enum enCurrencyOption
    {

        eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalicator = 4, eRetour = 5

    };

    static short _ReadCurrencyOption()
    {
        cout << setw(37) << left << "" << "Choisissez ce que vous voulez faire? [1 a 9] ";
        short Choice = clsInputValidation::ReadNumberBetween("Entrez un nombre entre 1 et 8? ", 1, 5);
        return Choice;
    }

    static  void _GoBackToCurrencyMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrencyMenue();
    }

    static void _ShowListCurrencyScreen()
    {
        clsCurrenciesList::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrency::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateScreen()
    {
        clsUpdateRateScreen::ShowUpdateCurrencyScreen();
    }
    static void _ShowCalCurrencyScreen()
    {
        clsCurrencyCalucatorScreen::ShowCurrencyCalucatorScreen();
    }
   

    static void _PerformanceMainMenueOption(enCurrencyOption CurrencyOption)
    {

        switch (CurrencyOption)
        {
        case enCurrencyOption::eListCurrency:
        {
            system("cls");
            _ShowListCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;

        }
        case enCurrencyOption::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        }
        case enCurrencyOption::eUpdateRate:
        {
            system("cls");
            _ShowUpdateScreen();
            _GoBackToCurrencyMenue();
            break;
        }
        case enCurrencyOption::eCurrencyCalicator:
        {
            system("cls");
            _ShowCalCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        }
        case enCurrencyOption::eRetour:
        {

        }
        }
    }


public:

    static void ShowCurrencyMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tEcran De Devise");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMenu de devise\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Liste des devises\n";
        cout << setw(37) << left << "" << "\t[2] Trouve Devise.\n";
        cout << setw(37) << left << "" << "\t[3] Mettre a jour Taux\n";
        cout << setw(37) << left << "" << "\t[4] Calculateur de devises\n";
        cout << setw(37) << left << "" << "\t[5] Menu Principale\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformanceMainMenueOption((enCurrencyOption)_ReadCurrencyOption());
    }

};

