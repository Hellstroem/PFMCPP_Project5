#include "Kitchen.h"

Kitchen::Kitchen() 
{
    std::cout << "Kitchen Object constructed!" << '\n';
}

Kitchen::~Kitchen() 
{
    std::cout << "Kitchen Object destructed!" << '\n';
}

void Kitchen::makeCappucino() // const does not work here: "binding value of type 'const Fridge::Door' to reference to type 'Fridge::Door' drops 'const' qualifier"

{
    bool opened = this->fridge.openDoor(this->fridge.door1, 45);

    if(opened == true)
    {
        this->machine.heatUp(10);
        this->machine.foamMilk(10);
        this->machine.makeCoffee(10, machine.crushBeans());
    }

    std::cout << "Done, making cappucino!" << '\n';
}

void Kitchen::fillCoffeeTank() // const does not work here: "cannot assign to non-static data member within const member function 'fillCoffeeTank'""

{
    this->machine.tankVolume = fridge.streamWater(this->fridge.waterTankVolume);

    std::cout << "Coffee tank filled with water!" << '\n';
}

void Kitchen::printObjectMemberInfos() const 
{
    this->fridge.printMemberData();
    this->machine.printMemberData();
    
}
