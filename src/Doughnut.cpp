#include <iostream>
#include "Doughnut.h"

Doughnut::Doughnut() : Bread("Doughnut", BT_Doughnut, 426, 3.75, 15) {}; //label, type, calories, price, stock
Doughnut::~Doughnut() {};

void Doughnut::displayBread() {
	std::cout << "Doughnut" << std::endl;
}
