#pragma once

#include "Vehicle.cpp"
#include "Ride.cpp"

class Simulation {
private:
	int nbVehicle;
	int nbRide;
	int time;
	int height;
	int width;
protected:
	Simulation();
	void run();
};
