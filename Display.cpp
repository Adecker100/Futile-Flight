#include "Display.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

//Constructor

Display::Display() {
	screenHeight = 101;
	screenWidth = 51;
	screenBuffer.resize(screenWidth);

	for (int i = 0; i < screenBuffer.size(); i++) {
		screenBuffer.at(i).resize(screenHeight, '+');
	}

}

//Overloaded contructor with user-adjustable sizing

Display::Display(int width, int height) {
	screenHeight = height;
	screenWidth = width;
	screenBuffer.resize(screenWidth);

	for (int i = 0; i < screenBuffer.size(); i++) {
		screenBuffer.at(i).resize(screenHeight, '+');
	}

}

//Adds a graphic in a text file to the screen buffer

void Display::addGraphic(int distFromRight, int distFromTop, string fileName) {
	int width;
	int height;

	ifstream fileInput;

	fileInput.open(fileName);

	if (!fileInput.is_open()) {
		throw runtime_error("Graphic file not found: " + fileName);
	}

	fileInput >> width >> height;

	if (!(width > 0 && height > 0)) {
		throw runtime_error("Graphic file header incorrect: Width value: " + to_string(width) + " Height value: " + to_string(height));
	}

	if (distFromRight < 1) {
		throw runtime_error("addGraphic command distFromRight out of range: " + to_string(distFromRight));
	}

	for (int i = distFromTop; i < (distFromTop + height); i++) {
		for (int ii = distFromRight - 1; ii < (distFromRight + width); ii++) {
			screenBuffer.at(i).at(ii) = fileInput.get();
		}
	}

	fileInput.close();
}

void Display::addString(int x, int y, string inputStr) {
	for (int i = 0; i < inputStr.size(); i++) {
		screenBuffer.at(y).at(x + i) = inputStr[i];
	}
	
}

//Sets the cursor position in the console window; used for the drawScreen function

void Display::setCursorPosition(int widthPos, int heightPos) {
	if ((widthPos >= 0 && widthPos < screenWidth) && (heightPos >= 0 && heightPos < screenHeight)) {
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coordinates = { static_cast<SHORT>(heightPos), static_cast<SHORT>(widthPos) };
		SetConsoleCursorPosition(console, coordinates);
	}
	else {
		throw runtime_error("Cursor position out of range! Width Position: " + to_string(widthPos) + " Height Position: " + to_string(heightPos));
	}
}

//Draws the contents of the screen buffer to the console window

void Display::drawScreen() {
	for (int i = 0; i < screenBuffer.size(); i++) {
		for (int ii = 0; ii < screenBuffer.at(i).size(); ii++) {
			setCursorPosition(i, ii);
			cout << screenBuffer.at(i).at(ii);
		}
	}
}

//Clears all text from the console window

void Display::clearScreen() {
	clearBuffer();
	drawScreen();
}

//Replaces the entire screen buffer with spaces

void Display::clearBuffer() {
	for (int i = 0; i < screenBuffer.size(); i++) {
		for (int ii = 0; ii < screenBuffer.at(i).size(); ii++) {
			screenBuffer.at(i).at(ii) = ' ';
		}
	}
}
