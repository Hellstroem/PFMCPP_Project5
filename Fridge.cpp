#include "Fridge.h"

Fridge::Fridge() : waterTankVolume(1.0), amountOfIce(2), height(220.5f)
{
    std::cout << "Fridge created!" << '\n';
}

Fridge::~Fridge()
{
    std::cout << "Fridge Object destruceted!" << '\n';
}

Fridge::Door::Door() : depth(12.3f), angle(0)
{
    std::cout << "Door created!" << '\n';
}

void Fridge::Door::closeDoor() const
{
    std::cout << "Door Closed!" << '\n';
}

bool Fridge::Door::switchOnDisplay(const bool touched) const
{
    return touched ? true : false;
}

void Fridge::Door::alert(const bool open,const int time) const 
{
    auto i = 0;

    while(open)
    {
        ++i;
        if( i == time ) 
        {
            std::cout << "RING!!! CLOSE DOOR!" << '\n';
            break;
        }
    }
}

void Fridge::crushIce(const unsigned int ice) const
{
    std::cout << ice << "Ice cubes crushed! " << '\n';
}

double Fridge::streamWater(const double tankVolume) const
{
    return (tankVolume - 1.0);
}

unsigned int Fridge::adjustTemperature(Door& door) const 
{
    return (door.switchOnDisplay(true)) ? true : false;
}

bool Fridge::openDoor(Door& door, const int angle = 45) const
{
    for(auto i = 0; i <= angle; ++i)
    {
        door.angle = i;
        std::cout << "Door angle " << i << "degrees!" << '\n';
    }

    return true;
}

void Fridge::printMemberData() const 
{
    std::cout << "temperature: " << this->temperature << "\nemittedHeat: " << this->emittedHeat << '\n';  
}
