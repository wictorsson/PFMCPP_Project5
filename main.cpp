/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */







#include <iostream>
//#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */








/*
 copied UDT 2:
 */


/*
 copied UDT 3:
 */


/*
 new UDT 4:
 with 2 member functions
 */


/*
 new UDT 5:
 with 2 member functions
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include "Wrappers.h"
#include "Guitar.h"
#include "MediaHouse.h"
#include "Shop.h"
#include "TVStation.h"
#include "VendingMachine.h"


int main()
{ 
    std::cout << std::endl;
    
    GuitarWrapper guitarWrapper(new Guitar);
    std::cout << "Is this a 6 stringed guitar? " << (guitarWrapper.pointerToGuitar->numberOfStrings == 6 ? "Yes" : "No") << "\n";
    guitarWrapper.pointerToGuitar->reStringGuitar(2);
    guitarWrapper.pointerToGuitar->vibrateGuitarString(guitarWrapper.pointerToGuitar->stringNested);
    guitarWrapper.pointerToGuitar->amplifyGuitar(true, 10);
    guitarWrapper.pointerToGuitar->calculateElectricityConsumtion(50);
    guitarWrapper.pointerToGuitar->checkThisNumberOfStrings();

    guitarWrapper.pointerToGuitar->stringNested.calculateGuitarStringAgeBeforeBreakingDown(8);
    guitarWrapper.pointerToGuitar->stringNested.breakDownGuitarString(200,0.1f);
    guitarWrapper.pointerToGuitar->stringNested.oxidizeGuitarString(6);
    guitarWrapper.pointerToGuitar->stringNested.kill(5,5.5f);
    std::cout << "Is the string short ? " << (guitarWrapper.pointerToGuitar->stringNested.length <= 6 ? "Yes" : "No") << "\n";
    guitarWrapper.pointerToGuitar->stringNested.checkThisStringLength();
    std::cout << std::endl;

    VendingMachineWrapper vendingMachineWrapper( new VendingMachine() );
    vendingMachineWrapper.pointerToVendingMachine->purchaseWithFiftyCents(0.5f,15);
    vendingMachineWrapper.pointerToVendingMachine->chargeCustomer(true, 5.5f);
    vendingMachineWrapper.pointerToVendingMachine->feedCustomer(2);
    vendingMachineWrapper.pointerToVendingMachine->coolDownMashine(25, 200);
    std::cout << "Do we need to refill drinks? " << (vendingMachineWrapper.pointerToVendingMachine->amountOfCandy > 
    vendingMachineWrapper.pointerToVendingMachine->amountOfDrinks ? "Yes" : "No") << "\n";
    vendingMachineWrapper.pointerToVendingMachine->checkThisCandyDrinksRatio();
    std::cout << std::endl;
    
    TVStationWrapper tvStationWrapper(new TVStation); 
    std::cout << "Moving the satellite dish "<< "\n";
    tvStationWrapper.pointerToTVStation->changeSatelliteRange(10.5f, true);
    tvStationWrapper.pointerToTVStation->broadcastChannel("CNN");
    tvStationWrapper.pointerToTVStation->produceVideo(tvStationWrapper.pointerToTVStation->studioNested);
    tvStationWrapper.pointerToTVStation->getFeedback(10,"Nice show");
    std::cout << "Station has "<< tvStationWrapper.pointerToTVStation->numberOfCameras << " cameras" << "\n";
    tvStationWrapper.pointerToTVStation->countThisStationsCameras();
    std::cout << "Distributing lightbulbs" << std::endl;
    tvStationWrapper.pointerToTVStation->studioNested.distributeLamps(10);
    tvStationWrapper.pointerToTVStation->studioNested.transmitVideo(true);
    tvStationWrapper.pointerToTVStation->studioNested.transmitAudio(true);
    tvStationWrapper.pointerToTVStation->studioNested.getOnAirStatus(false);
    std::cout << "Enough cameras in the newsroom? " << (tvStationWrapper.pointerToTVStation->studioNested.cameras > 0 && tvStationWrapper.pointerToTVStation->studioNested.isNewsStudio ? "Yes" : "No") << "\n";
    tvStationWrapper.pointerToTVStation->studioNested.countCamerasInThisStudio();
    std::cout << std::endl;

    ShopWrapper shopWrapper(new Shop);
    shopWrapper.pointerToShop->sellSparePartsFromShopItems(2);
    std::cout << "The shop is selling this many items: " << guitarWrapper.pointerToGuitar->numberOfPickups + guitarWrapper.pointerToGuitar->numberOfStrings + tvStationWrapper.pointerToTVStation->numberOfCameras << std::endl;
    shopWrapper.pointerToShop->sumItemsForSale();
    shopWrapper.pointerToShop->repairItemFromShop("Cooling system");
    std::cout << std::endl;

    MediaHouseWrapper mediaHouseWrapper(new MediaHouse);
    mediaHouseWrapper.pointerToMediaHouse->cleanArea();
    mediaHouseWrapper.pointerToMediaHouse->shutDownItem("VendingMachine");

    std::cout << std::endl;
    std::cout << "Get amount of drinks in mediahouse: " << vendingMachineWrapper.pointerToVendingMachine->amountOfDrinks << std::endl;
    mediaHouseWrapper.pointerToMediaHouse->thisAmountOfDrinks();
    std::cout << "good to go!" << std::endl;
}
