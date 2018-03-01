#include "Simulation.h"

using namespace std;

Simulation::Simulation() {
	width = height = time = nbRide = nbVehicle = 0;
}

void Simulation::run(){
	loadFiles("a_example.in");
	for (const auto& element : vectRide) {

	}
	/*
	for(unsigned int i=0; i<nbRide;++i){
		for(unsigned int j=0; j<nbVehicle;++j){
      
		}
	}
	*/
}

void Simulation::loadFiles(string filename) {
	string filepath = "../inputFiles/" + filename;

	ifstream file(filepath, ios::in);

	if (!file) {
		cout << "erreur chargement fichier" << endl;
		return;
	}
	else {
		auto steps = pow(10, 9);
		steps = 0;

		file >> height >> width >> nbRide >> bonus >> time;

		unsigned int startX, startY, endX, endY, startLine, deadLine;
		for (unsigned int i = 0; i < nbRide; ++i) {
			file >> startX >> startY >> endX >> endY >> startLine >> deadLine;

			vectRide.emplace_back(intersection(startX, startY), intersection(endX, endY), startLine, deadLine);
		}
	}
}

void Simulation::display() {
	/*
	std::vector<Vehicle> activeVehicle;
	std::vector<Vehicle> inactiveVehicle;
	std::vector<Ride> vectRide;
	unsigned int nbVehicle;
	unsigned int nbRide;
	unsigned int time;
	unsigned int height;
	unsigned int width;
	unsigned int bonus;
	*/
}
