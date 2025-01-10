#include "NPCShip.h"
#include <random>

NPCShip::NPCShip() {
	random_device seed;
	mt19937 gen(seed());
	uniform_int_distribution<int> stdRange(1, 10);

	setType("ship");

	int chanceValue = stdRange(gen);

	if (chanceValue <= 6) { enemy = true; }
	else { enemy = false; }

	chanceValue = stdRange(gen);

	if (chanceValue <= 4) {
		size = "Scout";
		setTorpedoTubes(2);
		setLaserBanks(3);
		setHull(50.0);
		setMaxHull(50.0);
		setShields(50.0);
		setMaxShields(50.0);
	}
	else {
		if (chanceValue <= 7) {
			size = "Frigate";
			setTorpedoTubes(4);
			setLaserBanks(8);
			setHull(75.0);
			setMaxHull(75.0);
			setShields(75.0);
			setMaxShields(75.0);
		}
		else {
			if (chanceValue <= 10) {
				size = "Battleship";
				setTorpedoTubes(5);
				setLaserBanks(11);
				setHull(100.0);
				setMaxHull(100.0);
				setShields(100.0);
				setMaxShields(100.0);
			}
		}
	}
}

bool NPCShip::isEnemy() {
	return enemy;
}

string NPCShip::getSize() {
	return size;
}

void NPCShip::setEnemy(bool newEnemy) {
	enemy = newEnemy;
}

void NPCShip::setSize(string newSize) {
	size = newSize;
}