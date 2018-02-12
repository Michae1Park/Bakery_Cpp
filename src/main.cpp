#include <iostream>
#include <vector>

#include "Inventory.h"
#include "DisplayStock.h"
#include "DisplaySpecialDeal.h"
#include "Pretzel.h"
#include "Muffin.h"
#include "Doughnut.h"

int main() {
	Pretzel* pretzel = new Pretzel();
	Doughnut* doughnut = new Doughnut();
	Muffin* muffin = new Muffin(); 
	
	Inventory inven;
	DisplayStock dpstock(&inven); 
	DisplaySpecialDeal dpspecdeal(&inven);

	inven.addBread(doughnut);
	inven.notify();
	inven.addBread(pretzel);
	inven.notify();
	inven.addBread(muffin);
	inven.notify();
	inven.addBread(muffin);
	inven.notify();

	inven.changeStock(muffin, 30);
	inven.notify();
	inven.changeStock(muffin, 510);
	inven.notify();

	inven.changePrice(muffin, 510);
	inven.notify();
	inven.changePrice(muffin, 51000);
	inven.notify();
	while (1);
}