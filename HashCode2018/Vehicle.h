#pragma once

#include "main.hpp"
#include "Ride.h"

class Vehicle {
	private:
		intersection position;
		bool isRiding;
		intersaction destination;
	public:
		void setDestination(int x, int y);
		bool isFull();
		Vehicle();
		~Vehicle();
};

