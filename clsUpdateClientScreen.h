#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidation.h"

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Saisir le prenom, s'il vous plaits" << endl;
		Client.FirstName = clsInputValidation::ReadString();

		cout << "Saisir le nom, s'il vous plaits" << endl;
		Client.LastName = clsInputValidation::ReadString();

		cout << "Saisir l'e prenom'Email, s'il vous plaits" << endl;
		Client.Email = clsInputValidation::ReadString();

		cout << "Saisir le numero de telephone, s'il vous plaits" << endl;
		Client.Phone = clsInputValidation::ReadString();

		cout << "Saisir le code pin, s'il vous plaits" << endl;
		Client.PinCode = clsInputValidation::ReadString();

		cout << "Saisir le solde de compte, s'il vous plaits" << endl;
		Client.AccountBalance = clsInputValidation::ReadNumber<int>();

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

	static void UpdateClient()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pUpdateClients))
		{
			return;// this will exit the function and it will not continue
		}

		string AccountNumber = "";

		cout << "\nS'il vous plaits entrez un numero de compte: ";
		AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nCe numero de compte pas trouve, Saisir un autre: ";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";

		_ReadClientInfo(Client1);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSaveSucceeded:
		{
			cout << "\nCe compte est modifie avec reussi :-)\n";
			_PrintClient(Client1);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError ce compte ne modifier pas car il est vide :-(";
			break;

		}

		}
	}

};

