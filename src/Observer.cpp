#include "Observer.h"

Observer::Observer(Inventory *mod) {
	model_ = mod;
	model_->attach(this);
}
Inventory *Observer:: getInventory() {
	return model_;
}