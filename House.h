#pragma once

#include "LeakedObjectDetector.h"
#include "Kitchen.h"
#include "Amplifier.h"

struct House
{
    House();
    ~House();

    Kitchen kitchen;
    Amplifier radio;

    bool putRadioOnTableAndSwitchOn();
    void removeFromTable(const bool isOnTable);

    void printMemberInfos() const ;

    JUCE_LEAK_DETECTOR(House)
};
