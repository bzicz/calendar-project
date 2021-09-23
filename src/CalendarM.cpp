#include "CalendarM.h"
#include "Date.h"
#include <stdexcept>
#include <cstring>

using namespace std;

const char* MONTHS[12] =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

CalendarM::CalendarM()
{
	Date date;

	year = date.GetYear();
	month = date.GetMonth();
}

CalendarM::CalendarM(int year, int month)
{
	if (year < 1970 || year > 2038)
	{
		throw out_of_range("year");
	}

	if (month < 1 || month > 12)
	{
		throw out_of_range("month");
	}

	this->year = year;
	this->month = month;
}

void CalendarM::Print(Console& console, bool includeYear, int cx, int cy)
{
	char line[500];
	int n;

	if (cx < 0)
	{
		throw out_of_range("cx");
	}

	if (cy < 0)
	{
		throw out_of_range("cy");
	}

	console.SetCPosition(cx, cy);
	n = sprintf(line, "            %s", MONTHS[month - 1]);

	if (includeYear)
	{
		sprintf(line + n, " %d", year);
	}

	console.Print(line);
	console.SetCPosition(cx, ++cy);
	console.Print("mo   tu   we   th   fr   sa   su");
	console.SetCPosition(cx, ++cy);

	Date date(year, month, 1);
	bool printed = false;
	int offset;

	memset(line, 0, sizeof(line));
	memset(line, ' ', 100);

	while (date.GetMonth() == month)
	{
		printed = false;
		offset = (date.GetDayOfWeek() - 1) * 5;

		if (date.IsChristmasDay())
		{
			n = sprintf(line + offset, "<%d>", date.GetDay());
		}
		else if (date.IsEasterDay())
		{
			n = sprintf(line + offset, "[%d]", date.GetDay());
		}
		else
		{
			n = sprintf(line + offset, "%d", date.GetDay());
		}

		line[offset + n] = SPACE;

		if (date.GetDayOfWeek() == 7)
		{
			line[offset + n] = '\0';
			console.Print(line);
			memset(line, 0, sizeof(line));
			memset(line, ' ', 100);
			console.SetCPosition(cx, ++cy);
			printed = true;
		}

		date = date.AddDays(1);
	}

	if (!printed)
	{
		line[offset + n] = '\0';
		console.Print(line);
	}
}
