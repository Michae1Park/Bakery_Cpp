#include <iostream>
#include "Bread.h"

class Muffin : public Bread {
public:
	void displayBread() {
		std::cout << "Muffin" << std::endl;
	}
};