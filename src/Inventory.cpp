#include "Inventory.h"
#include <iostream>
#include <string>

void Inventory::attach(Observer *observer) {
	obsList_.push_back(observer);
}

void Inventory::addBread(Bread* bread) {
	if (breads_.count(bread->getType()) > 0 ) { 
		std::cout << bread->getLabel() << " already exists in inventory!" << std::endl; 
	}
	else {
		breads_.insert(std::make_pair(bread->getType(), bread));
	}
}
void Inventory::changeStock(Bread* bread, int stock) {
	if (stock < 0) {
		std::cout << "stock cannot be below 0!" << std::endl;
	}
	else if (stock > 500) {
		std::cout << "maximum inventory capacity is 500 per one type of bread!" << std::endl;
	}
	else {
		breads_[bread->getType()]->stock_ = stock;
	}
}
void Inventory::changePrice(Bread* bread, float price) {
	if (price < 0) {
		std::cout << "price cannot be below 0!" << std::endl;
	}
	else if (price > 10000) {
		std::cout << "Come on, no one is going to buy that!" << std::endl;
	}
	else {
		breads_[bread->getType()]->price_ = price;
	}
}

void Inventory::notify() {
	for (int i = 0; i < obsList_.size(); i++) //Broad casts to all subscribers
		obsList_[i]->update();
}

std::unordered_map<BreadType, Bread*> Inventory::getBreads() {
	return breads_;
}