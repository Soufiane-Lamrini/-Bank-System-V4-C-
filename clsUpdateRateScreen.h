#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"


using namespace std;

class clsUpdateRateScreen : public clsScreen
{

private:

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidation:: ReadNumber<float>("Veuillez saisir un nombre");
        return NewRate;
    }

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

public:

    static void ShowUpdateCurrencyScreen()
    {
        _DrawScreenHeader("Mettre a jour le taux de devise");

        string Code = "";

        cout << "\nS'il vous plaits entrez le code de devise: ";
        Code = clsInputValidation::ReadString();

        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nDevise est pas trouve, saisir un autre code: ";
            Code = clsInputValidation::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);
        _PrintCurrency(Currency);

        cout << "\nEtes-vous sure pour modifier ce taux devise o/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'o' || Answer == 'n')
        {

            cout << "\n\nMettre a jour le taux:";
            cout << "\n________________________\n";

            Currency.UpdateRate(_ReadRate());

            cout << "\nTaux devise est mit a jour avec succes :-)\n";
            _PrintCurrency(Currency);;

        }
    };
};

