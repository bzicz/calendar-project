#pragma once
#include "Console.h"

class CalendarM
{
public:
	CalendarM();
	CalendarM(int year, int month);
	void Print(Console& console, bool includeYear = true, int cx = 0, int cy = 0);
private:
	int year;
	int month;
};
