#pragma once

struct CoffeeMachine;
struct Fridge;
struct Amplifier;
struct Kitchen;
struct House;

struct CoffeeMachineWrapper
{
    CoffeeMachineWrapper(CoffeeMachine* ptr);
    ~CoffeeMachineWrapper();

    CoffeeMachine* coffPtr = nullptr;
};

struct FridgeWrapper
{
    FridgeWrapper(Fridge* ptr);
    ~FridgeWrapper();

    Fridge* fridgePtr = nullptr;
};


struct AmpWrapper
{
    AmpWrapper(Amplifier* ptr);
    ~AmpWrapper();

    Amplifier* ampPtr = nullptr;

};

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* ptr);
    ~KitchenWrapper();

    Kitchen* kitPtr = nullptr;
};

struct HouseWrapper
{
    HouseWrapper(House* ptr);
    ~HouseWrapper();

    House* housePtr = nullptr;
};
