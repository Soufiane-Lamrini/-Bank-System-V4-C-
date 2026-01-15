#pragma once


#include <iostream>
#include <string>
#include "clsInterfaceCommunication.h"
using namespace std;

class clsPerson : public clsInterfaceCommunication
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	//Property FirstName
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string getFirstName()
	{
		return _FirstName;
	}
	_declspec(property (get = getFirstName, put = SetFirstName)) string FirstName;

	//Property LastName
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string getLastName()
	{
		return _LastName;
	}
	_declspec(property (get = getLastName, put = SetLastName)) string LastName;

	//Property Email
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string getEmail()
	{
		return _Email;
	}
	_declspec(property (get = getEmail, put = SetEmail)) string Email;

	//Property Phone Number
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string getPhone()
	{
		return _Phone;
	}
	_declspec(property (get = getPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << _FirstName;
		cout << "\nLastName : " << _LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << _Email;
		cout << "\nPhone    : " << _Phone;
		cout << "\n___________________\n";
	}

	void SendEmail(string Title, string Body)
	{

	}

	void SendSMS(string Title, string Body)
	{

	}

	void SendFax(string Title, string Body)
	{

	}
};

