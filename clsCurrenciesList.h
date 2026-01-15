#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrenciesList : protected clsScreen
{
private:

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(15) << left << Currency.CurrencyCode();
        cout << "| " << setw(30) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
	}

public:

    static void ShowCurrenciesList()
    {
       
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        string Title = "\t Liste des Devises";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Devise(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Pays";
        cout << "| " << left << setw(15) << "Code de devise";
        cout << "| " << left << setw(30) << "Nom de devise";
        cout << "| " << left << setw(10) << "Taux de devise";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\tAucun devise disponible dans le systeme !";
        }
        else
        {
            for (clsCurrency Currency : vCurrencies)
            {
                _PrintCurrencyRecord(Currency);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

