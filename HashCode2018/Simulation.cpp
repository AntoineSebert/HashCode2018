#include "Simulation.h"

using namespace std;

Simulation::Simulation() {
	width = height = time = nbRide = nbVehicle = 0;
}

void Simulation::run(){
	loadFiles("a_example.in");
	/*
	for (const auto& element : vectRide) {

	}
	for(unsigned int i=0; i<nbRide;++i){
		for(unsigned int j=0; j<nbVehicle;++j){
      
		}
	}
	*/
}


void Simulation::loadFiles(string filename) {
	string filepath = "../inputFiles" + filename;

	ifstream file(filepath, ios::in);

	if (!file) {
		cout << "erreur chargement fichier" << endl;
		return;
	}
	else {
		unsigned int rows, columns, nb_rides, bonus;
		auto steps = pow(10, 9);
		steps = 0;

		file >> rows >> columns >> nb_rides >> bonus >> steps;

		std::vector<Ride> Rides;
		unsigned int startX, startY, endX, endY, startLine, deadLine;
		for (unsigned int i = 0; i < nb_rides; ++i) {
			file >> startX >> startY >> endX >> endY >> startLine >> deadLine;

			Rides.emplace_back(intersection(startX, startY), intersection(endX, endY), startLine, deadLine);
		}

		cout << rows << "; " << columns << "; " << nb_rides << "; " << bonus << "; " << steps << endl;
	}
}