#pragma once
#include "playerShip.h"
#include "NPCShip.h"
#include "Display.h"
#include "Planet.h"

#include <chrono>

using namespace chrono;

class Game {
public:
	void titleScreen();
	void mainMenu();
	void diffSelect();
	void instructions();
	void loadGame();
	void sectorTab();
	void statusTab();
	void energyTab();
	void repairTab();
	void battle();
	void newSector();
	char checkForInput();
	char waitForInput();
	void resourceMove(Planet*);
	bool enemyInSector();
	string numToStr(double);
	string numToStr0(double);
	void generateTargetList();
	void loseGame(string);
	double roundToTens(double);
	void repair();
	void clearSector();
	void saveGame();
	void startGame();
private:
	string tab;
	string energySelection;
	int battleStage = 0;
	int planetAt = 11;
	bool isBattle;
	vector<Object*> sector;
	vector<Ship*> friendlyList;
	vector<NPCShip*> enemyList;
	Display display1;
	playerShip* playerShip1;
	steady_clock::time_point lastBattleTime = steady_clock::now();
};

