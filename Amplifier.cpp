#include "Amplifier.h"

Amplifier::Amplifier() : inputs(8), wattage(45), maxVolume(10.0)
{
    std::cout << "Amplifier created!" << '\n';
}

Amplifier::~Amplifier()
{
    std::cout << "Amplifier Object destruceted!" << '\n';
}

Amplifier::Preamp::Preamp() : thdNoise(0.0001f), voltage(12)
{
    std::cout << "Preamp created!" << '\n';
}

void Amplifier::Preamp::increaseAmplification(const float ampFac) const
{
    std::cout << "Factor set: " << ampFac << '\n';
}

void Amplifier::Preamp::switchOutResistance(const unsigned int outR) const
{
    std::cout << "Output Resistance set: " << outR<< '\n';
}

void Amplifier::Preamp::switchInResistance(const unsigned int inR) const
{
    std::cout << "Input Resistance set: " << inR << '\n';
}

void Amplifier::adjustVolume(Preamp& pre) const
{
    pre.increaseAmplification(5);
}

bool Amplifier::switchOn() const 
{
    return true;
}

bool Amplifier::changeInp(const char type) const
{
    switch(type) 
    {
        case 'A' :
            std::cout << "Class A" << '\n'; 
            break;
        case 'B' :
            std::cout << "Class B" << '\n';
            break;
        default :
            std::cout << "Invalid type" << '\n';
   }

    return (type == ('A' | 'B') ? true : false);
}

void Amplifier::ejectCd(const int time) const
{
    auto i {0};
    while(i != time)
    {
        ++i;
    }
    std::cout << "Ejecting CD took " << i << " seconds" << '\n';
}

void Amplifier::showIoCounts() const 
{
    std::cout << "inputs:" << this->inputs << "\noutputs" << this->outputs << "\n";  
}
