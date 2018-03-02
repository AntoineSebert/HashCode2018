#include "Vehicle.h"

using namespace std;

unsigned int Vehicle::counter = 0;

// constructors
	Vehicle::Vehicle() {
		id = Vehicle::counter;
		++Vehicle::counter;
	}
	Vehicle::~Vehicle() {}
// getters
	intersection Vehicle::getPosition() { return position; }
// setters
	void Vehicle::setDestination(intersection dest) { destination = dest; }
// operators
	ostream& Vehicle::operator<<(ostream& os) const {
		os << id << "=pos(" << position << "), dest(" << destination << "), rides{";
		for (Ride* ride : rides)
			os << ride;
		os << '}';
	}
// others
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
	bool Vehicle::active() { return !rides.empty(); }