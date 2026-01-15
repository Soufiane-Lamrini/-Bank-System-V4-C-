#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidation.h"

using namespace std;


class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nNome Complet      : " << Client.FullName();
        cout << "\nNumero de compte  : " << Client.AccountNumber();
        cout << "\nSolde             : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumberFrom()
    {
        string AccountNumber = "";

        cout << "\nVeuillez entrer le numero de compte **Source** (From) : ";
        AccountNumber = clsInputValidation::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nCe numero de compte pas trouve, Saisir un autre: ";
            AccountNumber = clsInputValidation::ReadString();
        };

        return AccountNumber;
    }

    static string _ReadAccountNumberTo()
    {
        string AccountNumber = "";

        cout << "\nVeuillez entrer le numero de compte **Destination** (To) : ";
        AccountNumber = clsInputValidation::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nCe numero de compte pas trouve, Saisir un autre: ";
            AccountNumber = clsInputValidation::ReadString();
        };

        return AccountNumber;
    }

    static double ReadAmount(clsBankClient SourceClient)
    {
        double Amount;

        cout << "\nS'il vous plait saisir le montant que tu veux transferer? \n";

        Amount = clsInputValidation::ReadNumber<double>();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nTransfere impossible, solde insuffisant !\n";
            Amount = clsInputValidation::ReadNumber<double>();
        }
        return Amount;
    }


public:


    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t Ecran de transfer");



        clsBankClient ClientFrom = clsBankClient::Find(_ReadAccountNumberFrom());

        _PrintClient(ClientFrom);


        clsBankClient ClientTo = clsBankClient::Find(_ReadAccountNumberTo());

        _PrintClient(ClientTo);

        float Amount = ReadAmount(ClientFrom);

        cout << "\nEtes-vous sur de vouloir faire cette operation o/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'o' || Answer == 'O')
        {

            if (ClientFrom.Transfer(Amount, ClientTo, CurrentUser.UserName))
            {
                cout << "\nOperation fait avec succes :-)\n";
            }
            else
            {
                cout << "\nErreur : Operation annule\n";
            };

            _PrintClient(ClientFrom);
            _PrintClient(ClientTo);

        }
    };

};

