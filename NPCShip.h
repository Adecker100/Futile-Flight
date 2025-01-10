#pragma once
#include "Ship.h"

class NPCShip : public Ship {
public:
	NPCShip();
	bool isEnemy();
	string getSize();
	void setEnemy(bool);
	void setSize(string);
private:
	bool enemy;
	string size;
};

