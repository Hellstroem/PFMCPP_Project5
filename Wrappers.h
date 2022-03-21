#pragma once

#include "CoffeeMachine.h"
#include "Fridge.h"
#include "Amplifier.h"
#include "Kitchen.h"
#include "House.h"

struct CoffeeMachineWrapper
{
    CoffeeMachineWrapper(CoffeeMachine* ptr);
    ~CoffeeMachineWrapper();

    CoffeeMachine* coffPtr = nullptr;

};

CoffeeMachineWrapper::CoffeeMachineWrapper(CoffeeMachine* ptr) : coffPtr(ptr) {}

CoffeeMachineWrapper::~CoffeeMachineWrapper()
{
    delete coffPtr;
}


struct FridgeWrapper
{
    FridgeWrapper(Fridge* ptr);
    ~FridgeWrapper();

    Fridge* fridgePtr = nullptr;
};

FridgeWrapper::FridgeWrapper(Fridge* ptr) : fridgePtr(ptr) {}

FridgeWrapper::~FridgeWrapper()
{
    delete fridgePtr;
}

struct AmpWrapper
{
    AmpWrapper(Amplifier* ptr);
    ~AmpWrapper();

    Amplifier* ampPtr = nullptr;

};

AmpWrapper::AmpWrapper(Amplifier* ptr) : ampPtr(ptr) {}

AmpWrapper::~AmpWrapper()
{
    delete ampPtr;
}

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* ptr);
    ~KitchenWrapper();

    Kitchen* kitPtr = nullptr;
};

KitchenWrapper::KitchenWrapper(Kitchen* ptr) : kitPtr(ptr) {}

KitchenWrapper::~KitchenWrapper()
{
    delete kitPtr;
}

struct HouseWrapper
{
    HouseWrapper(House* ptr);
    ~HouseWrapper();

    House* housePtr = nullptr;
};

HouseWrapper::HouseWrapper(House* ptr) : housePtr(ptr) {}

HouseWrapper::~HouseWrapper()
{
    delete housePtr;
}
