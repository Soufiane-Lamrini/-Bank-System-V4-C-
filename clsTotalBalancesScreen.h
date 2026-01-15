#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtility.h"

using namespace std;



class clsTotalBalancesScreen : protected clsScreen
{
private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << setw(25) << left << "" << "| " << setw(17) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public:

    static void ShowTotalBalancesScreen()
    {

        vector < clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Fenetre  Total des Soldes";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Numero de Compte";
        cout << "| " << left << setw(40) << "Nome de Client";
        cout << "| " << left << setw(12) << "Solde";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;


        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtility::NumberToText(TotalBalances) << ")";
    }

};

