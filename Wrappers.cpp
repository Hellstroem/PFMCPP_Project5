#include "Wrappers.h"
#include "CoffeeMachine.h"
#include "Amplifier.h"
#include "Fridge.h"
#include "Kitchen.h"
#include "House.h"

CoffeeMachineWrapper::CoffeeMachineWrapper(CoffeeMachine* ptr) : coffPtr(ptr) {}

CoffeeMachineWrapper::~CoffeeMachineWrapper()
{
    delete coffPtr;
}

FridgeWrapper::FridgeWrapper(Fridge* ptr) : fridgePtr(ptr) {}

FridgeWrapper::~FridgeWrapper()
{
    delete fridgePtr;
}

AmpWrapper::AmpWrapper(Amplifier* ptr) : ampPtr(ptr) {}

AmpWrapper::~AmpWrapper()
{
    delete ampPtr;
}

KitchenWrapper::KitchenWrapper(Kitchen* ptr) : kitPtr(ptr) {}

KitchenWrapper::~KitchenWrapper()
{
    delete kitPtr;
}

HouseWrapper::HouseWrapper(House* ptr) : housePtr(ptr) {}

HouseWrapper::~HouseWrapper()
{
    delete housePtr;
}
