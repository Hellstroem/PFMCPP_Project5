#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine() : tankVolume(1.45), airPressure(5)
{
    std::cout << "CoffeeMachine created!" << '\n';
}

CoffeeMachine::~CoffeeMachine()
{
    std::cout << "CoffeeMachine Object destruceted!" << '\n';
}

void CoffeeMachine::foamMilk(const int airPre) const 
{
    std::cout << "Milk foamed with " << airPre << "bars" << '\n';  
}

float CoffeeMachine::crushBeans() const
{
    std::string crushed = "CRUSHED!";
    std::cout << crushed << '\n';  

    return 10.0f;
}

void CoffeeMachine::makeCoffee(const int airPres, const float crushedBeans) const 
{
    std::cout << "Beans: " << crushedBeans << " crushed with " << airPres << " bars !" << '\n'; 
}

void CoffeeMachine::heatUp(const int min) const
{
    for(auto i = min; i >= 0; --i)
    {
        std::cout << "CoffeeMachine ready in " << i << " minutes" << '\n'; 
    }
}

void CoffeeMachine::printMemberData() const
{
    std::cout << "crushPower: " << this->crushPower << "\nmilkTankVolume: " << this->milkTankVolume << '\n';  
}
