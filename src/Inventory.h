#pragma once
#include <vector>
#include <unordered_map>
#include "Observer.h"
#include "Bread.h"

class Observer;

class Inventory {
	std::vector<Observer*> obsList_; 
	std::unordered_map<BreadType, Bread*> breads_;

public:
	void attach(Observer *observer);
	void addBread(Bread* bread);
	void changeStock(Bread* bread, int stock);
	void changePrice(Bread* bread, float price);
	void notify();
	std::unordered_map<BreadType, Bread*> getBreads();
};
