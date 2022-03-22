#include "House.h"

House::House()
{
    std::cout << "House object constructed!" << '\n';
}

House::~House()
{
    std::cout << "House object destructed!" << '\n';
}

bool House::putRadioOnTableAndSwitchOn()
{
    this->kitchen.tableIsOccupied = true;    
    if(this->radio.switchOn() && this->kitchen.tableIsOccupied)
    {
        std::cout << "Radio put on table!" << '\n';
        return true;
    }
    return false;
}

void House::removeFromTable(const bool onTable)
{
    if(onTable) 
        this->kitchen.tableIsOccupied = false;

    std::cout << "Object removed from table" << '\n';
}

void House::printMemberInfos() const 
{
    this->kitchen.fridge.printMemberData();
    std::cout << "wattage "<< this->radio.wattage << "\nmaxVolume " << this->radio.maxVolume << '\n';
}
