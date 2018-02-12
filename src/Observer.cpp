#include "Observer.h"

Observer::Observer(Inventory *mod) {
	model = mod;
	model->attach(this);
}
Inventory *Observer:: getInventory() {
		return model;
	}