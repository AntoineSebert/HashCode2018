#include "main.hpp"

using namespace std;

int main(int argc, char** argv) {
	/*
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " file" << endl;
		return 1;
	}
	*/
	Simulation simul = Simulation();
	//simul.loadFile(argv[1]);
	simul.loadFile("a_example.in");
	simul.run();
	simul.exportToFile();

	system("pause");
	
	return 0;
}