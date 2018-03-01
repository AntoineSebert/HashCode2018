#pragma once

#include "Ride.h"

class Vehicle {
	private:
		intersection position;
		bool isRiding;
		intersection destination;
	public:
		void setDestination(int x, int y);
		bool isFull();
		Vehicle();
		~Vehicle();
};

