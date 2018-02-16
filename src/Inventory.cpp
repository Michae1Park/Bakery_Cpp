#include "Inventory.h"
#include <iostream>
#include <string>

void Inventory::attach(Observer *obs) {
	obsList_.push_back(obs);
}

void Inventory::addBread(Bread* b) {
	if (breads_.count(b->getType()) > 0 ) { 
		std::cout << b->getLabel() << " already exists in inventory!" << std::endl; 
	}
	else {
		breads_.insert(std::make_pair(b->getType(), b));
	}
}
void Inventory::changeStock(Bread* b, int i) {
	if (i < 0) {
		std::cout << "stock cannot be below 0!" << std::endl;
	}
	else if (i > 500) {
		std::cout << "maximum inventory capacity is 500 per one type of bread!" << std::endl;
	}
	else {
		breads_[b->getType()]->stock_ = i;
	}
}
void Inventory::changePrice(Bread* b, float f) {
	if (f < 0) {
		std::cout << "price cannot be below 0!" << std::endl;
	}
	else if (f > 10000) {
		std::cout << "Come on, no one is going to buy that!" << std::endl;
	}
	else {
		breads_[b->getType()]->price_ = f;
	}
}

void Inventory::notify() {
	for (int i = 0; i < obsList_.size(); i++) //Broad casts to all subscribers
		obsList_[i]->update();
}

std::unordered_map<BreadType, Bread*> Inventory::getBreads() {
	return breads_;
}