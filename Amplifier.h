#pragma once

#include "LeakedObjectDetector.h"

struct Amplifier 
{ 
    Amplifier();
    ~Amplifier();

    unsigned int inputs;
    unsigned int outputs {4};
    char inputType {'B'};
    unsigned int wattage;
    double maxVolume ;

    struct Preamp
    {
        Preamp();

        unsigned int inputResistance {1000};
        unsigned int outputResistance {8};
        float amplificationFactor {10.0f};
        float thdNoise;
        float voltage;

        void increaseAmplification(const float ampFactor) const;
        void switchOutResistance(const unsigned int outRes) const;
        void switchInResistance(const unsigned int inRes) const;

        JUCE_LEAK_DETECTOR(Preamp)
    };

    Preamp preA;

    void adjustVolume(Preamp& pre) const;
    bool switchOn() const ; 
    bool changeInp(const char inputType) const; 
    void ejectCd(const int time) const;

    void showIoCounts() const ;

    JUCE_LEAK_DETECTOR(Amplifier)
};
