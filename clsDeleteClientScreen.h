#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

using namespace std;


class clsDeleteClientScreen :protected clsScreen
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

public:

    static void DeleteClient()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tSuprimer Client Screen");

        string AccountNumber = "";


        cout << "\nS'il vous plaits entrez un numero de compte: ";
        AccountNumber = clsInputValidation::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nCe numero de compte pas trouve, Saisir un autre: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nEtes-vous sur de vouloir supprimer ce client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client.Delete())
            {

                cout << "\nClient supprime avec succes :-)\n";
                _PrintClient(Client);

            }
            else
            {
                cout << "\nErreur : le client n'a pas ete supprime\n";
            }
        }
    }
     
     
};

