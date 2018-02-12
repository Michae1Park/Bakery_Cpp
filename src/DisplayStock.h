#pragma once
#include "Observer.h"

class DisplayStock : public Observer {
public:
	DisplayStock(Inventory *mod);
	void update();
};