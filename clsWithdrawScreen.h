#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;


class clsWithdrawScreen : protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";

        cout << "\nS'il vous plaits entrez un numero de compte: ";
        AccountNumber = clsInputValidation::ReadString();

        return AccountNumber;
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t Ecran de Retirer");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nCe numero de compte pas trouve, Saisir un autre: ";
            AccountNumber = clsInputValidation::ReadString();
        };

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        double Amount = 0;
        cout << "S'il vous plait saisir le montant que tu veux retirer? ";
        Amount = clsInputValidation::ReadNumber<double>();

        if (Amount > Client.AccountBalance)
        {
            cout << "\nRetrait impossible, solde insuffisant !\n";
            cout << "\nAmout to withdraw is : " << Amount;
            cout << "\nVotre solde est : " << Client.AccountBalance;
        }
        else
        {
            cout << "\nEtes-vous sur de vouloir faire cette operation o/n? ";

            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'o' || Answer == 'O')
            {

                if (Client.Withdraw(Amount))

                {
                    cout << "\nOperation fait avec succes :-)\n";

                    cout << "\nNouveau Solde est: " << Client.AccountBalance;
                }
                else
                {
                    cout << "\nErreur : Operation annule\n";
                };
            }
        }
    }

};

