#include "playerShip.h"
#include <string>

using namespace std;

playerShip::playerShip(string shipSize) {
	setType("playerShip");
	playerShipSize = shipSize;
	if (shipSize == "Scout") {
		setTorpedoTubes(2);
		setLaserBanks(3);
		setHull(50.0);
		setMaxHull(50.0);
		setShields(50.0);
		setMaxShields(50.0);
		maxCrew = 10;
		crew = 10;
		cargoSpace = 50;
		fuel = 25;
		torpedoes = 25;
		laserHealth = 100.0;
		engineHealth = 100.0;
		reactorHealth = 100.0;
		lifeSupportHealth = 100.0;
		laserPower = 100.0;
		enginePower = 100.0;
		lifeSupportPower = 100.0;
		shieldPower = 100.0;
		reactorOutput = 440.0;
		maxReactorOutput = 440.0;
		auxPower = 40.0;
		engineCrew = 0;
		laserCrew = 0;
		lifeSupportCrew = 0;
		reactorCrew = 0;
		shieldCrew = 0;
		hullCrew = 0;
	}
	if (shipSize == "Frigate") {
		setTorpedoTubes(4);
		setLaserBanks(8);
		setHull(75.0);
		setMaxHull(75.0);
		setShields(75.0);
		setMaxShields(75.0);
		maxCrew = 20;
		crew = 20;
		cargoSpace = 100;
		fuel = 50;
		torpedoes = 50;
		laserHealth = 100.0;
		engineHealth = 100.0;
		reactorHealth = 100.0;
		lifeSupportHealth = 100.0;
		laserPower = 100.0;
		enginePower = 100.0;
		lifeSupportPower = 100.0;
		shieldPower = 100.0;
		reactorOutput = 480.0;
		maxReactorOutput = 480.0;
		auxPower = 80.0;
		engineCrew = 0;
		laserCrew = 0;
		lifeSupportCrew = 0;
		reactorCrew = 0;
		shieldCrew = 0;
		hullCrew = 0;
	}
	if (shipSize == "Battleship") {
		setTorpedoTubes(5);
		setLaserBanks(11);
		setHull(100.0);
		setMaxHull(100.0);
		setShields(100.0);
		setMaxShields(100.0);
		maxCrew = 30;
		crew = 30;
		cargoSpace = 175;
		fuel = 75;
		torpedoes = 100;
		laserHealth = 100.0;
		engineHealth = 100.0;
		reactorHealth = 100.0;
		lifeSupportHealth = 100.0;
		laserPower = 100.0;
		enginePower = 100.0;
		lifeSupportPower = 100.0;
		shieldPower = 100.0;
		reactorOutput = 520.0;
		maxReactorOutput = 520.0;
		auxPower = 120.0;
		engineCrew = 0;
		laserCrew = 0;
		lifeSupportCrew = 0;
		reactorCrew = 0;
		shieldCrew = 0;
		hullCrew = 0;
	}
}

int playerShip::getCrew() { return crew; }
int playerShip::getMaxCrew() { return maxCrew; }
int playerShip::getFuel() { return fuel; }
int playerShip::getTorpedoes() { return torpedoes; }
int playerShip::getCargoSpace() { return cargoSpace; }
double playerShip::getLaserHealth() { return laserHealth; }
double playerShip::getEngineHealth() { return engineHealth; }
double playerShip::getReactorHealth() { return reactorHealth; }
double playerShip::getLifeSupportHealth() { return lifeSupportHealth; }
double playerShip::getLaserPower() { return laserPower; }
double playerShip::getEnginePower() { return enginePower; }
double playerShip::getAuxPower() { return auxPower; }
double playerShip::getLifeSupportPower() { return lifeSupportPower; }
double playerShip::getShieldPower() { return shieldPower; }
double playerShip::getReactorOutput() { return reactorOutput; }
int playerShip::getEngineCrew() { return engineCrew; }
int playerShip::getLaserCrew() { return laserCrew; }
int playerShip::getReactorCrew() { return reactorCrew; }
int playerShip::getLifeSupportCrew() { return lifeSupportCrew; }
int playerShip::getShieldCrew() { return shieldCrew; }
int playerShip::getHullCrew() { return hullCrew; }
void playerShip::setCrew(int newCrew) { if (newCrew <= maxCrew) { crew = newCrew; } }
void playerShip::setMaxCrew(int newMaxCrew) {
	maxCrew = newMaxCrew;
}
void playerShip::setFuel(int newFuel) {
	fuel = newFuel;
}
void playerShip::setTorpedoes(int newTorpedoes) {
	torpedoes = newTorpedoes;
}
void playerShip::setCargoSpace(int newCargoSpace) {
	cargoSpace = newCargoSpace;
}
void playerShip::setLaserHealth(double newLaserHealth) {
	laserHealth = newLaserHealth;
}
void playerShip::setEngineHealth(double newEngineHealth) {
	engineHealth = newEngineHealth;
}
void playerShip::setReactorHealth(double newReactorHealth) {
	reactorHealth = newReactorHealth;
}
void playerShip::setLifeSupportHealth(double newLifeSupportHealth) {
	lifeSupportHealth = newLifeSupportHealth;
}
void playerShip::setLaserPower(double newLaserPower) {
	laserPower = newLaserPower;
}
void playerShip::setEnginePower(double newEnginePower) {
	enginePower = newEnginePower;
}
void playerShip::setAuxPower(double newAuxPower) {
	auxPower = newAuxPower;
}
void playerShip::setLifeSupportPower(double newLifeSupportPower) {
	lifeSupportPower = newLifeSupportPower;
}
void playerShip::setShieldPower(double newShieldPower) {
	shieldPower = newShieldPower;
}
void playerShip::setReactorOutput(double newReactorOutput) {
	reactorOutput = newReactorOutput;
}
void playerShip::setEngineCrew(int newEngineCrew) {
	engineCrew = newEngineCrew;
}
void playerShip::setLaserCrew(int newLaserCrew) {
	laserCrew = newLaserCrew;
}
void playerShip::setReactorCrew(int newReactorCrew) {
	reactorCrew = newReactorCrew;
}
void playerShip::setLifeSupportCrew(int newLifeSupportCrew) {
	lifeSupportCrew = newLifeSupportCrew;
}
void playerShip::setShieldCrew(int newShieldCrew) {
	shieldCrew = newShieldCrew;
}
void playerShip::setHullCrew(int newHullCrew) {
	hullCrew = newHullCrew;
}

int playerShip::crewWorking() {
	int numWorking = 0;
	numWorking = numWorking + getEngineCrew();
	numWorking = numWorking + getLaserCrew();
	numWorking = numWorking + getLifeSupportCrew();
	numWorking = numWorking + getReactorCrew();
	numWorking = numWorking + getShieldCrew();
	numWorking = numWorking + getHullCrew();

	return numWorking;
}

double playerShip::getMaxReactorOutput() {
	return maxReactorOutput;
}

double playerShip::totalPowerUsage() {
	double totalPower = 0;
	totalPower = totalPower + shieldPower;
	totalPower = totalPower + laserPower;
	totalPower = totalPower + enginePower;
	totalPower = totalPower + lifeSupportPower;
	return totalPower;
}

void playerShip::setShipSize(string newShipSize) {
	playerShipSize = newShipSize;
}
string playerShip::getShipSize() {
	return playerShipSize;
}