#include "Simulation.h"

using namespace std;

// constructor
	Simulation::Simulation() { width = height = time = nbRide = nbVehicle = 0; }
// operators
	ostream& Simulation::operator<<(ostream& os) const {
		// TODO: insérer une instruction return ici
		return os;
	}
	istream& Simulation::operator>>(istream& is) {
		// TODO: insérer une instruction return ici
		return is;
	}
// others
	void Simulation::run() {
		loadFiles("a_example.in");
		vector<int> deleteMe;

		while (vectRide.size()) {
			for (int j = 0; j < vectRide.size(); ++j) {
				for (unsigned int i = 0; i < inactiveVehicle.size(); ++i) {
					if (time + (vectRide[j].getFinish() - inactiveVehicle[i].getPosition()) <= vectRide[j].getLatest()) {
						deleteMe.push_back(j);
						activeVehicle.push_back(inactiveVehicle[i]);
						inactiveVehicle.erase(inactiveVehicle.begin() + i);
						i = (unsigned int)inactiveVehicle.size();
					}
				}
			}
			for (int i = 0; i < deleteMe.size(); ++i)
				vectRide.erase(vectRide.begin() + (deleteMe[i] - i));

			deleteMe.clear();

			for (int i = 0; i < activeVehicle.size(); ++i) {
				if (activeVehicle[i].moveToDest()) {
					inactiveVehicle.push_back(activeVehicle[i]);
					activeVehicle.erase(activeVehicle.begin() + i);
				}
			}
			++time;
		}
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

			intersection start, end;
			unsigned int startLine, deadLine;
			for (unsigned int i = 0; i < nbRide; ++i) {
				file >> start >> end >> startLine >> deadLine;
				vectRide.emplace_back(start, end, startLine, deadLine);
			}
		}
	}
