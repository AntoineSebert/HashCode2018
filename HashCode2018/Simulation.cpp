#include "Simulation.h"

using namespace std;

// constructor
	Simulation::Simulation() { width = height = maximalTime = nbRide = nbVehicle = 0; }
// operators
	ostream& Simulation::operator<<(ostream& os) const {
		os << fileLoaded << "=(height:" << height << ",width:" << width << "),(time:" << maximalTime << ",bonus:" << bonus << ')' << endl;
		os << "vehicles:" << nbVehicle << endl;
		os << "active vehicles:" << activeVehicle.size() << endl;
		/*
		for (const auto& element : activeVehicle)
			os << element << endl;
		os << "inactive vehicles:" << inactiveVehicle.size() << endl;
		for (const auto& element : inactiveVehicle)
			os << element << endl;
		os << "rides:" << activeVehicle.size() << endl;
		for (const auto& element : rides)
			os << element << endl;
		*/
		return os;
	}
// others
	void Simulation::run() {
		vector<int> deleteMe;
		unsigned int time = 0;

		cout << "Running... " << endl;

		while (rides.size() && time < maximalTime) {
			for (int j = 0; j < rides.size(); ++j) {
				if(time > rides.at(j).getLatest()){
					deleteMe.push_back(j);
					continue;
				}
				for (unsigned int i = 0; i < inactiveVehicle.size(); ++i) {
					if (time + (rides.at(j).getFinish() - inactiveVehicle.at(i).getPosition()) <= rides.at(j).getLatest()) {
						//deleteMe.push_back(j);
						//activeVehicle.push_back(inactiveVehicle.at(i));

						inactiveVehicle.erase(inactiveVehicle.begin() + i);
						i = (unsigned int)inactiveVehicle.size();
					}
				}
			}
			updateRides(deleteMe);
			updateVehiclesStatus();
			++time;
		}

		cout << "Heuristic completed" << endl;
	}
	void Simulation::loadFile(string filename) {
		ifstream file(filename, ios::in);

		if (!file) {
			cerr << "error loading the file " << filename << endl;
			return;
		}
		else {
			cout << "loading file " << filename << "..." << endl;
			auto steps = pow(10, 9);
			steps = 0;
			fileLoaded = filename;

			file >> height >> width >> nbVehicle >> nbRide >> bonus >> maximalTime;
			
			for (unsigned int i = 0; i < nbVehicle; ++i)
				inactiveVehicle.push_back(Vehicle());
			
			intersection start, end;
			unsigned int startLine, deadLine;
			rides.clear();
			for (unsigned int i = 0; i < nbRide; ++i) {
				file >> start >> end >> startLine >> deadLine;
				rides.emplace_back(start, end, startLine, deadLine);
			}
			cout << "file loaded" << endl;
		}

	}
	void Simulation::exportToFile() {
		string outputfile = fileLoaded.substr(0, fileLoaded.find('.'));
		ofstream os(outputfile + ".out", std::ofstream::out);

		cout << "Exporting data to " << outputfile << "..." << endl;

		for (const auto& vehicle : inactiveVehicle) {
			os << vehicle.getRidesCount() << ' ';
			for (unsigned int i = 0; i < vehicle.getRides().size(); ++i)
				os << i << ' ';
			os << endl;
		}

		os.close();
		cout << "Exportation done" << endl;
	}

	void Simulation::updateVehiclesStatus() {
		for (auto it = activeVehicle.begin(); it != activeVehicle.end(); ++it) {
			if (it->moveToDest())
				move(it, it + 1, back_inserter(inactiveVehicle));
		}
	}
	void Simulation::updateRides(vector<int>& toDelete) {
		for (unsigned int i = 0; i < toDelete.size(); ++i)
			rides.erase(rides.begin() + (toDelete.at(i) - i));
		toDelete.clear();
	}
