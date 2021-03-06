#pragma once

#include "Vehicle.h"

#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Simulation {
	private:
		std::vector<Vehicle> activeVehicle, inactiveVehicle;
		std::vector<Ride> rides;
		unsigned int nbVehicle, nbRide;
		unsigned int maximalTime, bonus;
		unsigned int height, width;
		std::string fileLoaded;
	public:
		// constructor
			Simulation();
		// operators
			std::ostream& operator<<(std::ostream& os) const;
		// others
			void run();
			void loadFile(std::string filename);
			void exportToFile();
	private:
		void updateVehiclesStatus();
		void updateRides(std::vector<int>& toDelete);
};
