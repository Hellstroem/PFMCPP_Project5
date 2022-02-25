/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

#include <iostream>

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

    void foamMilk(int airPressure);
    float crushBeans(); 
    void makeCoffee(int airPressure, float crushedBeans); 
    void heatUp(int minutes);

};

CoffeeMachine::CoffeeMachine() : tankVolume(1.45), airPressure(5)
{
    std::cout << "CoffeeMachine created!" << '\n';
}

CoffeeMachine::~CoffeeMachine()
{
    std::cout << "CoffeeMachine Object destruceted!" << '\n';
}

void CoffeeMachine::foamMilk(int airPre)
{
    std::cout << "Milk foamed with " << airPre << "bars" << '\n';  
}

float CoffeeMachine::crushBeans()
{
    std::string crushed = "CRUSHED!";
    std::cout << crushed << '\n';  

    return 10.0f;
}

void CoffeeMachine::makeCoffee(int airPres, float crushedBeans)
{
    std::cout << "Beans: " << crushedBeans << " crushed with " << airPres << " bars !" << '\n'; 
}

void CoffeeMachine::heatUp(int min)
{
    for(auto i = min; i >= 0; --i)
    {
        std::cout << "CoffeeMachine ready in " << i << " minutes" << '\n'; 
    }
}

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

        void closeDoor();
        bool switchOnDisplay(bool displayTouched); 
        void alert(bool, int);
    };

    Door door1;

    void crushIce(unsigned int amountOfIce);
    double streamWater(double waterTankVolume);
    unsigned int adjustTemperature(Door door); 
    bool openDoor(Door door, int angle);
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

void Fridge::Door::closeDoor()
{
    std::cout << "Door Closed!" << '\n';
}

bool Fridge::Door::switchOnDisplay(bool touched)
{
    return touched ? true : false;
}

void Fridge::Door::alert(bool open, int time)
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

void Fridge::crushIce(unsigned int ice)
{
    std::cout << ice << "Ice cubes crushed! " << '\n';
}

double Fridge::streamWater(double tankVolume)
{
    return (tankVolume - 1.0);
}

unsigned int Fridge::adjustTemperature(Door door)
{
    bool switchedOn = door.switchOnDisplay(true);

    return switchedOn ? true : false;
}

bool Fridge::openDoor(Door door, int angle = 45)
{
    for(auto i = 0; i <= angle; ++i)
    {
        door.angle = i;
        std::cout << "Door angle " << i << "degrees!" << '\n';
    }

    return true;
}

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

        void increaseAmplification(float ampFactor);
        void switchOutResistance(unsigned int outRes);
        void switchInResistance(unsigned int inRes);
    };

    Preamp preA;

    void adjustVolume(Preamp pre);
    bool switchOn(); 
    bool changeInp(char inputType); 
    void ejectCd(int time);
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

void Amplifier::Preamp::increaseAmplification(float ampFac)
{
    std::cout << "Factor set: " << ampFac << '\n';
}

void Amplifier::Preamp::switchOutResistance(unsigned int outR)
{
    std::cout << "Output Resistance set: " << outR<< '\n';
}

void Amplifier::Preamp::switchInResistance(unsigned int inR)
{
    std::cout << "Input Resistance set: " << inR<< '\n';
}

void Amplifier::adjustVolume(Preamp pre)
{
    pre.increaseAmplification(5);
}

bool Amplifier::switchOn()
{
    return true;
}

bool Amplifier::changeInp(char type)
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


/*
 new UDT 5:
 with 2 member functions
 */

struct Room
{
    Room();
    ~Room();

    Kitchen kitchen;
    Amplifier radio;

    bool putRadioOnTableAndSwitchOn();
    void removeFromTable(bool isOnTable);
};

Room::Room()
{
    std::cout << "Kitchen room object constructed!" << '\n';
}

Room::~Room()
{
    std::cout << "Kitchen room object destructed!" << '\n';
}

bool Room::putRadioOnTableAndSwitchOn()
{
    this->kitchen.tableIsOccupied = true;    
    if(this->radio.switchOn() && this->kitchen.tableIsOccupied)
    {
        std::cout << "Radio put on table!" << '\n';
        return true;
    }
    return false;
}

void Room::removeFromTable(bool onTable)
{
    if(onTable) this->kitchen.tableIsOccupied = false;

    std::cout << "Object removed from table" << '\n';
}

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
    CoffeeMachine coffeeMachine;
    coffeeMachine.foamMilk(5);
    float beans = coffeeMachine.crushBeans();
    coffeeMachine.makeCoffee(5, beans);
    coffeeMachine.heatUp(15);

    Fridge::Door door;
    door.closeDoor();
    bool dispOn = door.switchOnDisplay(true);

    std::cout << "Display is " <<  (dispOn ? "on" : "off") << '\n';

    Fridge fridge;
    fridge.crushIce(100);
    double vol = fridge.streamWater(10);
    unsigned int temp = fridge.adjustTemperature(door);
    door.doorOpened = fridge.openDoor(door, 22);
    door.alert(door.doorOpened, door.alertTime);

    std::cout << "Fridge volume is " << vol << " and temperature is " << temp << '\n'; 

    Amplifier::Preamp pre;
    pre.increaseAmplification(3.5f);
    pre.switchOutResistance(8);
    pre.switchInResistance(1000);

    Amplifier amp;
    amp.adjustVolume(pre);
    bool ampOn = amp.switchOn();
    bool inType = amp.changeInp('B');
    amp.ejectCd(7);

    std::cout << "Amp is " << (ampOn ? "on" : "off") << " and Input" << (inType ? " is active!" : " is not active") << '\n';

    Kitchen k;
    k.makeCappucino();
    k.fillCoffeeTank();

    Room kr;
    bool onTable = kr.putRadioOnTableAndSwitchOn();
    kr.removeFromTable(onTable);
    
    std::cout << "good to go!" << std::endl;
}
