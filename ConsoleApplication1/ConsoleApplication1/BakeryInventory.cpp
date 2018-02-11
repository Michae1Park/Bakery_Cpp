#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#include "Subject.h"
#include "Observer.h"
#include "Bread.h"
#include "BakeryInventory.h"

class BakeryInventory : Subject {
private:
	std::unordered_map<BreadType, int> breads;
	std::unordered_set<Observer> observerList;

public:
	void registerObserver(Observer o) {
		observerList.insert(o);
	}
	void unregisterObserver(Observer o) {
		observerList.erase(o);
	}

	void notifyObservers() {
		for (auto it = observerList.begin(); it != observerList.end(); ++it) {
			*it.update();
		}
	}

	void makeBread(BreadType bt, int cnt) {
		if (cnt + breads[bt] > INT_MAX) {
			std::cout << "bread capacity exceeded" << std::endl;
		}
		else if (cnt <= 0) {
			std::cout << "must make at least one bread to add to inventory" << std::endl;
		}
		else {
			breads[bt] += cnt;
		}
	}
	
	void sellBread(BreadType bt, int cnt) {
		breads[bt] -= cnt;
	}

	void dataChanged(BreadType bt, int cnt, ActionType at) {
		if (at == AT_MakeBread) {
			makeBread(bt, cnt);
		}
		else if (at == AT_SellBread) {
			sellBread(bt, cnt);
		}
		else {
			std::cout << "Something is wrong" << std::endl;
		}
		notifyObservers();
	}
};