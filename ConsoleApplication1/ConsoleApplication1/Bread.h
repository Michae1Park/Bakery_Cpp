#pragma once
#include <iostream>

enum BreadType {
	BT_Doughnut,
	BT_Muffin,
	BT_Pretzel
};

class Bread {
public:
	virtual void displayBread() = 0;
	static Bread* Create(BreadType type);
};
