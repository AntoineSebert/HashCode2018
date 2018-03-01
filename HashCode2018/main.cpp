#include "main.hpp"

/**
* This function allow us to load the input files
* filename is the name of the file we want to use
*/
void loadFiles(string filename){
	
	string filepath = "../inputFiles" + filename;

	ifstream file(filepath, ios::in);
	
	if(!file)
		cout << "erreur chargement fichier" << endl;
		return ;
	else{
		unsigned int rows, columns, nb_rides, bonus;
		unsigned long int steps;

		file >> rows >> columns >> nb_rides >> bonus >> steps;

		std::array<Ride, nb_rides> Rides;

		for(int i = 0; i < nb_rides; i++){

			unsigned int startX, startY, endX, endY, startLine, deadLine;

			file >> startX >> startY >> endX >> endY >> startLine >> deadLine;

			Rides[i] = new Ride(new intersection(startX, startY), new intersection(endX,endY), startLine, deadLine);

		}

		cout << rows << "; " << columns << "; " << nb_rides << "; " << bonus << "; " << steps << endl;

	}
}


int main(int ac, char** av) {

	loadFiles("a_example.in");

	return 0;
}