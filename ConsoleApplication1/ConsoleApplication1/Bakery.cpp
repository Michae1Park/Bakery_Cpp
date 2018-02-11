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

class Doughnut : public Bread {
public:
	void displayBread() {
		std::cout << "Doughnut" << std::endl;
	}
};
class Muffin : public Bread {
public:
	void displayBread() {
		std::cout << "Muffin" << std::endl;
	}
};
class Pretzel : public Bread {
public:
	void displayBread() {
		std::cout << "Pretzel" << std::endl;
	}
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
// Does it have to return as a pointer??
Bread* Bread::Create(BreadType type) {
	if (type == BT_Doughnut)
		return new Doughnut();
	else if (type == BT_Muffin)
		return new Muffin();
	else if (type == BT_Pretzel)
		return new Pretzel();
	else return NULL;
}

// Client class
 class Client {
 public:
     // Client doesn't explicitly create objects
     // but passes type to factory method "Create()"
     Client(BreadType type)
     {
         //BreadType type = BT_ThreeWheeler;
         pBread = Bread::Create(type);
     }
     ~Client() {
         if (pBread) {
             delete[] pBread;
             pBread = NULL;
         }
     }
	 Bread* getBread()  {
         return pBread;
     }

 private:
	 Bread *pBread;
 };

// Driver program
int main() {
	Client *pClient = new Client(BT_Doughnut);
	Bread * pBread = pClient->getBread();
	pBread->displayBread();
	return 0;
}