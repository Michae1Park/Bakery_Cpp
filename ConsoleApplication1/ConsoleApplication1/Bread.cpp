#include <iostream>
#include "Bread.h"
#include "Doughnut.h"
#include "Muffin.h"
#include "Pretzel.h"


// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
// Does it have to return as a pointer??

class Bread {
public:
	virtual void displayBread() = 0;

	static Bread* Create(BreadType type) {
		if (type == BT_Doughnut)
			return new Doughnut();
		else if (type == BT_Muffin)
			return new Muffin();
		else if (type == BT_Pretzel)
			return new Pretzel();
		else return NULL;
	}
};

