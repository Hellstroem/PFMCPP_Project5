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
#include "Wrappers.h"

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
