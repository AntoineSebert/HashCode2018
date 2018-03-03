#pragma once

#include <iostream>

#include "intersection.hpp"

class Ride {
	private:
		intersection start, finish;
		unsigned int earliest, latest;
	public:
		// constructors
			Ride(intersection start, intersection finish, unsigned int earliest, unsigned int latest);
			Ride() = delete;
		// getters
			intersection getStart() const;
			intersection getFinish() const;
			unsigned int getEarliest() const;
			unsigned int getLatest() const;
		// operators
			std::ostream& operator<<(std::ostream& os) const;
			std::istream& operator>>(std::istream& is);
};

