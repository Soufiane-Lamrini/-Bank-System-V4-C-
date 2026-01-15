#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;


class clsDepositScreen : protected clsScreen
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

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t Ecran de depot");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nCe numero de compte pas trouve, Saisir un autre: ";
            AccountNumber = clsInputValidation::ReadString();
        };

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        double Amount = 0;
        cout << "S'il vous plait saisir le montant que tu veux deposer? ";
        Amount = clsInputValidation::ReadNumber<double>();


        cout << "\nEtes-vous sur de vouloir faire cette operation o/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {

            Client.Deposit(Amount);

            cout << "\nOperation fait avec succes :-)\n";

            cout << "\nNouveau Solde est: " << Client.AccountBalance;
        }
        else
        {
            cout << "\nErreur : Operation echoue\n";
        };
        
    };



};

