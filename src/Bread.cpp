#include "Bread.h"

Bread::Bread(std::string label, BreadType type, int calories, float price, int stock) {
	label_ = label;
	type_ = type;
	calories_ = calories;
	price_ = price;
	stock_ = stock;
}

BreadType Bread::getType() {
	return type_;
}
std::string Bread::getLabel() {
	return label_;
}
