#pragma once

#include "LeakedObjectDetector.h"
#include "Fridge.h"
#include "CoffeeMachine.h"

struct Kitchen
{
    Kitchen();
    ~Kitchen();

    Fridge fridge;
    CoffeeMachine machine;
    bool tableIsOccupied {false};

    void makeCappucino();
    void fillCoffeeTank();

    void printObjectMemberInfos() const;

    JUCE_LEAK_DETECTOR(Kitchen)
};
