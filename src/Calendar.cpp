#include <iostream>
#include <string>
#include "CalendarY.h"

using namespace std;

void PrintYearCalendar(Console& console, int year);
void PrintMonthCalendar(Console& console, int year, int month);


int main(int argc, char** argv)
{
	
	try
	{
		Console console;

		if (argc == 2)
		{
			PrintYearCalendar(console, stoi(argv[1]));
		}

		else if (argc == 3)
		{
			PrintMonthCalendar(console, stoi(argv[2]), stoi(argv[1]));
		}
		else
		{
			PrintMonthCalendar(console, 0, 0);
		}

		console.Flush();
	}

	catch (const exception & e)
	{
		cerr << "podane nieprawidlowe dane" << e.what() << "'" << endl;
	}


	return 0;
}


void PrintYearCalendar(Console& console, int year)
{
	CalendarY calendar(year);
	calendar.Print(console);
}

void PrintMonthCalendar(Console& console, int year, int month)
{
	if (year != 0 && month != 0)
	{
		CalendarM calendar(year, month);
		calendar.Print(console);
	}
	else
	{
		CalendarM calendar;
		calendar.Print(console);
	}
}
