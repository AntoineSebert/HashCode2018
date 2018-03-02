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
			// input stream operator to read files ?
			// ouput stream
		// others
			void run();
			void loadFiles(std::string filename);
			void display();
};
