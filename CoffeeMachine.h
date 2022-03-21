#pragma once

#include "LeakedObjectDetector.h"

struct CoffeeMachine 
{   
    CoffeeMachine();
    ~CoffeeMachine();

    double tankVolume;
    int airPressure;
    unsigned int maxQuanBeans {150};
    double milkTankVolume {1.0};
    unsigned int crushPower {5};

    void foamMilk(const int airPressure) const;
    float crushBeans() const; 
    void makeCoffee(const int airPressure, const float crushedBeans) const; 
    void heatUp(const int minutes) const;

    void printMemberData() const;

    JUCE_LEAK_DETECTOR(CoffeeMachine)
};
