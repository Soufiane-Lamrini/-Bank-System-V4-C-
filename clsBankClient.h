#pragma once



#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtility.h"
#include <vector>
#include <fstream>

using namespace std;


class clsBankClient : public clsPerson
{
private:
	enum enMode {
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	struct stTransferLog;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0],
			vClientData[1], vClientData[2], vClientData[3], vClientData[4],
			vClientData[5], stod(vClientData[6]));
	}


	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Separator;
		stClientRecord += Client.LastName + Separator;
		stClientRecord += Client.Email + Separator;
		stClientRecord += Client.Phone + Separator;
		stClientRecord += Client.AccountNumber() + Separator;
		stClientRecord += Client.PinCode + Separator;
		stClientRecord += to_string(Client.AccountBalance);

		
		return stClientRecord;
	}

	string _ConvertTranferLogObjectToLine(clsBankClient ClientTo, double Amount, string UserName, string Separator = "#//#")
	{
		string stTransferObject = "";
		stTransferObject += clsDate::getCurrentDateTime() + Separator;
		stTransferObject += AccountNumber() + Separator;
		stTransferObject += ClientTo.AccountNumber() + Separator;
		stTransferObject += to_string(Amount) + Separator;
		stTransferObject += to_string(AccountBalance) + Separator;
		stTransferObject += to_string(ClientTo.AccountBalance) + Separator;
		stTransferObject += UserName;


		return stTransferObject;
	}

	static vector <clsBankClient> _LoadClientDateFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read mode

			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsBankClient Client = _ConvertLinetoClientObject(Line);
					vClients.push_back(Client);
				}
				MyFile.close();
			}

			return vClients;

	}

	static void _SaveClientDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out); //overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if(C.MarkedForDeleted() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientDateFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	static clsBankClient _GsetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	
	void _Transferlogin(clsBankClient& ClientTo, double Amount, string UserName)
	{
		string stDataLine = _ConvertTranferLogObjectToLine(ClientTo, Amount, UserName);

		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	};

	static stTransferLog _ConvertLineToTransferRecord(string Line, string Seperator = "#//#")
	{
		stTransferLog TransferLog;

		vector <string> vLoginTransferData = clsString::Split(Line, Seperator);

		TransferLog.Date = vLoginTransferData[0];
		TransferLog.AccountNumberSource = vLoginTransferData[1];
		TransferLog.AccountNumberDestination = vLoginTransferData[2];
		TransferLog.Amount = stoi(vLoginTransferData[3]);
		TransferLog.SoldeClinetSource = stoi(vLoginTransferData[4]);
		TransferLog.SoldeClientDestination = stoi(vLoginTransferData[5]);
		TransferLog.User = vLoginTransferData[6];


		return TransferLog;
	}

public:

	struct stTransferLog
	{
		string Date;
		string AccountNumberSource;
		string AccountNumberDestination;
		double Amount = 0;
		double SoldeClinetSource;
		double SoldeClientDestination;
		string User;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	// Property Read Only
	string AccountNumber()
	{
		return _AccountNumber;
	}

	// Property Pin Code
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	// Property Pin Code
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	bool MarkedForDeleted()
	{
		return _MarkForDelete;
	}

	void Deposit(double Amount) 
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount) //Retirer
	{
		if (_AccountBalance < Amount)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount, clsBankClient& ClientDestination, string UserName)
	{
		if (AccountBalance < Amount)
		{
			return false;
		}
		else {
			Withdraw(Amount);
			ClientDestination.Deposit(Amount);
			_Transferlogin(ClientDestination, Amount, UserName);
			return true;
		}
	}
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GsetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GsetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResults {
		svFaildEmptyObject = 0, svSaveSucceeded = 1, svFaildAccountNumberExists = 2
	};

	enSaveResults Save()
	{
		switch (_Mode)
		{

		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSaveSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSaveSucceeded;
			}
			break;
		}

		}
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;

		_vClients = _LoadClientDateFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);

		*this = _GsetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientDateFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <stTransferLog> _LoadLoginTransferDataFromFile()
	{
		vector<stTransferLog> vLoginTransferRecords;
		fstream MyFile("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					stTransferLog LoginTransferData = _ConvertLineToTransferRecord(Line);
					vLoginTransferRecords.push_back(LoginTransferData);
				}
			}
			MyFile.close();
		}

		return vLoginTransferRecords;
	}
};

