#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsGlobal.h"


class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFailed = false;

		string UserName, PassWord;

		short NombreEssaye = 0;
		do
		{
			if (LoginFailed)
			{
				NombreEssaye++;
				cout << "\nNom ou mot passe est incoreect! Essayez autre fois" << endl;
				cout << "\n Tu reste sauf " << (3 - NombreEssaye) << " pour essayez!" << endl;
			};

			if (NombreEssaye == 3)
			{
				cout << "\nTrop d'essais. Le programme va se fermer.\n";
				return false;

			}
			cout << "Entrez nom d'utilisateur?" << endl;
			cin >> UserName;

			cout << "Entrez mot de passe?" << endl;
			cin >> PassWord;

			CurrentUser = clsUser::Find(UserName, PassWord);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.Registerlogin();
		clsMainScreen::ShowMainMenue();

		return true;
	};

	public:

		static bool ShowLoginScreen()
		{
			system("cls");
			_DrawScreenHeader("\t  Login Screen");
			return _Login();

		}
};

