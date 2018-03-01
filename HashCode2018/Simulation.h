#pragma once

#include "Vehicle.h"

#include <vector>
#include <fstream>

class Simulation {
	private:
		std::vector<Vehicle> activeVehicle;
		std::vector<Vehicle> inactiveVehicle;
		std::vector<Ride> vectRide;
		unsigned int nbVehicle;
		unsigned int nbRide;
		unsigned int time;
		unsigned int height;
		unsigned int width;
		unsigned int bonus;
	public:
		Simulation();
		void run();
		void loadFiles(std::string filename);
		void display();
};
