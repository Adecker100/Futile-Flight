#include "Game.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <random>
#include <chrono>
#include <cmath>

void Game::titleScreen() {
	display1.drawScreen();
	display1.clearScreen();
	display1.addGraphic(4, 6, "titleScreen.txt");
	display1.addString(10, 49, "Futile Flight written by Alex Decker 2024");
	display1.drawScreen();
	waitForInput();
	mainMenu();
}

void Game::mainMenu() {
	char ch = ' ';
	int status = 1;
	display1.clearScreen();
	display1.addGraphic(1, 1, "outline.txt");
	display1.addGraphic(8, 3, "FutileFlight!.txt");
	display1.addGraphic(3, 15, "fullWidthDivider.txt");
	display1.addGraphic(10, 25, "NewGameSelected.txt");
	display1.addGraphic(10, 33, "LoadGame.txt");
	display1.addGraphic(10, 41, "Instructions.txt");
	display1.drawScreen();
	while (true) {
		ch = waitForInput();
		if (ch == 'v') {
			status = status + 1;
			if (status >= 3) {
				status = 3;
			}
		}
		if (ch == '^') {
			status = status - 1;
			if (status <= 1) {
				status = 1;
			}
		}
		if (ch == '\n') {
			if (status == 1) {
				diffSelect();
				break;
			}
			if (status == 2) {
				loadGame();
			}
			if (status == 3) {
				instructions();
			}
		}
		if (status == 1) {
			display1.clearBuffer();
			display1.addGraphic(1, 1, "outline.txt");
			display1.addGraphic(8, 3, "FutileFlight!.txt");
			display1.addGraphic(3, 15, "fullWidthDivider.txt");
			display1.addGraphic(10, 25, "NewGameSelected.txt");
			display1.addGraphic(10, 33, "LoadGame.txt");
			display1.addGraphic(10, 41, "Instructions.txt");
			display1.drawScreen();
		}
		if (status == 2) {
			display1.clearBuffer();
			display1.addGraphic(1, 1, "outline.txt");
			display1.addGraphic(8, 3, "FutileFlight!.txt");
			display1.addGraphic(3, 15, "fullWidthDivider.txt");
			display1.addGraphic(10, 25, "NewGame.txt");
			display1.addGraphic(10, 33, "LoadGameSelected.txt");
			display1.addGraphic(10, 41, "Instructions.txt");
			display1.drawScreen();
		}
		if (status == 3) {
			display1.clearBuffer();
			display1.addGraphic(1, 1, "outline.txt");
			display1.addGraphic(8, 3, "FutileFlight!.txt");
			display1.addGraphic(3, 15, "fullWidthDivider.txt");
			display1.addGraphic(10, 25, "NewGame.txt");
			display1.addGraphic(10, 33, "LoadGame.txt");
			display1.addGraphic(10, 41, "InstructionsSelected.txt");
			display1.drawScreen();
		}
	}
}

void Game::diffSelect() {
	char ch = ' ';
	int status = 1;
	display1.clearScreen();
	display1.addGraphic(1, 1, "outline.txt");
	display1.addGraphic(3, 3, "SelectDifficulty.txt");
	display1.addGraphic(36, 10, "easySelected.txt");
	display1.addGraphic(28, 17, "medium.txt");
	display1.addGraphic(35, 23, "hard.txt");
	display1.addGraphic(24, 38, "easyInfo.txt");
	display1.drawScreen();
	while (true) {
		ch = waitForInput();
		if (ch == 'v') {
			status = status + 1;
			if (status >= 3) {
				status = 3;
			}
		}
		if (ch == '^') {
			status = status - 1;
			if (status <= 1) {
				status = 1;
			}
		}
		if (ch == '\n') {
			if (status == 1) {
				playerShip1 = new playerShip("Battleship");
				newSector();
				break;
			}
			if (status == 2) {
				playerShip1 = new playerShip("Frigate");
				newSector();
				break;
			}
			if (status == 3) {
				playerShip1 = new playerShip("Scout");
				newSector();
				break;
			}
		}
		if (status == 1) {
			display1.clearBuffer();
			display1.addGraphic(1, 1, "outline.txt");
			display1.addGraphic(3, 3, "SelectDifficulty.txt");
			display1.addGraphic(36, 10, "easySelected.txt");
			display1.addGraphic(28, 17, "medium.txt");
			display1.addGraphic(35, 23, "hard.txt");
			display1.addGraphic(24, 38, "easyInfo.txt");
			display1.drawScreen();
		}
		if (status == 2) {
			display1.clearBuffer();
			display1.addGraphic(1, 1, "outline.txt");
			display1.addGraphic(3, 3, "SelectDifficulty.txt");
			display1.addGraphic(36, 10, "easy.txt");
			display1.addGraphic(28, 17, "mediumSelected.txt");
			display1.addGraphic(35, 23, "hard.txt");
			display1.addGraphic(24, 38, "mediumInfo.txt");
			display1.drawScreen();
		}
		if (status == 3) {
			display1.clearBuffer();
			display1.addGraphic(1, 1, "outline.txt");
			display1.addGraphic(3, 3, "SelectDifficulty.txt");
			display1.addGraphic(36, 10, "easy.txt");
			display1.addGraphic(28, 17, "medium.txt");
			display1.addGraphic(35, 23, "hardSelected.txt");
			display1.addGraphic(24, 38, "hardInfo.txt");
			display1.drawScreen();
		}
	}
}

void Game::instructions() {
	display1.clearScreen();
	display1.addGraphic(1, 1, "instructionPage.txt");
	display1.drawScreen();
	waitForInput();
	mainMenu();
}

void Game::loadGame() {
	string gameName;
	string inputString;
	double inputDouble;
	int inputInt;
	display1.clearScreen();
	display1.addString(5, 10, "What is the name of your saved game?");
	display1.drawScreen();
	display1.setCursorPosition(20, 30);

	cin >> gameName;

	ifstream loadFile;

	loadFile.open(gameName + ".txt");

	if (!loadFile.is_open()) {
		throw runtime_error("Game save file not found: " + gameName);
	}

	loadFile >> inputString;
	playerShip1 = new playerShip(inputString);

	loadFile >> inputDouble;
	playerShip1->setHull(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setShields(inputDouble);

	loadFile >> inputInt;
	playerShip1->setCrew(inputInt);

	loadFile >> inputInt;
	playerShip1->setFuel(inputInt);

	loadFile >> inputInt;
	playerShip1->setTorpedoes(inputInt);

	loadFile >> inputDouble;
	playerShip1->setLaserHealth(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setEngineHealth(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setReactorHealth(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setLifeSupportHealth(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setLaserPower(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setEnginePower(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setLifeSupportPower(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setShieldPower(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setReactorOutput(inputDouble);

	loadFile >> inputDouble;
	playerShip1->setAuxPower(inputDouble);

	loadFile >> inputInt;
	playerShip1->setEngineCrew(inputInt);

	loadFile >> inputInt;
	playerShip1->setLaserCrew(inputInt);

	loadFile >> inputInt;
	playerShip1->setLifeSupportCrew(inputInt);

	loadFile >> inputInt;
	playerShip1->setReactorCrew(inputInt);

	loadFile >> inputInt;
	playerShip1->setShieldCrew(inputInt);

	loadFile >> inputInt;
	playerShip1->setHullCrew(inputInt);

	loadFile.close();

	newSector();
}

void Game::sectorTab() {
	char ch = ' ';
	int status = 1;
	display1.clearScreen();
	while (true) {
		int shipInSector = 0;
		if (ch == '>') {
			status = status + 1;
			if (status >= sector.size()) {
				status = sector.size();
			}
		}
		if (ch == '<') {
			status = status - 1;
			if (status <= 1) {
				status = 1;
			}
		}
		if (ch == '2') {
			statusTab();
			break;
		}
		if (ch == '3') {
			energyTab();
			break;
		}
		if (ch == '4') {
			repairTab();
			break;
		}
		
		display1.addGraphic(1, 1, "outline.txt");
		display1.addGraphic(31, 1, "sectorTab.txt");
		display1.addGraphic(3, 20, "hLine.txt");

		for (int i = 0; i < sector.size(); i++) {
			if (sector.at(i)->getType() == "planet") {
				if ((status - 1) == i) {
					display1.addGraphic(5 + (i * 9), 10, "planetSelected.txt");
				}
				else {
					display1.addGraphic(5 + (i * 9), 10, "planetUnselected.txt");
				}
			}
			if (sector.at(i)->getType() == "ship") {
				if ((status - 1) == i) {
					display1.addGraphic(5 + (i * 9), 10, "shipSelected.txt");
					NPCShip* shipPtr = dynamic_cast<NPCShip*>(sector.at(i));
					if (shipPtr->isEnemy()) {
						shipInSector += 1;
					}
				}
				else {
					display1.addGraphic(5 + (i * 9), 10, "shipUnselected.txt");
					NPCShip* shipPtr = dynamic_cast<NPCShip*>(sector.at(i));
					if (shipPtr->isEnemy()) {
						shipInSector += 1;
					}
				}
			}
			if (sector.at(i)->getType() == "destroyedShip") {
				if ((status - 1) == i) {
					display1.addGraphic(5 + (i * 9), 10, "destroyedShipSelected.txt");
				}
				else {
					display1.addGraphic(5 + (i * 9), 10, "destroyedShipUnselected.txt");
				}
			}
		}

		if (ch == 'n') {
			if (shipInSector == 0) {
				clearSector();
				newSector();
			}
		}
		if (ch == 's') {
			if (shipInSector == 0) {
				saveGame();
			}
		}
		if (sector.at(status - 1)->getType() == "planet") {
			Planet* planetPtr = dynamic_cast<Planet*>(sector.at(status - 1));
			display1.addString(10, 25, "Type: Planet");
			display1.addString(10, 30, "Available Resources:");
			if (planetPtr->getFuel() > 0) {
				display1.addString(13, 32, "Fuel");
			}
			if (planetPtr->getTorpedoes() > 0) {
				display1.addString(13, 34, "Torpedoes");
			}
			if (planetPtr->getCrew() > 0) {
				display1.addString(13, 36, "Crew");
			}
		}
		if (sector.at(status - 1)->getType() == "ship") {
			NPCShip* shipPtr = dynamic_cast<NPCShip*>(sector.at(status - 1));
			if (shipPtr->isEnemy()) {
				display1.addString(10, 25, "Type: Enemy Ship");
			}
			else {
				display1.addString(10, 25, "Type: Friendly Ship");
			}
			display1.addString(10, 27, "Class: " + shipPtr->getSize());
			display1.addString(10, 29, "Torpedo Tubes: " + to_string(shipPtr->getTorpedoTubes()));
			display1.addString(10, 31, "Laser Banks: " + to_string(shipPtr->getLaserBanks()));
			display1.addString(10, 34, "Shields: " + numToStr(shipPtr->getShields()) + " / " + numToStr(shipPtr->getMaxShields()));
			display1.addString(10, 36, "Hull: " + numToStr(shipPtr->getHull()) + " / " + numToStr(shipPtr->getMaxHull()));
		}
		if (sector.at(status - 1)->getType() == "destroyedShip") {
			NPCShip* shipPtr = dynamic_cast<NPCShip*>(sector.at(status - 1));
			if (shipPtr->isEnemy()) {
				display1.addString(10, 25, "Type: Destroyed Enemy Ship");
			}
			else {
				display1.addString(10, 25, "Type: Destroyed Friendly Ship");
			}
		}

		if (planetAt != status - 1) {
			if (ch == '\n') {
				if (sector.at(status - 1)->getType() == "planet") {
					if (playerShip1->getFuel() > 0) {
						if (planetAt != status - 1) {
							playerShip1->setFuel(playerShip1->getFuel() - 1);
							planetAt = status - 1;
						}
						Planet* planetPtr = dynamic_cast<Planet*>(sector.at(status - 1));
						if (planetPtr->getFuel() > 0) {
							display1.addString(17, 32, ": " + to_string(planetPtr->getFuel()));
						}
						if (planetPtr->getTorpedoes() > 0) {
							display1.addString(22, 34, ": " + to_string(planetPtr->getTorpedoes()));
						}
						if (planetPtr->getCrew() > 0) {
							display1.addString(17, 36, ": " + to_string(planetPtr->getCrew()));
						}
					}
				}
			}
		}
		else {
			Planet* planetPtr = dynamic_cast<Planet*>(sector.at(status - 1));
			if (planetPtr->getFuel() > 0) {
				display1.addString(17, 32, ": " + to_string(planetPtr->getFuel()));
			}
			if (planetPtr->getTorpedoes() > 0) {
				display1.addString(22, 34, ": " + to_string(planetPtr->getTorpedoes()));
			}
			if (planetPtr->getCrew() > 0) {
				display1.addString(17, 36, ": " + to_string(planetPtr->getCrew()));
			}
			if (ch == '\n') {
				resourceMove(planetPtr);
			}
		}

		display1.drawScreen();
		display1.clearBuffer();

		ch = checkForInput();
		battle();
	}
}

void Game::statusTab() {
	char ch = ' ';
	display1.clearScreen();
	while (true) {
		if (ch == '1') {
			sectorTab();
			break;
		}
		if (ch == '3') {
			energyTab();
			break;
		}
		if (ch == '4') {
			repairTab();
			break;
		}

		display1.addGraphic(1, 1, "outline.txt");
		display1.addGraphic(31, 1, "statusTab.txt");
		display1.addGraphic(3, 4, "statusLines.txt");
		display1.addString(20, 5, "----- System Health -----");
		display1.addString(71, 5, "----- Voyage Info -----");
		display1.addString(18, 37, "----- Ship Resources -----");
		display1.addString(10, 8, "Shields: " + numToStr(playerShip1->getShields()) + " / " + numToStr(playerShip1->getMaxShields()));
		display1.addString(10, 12, "Hull: " + numToStr(playerShip1->getHull()) + " / " + numToStr(playerShip1->getMaxHull()));
		display1.addString(10, 19, "Lasers: " + numToStr(playerShip1->getLaserHealth()) + " %");
		display1.addString(10, 23, "Engines: " + numToStr(playerShip1->getEngineHealth()) + " %");
		display1.addString(10, 27, "Life Support: " + numToStr(playerShip1->getLifeSupportHealth()) + " %");
		display1.addString(10, 31, "Reactor: " + numToStr(playerShip1->getReactorHealth()) + " %");
		display1.addString(10, 40, "Fuel: " + to_string(playerShip1->getFuel()));
		display1.addString(10, 43, "Torpedoes: " + to_string(playerShip1->getTorpedoes()));
		display1.addString(10, 46, "Crew: " + to_string(playerShip1->getCrew()));
		display1.drawScreen();
		ch = checkForInput();
		battle();
	}
}

void Game::energyTab() {
	char ch = ' ';
	int status = 1;
	display1.clearScreen();
	display1.addGraphic(1, 1, "outline.txt");
	display1.addGraphic(31, 1, "energyTab.txt");

	while (true) {
		if (ch == '>') {
			status = status + 1;
			if (status >= 4) {
				status = 4;
			}
		}
		if (ch == '<') {
			status = status - 1;
			if (status <= 1) {
				status = 1;
			}
		}
		if (ch == '1') {
			sectorTab();
			break;
		}
		if (ch == '2') {
			statusTab();
			break;
		}
		if (ch == '4') {
			repairTab();
			break;
		}

		if (status == 1) {
			display1.addGraphic(12, 35, "shieldsEnergy.txt");
			if (ch == '^') {
				if (playerShip1->getShieldPower() < 150.0) {
					if (playerShip1->getAuxPower() > 0) {
						playerShip1->setShieldPower(playerShip1->getShieldPower() + 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() - 10.0);
					}
				}
			}
			if (ch == 'v') {
				if (playerShip1->getShieldPower() > 10.0) {
					if (playerShip1->getAuxPower() < 150.0) {
						playerShip1->setShieldPower(playerShip1->getShieldPower() - 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() + 10.0);
					}
				}
			}
		}
		if (status == 2) {
			display1.addGraphic(12, 35, "lasersEnergy.txt");
			if (ch == '^') {
				if (playerShip1->getLaserPower() < 150.0) {
					if (playerShip1->getAuxPower() > 0) {
						playerShip1->setLaserPower(playerShip1->getLaserPower() + 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() - 10.0);
					}
				}
			}
			if (ch == 'v') {
				if (playerShip1->getLaserPower() > 10.0) {
					if (playerShip1->getAuxPower() < 150.0) {
						playerShip1->setLaserPower(playerShip1->getLaserPower() - 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() + 10.0);
					}
				}
			}
		}
		if (status == 3) {
			display1.addGraphic(12, 35, "enginesEnergy.txt");
			if (ch == '^') {
				if (playerShip1->getEnginePower() < 150.0) {
					if (playerShip1->getAuxPower() > 0) {
						playerShip1->setEnginePower(playerShip1->getEnginePower() + 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() - 10.0);
					}
				}
			}
			if (ch == 'v') {
				if (playerShip1->getEnginePower() > 10.0) {
					if (playerShip1->getAuxPower() < 150.0) {
						playerShip1->setEnginePower(playerShip1->getEnginePower() - 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() + 10.0);
					}
				}
			}
		}
		if (status == 4) {
			display1.addGraphic(12, 35, "lifeSupportEnergy.txt");
			if (ch == '^') {
				if (playerShip1->getLifeSupportPower() < 150.0) {
					if (playerShip1->getAuxPower() > 0) {
						playerShip1->setLifeSupportPower(playerShip1->getLifeSupportPower() + 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() - 10.0);
					}
				}
			}
			if (ch == 'v') {
				if (playerShip1->getLifeSupportPower() > 10.0) {
					if (playerShip1->getAuxPower() < 150.0) {
						playerShip1->setLifeSupportPower(playerShip1->getLifeSupportPower() - 10.0);
						playerShip1->setAuxPower(playerShip1->getAuxPower() + 10.0);
					}
				}
			}
		}



		display1.addGraphic(13, 19, numToStr0(roundToTens(playerShip1->getShieldPower())) + ".txt");
		display1.addGraphic(28, 19, numToStr0(roundToTens(playerShip1->getLaserPower())) + ".txt");
		display1.addGraphic(43, 19, numToStr0(roundToTens(playerShip1->getEnginePower())) + ".txt");
		display1.addGraphic(58, 19, numToStr0(roundToTens(playerShip1->getLifeSupportPower())) + ".txt");
		display1.addGraphic(73, 19, numToStr0(roundToTens(playerShip1->getAuxPower())) + ".txt");

		display1.drawScreen();
		ch = checkForInput();
		battle();
	}
}

void Game::repairTab() {
	char ch = ' ';
	int status = 1;
	display1.clearScreen();

	while (true) {

	display1.clearBuffer();
	display1.addGraphic(1, 1, "outline.txt");
	display1.addGraphic(31, 1, "repairTab.txt");
	display1.addGraphic(33, 5, "44vLine.txt");
	display1.addGraphic(65, 5, "44vLine.txt");
	display1.addString(14, 5, "System");
	display1.addString(10, 7, "---------------");
	display1.addString(43, 5, "Repair Status");
	display1.addString(39, 7, "---------------------");
	display1.addString(77, 5, "Crew Assigned");
	display1.addString(73, 7, "---------------------");
	display1.addString(14, 10, "Engines");
	display1.addString(46, 10, numToStr(playerShip1->getEngineHealth()) + " %");
	display1.addString(14, 15, "Lasers");
	display1.addString(46, 15, numToStr(playerShip1->getLaserHealth()) + " %");
	display1.addString(12, 20, "Life Support");
	display1.addString(46, 20, numToStr(playerShip1->getLifeSupportHealth()) + " %");
	display1.addString(13, 25, "Reactor");
	display1.addString(46, 25, numToStr(playerShip1->getReactorHealth()) + " %");
	display1.addString(13, 30, "Shields");
	display1.addString(46, 30, numToStr((playerShip1->getShields() / playerShip1->getMaxShields()) * 100) + " %");
	display1.addString(15, 35, "Hull");
	display1.addString(46, 35, numToStr((playerShip1->getHull() / playerShip1->getMaxHull()) * 100) + " %");

		if (ch == 'v') {
			status = status + 1;
			if (status >= 6) {
				status = 6;
			}
		}
		if (ch == '^') {
			status = status - 1;
			if (status <= 1) {
				status = 1;
			}
		}
		if (ch == '1') {
			sectorTab();
			break;
		}
		if (ch == '2') {
			statusTab();
			break;
		}
		if (ch == '3') {
			energyTab();
			break;
		}

		if (status == 1) {
			if (ch == '>') {
				if (playerShip1->getEngineCrew() < 3) {
					if (playerShip1->crewWorking() < playerShip1->getCrew()) {
						playerShip1->setEngineCrew(playerShip1->getEngineCrew() + 1);
					}
				}
			}
			if (ch == '<') {
				if (playerShip1->getEngineCrew() > 0) {
					playerShip1->setEngineCrew(playerShip1->getEngineCrew() - 1);
				}
			}
			display1.addString(12, 10, "< Engines >");
			display1.addString(44, 10, "< " + numToStr(playerShip1->getEngineHealth()) + " % >");
			display1.addString(73, 10, "<");
			display1.addString(91, 10, ">");
		}
		if (status == 2) {
			if (ch == '>') {
				if (playerShip1->getLaserCrew() < 3) {
					if (playerShip1->crewWorking() < playerShip1->getCrew()) {
						playerShip1->setLaserCrew(playerShip1->getLaserCrew() + 1);
					}
				}
			}
			if (ch == '<') {
				if (playerShip1->getLaserCrew() > 0) {
					playerShip1->setLaserCrew(playerShip1->getLaserCrew() - 1);
				}
			}
			display1.addString(12, 15, "< Lasers >");
			display1.addString(44, 15, "< " + numToStr(playerShip1->getLaserHealth()) + " % >");
			display1.addString(73, 15, "<");
			display1.addString(91, 15, ">");
		}
		if (status == 3) {
			if (ch == '>') {
				if (playerShip1->getLifeSupportCrew() < 3) {
					if (playerShip1->crewWorking() < playerShip1->getCrew()) {
						playerShip1->setLifeSupportCrew(playerShip1->getLifeSupportCrew() + 1);
					}
				}
			}
			if (ch == '<') {
				if (playerShip1->getLifeSupportCrew() > 0) {
					playerShip1->setLifeSupportCrew(playerShip1->getLifeSupportCrew() - 1);
				}
			}
			display1.addString(10, 20, "< Life Support >");
			display1.addString(44, 20, "< " + numToStr(playerShip1->getLifeSupportHealth()) + " % >");
			display1.addString(73, 20, "<");
			display1.addString(91, 20, ">");
		}
		if (status == 4) {
			if (ch == '>') {
				if (playerShip1->getReactorCrew() < 3) {
					if (playerShip1->crewWorking() < playerShip1->getCrew()) {
						playerShip1->setReactorCrew(playerShip1->getReactorCrew() + 1);
					}
				}
			}
			if (ch == '<') {
				if (playerShip1->getReactorCrew() > 0) {
					playerShip1->setReactorCrew(playerShip1->getReactorCrew() - 1);
				}
			}
			display1.addString(11, 25, "< Reactor >");
			display1.addString(44, 25, "< " + numToStr(playerShip1->getReactorHealth()) + " % >");
			display1.addString(73, 25, "<");
			display1.addString(91, 25, ">");
		}
		if (status == 5) {
			if (ch == '>') {
				if (playerShip1->getShieldCrew() < 3) {
					if (playerShip1->crewWorking() < playerShip1->getCrew()) {
						playerShip1->setShieldCrew(playerShip1->getShieldCrew() + 1);
					}
				}
			}
			if (ch == '<') {
				if (playerShip1->getShieldCrew() > 0) {
					playerShip1->setShieldCrew(playerShip1->getShieldCrew() - 1);
				}
			}
			display1.addString(11, 30, "< Shields >");
			display1.addString(44, 30, "< " + numToStr((playerShip1->getShields() / playerShip1->getMaxShields()) * 100) + " % >");
			display1.addString(73, 30, "<");
			display1.addString(91, 30, ">");
		}
		if (status == 6) {
			if (ch == '>') {
				if (playerShip1->getHullCrew() < 3) {
					if (playerShip1->crewWorking() < playerShip1->getCrew()) {
						playerShip1->setHullCrew(playerShip1->getHullCrew() + 1);
					}
				}
			}
			if (ch == '<') {
				if (playerShip1->getHullCrew() > 0) {
					playerShip1->setHullCrew(playerShip1->getHullCrew() - 1);
				}
			}
			display1.addString(13, 35, "< Hull >");
			display1.addString(44, 35, "< " + numToStr((playerShip1->getHull() / playerShip1->getMaxHull()) * 100) + " % >");
			display1.addString(73, 35, "<");
			display1.addString(91, 35, ">");
		}

			for (int i = 0; i < 3; i++) {
				if (playerShip1->getEngineCrew() >= (i + 1)) {
					display1.addString((75 + (i * 6)), 10, "[#]");
				}
				else {
					display1.addString((75 + (i * 6)), 10, "[ ]");
				}
			}
			for (int i = 0; i < 3; i++) {
				if (playerShip1->getLaserCrew() >= (i + 1)) {
					display1.addString((75 + (i * 6)), 15, "[#]");
				}
				else {
					display1.addString((75 + (i * 6)), 15, "[ ]");
				}
			}
			for (int i = 0; i < 3; i++) {
				if (playerShip1->getLifeSupportCrew() >= (i + 1)) {
					display1.addString((75 + (i * 6)), 20, "[#]");
				}
				else {
					display1.addString((75 + (i * 6)), 20, "[ ]");
				}
			}
			for (int i = 0; i < 3; i++) {
				if (playerShip1->getReactorCrew() >= (i + 1)) {
					display1.addString((75 + (i * 6)), 25, "[#]");
				}
				else {
					display1.addString((75 + (i * 6)), 25, "[ ]");
				}
			}
			for (int i = 0; i < 3; i++) {
				if (playerShip1->getShieldCrew() >= (i + 1)) {
					display1.addString((75 + (i * 6)), 30, "[#]");
				}
				else {
					display1.addString((75 + (i * 6)), 30, "[ ]");
				}
			}
			for (int i = 0; i < 3; i++) {
				if (playerShip1->getHullCrew() >= (i + 1)) {
					display1.addString((75 + (i * 6)), 35, "[#]");
				}
				else {
					display1.addString((75 + (i * 6)), 35, "[ ]");
				}
			}


		display1.drawScreen();
		ch = checkForInput();
		battle();
	}
}

void Game::battle() {
	random_device seed;
	mt19937 gen(seed());
	uniform_int_distribution<int> randomFriendly(0, friendlyList.size() - 1);
	uniform_int_distribution<int> outOf100(1, 100);

	steady_clock::time_point currentTime = steady_clock::now();
	auto elapsedTime = duration_cast<seconds>(currentTime - lastBattleTime).count();

	if (elapsedTime >= 2) {
		repair();
		if (enemyList.size() > 0) {
			uniform_int_distribution<int> randomEnemy(0, enemyList.size() - 1);
			if (battleStage > ((enemyList.size() + friendlyList.size()) - 1)) {
				battleStage = 0;
			}
			if (battleStage < enemyList.size()) { //Enemy is firing
				NPCShip* shipPtr = dynamic_cast<NPCShip*>(enemyList.at(battleStage));

				if (outOf100(gen) < 50) { //Lasers
					for (int i = 0; i < shipPtr->getLaserBanks(); i++) {
						int index = randomFriendly(gen);
						if (index == 0) { //playerShip is targeted
							if (((playerShip1->getEngineHealth() / 100) * (playerShip1->getEnginePower() / 100) * outOf100(gen)) < 50) { //Chance of playerShip getting hit
								if (playerShip1->getShields() > 0) { //Shields are still up
									playerShip1->setShields(playerShip1->getShields() - (5.0 - (((playerShip1->getShieldPower() - 100) / 100) * 5.0)));
								}
								else { //Shields are down
									playerShip1->setHull(playerShip1->getHull() - 5.0);
									if (playerShip1->getHull() <= 0) {
										loseGame("hull integrity");
									}
									if (outOf100(gen) < 5) {
										playerShip1->setCrew(playerShip1->getCrew() - 1);
										if (playerShip1->getCrew() <= 0) {
											loseGame("crew");
										}
									}
									int system = outOf100(gen);
									if (system <= 25) { //Engines take damage
										playerShip1->setEngineHealth(playerShip1->getEngineHealth() - 5.0);
									}
									if (system > 25 && system <= 50) { //Lasers take damage
										playerShip1->setLaserHealth(playerShip1->getLaserHealth() - 5.0);
									}
									if (system > 50 && system <= 75) { //Life Support takes damage
										playerShip1->setLifeSupportHealth(playerShip1->getLifeSupportHealth() - 5.0);
										if (playerShip1->getLifeSupportHealth() <= 0) {
											loseGame("Life Support system");
										}
									}
									if (system > 75 && system <= 100) { //Reactor takes damage
										playerShip1->setReactorHealth(playerShip1->getReactorHealth() - 5.0);
										if (playerShip1->getReactorHealth() <= 0) {
											loseGame("Reactor");
										}
									}
								}
							}
						}
						else { //friendlyShip is targeted
							if (outOf100(gen) < 50) { //Hit
								if (friendlyList.at(index)->getShields() > 0) { //Shields are still up
									friendlyList.at(index)->setShields(friendlyList.at(index)->getShields() - 5);
								}
								else { //Laser hits hull
									friendlyList.at(index)->setHull(friendlyList.at(index)->getHull() - 5);
									if (friendlyList.at(index)->getHull() <= 0.0) {
										friendlyList.at(index)->setType("destroyedShip");
									}
								}
							}
						}
					}
				}
				else { //Torpedoes
					for (int i = 0; i < shipPtr->getTorpedoTubes(); i++) {
						int index = randomFriendly(gen);
						if (index == 0) { //playerShip is targeted
							if (((playerShip1->getEngineHealth() / 100) * (playerShip1->getEnginePower() / 100) * outOf100(gen)) < 25) { //Chance of playerShip getting hit
								if (playerShip1->getShields() > 0) { //Shields are still up
									playerShip1->setShields(playerShip1->getShields() - (10.0 - (((playerShip1->getShieldPower() - 100) / 100) * 10.0)));
								}
								else { //Shields are down
									playerShip1->setHull(playerShip1->getHull() - 10.0);
									if (playerShip1->getHull() <= 0) {
										loseGame("hull integrity");
									}
									if (outOf100(gen) < 10) {
										playerShip1->setCrew(playerShip1->getCrew() - 1);
										if (playerShip1->getCrew() <= 0) {
											loseGame("crew");
										}
									}
									int system = outOf100(gen);
									if (system <= 25) { //Engines take damage
										playerShip1->setEngineHealth(playerShip1->getEngineHealth() - 10.0);
									}
									if (system > 25 && system <= 50) { //Lasers take damage
										playerShip1->setLaserHealth(playerShip1->getLaserHealth() - 10.0);
									}
									if (system > 50 && system <= 75) { //Life Support takes damage
										playerShip1->setLifeSupportHealth(playerShip1->getLifeSupportHealth() - 10.0);
										if (playerShip1->getLifeSupportHealth() <= 0) {
											loseGame("Life Support system");
										}
									}
									if (system > 75 && system <= 100) { //Reactor takes damage
										playerShip1->setReactorHealth(playerShip1->getReactorHealth() - 10.0);
										if (playerShip1->getReactorHealth() <= 0) {
											loseGame("Reactor");
										}
									}
								}
							}
						}
						else { //friendlyShip is targeted
							if (outOf100(gen) < 25) { //Hit
								if (friendlyList.at(index)->getShields() > 0) { //Shields are still up
									friendlyList.at(index)->setShields(friendlyList.at(index)->getShields() - 10);
								}
								else { //Torpedo hits hull
									friendlyList.at(index)->setHull(friendlyList.at(index)->getHull() - 10);
									if (friendlyList.at(index)->getHull() <= 0.0) {
										friendlyList.at(index)->setType("destroyedShip");
									}
								}
							}
						}
					}
				}
			}
			else {
				if ((battleStage - enemyList.size()) == 0) {
					if (playerShip1->getTorpedoes() == 0) {

					}
					else {
						if (outOf100(gen) < 50) { //Lasers
							for (int i = 0; i < playerShip1->getLaserBanks(); i++) {
								int index = randomEnemy(gen);
								if ((((playerShip1->getLaserHealth() / 100) * (playerShip1->getLaserPower() / 100) * outOf100(gen)) > 50)) { //Chance of getting a hit
									if (enemyList.at(index)->getShields() > 0) { //Shields are still up
										enemyList.at(index)->setShields(enemyList.at(index)->getShields() - 5);
									}
									else { //Laser hits hull
										enemyList.at(index)->setHull(enemyList.at(index)->getHull() - 5);
										if (enemyList.at(index)->getHull() <= 0.0) {
											enemyList.at(index)->setType("destroyedShip");
										}
									}
								}
							}
						}
						else { //Torpedoes
							for (int i = 0; i < playerShip1->getTorpedoTubes(); i++) {
								playerShip1->setTorpedoes(playerShip1->getTorpedoes() - 1);
								int index = randomEnemy(gen);
								if (outOf100(gen) < 25) { //Hit
									if (enemyList.at(index)->getShields() > 0) { //Shields are still up
										enemyList.at(index)->setShields(enemyList.at(index)->getShields() - 10);
									}
									else { //Torpedo hits hull
										enemyList.at(index)->setHull(enemyList.at(index)->getHull() - 10);
										if (enemyList.at(index)->getHull() <= 0.0) {
											enemyList.at(index)->setType("destroyedShip");
										}
									}
								}
							}
						}
					}
				}
				else {
					NPCShip* shipPtr = dynamic_cast<NPCShip*>(friendlyList.at(battleStage - enemyList.size()));
					if (outOf100(gen) < 50) { //Lasers
						for (int i = 0; i < shipPtr->getLaserBanks(); i++) {
							int index = randomEnemy(gen);
							if (outOf100(gen) < 50) { //Hit
								if (enemyList.at(index)->getShields() > 0) { //Shields are still up
									enemyList.at(index)->setShields(enemyList.at(index)->getShields() - 5);
								}
								else { //Laser hits hull
									enemyList.at(index)->setHull(enemyList.at(index)->getHull() - 5);
									if (enemyList.at(index)->getHull() <= 0.0) {
										enemyList.at(index)->setType("destroyedShip");
									}
								}
							}
						}
					}
					else { //Torpedoes
						for (int i = 0; i < shipPtr->getTorpedoTubes(); i++) {
							int index = randomEnemy(gen);
							if (outOf100(gen) < 25) { //Hit
								if (enemyList.at(index)->getShields() > 0) { //Shields are still up
									enemyList.at(index)->setShields(enemyList.at(index)->getShields() - 10);
								}
								else { //Torpedo hits hull
									enemyList.at(index)->setHull(enemyList.at(index)->getHull() - 10);
									if (enemyList.at(index)->getHull() <= 0.0) {
										enemyList.at(index)->setType("destroyedShip");
									}
								}
							}
						}
					}
				}
			}
			battleStage += 1;
			lastBattleTime = currentTime;
			generateTargetList();
		}
	}
}

void Game::newSector() {
	random_device seed;
	mt19937 gen(seed());
	uniform_int_distribution<int> stdRange(1, 10);
	uniform_int_distribution<int> halfRange(1, 2);

	int sectorSize = stdRange(gen);
	sector.resize(sectorSize);

	for (int i = 0; i < sectorSize; i++) {
		if (halfRange(gen) == 1) {
			sector.at(i) = new Planet();
		}
		else {
			sector.at(i) = new NPCShip();
		}
	}
	generateTargetList();
	sectorTab();
}

char Game::checkForInput() {
	if (_kbhit()) {
		int ch = _getch();

		if (ch == 0 || ch == 224) {
			int specialKey = _getch();

			switch (specialKey) {
				case 72: return '^';
				case 80: return 'v';
				case 75: return '<';
				case 77: return '>';
				default: return '?';
			}
		}

		if (ch == 13) {
			return '\n';
		}

		return static_cast<char>(ch);
	}
}

char Game::waitForInput() {
	int ch = _getch();

	if (ch == 0 || ch == 224) {
		int specialKey = _getch();

		switch (specialKey) {
		case 72: return '^';
		case 80: return 'v';
		case 75: return '<';
		case 77: return '>';
		default: return '?';
		}
	}

	if (ch == 13) {
		return '\n';
	}

	return static_cast<char>(ch);
}

void Game::resourceMove(Planet* planetPtr) {
	int cargoSpaceLeft = playerShip1->getCargoSpace() - (playerShip1->getFuel() + playerShip1->getTorpedoes());
	int totalSpace = planetPtr->getFuel() + planetPtr->getTorpedoes();
	if (cargoSpaceLeft > 0) {
		if (totalSpace < cargoSpaceLeft) {
			playerShip1->setFuel(playerShip1->getFuel() + planetPtr->getFuel());
			playerShip1->setTorpedoes(playerShip1->getTorpedoes() + planetPtr->getTorpedoes());
			planetPtr->setFuel(0);
			planetPtr->setTorpedoes(0);
		}
		else {
			while (cargoSpaceLeft > 0) {
				playerShip1->setFuel(playerShip1->getFuel() + 1);
				planetPtr->setFuel(planetPtr->getFuel() - 1);
				cargoSpaceLeft = playerShip1->getCargoSpace() - (playerShip1->getFuel() + playerShip1->getTorpedoes());
				playerShip1->setTorpedoes(playerShip1->getTorpedoes() + 1);
				planetPtr->setTorpedoes(planetPtr->getTorpedoes() - 1);
				cargoSpaceLeft = playerShip1->getCargoSpace() - (playerShip1->getFuel() + playerShip1->getTorpedoes());
				if (planetPtr->getFuel() == 0 && planetPtr->getTorpedoes() == 0) {
					break;
				}
			}
		}
	}
	while (playerShip1->getCrew() < playerShip1->getMaxCrew()) {
		playerShip1->setCrew(playerShip1->getCrew() + 1);
		planetPtr->setCrew(planetPtr->getCrew() - 1);
		if (planetPtr->getCrew() == 0) {
			break;
		}
	}
}

bool Game::enemyInSector() {
	return true;
}

string Game::numToStr(double num) {
	ostringstream output;
	output << fixed << setprecision(1) << num;
	return output.str();
}

string Game::numToStr0(double num) {
	ostringstream output;
	output << fixed << setprecision(0) << num;
	return output.str();
}

void Game::generateTargetList() {
	enemyList.clear();
	friendlyList.clear();
	friendlyList.push_back(playerShip1);

	for (int i = 0; i < sector.size(); i++) {
		if (sector.at(i)->getType() == "ship") {
			NPCShip* shipPtr = dynamic_cast<NPCShip*>(sector.at(i));
			if (shipPtr->isEnemy()) {
				enemyList.push_back(shipPtr);
			}
			else {
				friendlyList.push_back(shipPtr);
			}
		}
	}
}

void Game::loseGame(string lossReason) {
	display1.clearScreen();
	display1.addGraphic(10, 10, "gameOver.txt");
	display1.addString(20, 40, "You lost because your " + lossReason + " reached zero. Better luck next time!");
	display1.drawScreen();
	exit(0);
}

double Game::roundToTens(double inputNum) {
	return (round(inputNum / 10.0) * 10.0);
}

void Game::repair() {
	playerShip1->setEngineHealth(playerShip1->getEngineHealth() + (playerShip1->getEngineCrew() * (0.5 * ((playerShip1->getLifeSupportPower() / 100) * (playerShip1->getLifeSupportHealth() / 100)))));
	if (playerShip1->getEngineHealth() > 100.0) {
		playerShip1->setEngineHealth(100.0);
	}
	playerShip1->setLaserHealth(playerShip1->getLaserHealth() + (playerShip1->getLaserCrew() * (0.5 * ((playerShip1->getLifeSupportPower() / 100) * (playerShip1->getLifeSupportHealth() / 100)))));
	if (playerShip1->getLaserHealth() > 100.0) {
		playerShip1->setLaserHealth(100.0);
	}
	playerShip1->setLifeSupportHealth(playerShip1->getLifeSupportHealth() + (playerShip1->getLifeSupportCrew() * (0.5 * ((playerShip1->getLifeSupportPower() / 100) * (playerShip1->getLifeSupportHealth() / 100)))));
	if (playerShip1->getLifeSupportHealth() > 100.0) {
		playerShip1->setLifeSupportHealth(100.0);
	}
	playerShip1->setReactorHealth(playerShip1->getReactorHealth() + (playerShip1->getReactorCrew() * (0.5 * ((playerShip1->getLifeSupportPower() / 100) * (playerShip1->getLifeSupportHealth() / 100)))));
	if (playerShip1->getReactorHealth() > 100.0) {
		playerShip1->setReactorHealth(100.0);
	}
	playerShip1->setShields(playerShip1->getShields() + (playerShip1->getShieldCrew() * (0.5 * ((playerShip1->getLifeSupportPower() / 100) * (playerShip1->getLifeSupportHealth() / 100)))));
	if (playerShip1->getShields() > playerShip1->getMaxShields()) {
		playerShip1->setShields(playerShip1->getMaxShields());
	}
	playerShip1->setHull(playerShip1->getHull() + (playerShip1->getHullCrew() * (0.5 * ((playerShip1->getLifeSupportPower() / 100) * (playerShip1->getLifeSupportHealth() / 100)))));
	if (playerShip1->getHull() > playerShip1->getMaxHull()) {
		playerShip1->setHull(playerShip1->getMaxHull());
	}
}

void Game::clearSector() {
	for (Object* obj : sector) {
		delete obj;
	}
	sector.clear();
}

void Game::saveGame() {
	string gameName;
	display1.clearScreen();
	display1.addString(5, 10, "What would you like to name your saved game?");
	display1.drawScreen();
	display1.setCursorPosition(20, 30);

	cin >> gameName;

	ofstream saveFile;

	saveFile.open(gameName + ".txt");

	saveFile << playerShip1->getShipSize() << endl;
	saveFile << playerShip1->getHull() << endl;
	saveFile << playerShip1->getShields() << endl;
	saveFile << playerShip1->getCrew() << endl;
	saveFile << playerShip1->getFuel() << endl;
	saveFile << playerShip1->getTorpedoes() << endl;
	saveFile << playerShip1->getLaserHealth() << endl;
	saveFile << playerShip1->getEngineHealth() << endl;
	saveFile << playerShip1->getReactorHealth() << endl;
	saveFile << playerShip1->getLifeSupportHealth() << endl;
	saveFile << playerShip1->getLaserPower() << endl;
	saveFile << playerShip1->getEnginePower() << endl;
	saveFile << playerShip1->getLifeSupportPower() << endl;
	saveFile << playerShip1->getShieldPower() << endl;
	saveFile << playerShip1->getReactorOutput() << endl;
	saveFile << playerShip1->getAuxPower() << endl;
	saveFile << playerShip1->getEngineCrew() << endl;
	saveFile << playerShip1->getLaserCrew() << endl;
	saveFile << playerShip1->getLifeSupportCrew() << endl;
	saveFile << playerShip1->getReactorCrew() << endl;
	saveFile << playerShip1->getShieldCrew() << endl;
	saveFile << playerShip1->getHullCrew() << endl;

	saveFile.close();

	display1.clearScreen();
	display1.addString(5, 10, "Game saved!");
	display1.drawScreen();
	sectorTab();
}

void Game::startGame() {
	display1.clearScreen();
	display1.addString(10, 5, "Welcome to the game! Please make sure the console window is running in fullscreen");
	display1.addString(10, 10, "If you are on Windows 11, please enter the console settings and");
	display1.addString(10, 12, "make sure you are running the Windows Console Host rather than the default Windows Terminal");
	display1.addString(10, 25, "Use the arrow keys and the Enter key to interact with menus");
	display1.addString(10, 35, "Press any key to continue...");
	display1.drawScreen();
	waitForInput();
	titleScreen();
}