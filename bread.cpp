#include <iostream>

enum BreadType {
    BT_Doughut,    
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
class Muffin : public Bread  {
public:
    void displayBread() {
        std::cout << "Muffin" << std::endl;
    }
};
class Pretzel : public Bread  {
    public:
    void displayBread() {
        std::cout << "Pretzel" << std::endl;
    }
};
 
// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
// Does it have to return as a pointer??
Bread* Bread::Create(BreadType type) {
    if (type == BT_Doughut)
        return new Doughut();
    else if (type == BT_Muffin)
        return new Muffin();
    else if (type == BT_Pretzel)
        return new Pretzel();
    else return NULL;
}
 
// Client class
// class Client {
// public:
 
//     // Client doesn't explicitly create objects
//     // but passes type to factory method "Create()"
//     Client()
//     {
//         VehicleType type = VT_ThreeWheeler;
//         pVehicle = Vehicle::Create(type);
//     }
//     ~Client() {
//         if (pVehicle) {
//             delete[] pVehicle;
//             pVehicle = NULL;
//         }
//     }
//     Vehicle* getVehicle()  {
//         return pVehicle;
//     }
 
// private:
//     Vehicle *pVehicle;
// };
 
// Driver program
int main() {

    BreadType type = BT_Pretzel
    pBread = Bread::Create(type);

    std::cout << pBread << std::endl;
    // Client *pClient = new Client();
    // Vehicle * pVehicle = pClient->getVehicle();
    // pVehicle->printVehicle();
    return 0;
}