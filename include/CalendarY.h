#pragma once
#include "CalendarM.h"

class CalendarY
{
public:
	CalendarY(int year);
	~CalendarY();
	void Print(Console& console, int cx = 0, int cy = 0);
private:
	int year;
	CalendarM* monthCalendars[12];
};

