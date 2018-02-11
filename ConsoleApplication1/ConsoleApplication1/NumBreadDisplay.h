#pragma once
#include "Observer.h"

class NumBreadDisplay : Observer {
private:
	int runs, wickets;
	float overs;

public:
	void update(int runs, int wickets, float overs);
	void display();
};
