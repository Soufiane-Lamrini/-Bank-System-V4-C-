#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsGlobal.h"
#include "clsDate.h"
using namespace std;


class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";


        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << "User: "<<CurrentUser.UserName;
 
        cout << "\n\n\t\t\t\t\t  " << "Date: " << clsDate::DateToString(clsDate()) << "\n" << endl;

    
	}

    static bool CheckAccessRight(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccesPermession(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Accees Refuse! contactez votre administrateur.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }


    }
    


};

