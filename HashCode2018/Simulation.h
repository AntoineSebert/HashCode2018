#pragma once

#include "Vehicle.h"

#include <vector>
#include <string>
#include <fstream>

class Simulation {
	private:
		std::vector<Vehicle> activeVehicle, inactiveVehicle;
		std::vector<Ride> rides;
		unsigned int nbVehicle, nbRide;
		unsigned int time;
		unsigned int height, width;
		unsigned int bonus;
		std::string fileLoaded;
	public:
		// constructor
			Simulation();
		// operators
			std::ostream& operator<<(std::ostream& os) const;
		// others
			void run();
			void loadFile(std::string filename);
			void updateVehiclesStatus();
};
