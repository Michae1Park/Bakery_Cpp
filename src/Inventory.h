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
	void attach(Observer *obs);
	void addBread(Bread* b);
	void changeStock(Bread* b, int i);
	void changePrice(Bread* b, float f);
	void notify();
	std::unordered_map<BreadType, Bread*> getBreads();
};
