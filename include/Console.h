#pragma once

const int C_W = 120;
const int C_H = 60;
const char SPACE = ' ';

class Console
{
public:
	Console();
	void Clear();
	void Print(char c);
	void Print(const char* text);
	void SetCPosition(int cx, int cy);
	void GetCPosition(int& cx, int& cy) const;
	void Flush() const;
private:
	char buffer[C_H][C_W];
	int cx;
	int cy;
	int CompRHeight() const;
};

