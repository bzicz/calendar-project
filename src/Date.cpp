#include "Date.h"
#include <ctime>
#include <cstring>
#include <stdexcept>

using namespace std;

Date::Date()
{
	time_t now = time(NULL);
	dateTime = *localtime(&now);
}

Date::Date(int year, int month, int day)
{
	if (year < 1900 || year > 2038)
	{
		throw out_of_range("year");
	}

	if (month < 1 || month > 12)
	{
		throw out_of_range("month");
	}

	memset(&dateTime, 0, sizeof(tm));
	dateTime.tm_year = year - 1900;
	dateTime.tm_mon = month - 1;
	dateTime.tm_mday = day;
	Refresh();
}

int Date::GetYear() const
{
	return dateTime.tm_year + 1900;
}

int Date::GetMonth() const
{
	return dateTime.tm_mon + 1;
}

int Date::GetDay() const
{
	return dateTime.tm_mday;
}

int Date::GetDayOfWeek() const
{
	return ((dateTime.tm_wday + 6) % 7) + 1;
}

bool Date::IsChristmasDay() const
{
	return GetMonth() == 12 && GetDay() == 25;
}

bool Date::IsEasterDay() const
{
	int a = GetYear() % 19;
	int b = GetYear() % 4;
	int c = GetYear() % 7;
	int d = (a * 19 + 24) % 30;
	int e = (2 * b + 4 * c + 6 * d + 5) % 7;
	Date easterDate(GetYear(), 3, 22 + d + e);

	return GetMonth() == easterDate.GetMonth() && GetDay() == easterDate.GetDay();
}

Date Date::AddDays(int days)
{
	return Date(GetYear(), GetMonth(), GetDay() + days);
}

void Date::Refresh()
{
	mktime(&dateTime);
}

ostream& operator<<(ostream& out, const Date& date)
{
	char buffer[11];

	sprintf(buffer, "%d-%02d-%02d", date.GetYear(), date.GetMonth(), date.GetDay());
	out << buffer;

	return out;
}
