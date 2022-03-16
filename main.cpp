/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */





#include <iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

struct CoffeeMachine 
{   
    CoffeeMachine();
    ~CoffeeMachine();

    double tankVolume;
    int airPressure;
    unsigned int maxQuanBeans {150};
    double milkTankVolume {1.0};
    unsigned int crushPower {5};

    void foamMilk(const int airPressure);
    float crushBeans() const; 
    void makeCoffee(const int airPressure,const float crushedBeans); 
    void heatUp(const int minutes);

    void printMemberData() const;

    JUCE_LEAK_DETECTOR(CoffeeMachine)
};

CoffeeMachine::CoffeeMachine() : tankVolume(1.45), airPressure(5)
{
    std::cout << "CoffeeMachine created!" << '\n';
}

CoffeeMachine::~CoffeeMachine()
{
    std::cout << "CoffeeMachine Object destruceted!" << '\n';
}

void CoffeeMachine::foamMilk(const int airPre)
{
    std::cout << "Milk foamed with " << airPre << "bars" << '\n';  
}

float CoffeeMachine::crushBeans() const
{
    std::string crushed = "CRUSHED!";
    std::cout << crushed << '\n';  

    return 10.0f;
}

void CoffeeMachine::makeCoffee(const int airPres,const float crushedBeans)
{
    std::cout << "Beans: " << crushedBeans << " crushed with " << airPres << " bars !" << '\n'; 
}

void CoffeeMachine::heatUp(const int min)
{
    for(auto i = min; i >= 0; --i)
    {
        std::cout << "CoffeeMachine ready in " << i << " minutes" << '\n'; 
    }
}

void CoffeeMachine::printMemberData() const
{
    std::cout << "crushPower: " << this->crushPower << "\nmilkTankVolume: " << this->milkTankVolume << '\n';  
}

struct CoffeeMachineWrapper
{
    CoffeeMachineWrapper(CoffeeMachine* ptr) : coffPtr(ptr) {}
    ~CoffeeMachineWrapper()
    {
        delete coffPtr;
    }

    CoffeeMachine* coffPtr = nullptr;

};
/*
 copied UDT 2:
 */

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
        bool switchOnDisplay(const bool displayTouched); 
        void alert(const bool, const int);

        JUCE_LEAK_DETECTOR(Door)
    };

    Door door1;

    void crushIce(const unsigned int amountOfIce);
    double streamWater(const double waterTankVolume);
    unsigned int adjustTemperature(Door door) const; 
    bool openDoor(Door& door, const int angle);

    void printMemberData() const;

    JUCE_LEAK_DETECTOR(Fridge)
}; 

Fridge::Fridge() : waterTankVolume(1.0), amountOfIce(2), height(220.5f)
{
    std::cout << "Fridge created!" << '\n';
}

Fridge::~Fridge()
{
    std::cout << "Fridge Object destruceted!" << '\n';
}

Fridge::Door::Door() : depth(12.3f), angle(0)
{
    std::cout << "Door created!" << '\n';
}

void Fridge::Door::closeDoor() const
{
    std::cout << "Door Closed!" << '\n';
}

bool Fridge::Door::switchOnDisplay(const bool touched)
{
    return touched ? true : false;
}

void Fridge::Door::alert(const bool open,const int time)
{
    auto i = 0;

    while(open)
    {
        ++i;
        if( i == time ) 
        {
            std::cout << "RING!!! CLOSE DOOR!" << '\n';
            break;
        }
    }
}

void Fridge::crushIce(const unsigned int ice)
{
    std::cout << ice << "Ice cubes crushed! " << '\n';
}

double Fridge::streamWater(const double tankVolume)
{
    return (tankVolume - 1.0);
}

unsigned int Fridge::adjustTemperature(Door door) const 
{
    return (door.switchOnDisplay(true)) ? true : false;
}

bool Fridge::openDoor(Door& door, const int angle = 45)
{
    for(auto i = 0; i <= angle; ++i)
    {
        door.angle = i;
        std::cout << "Door angle " << i << "degrees!" << '\n';
    }

    return true;
}

void Fridge::printMemberData() const 
{
    std::cout << "temperature: " << this->temperature << "\nemittedHeat: " << this->emittedHeat << '\n';  
}

struct FridgeWrapper
{
    FridgeWrapper(Fridge* ptr) : fridgePtr(ptr) {}
    ~FridgeWrapper()
    {
        delete fridgePtr;
    }

    Fridge* fridgePtr = nullptr;
};

/*
 copied UDT 3:
 */

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

        void increaseAmplification(const float ampFactor);
        void switchOutResistance(const unsigned int outRes);
        void switchInResistance(const unsigned int inRes);

        JUCE_LEAK_DETECTOR(Preamp)
    };

    Preamp preA;

    void adjustVolume(Preamp& pre);
    bool switchOn() const ; 
    bool changeInp(const char inputType); 
    void ejectCd(const int time);

    void showIoCounts() const ;

    JUCE_LEAK_DETECTOR(Amplifier)
}; 

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

void Amplifier::Preamp::increaseAmplification(const float ampFac)
{
    std::cout << "Factor set: " << ampFac << '\n';
}

void Amplifier::Preamp::switchOutResistance(const unsigned int outR)
{
    std::cout << "Output Resistance set: " << outR<< '\n';
}

void Amplifier::Preamp::switchInResistance(const unsigned int inR)
{
    std::cout << "Input Resistance set: " << inR<< '\n';
}

void Amplifier::adjustVolume(Preamp& pre)
{
    pre.increaseAmplification(5);
}

bool Amplifier::switchOn() const 
{
    return true;
}

bool Amplifier::changeInp(const char type)
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

void Amplifier::ejectCd(int time)
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

struct AmpWrapper
{
    AmpWrapper(Amplifier* ptr) : ampPtr(ptr) {}
    ~AmpWrapper()
    {
        delete ampPtr;
    }

    Amplifier* ampPtr = nullptr;

};

/*
 new UDT 4:
 with 2 member functions
 */

struct Kitchen
{
    Kitchen();
    ~Kitchen();

    Fridge fridge;
    CoffeeMachine machine;
    bool tableIsOccupied {false};

    void makeCappucino();
    void fillCoffeeTank();

    void printObjectMemberInfos() const ;

    JUCE_LEAK_DETECTOR(Kitchen)
};

Kitchen::Kitchen() 
{
    std::cout << "Kitchen Object constructed!" << '\n';
}

Kitchen::~Kitchen() 
{
    std::cout << "Kitchen Object destructed!" << '\n';
}

void Kitchen::makeCappucino() 
{
    bool opened = this->fridge.openDoor(this->fridge.door1, 45);

    if(opened == true)
    {
        this->machine.heatUp(10);
        this->machine.foamMilk(10);
        this->machine.makeCoffee(10, machine.crushBeans());
    }

    std::cout << "Done, making cappucino!" << '\n';
}

void Kitchen::fillCoffeeTank()
{
    this->machine.tankVolume = fridge.streamWater(this->fridge.waterTankVolume);

    std::cout << "Coffee tank filled with water!" << '\n';
}

void Kitchen::printObjectMemberInfos() const 
{
    this->fridge.printMemberData();
    this->machine.printMemberData();
    
}

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* ptr) : kitPtr(ptr) {}
    ~KitchenWrapper()
    {
        delete kitPtr;
    }

    Kitchen* kitPtr = nullptr;
};


/*
 new UDT 5:
 with 2 member functions
 */

struct House
{
    House();
    ~House();

    Kitchen kitchen;
    Amplifier radio;

    bool putRadioOnTableAndSwitchOn();
    void removeFromTable(bool isOnTable);

    void printMemberInfos() const ;

    JUCE_LEAK_DETECTOR(House)
};

House::House()
{
    std::cout << "House object constructed!" << '\n';
}

House::~House()
{
    std::cout << "House object destructed!" << '\n';
}

bool House::putRadioOnTableAndSwitchOn()
{
    this->kitchen.tableIsOccupied = true;    
    if(this->radio.switchOn() && this->kitchen.tableIsOccupied)
    {
        std::cout << "Radio put on table!" << '\n';
        return true;
    }
    return false;
}

void House::removeFromTable(bool onTable)
{
    if(onTable) 
        this->kitchen.tableIsOccupied = false;

    std::cout << "Object removed from table" << '\n';
}

void House::printMemberInfos() const 
{
    this->kitchen.fridge.printMemberData();
    std::cout << "wattage "<< this->radio.wattage << "\nmaxVolume " << this->radio.maxVolume << '\n';
}

struct HouseWrapper
{
    HouseWrapper(House* ptr) : housePtr(ptr) {}
    ~HouseWrapper()
    {
        delete housePtr;
    }

    House* housePtr = nullptr;
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    CoffeeMachineWrapper cMW(new CoffeeMachine());
    cMW.coffPtr->foamMilk(5);
    float beans = cMW.coffPtr->crushBeans();
    cMW.coffPtr->makeCoffee(5, beans);
    cMW.coffPtr->heatUp(15);

    std::cout << "crushPower: " << cMW.coffPtr->crushPower << "\nmilkTankVolume: " << cMW.coffPtr->milkTankVolume << '\n';
    cMW.coffPtr->printMemberData();

    Fridge::Door door;
    door.closeDoor();
    bool dispOn = door.switchOnDisplay(true);

    std::cout << "Display is " <<  (dispOn ? "on" : "off") << '\n';

    FridgeWrapper fW(new Fridge());
    fW.fridgePtr->crushIce(100);
    double vol = fW.fridgePtr->streamWater(10);
    unsigned int temp = fW.fridgePtr->adjustTemperature(door);
    door.doorOpened = fW.fridgePtr->openDoor(door, 22);
    door.alert(door.doorOpened, door.alertTime);

    std::cout << "temperature: " << fW.fridgePtr->temperature << "\nemittedHeat: " << fW.fridgePtr->emittedHeat << '\n';
    fW.fridgePtr->printMemberData();

    std::cout << "Fridge volume is " << vol << " and temperature is " << temp << '\n'; 

    Amplifier::Preamp pre;
    pre.increaseAmplification(3.5f);
    pre.switchOutResistance(8);
    pre.switchInResistance(1000);

    AmpWrapper aW(new Amplifier());
    aW.ampPtr->adjustVolume(pre);
    bool ampOn = aW.ampPtr->switchOn();
    bool inType = aW.ampPtr->changeInp('B');
    aW.ampPtr->ejectCd(7);

    std::cout << "inputs:" << aW.ampPtr->inputs << "\noutputs" << aW.ampPtr->outputs << "\n";
    aW.ampPtr->showIoCounts();

    std::cout << "Amp is " << (ampOn ? "on" : "off") << " and Input" << (inType ? " is active!" : " is not active") << '\n';

    KitchenWrapper kW(new Kitchen());
    kW.kitPtr->makeCappucino();
    kW.kitPtr->fillCoffeeTank();
    kW.kitPtr->printObjectMemberInfos();

    std::cout << "temperature: " << kW.kitPtr->fridge.temperature << "\nemittedHeat: " << kW.kitPtr->fridge.emittedHeat << '\n' << "crushPower: " << kW.kitPtr->machine.crushPower << "\nmilkTankVolume: " << kW.kitPtr->machine.milkTankVolume << '\n';    
    
    HouseWrapper hW(new House());
    bool onTable = hW.housePtr->putRadioOnTableAndSwitchOn();
    hW.housePtr->removeFromTable(onTable);
    hW.housePtr->printMemberInfos();

    std::cout << "temperature: " << hW.housePtr->kitchen.fridge.temperature << "\nemittedHeat: " << hW.housePtr->kitchen.fridge.emittedHeat << "\nwattage: " << hW.housePtr->radio.wattage << "\nmaxVolume: " << hW.housePtr->radio.maxVolume << '\n';
    
    std::cout << "good to go!" << std::endl;
}
