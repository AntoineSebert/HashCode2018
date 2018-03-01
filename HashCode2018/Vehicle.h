#pragma once

#include "Ride.h"

#include <list>

class Vehicle {
	private:
		intersection position, destination;
		std::list<Ride*> rides;
	public:
		void setDestination(intersection dest);
		void addRide(Ride* ride);
		intersection getPosition();
		bool active();
		Vehicle();
		~Vehicle();
};

