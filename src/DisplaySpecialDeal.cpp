#include <iostream>
#include <string>
#include "DisplaySpecialDeal.h"

DisplaySpecialDeal::DisplaySpecialDeal(Inventory *mod) : Observer(mod) {}

void DisplaySpecialDeal::update() {
	std::cout << "---------- Special Deal! ------------" << std::endl;
	std::cout << " Buy 5 get 20% off! " << std::endl;
	for (std::pair<BreadType, Bread*> element : getInventory()->getBreads()) {
		std::cout << element.second->getLabel() << " : $" << element.second->price_ << " each, " << 5*0.8*element.second->price_ <<" for five! " << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl << std::endl;
}