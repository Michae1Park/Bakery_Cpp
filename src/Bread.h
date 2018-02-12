#pragma once
#include <iostream>

enum BreadType {
	BT_Doughnut,
	BT_Muffin,
	BT_Pretzel
};

class Bread {
protected:
	std::string label_;
	BreadType type_;
	int calories_;

public:
	float price_; // Public easy get/set
	int stock_;

	Bread(std::string label, BreadType type, int calories, float price, int stock);
	virtual void displayBread() = 0; 
	BreadType getType(); //get only
	std::string getLabel();
};
