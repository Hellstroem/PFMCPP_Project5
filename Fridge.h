#pragma once

#include "LeakedObjectDetector.h"

struct Fridge 
{ 
    Fridge();
    ~Fridge();

    int temperature {7};
    int emittedHeat {27};
    double waterTankVolume;
    unsigned int amountOfIce;
    float height;

    struct Door
    {
        Door();

        float height {210.0f};
        float width {50.8f};
        float depth;
        int angle;
        int alertTime {10};
        bool doorOpened {false};
        std::string typeOfDoorHandle = "integrated";
        std::string typeOfDoor = "WithDisplay"; 

        void closeDoor() const;
        bool switchOnDisplay(const bool displayTouched) const; 
        void alert(const bool, const int) const;

        JUCE_LEAK_DETECTOR(Door)
    };

    Door door1;

    void crushIce(const unsigned int amountOfIce) const;
    double streamWater(const double waterTankVolume) const;
    unsigned int adjustTemperature(Door& door) const; 
    bool openDoor(Door& door, const int angle) const;

    void printMemberData() const;

    JUCE_LEAK_DETECTOR(Fridge)
}; 
