#pragma once
#include "Inventory.h"

class Inventory;	//forward declaration

class Observer {
	Inventory *model_;
public:
	Observer(Inventory *mod);
	virtual void update() = 0;
protected:
	Inventory * getInventory();
};
