#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Subject.h"
#include "Observer.h"
#include "Bread.h"

enum ActionType {
	AT_MakeBread,
	AT_SellBread
};

class BakeryInventory : Subject {
private:
	std::unordered_map<Bread, int> breads;
	std::unordered_set<Observer> observerList;

public:
	void registerObserver(Observer o);
	void unregisterObserver(Observer o);
	void notifyObservers();
	void makeBread(BreadType bt, int cnt);
	void sellBread(BreadType bt, int cnt);
	void dataChanged();
};