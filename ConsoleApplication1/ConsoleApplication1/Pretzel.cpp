#include <iostream>
#include "Bread.h"

class Pretzel : public Bread {
public:
	void displayBread() {
		std::cout << "Pretzel" << std::endl;
	}
};