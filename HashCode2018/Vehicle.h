#pragma once

#include "Ride.h"

#include <list>

class Vehicle {
	private:
		intersection position, destination;
		std::list<Ride*> rides;
		static unsigned int counter;
		unsigned int id;
	public:
		// constructors
			Vehicle();
			~Vehicle();
		// getters
			intersection getPosition();
		// setters
			void setDestination(intersection dest);
		// operators
			std::ostream& operator<<(std::ostream& os) const;
		// others
			bool moveToDest();
			void addRide(Ride* ride);
			bool active();
};

