#pragma once

#include "Vehicle.h"

#include <vector>
#include <fstream>

class Simulation {
	private:
		std::vector<Vehicle> activeVehicle, inactiveVehicle;
		std::vector<Ride> vectRide;
		unsigned int nbVehicle, nbRide;
		unsigned int time;
		unsigned int height, width;
		unsigned int bonus;
	public:
		// constructor
			Simulation();
		// operators
			std::ostream& operator<<(std::ostream& os) const;
			std::istream& operator>>(std::istream& is);
		// others
			void run();
			void loadFiles(std::string filename);
};
