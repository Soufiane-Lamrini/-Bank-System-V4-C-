#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"


using namespace std;


class clsInputValidation
{
public:

	template <typename T>
	static bool IsNumberBetween(T num, T from = 0, T to = 0)
	{
		
		return (num >= from && num <= to);
		
	};

	static bool IsDateBetween(clsDate Date, clsDate from, clsDate to)
	{
		if ((clsDate::IsDate1AfterDate2(Date, from) || clsDate::IsDate1EqualDate2(Date, from))
			&&
			(clsDate::IsDate1BeforeDate2(Date, to) || clsDate::IsDate1EqualDate2(Date, to)))
			return true;
		if ((clsDate::IsDate1AfterDate2(Date, to) || clsDate::IsDate1EqualDate2(Date, to))
			&&
			(clsDate::IsDate1BeforeDate2(Date, from) || clsDate::IsDate1EqualDate2(Date, from)))
			return true;
		return false;
	}

	template <typename T>
	static T ReadNumber(string message = "Saisir un nombre")
	{
		T num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}

		return num;
	};

	template <typename T>
	static T ReadNumberBetween(string message, T from = 0, T to = 0)
	{
		T num = ReadNumber<T>(message);

		while (!IsNumberBetween(num, from, to))
		{
			cout << message;
			num = ReadNumber<T>(message);
		}

		return num;
	}

	

	static	bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

};

