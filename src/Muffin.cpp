#include <iostream>
#include "Muffin.h"

Muffin::Muffin() : Bread ("Muffin", BT_Muffin, 426, 3.75, 15) {}; //label, type, calories, price, stock
// Muffin::~Muffin() {};

void Muffin:: displayBread() {
	std::cout << "Muffin" << std::endl;	
}
