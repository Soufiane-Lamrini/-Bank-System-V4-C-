#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsBankClient.h"

using namespace std;


class clsFindClientScreen : protected clsScreen
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


    static void ShowFindClientScreen()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber = "";

        cout << "\nS'il vous plaits entrez un numero de compte: ";
        AccountNumber = clsInputValidation::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nCe numero de compte pas trouve, Saisir un autre: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client);

    }

    
};

