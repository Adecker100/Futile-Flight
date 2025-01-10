#pragma once

#include <vector>
#include <string>

using namespace std;

class Display {
public:
	Display();
	Display(int, int);
	void addGraphic(int, int, string);
	void addString(int, int, string);
	void drawScreen();
	void clearScreen();
	void clearBuffer();
	void setCursorPosition(int, int);
private:
	vector<vector<char>> screenBuffer;
	int screenHeight;
	int screenWidth;
};

