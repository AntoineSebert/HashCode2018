#include "Vehicle.h"

using namespace std;

void Vehicle::setDestination(intersection dest) { destination = dest; }

bool Vehicle::moveToDest() {
	if (position.first < destination.first)
		++position.first;
	else if (destination.first < position.first)
		--position.first;
	else {
		if (position.second < destination.second)
			++position.second;
		else if (destination.second < position.second)
			--position.second;
	}
	
	return position == destination;
}

void Vehicle::addRide(Ride* ride) { rides.push_back(ride); }

intersection Vehicle::getPosition() { return position; }

bool Vehicle::active() { return !rides.empty(); }

Vehicle::Vehicle() {}


Vehicle::~Vehicle() {}