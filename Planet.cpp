#include "Planet.h"
#include <random>

using namespace std;

Planet::Planet() {
	random_device seed;
	mt19937 gen(seed());
	uniform_int_distribution<int> stdRange(0, 10);

	fuel = stdRange(gen);
	torpedoes = stdRange(gen);
	crew = (stdRange(gen) / 3);
	setType("planet");
}

int Planet::getFuel() {
	return fuel;
}

int Planet::getTorpedoes() {
	return torpedoes;
}

int Planet::getCrew() {
	return crew;
}

void Planet::setFuel(int newFuel) {
	fuel = newFuel;
}

void Planet::setTorpedoes(int newTorpedoes) {
	torpedoes = newTorpedoes;
}

void Planet::setCrew(int newCrew) {
	crew = newCrew;
}