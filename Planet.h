#pragma once
#include "Object.h"
class Planet : public Object {
public:
	Planet();
	int getFuel();
	int getTorpedoes();
	int getCrew();
	void setFuel(int);
	void setTorpedoes(int);
	void setCrew(int);
private:
	int fuel;
	int torpedoes;
	int crew;
};

