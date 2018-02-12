#include <iostream>
#include "Pretzel.h"

Pretzel::Pretzel() : Bread("Pretzel", BT_Pretzel, 108, 5.65, 15) {}; //label, type, calories, price, stock
Pretzel::~Pretzel() {};

void Pretzel::displayBread() {
	std::cout << "Pretzel" << std::endl;
}
