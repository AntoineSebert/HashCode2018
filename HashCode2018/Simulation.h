#pragma once

#include "Vehicle.cpp"
#include "Ride.cpp"
#include <vector>

class Simulation {
private:
  vector<Vehicle> vectVehicle;
  vector<Vehicle> vectRide;
	int nbVehicle;
	int nbRide;
	int time;
	int height;
	int width;
protected:
	Simulation();
	void run();
};
