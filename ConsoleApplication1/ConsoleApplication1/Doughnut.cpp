#include <iostream>
#include "Bread.h"

class Doughnut : public Bread {
public:
	void displayBread() {
		std::cout << "Doughnut" << std::endl;
	}
};