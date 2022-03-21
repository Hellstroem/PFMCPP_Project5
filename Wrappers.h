#pragma once

#include "CoffeeMachine.cpp"
#include "Fridge.cpp"
#include "Amplifier.cpp"
#include "Kitchen.cpp"
#include "House.cpp"

struct CoffeeMachineWrapper
{
    CoffeeMachineWrapper(CoffeeMachine* ptr) : coffPtr(ptr) {}
    ~CoffeeMachineWrapper()
    {
        delete coffPtr;
    }

    CoffeeMachine* coffPtr = nullptr;

};

struct FridgeWrapper
{
    FridgeWrapper(Fridge* ptr) : fridgePtr(ptr) {}
    ~FridgeWrapper()
    {
        delete fridgePtr;
    }

    Fridge* fridgePtr = nullptr;
};

struct AmpWrapper
{
    AmpWrapper(Amplifier* ptr) : ampPtr(ptr) {}
    ~AmpWrapper()
    {
        delete ampPtr;
    }

    Amplifier* ampPtr = nullptr;

};

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* ptr) : kitPtr(ptr) {}
    ~KitchenWrapper()
    {
        delete kitPtr;
    }

    Kitchen* kitPtr = nullptr;
};

struct HouseWrapper
{
    HouseWrapper(House* ptr) : housePtr(ptr) {}
    ~HouseWrapper()
    {
        delete housePtr;
    }

    House* housePtr = nullptr;
};
