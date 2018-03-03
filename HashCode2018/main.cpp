#include "main.hpp"

using namespace std;

int main(int argc, char** argv) {
	/*
	if (argc != 2) {
		// Tell the user how to run the program
		std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
		return 1;
	}
	// Print the user's name:
	std::cout << argv[0] << "says hello, " << argv[1] << "!" << std::endl;
	*/
	cout << argc << endl;
	Simulation simul = Simulation();
	simul.loadFile("a_example.in");
	simul.run();

	system("pause");
	
	return 0;
}