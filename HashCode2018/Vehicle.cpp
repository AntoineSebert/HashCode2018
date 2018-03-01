#include "Vehicle.h"

using namespace std;

void Vehicle::setDestination(intersection dest) { destination = dest; }

void Vehicle::addRide(Ride* ride) { rides.push_back(ride); }

intersection Vehicle::getPosition() { return position; }

bool Vehicle::active() { return !rides.empty(); }

Vehicle::Vehicle() {}


Vehicle::~Vehicle() {}