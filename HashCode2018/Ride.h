#pragma once

#include <iostream>

#include "main.hpp"

class Ride {
	private:
		intersection start, finish;
		unsigned int earliest, latest;
	public:
		Ride() = delete;
		Ride(intersection start, intersection finish, unsigned int earliest, unsigned int latest);
		std::ostream& operator<<(std::ostream& os);
};

