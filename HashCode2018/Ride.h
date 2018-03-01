#pragma once

#include "main.hpp"

class Ride {
	private:
		intersection start, finish;
		unsigned int earliest, latest;
	public:
		Ride() = delete;
		~Ride();
};

