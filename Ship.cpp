#include "Ship.h"

double Ship::getHull() {
	return hull;
}

double Ship::getShields() {
	return shields;
}

double Ship::getMaxHull() {
	return maxHull;
}

double Ship::getMaxShields() {
	return maxShields;
}

int Ship::getTorpedoTubes() {
	return torpedoTubes;
}
int Ship::getLaserBanks() {
	return laserBanks;
}

void Ship::setHull(double newHull) {
	if (newHull < 0) {
		hull = 0;
	}
	else {
		hull = newHull;
	}
}

void Ship::setMaxHull(double newMaxHull) {
	maxHull = newMaxHull;
}

void Ship::setShields(double newShields) {
	if (newShields < 0) {
		shields = 0;
	}
	else {
		shields = newShields;
	}
}

void Ship::setMaxShields(double newMaxShields) {
	maxShields = newMaxShields;
}

void Ship::setTorpedoTubes(int newTorpedoTubes) {
	torpedoTubes = newTorpedoTubes;
}

void Ship::setLaserBanks(int newLaserBanks) {
	laserBanks = newLaserBanks;
}