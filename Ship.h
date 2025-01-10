#pragma once
#include "Object.h"
#include <string>

class Ship : public Object {
public:
	double getHull();
	double getShields();
	double getMaxHull();
	double getMaxShields();
	int getTorpedoTubes();
	int getLaserBanks();
	void setHull(double);
	void setMaxHull(double);
	void setShields(double);
	void setMaxShields(double);
	void setTorpedoTubes(int);
	void setLaserBanks(int);
private:
	double hull;
	double maxHull;
	double shields;
	double maxShields;
	int torpedoTubes;
	int laserBanks;
};

