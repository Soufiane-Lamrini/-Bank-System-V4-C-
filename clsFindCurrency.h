#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"
using namespace std;

class clsFindCurrency : protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCarte de devise:";
        cout << "\n________________________________";
        cout << "\nPays              : " << Currency.Country();
        cout << "\nCode de devise    : " << Currency.CurrencyCode();
        cout << "\nNom de devise     : " << Currency.CurrencyName();
        cout << "\nTaux              : " << Currency.Rate();
        cout << "\n________________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nDevise trouve :-)\n";
            _PrintCurrency(Currency);
        }
        else {
            cout << "\nDevise pas trouve :-(\n";
        }
    }

public:


    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\tTrouve devise");



        short Option;
        cout << "S'il vous plait choisis l'option de recherche: [1] Par code  [2] Par pays" << endl;
        Option = clsInputValidation::ReadNumberBetween("Saisir un nombre entre 1 et 2", 1, 2);

        if (Option == 1)
        {
            string Code = "";

            cout << "\nS'il vous plaits entrez le code de devise: ";
            Code = clsInputValidation::ReadString();

            clsCurrency Currency = clsCurrency::FindByCode(Code);
            _ShowResults(Currency);
        }
        else
        {
            string Country = "";

            cout << "\nS'il vous plaits entrez le pays de devise: ";
            Country = clsInputValidation::ReadString();

            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);

        }


    };

};

