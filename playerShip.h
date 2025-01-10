#pragma once
#include "Ship.h"

class playerShip : public Ship {
public:
	playerShip(string);
	int getCrew();
	int getMaxCrew();
	int getFuel();
	int getTorpedoes();
	int getCargoSpace();
	double getLaserHealth();
	double getEngineHealth();
	double getReactorHealth();
	double getLifeSupportHealth();
	double getLaserPower();
	double getEnginePower();
	double getAuxPower();
	double getLifeSupportPower();
	double getShieldPower();
	double getReactorOutput();
	double getMaxReactorOutput();
	int getEngineCrew();
	int getLaserCrew();
	int getReactorCrew();
	int getLifeSupportCrew();
	int getShieldCrew();
	int getHullCrew();
	int crewWorking();
	void setCrew(int);
	void setMaxCrew(int);
	void setFuel(int);
	void setTorpedoes(int);
	void setCargoSpace(int);
	void setLaserHealth(double);
	void setEngineHealth(double);
	void setReactorHealth(double);
	void setLifeSupportHealth(double);
	void setLaserPower(double);
	void setEnginePower(double);
	void setAuxPower(double);
	void setLifeSupportPower(double);
	void setShieldPower(double);
	void setReactorOutput(double);
	void setEngineCrew(int);
	void setLaserCrew(int);
	void setReactorCrew(int);
	void setLifeSupportCrew(int);
	void setShieldCrew(int);
	void setHullCrew(int);
	double totalPowerUsage();
	void setShipSize(string);
	string getShipSize();

private:
	int crew;
	int maxCrew;
	int fuel;
	int torpedoes;
	int cargoSpace;
	double laserHealth;
	double engineHealth;
	double reactorHealth;
	double lifeSupportHealth;
	double laserPower;
	double enginePower;
	double auxPower;
	double lifeSupportPower;
	double shieldPower;
	double reactorOutput;
	double maxReactorOutput;
	int engineCrew;
	int laserCrew;
	int reactorCrew;
	int lifeSupportCrew;
	int shieldCrew;
	int hullCrew;
	string playerShipSize;
};

