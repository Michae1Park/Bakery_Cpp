#include <iostream>
#include "Observer.h"

class NumBreadDisplay : Observer {
private:
	int runs, wickets;
	float overs;

public:
	void update(int runs, int wickets, float overs) {
		runs = runs;
		wickets = wickets;
		overs = overs;
		display();
	}

	void display() {
		std::cout << "runs: " + runs << std::endl;
	}
};