#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"


using namespace std;


class clsAddNewClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "Saisir le prenom, s'il vous plaits" << endl;
        Client.FirstName = clsInputValidation::ReadString();

        cout << "Saisir le nom, s'il vous plaits" << endl;
        Client.LastName = clsInputValidation::ReadString();

        cout << "Saisir Email, s'il vous plaits" << endl;
        Client.Email = clsInputValidation::ReadString();

        cout << "Saisir le numero de telephone, s'il vous plaits" << endl;
        Client.Phone = clsInputValidation::ReadString();

        cout << "Saisir le code pin, s'il vous plaits" << endl;
        Client.PinCode = clsInputValidation::ReadString();

        cout << "Saisir le solde de compte, s'il vous plaits" << endl;
        Client.AccountBalance = clsInputValidation::ReadNumber<float>();

    }
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nPrenom            : " << Client.FirstName;
        cout << "\nNome              : " << Client.LastName;
        cout << "\nNome Complet      : " << Client.FullName();
        cout << "\nEmail             : " << Client.Email;
        cout << "\nNumero Telephone  : " << Client.Phone;
        cout << "\nNumero de compte  : " << Client.AccountNumber();
        cout << "\nMot de passe      : " << Client.PinCode;
        cout << "\nSolde             : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:


    static void AddNewClient()
    {
        if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("\t Ajouter un nouveau client.");

        string AccountNumber = "";

        cout << "\nS'il vous plaits entrez un numero de compte: ";
        AccountNumber = clsInputValidation::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nCe numero de compte est deja utilise, Saisir un autre: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSaveSucceeded:
        {
            cout << "\nLe compte est ajouter avec reussi :-)\n";
           _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError ce compte n'ajouter pas car il est vide :-(\n";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError ce compte n'ajouter pas car le numero de compte est deja utiliser :-(\n";
            break;
        }
        }
    }



};

