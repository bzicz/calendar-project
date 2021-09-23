#pragma once
#include <ctime>
#include <ostream>

class Date
{
public:
	Date();
	Date(int year, int month, int day);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int GetDayOfWeek() const;
	bool IsChristmasDay() const;
	bool IsEasterDay() const;
	Date AddDays(int days);
	friend std::ostream& operator<<(std::ostream& out, const Date& date);
private:
	std::tm dateTime;
	void Refresh();
};
