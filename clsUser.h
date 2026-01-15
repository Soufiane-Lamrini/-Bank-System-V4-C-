#pragma once


#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtility.h"
#include <vector>
#include <fstream>


using namespace std;

class clsUser : public clsPerson
{
private:
	enum enMode {
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};

	enMode _Mode;
	string _UserName;
	string _PinCode;
	int _Permissions;

	bool _MarkForDelete = false;

	struct stLoginRegister;

	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0],
			vUserData[1], vUserData[2], vUserData[3], vUserData[4],
			clsUtility::DecryptionText(vUserData[5], 2), stoi(vUserData[6]));
	}

	static stLoginRegister   _ConvertLinetoLoginData(string Line, string Seperator = "#//#")
	{
		stLoginRegister LoginRegister;

		vector <string> vLoginData = clsString::Split(Line, Seperator);
		
		LoginRegister.DateTime = vLoginData[0];
		LoginRegister.UserName = vLoginData[1];
		LoginRegister.Password = clsUtility::DecryptionText(vLoginData[2], 2);
		LoginRegister.Permission = stoi(vLoginData[3]);

		return LoginRegister;
	};

	static string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += User.FirstName + Separator;
		stUserRecord += User.LastName + Separator;
		stUserRecord += User.Email + Separator;
		stUserRecord += User.Phone + Separator;
		stUserRecord += User.UserName + Separator;
		stUserRecord += clsUtility::EncryptText(User.PinCode,2) + Separator;
		stUserRecord += to_string(User.Permissions);


		return stUserRecord;
	}

    string _ConvertLoginObjectToLine( string Separator = "#//#")
	{
		string stloginRecord = "";
		stloginRecord += clsDate::getCurrentDateTime() + Separator;
		stloginRecord += UserName + Separator;
		stloginRecord += clsUtility::EncryptText(PinCode, 2) + Separator;
		stloginRecord += to_string(Permissions);


		return stloginRecord;
	}

	static vector <clsUser> _LoadUserDataFromFile()
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}

		return vUsers;

	}


	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out); //overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsUser U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUserDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	struct stLoginRegister
	{
		string DateTime;
		string UserName;
		string Password;
		int Permission;
	};


	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,
		pLoginRegister = 128
	};



	clsUser(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string UserName, string PinCode, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_PinCode = PinCode;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	// Property UserName

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	_declspec(property(get = GetUserName, put = SetUserName))string UserName;

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
	void SetPermissions(int Permession)
	{
		_Permissions = Permession;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	_declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	bool MarkedForDeleted()
	{
		return _MarkForDelete;
	}


	
	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
 
			MyFile.close();

		}

		return _GetEmptyUserObject();
	};


	static clsUser Find(string UserName, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName && User.PinCode == PinCode)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
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
			if(IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSaveSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
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

	bool CheckAccesPermession(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Delete()
	{
		vector <clsUser> _vUser;

		_vUser = _LoadUserDataFromFile();

		for (clsUser& U : _vUser)
		{
			if (U.UserName == UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(_vUser);

		*this = _GetEmptyUserObject();

		return true;
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}


	static clsUser GetAddNewClientObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	void Registerlogin()
	{
		string stDataLine = _ConvertLoginObjectToLine();

		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}


    static vector <stLoginRegister> _LoadLoginRegisterDataFromFile()
	{
		vector<stLoginRegister> vLoginRecords;
		fstream MyFile("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					stLoginRegister LoginData = _ConvertLinetoLoginData(Line);
					vLoginRecords.push_back(LoginData);
				}
			}
			MyFile.close();
		}

		return vLoginRecords;
	}

};

