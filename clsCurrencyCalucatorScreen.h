#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyCalucatorScreen : protected clsScreen
{
private:

    static float _ReadAmount()
    {
        cout << "\nVeuillez entrer le montant a convertir : ";
        float montant = 0;

        montant = clsInputValidation::ReadNumber<float>();
        return montant;
    }

    static clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode = "";
        cout << Message << endl;
        CurrencyCode = clsInputValidation::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nDevise introuvable, veuillez saisir un autre code : ";
            CurrencyCode = clsInputValidation::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        return Currency;
    }
    static void _PrintCurrencyCard(clsCurrency Currency,string message)
    {
        cout << "\n=== " << message << "===\n ";
        cout << "\nPays               : " << Currency.Country();
        cout << "\nCode               : " << Currency.CurrencyCode();
        cout << "\nNom                : " << Currency.CurrencyName();
        cout << "\nTaux (1 USD = ?)   : " << Currency.Rate();
        cout << "\n===================================\n";

    }

    static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode() << endl;

    }
public:

    static void ShowCurrencyCalucatorScreen()
    {

        char Answer = 'o';

        while (Answer == 'o' || Answer == 'O')
        {
            system("cls");

            _DrawScreenHeader("\tChange devise");

            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
            float Amount = _ReadAmount();

            _PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);


            cout << "Etes-vous sure tu veux encore faire un autre operation" << endl;

            cin >> Answer;

        }
       
    }
};

