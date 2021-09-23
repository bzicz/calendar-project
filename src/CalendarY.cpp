#include "CalendarY.h"
#include <cstdio>

using namespace std;

CalendarY::CalendarY(int year)
{
	this->year = year;

	for (int i = 0; i < 12; i++)
	{
		monthCalendars[i] = new CalendarM(year, i + 1);
	}
}

CalendarY::~CalendarY()
{
	for (int i = 0; i < 12; i++)
	{
		delete monthCalendars[i];
	}
}

void CalendarY::Print(Console& console, int cx, int cy)
{
	int calendarIndex = 0;
	char line[500];

	sprintf(line, "%52d", year);
	console.Print(line);
	console.SetCPosition(cx, ++cy);

	for (int rowIndex = 0; rowIndex < 4; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < 3; columnIndex++)
		{
			monthCalendars[calendarIndex]->Print(
				console, false, cx + columnIndex * 36, cy + rowIndex * 8);
			calendarIndex++;
		}
	}
}


