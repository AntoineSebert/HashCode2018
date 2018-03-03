#include "Ride.h"

using namespace std;

// constructors
	Ride::Ride(intersection start, intersection finish, unsigned int earliest, unsigned int latest) : start(start), finish(finish), earliest(earliest), latest(latest) {}
// getters
	intersection Ride::getStart() const { return start; }
	intersection Ride::getFinish() const { return finish; }
	unsigned int Ride::getEarliest() const { return earliest; }
	unsigned int Ride::getLatest() const { return latest; }
// operators
	ostream& Ride::operator<<(ostream& os) const { return os << "r=" << start << ':' << finish << '|' << earliest << ':' << latest; }
	istream& Ride::operator>>(istream& is) { return is >> start >> finish >> earliest >> latest; }
