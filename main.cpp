/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
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

    void foamMilk(const int airPressure) const;
    float crushBeans() const; 
    void makeCoffee(const int airPressure, const float crushedBeans) const; 
    void heatUp(const int minutes) const;

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

void CoffeeMachine::foamMilk(const int airPre) const 
{
    std::cout << "Milk foamed with " << airPre << "bars" << '\n';  
}

float CoffeeMachine::crushBeans() const
{
    std::string crushed = "CRUSHED!";
    std::cout << crushed << '\n';  

    return 10.0f;
}

void CoffeeMachine::makeCoffee(const int airPres, const float crushedBeans) const 
{
    std::cout << "Beans: " << crushedBeans << " crushed with " << airPres << " bars !" << '\n'; 
}

void CoffeeMachine::heatUp(const int min) const
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

bool Fridge::Door::switchOnDisplay(const bool touched) const
{
    return touched ? true : false;
}

void Fridge::Door::alert(const bool open,const int time) const 
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

void Fridge::crushIce(const unsigned int ice) const
{
    std::cout << ice << "Ice cubes crushed! " << '\n';
}

double Fridge::streamWater(const double tankVolume) const
{
    return (tankVolume - 1.0);
}

unsigned int Fridge::adjustTemperature(Door& door) const 
{
    return (door.switchOnDisplay(true)) ? true : false;
}

bool Fridge::openDoor(Door& door, const int angle = 45) const
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

    void printObjectMemberInfos() const;

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

void Kitchen::makeCappucino() // const does not work here: "binding value of type 'const Fridge::Door' to reference to type 'Fridge::Door' drops 'const' qualifier"

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

void Kitchen::fillCoffeeTank() // const does not work here: "cannot assign to non-static data member within const member function 'fillCoffeeTank'""

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
    void removeFromTable(const bool isOnTable);

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

void House::removeFromTable(const bool onTable)
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
