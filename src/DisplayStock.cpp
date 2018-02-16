#include <iostream>
#include <string>
#include "DisplayStock.h"

DisplayStock::DisplayStock(Inventory *mod) : Observer(mod) {}

void DisplayStock:: update() {
	std::cout << "---------- Number of Stocks ------------" << std::endl;
	for (std::pair<BreadType, Bread*> element : getInventory()->getBreads()) {
		std::cout << element.second->getLabel() << " : " << element.second->stock_ << " in stock "<< std::endl;
	}
	std::cout << "---------------------------------------" << std::endl << std::endl;
}