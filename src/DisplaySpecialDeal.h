#pragma once
#include "Observer.h"

class DisplaySpecialDeal : public Observer {
public:
	DisplaySpecialDeal(Inventory *mod);
	void update();
};
