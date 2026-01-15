#pragma once
#pragma warning (disable:4996)


#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include "clsString.h"
using namespace std;


class clsDate
{
private:
	short _Year;
	short _Month;
	short _Day;

public:

	clsDate()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}

	clsDate(short Jour, short Mois, short Anne)
	{
		_Year = Anne;
		_Month = Mois;
		_Day = Jour;
	}

	clsDate(string sDate)
	{

		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		if (vDate.size() == 3)
		{
			_Day = stoi(vDate[0]);
			_Month = stoi(vDate[1]);
			_Year = stoi(vDate[2]);
		}
		else {
			cout << "Invalide forme!!!" << endl;
		}
	};

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}
	void setYear(short Year)
	{
		_Year = Year;
	};
	short getYear()
	{
		return _Year;
	};
	_declspec(property (get = getYear, put = setYear)) short Year;

	void setMonth(short Month)
	{
		_Month = Month;
	}
	short getMonth()
	{
		return _Month;
	};
	_declspec(property (get = getMonth, put = setMonth)) short Month;


	void setDay(short Day)
	{
		_Day = Day;
	}
	short getDay()
	{
		return _Day;
	};
	_declspec(property (get = getDay, put = setDay)) short Day;


	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month >12)
			return 0;

		int NumberOfDays[12] = {
		31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}


	clsDate(short DateOrderInYear, short Year)
	{

		clsDate Date = GetDateFromDayOrderInYear(DateOrderInYear, Year);

		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year;
	}

	static bool IsLeapYear(short Year)
	{

		return (Year % 4 == 0 && Year % 100 != 0) ||
			(Year % 400 == 0);
	}


	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	};
	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}


	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	};
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}


	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	};
	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}


	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	};
	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}


	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) * 24;
	};
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Month, _Year);
	};


	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	};
	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Month, _Year);
	}


	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	};
	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Month, _Year);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	};
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}


	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[7] = { " Sun"," Mon"," Tue"," Wed"," Thu"," Fri"," Sat" };

		return arrDayNames[DayOfWeekOrder];
	};
	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder(_Day, _Month, _Year));
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] =
		{ " Jan", " Feb", " Mar",
		" Apr", " May", " Jun",
		" Jul", " Aug", " Sep",
		" Oct", " Nov", " Dec" };

		return (Months[MonthNumber - 1]);
	};
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		int startDay = DayOfWeekOrder(1, Month, Year);

		cout << "\n  _______ " << MonthShortName(Month) << " " << Year << " _______\n\n";

		cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		for (int i = 0; i < startDay; i++)
			cout << "     ";

		for (int day = 1; day <= NumberOfDays; day++)
		{
			cout << setw(5) << day;
			if ((day + startDay) % 7 == 0)
				cout << "\n";
		}

		cout << "\n____________________________________\n\n";
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(short Year)
	{
		cout << "\n____________________________________\n\n";
		cout << "           Calendar " << Year << "\n\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year); // Appelle la fonction que tu as stylisée
		}
	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short NumberOfDaysFromTheBeginningOfTheYear(clsDate Date)
	{
		short TotalDays = 0;

		for (int i = 1; i < Date.Month; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Date.Year);
		}

		TotalDays += Date.Day;

		return TotalDays;
	}
	short NumberOfDaysFromTheBeginningOfTheYear()
	{
		return NumberOfDaysFromTheBeginningOfTheYear(*this);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date.Year = Year;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	};

	void DateAddDays(short Days)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(*this);
		short MonthDays = 0;
		_Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(_Month, _Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}
		}
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true :
			((Date1.Year == Date2.Year) ?
				(Date1.Month < Date2.Month ? true :
					(Date1.Month == Date2.Month ?
						Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}


	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ?
			((Date1.Month == Date2.Month) ?
				((Date1.Day == Date2.Day) ?
					true : false) : false) : false;
	}
	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	};
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}


	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	};
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
			Date.Day++;
		return Date;
	}
	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}


	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;
		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;
		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}
	void SwapDates(clsDate& Date2)
	{
		SwapDates(*this, Date2);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{

		int Days = 0;
		short SwapFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static clsDate GetSystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;
		return Date;
	}
	static short CalAge(clsDate Date2, bool IncludeEndDay = false)
	{
		clsDate Date = GetSystemDate();

		return GetDifferenceInDays(Date, Date2, IncludeEndDay);
	}
	short CalAge(bool IncludeEndDay = false)
	{
		return CalAge(*this, IncludeEndDay);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	};
	void IncreaseDateByXDays(short Days)
	{
		*this = IncreaseDateByXDays(Days, *this);
	}


	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
			Date = IncreaseDateByOneDay(Date);
		return Date;
	}
	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Weeks)
	{
		*this = IncreaseDateByXWeeks(Weeks, *this);
	}


	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
			Date.Month++;

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
			Date.Day = NumberOfDaysInCurrentMonth;

		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}


	static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{

			Date = IncreaseDateByOneMonth(Date);

		}
		return Date;
	}
	void IncreaseDateByXMonths(short Months)
	{
		*this = IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}


	static clsDate IncreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	};
	void IncreaseDateByXYears(short Years)
	{
		*this = IncreaseDateByXYears(Years, *this);
	}

	static clsDate IncreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date.Year += Years;
		return Date;
	};
	void IncreaseDateByXYearsFaster(short Years)
	{
		*this = IncreaseDateByXYearsFaster(Years, *this);
	}


	clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	};
	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}
	clsDate IncreaseDateByXDecades(short Decade, clsDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	};
	void IncreaseDateByXDecades(short Decade)
	{
		*this = IncreaseDateByXDecades(Decade, *this);
	}


	static clsDate IncreaseDateByXDecadesFaster(short Decade, clsDate Date)
	{
		Date.Year += Decade * 10;
		return Date;
	};
	void IncreaseDateByXDecadesFaster(short Decade)
	{
		*this = IncreaseDateByXDecadesFaster(Decade, *this);
	}


	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		//Period of 100 years
		Date.Year += 100;
		return Date;
	};
	void IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}


	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		//Period of 1000 years
		Date.Year += 1000;
		return Date;
	};

	void IncreaseDateByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}


	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else {
			Date.Day--;
		}

		return Date;
	}
	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	};
	void DecreaseDateByXDays(short Days)
	{
		*this = DecreaseDateByXDays(Days, *this);
	}


	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
			Date = DecreaseDateByOneDay(Date);
		return Date;
	}
	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short Weeks)
	{
		*this = DecreaseDateByXWeeks(Weeks, *this);
	}


	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
			Date.Day = NumberOfDaysInCurrentMonth;

		return Date;
	}
	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}


	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{

			Date = DecreaseDateByOneMonth(Date);

		}
		return Date;
	}
	void DecreaseDateByXMonths(short Months)
	{
		*this = DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date.Year--;
		return Date;
	}
	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}


	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	};
	void DecreaseDateByXYears(short Years)
	{
		*this = DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date.Year -= Years;
		return Date;
	};
	void DecreaseDateByXYearsFaster(short Years)
	{
		*this = DecreaseDateByXYearsFaster(Years, *this);
	}


	clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		//Period of 10 years
		Date.Year -= 10;
		return Date;
	};
	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}


	clsDate DecreaseDateByXDecades(short Decade, clsDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	};
	void DecreaseDateByXDecades(short Decade)
	{
		*this = DecreaseDateByXDecades(Decade, *this);
	}


	static clsDate DecreaseDateByXDecadesFaster(short Decade, clsDate Date)
	{
		Date.Year -= Decade * 10;
		return Date;
	};
	void DecreaseDateByXDecadesFaster(short Decade)
	{
		*this = DecreaseDateByXDecadesFaster(Decade, *this);
	}


	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		//Period of 100 years
		Date.Year -= 100;
		return Date;
	};
	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}


	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		//Period of 1000 years
		Date.Year -= 1000;
		return Date;
	};
	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
	};
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekend(clsDate Date)
	{
		// Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return (DayIndex == 6 || DayIndex == 5);
	};
	bool IsWeekend()
	{
		return IsWeekend(*this);
	}


	static bool IsBusinessDay(clsDate Date)
	{
		// Business Days are Sun , Mon , Tue , Wed and Thur
		return !IsWeekend(Date);
	};
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}


	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	};
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}
	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;
		EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;
		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	};
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfMonthDate;
		EndOfMonthDate.Day = 31;
		EndOfMonthDate.Month = 12;
		EndOfMonthDate.Year = Date.Year;
		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	};
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DaysCount;
	};
	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekend(DateFrom))
			{
				WeekEndCounter++;

			}
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DateFrom;
	};
	void CalculateVacationReturnDate(short VacationDays)
	{
		*this = CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2))
			&& !(IsDate1EqualDate2(Date1, Date2));
	};
	bool IsDate1AfterDate2(clsDate Date)
	{
		return IsDate1AfterDate2(*this, Date);
	}

	enum enDateCompare { Before = -1, Equal = 0, After };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	};
	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static	bool IsValidDate(clsDate Date)
	{

		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;

	}
	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static bool isDateInPeriod(clsDate Date, clsDate StartDate, clsDate EndDate)
	{
		return !(CompareDates(Date, StartDate) == enDateCompare::Before ||
			CompareDates(Date, EndDate) == enDateCompare::After);
	}

	bool isDateInPeriod(clsDate StartDate, clsDate EndDate)
	{
		return isDateInPeriod(*this, StartDate, EndDate);
	}

	static string getCurrentDateTime()
	{


		time_t Now = time(0);
		tm* now = localtime(&Now);
		short Day, Month, Year, Hour, Minute, Secound;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		Hour = now->tm_hour;
		Minute = now->tm_min;
		Secound = now->tm_sec;

		return  to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year)
			+ " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Secound);

	};



	void print()
	{
		cout << DateToString() << endl;
	}
};

