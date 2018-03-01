#include "Ride.h"

using namespace std;

Ride::Ride(intersection start, intersection finish, unsigned int earliest, unsigned int latest) : start(start), finish(finish), earliest(earliest), latest(latest) {}

std::ostream& Ride::operator<<(std::ostream& os) const {
	return os << "start =" << start << ':' << finish << '|' << earliest << ':' << latest;
}

intersection Ride::getStart() { return start; }

intersection Ride::getFinish() { return finish; }

unsigned int Ride::getEarliest() { return earliest; }

unsigned int Ride::getLatest() { return latest; }