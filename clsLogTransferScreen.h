#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsLogTransferScreen : protected clsScreen
{
private:

    static void _PrintTransfereInfo(const clsBankClient::stTransferLog& TransferLog)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLog.Date;
        cout << "| " << setw(15) << left << TransferLog.AccountNumberSource;
        cout << "| " << setw(15) << left << TransferLog.AccountNumberDestination;
        cout << "| " << setw(12) << left << TransferLog.Amount;
        cout << "| " << setw(18) << left << TransferLog.SoldeClinetSource;
        cout << "| " << setw(18) << left << TransferLog.SoldeClientDestination;
        cout << "| " << setw(12) << left << TransferLog.User;
    }

public:

    static void ShowLoginRegisterList()
    {
        vector<clsBankClient::stTransferLog> vTransferLog = clsBankClient::_LoadLoginTransferDataFromFile();

        string Title = "\tListe des transferts enregistres";
        string SubTitle = "\t    (" + to_string(vTransferLog.size()) + ") transfert(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << setw(25) << left << "Date";
        cout << "| " << setw(15) << left << "Compte Source";
        cout << "| " << setw(15) << left << "Compte Dest";
        cout << "| " << setw(12) << left << "Montant";
        cout << "| " << setw(18) << left << "Solde Source";
        cout << "| " << setw(18) << left << "Solde Dest";
        cout << "| " << setw(12) << left << "Utilisateur";

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransferLog.empty())
        {
            cout << "\t\t\tAucun transfert disponible dans le systeme !" << endl;
        }
        else
        {
            for (const clsBankClient::stTransferLog& Log : vTransferLog)
            {
                _PrintTransfereInfo(Log);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};
