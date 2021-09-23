#include "Console.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Console::Console()
{
#ifdef _WIN32
	system("chcp 1250 > NUL");
#endif

	Clear();
}

void Console::Clear()
{
	for (int y = 0; y < C_H; y++)
	{
		for (int x = 0; x < C_W; x++)
		{
			buffer[y][x] = SPACE;
		}
	}

	SetCPosition(0, 0);
}

void Console::Print(char c)
{
	buffer[cy][cx] = c;
	cx++;

	if (cx == C_W)
	{
		cx = 0;
		cy = (cy + 1) % C_H;
	}
}

void Console::Print(const char* text)
{
	while (*text != '\0')
	{
		Print(*text);
		text++;
	}
}

void Console::GetCPosition(int& cx, int& cy) const
{
	cx = this->cx;
	cy = this->cy;
}

void Console::SetCPosition(int cx, int cy)
{
	if (cx < 0 || cx >= C_W)
	{
		throw out_of_range("cx");
	}

	if (cy < 0 || cy >= C_H)
	{
		throw out_of_range("cy");
	}

	this->cx = cx;
	this->cy = cy;
}



void Console::Flush() const
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	for (int y = 0; y < CompRHeight(); y++)
	{
		for (int x = 0; x < C_W; x++)
		{
			cout << buffer[y][x];
		}
		cout << endl;
	}
}

int Console::CompRHeight() const
{
	int max = 0;

	for (int y = 0; y < C_H; y++)
	{
		for (int x = 0; x < C_W; x++)
		{
			if (buffer[y][x] != SPACE)
			{
				max = y;
			}
		}
	}

	return max + 1;
}
