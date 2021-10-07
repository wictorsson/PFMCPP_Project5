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
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
struct Guitar
{
    Guitar();
    ~Guitar();
    
    int numberOfPickups = 2;
    int numberOfStrings = 6;
    std::string logoName;
    std::string color;
    bool tuningSystem;
    
    struct String
    {
        String();
        ~String();
        
        std::string winding = "flatwound";
        std::string manufactor = "Earnie ball";
        float length;
        std::string material;
        int age;

        void calculateGuitarStringAgeBeforeBreakingDown(int ageLimit);
        void breakDownGuitarString(float pressure, float thickness);
        void oxidizeGuitarString(int age);
        void kill(int sharpness, float length);
        void checkThisStringLength();

        JUCE_LEAK_DETECTOR(String)
        
    };

    String stringNested;
    
    void reStringGuitar(int startingVal);
    void vibrateGuitarString(String string);
    void amplifyGuitar(bool guitarPluggedIn, int howLoud);
    float calculateElectricityConsumtion(float time); 
    void checkThisNumberOfStrings(); 

    JUCE_LEAK_DETECTOR(Guitar)
         
};

struct GuitarWrapper
{
    GuitarWrapper(Guitar* ptr) : pointerToGuitar(ptr){}
    ~GuitarWrapper()
    {
        delete pointerToGuitar;
    }
    Guitar* pointerToGuitar = nullptr;
};

Guitar::Guitar() : logoName("Gibson"), color("Black"), tuningSystem(true) 
{
    std::cout << "construct Guitar" << std::endl;
} 

Guitar::~Guitar()
{
    std::cout << "deconstruct Guitar" << std::endl; 
}

Guitar::String::String() : length (100.0f), age (12) 
{
    std::cout << "construct string" << std::endl;
} 

Guitar::String::~String()
{
   std::cout << "deconstruct String" << std::endl; 
}

void Guitar::checkThisNumberOfStrings()
{
    std::cout << "Is this a 6 stringed guitar? " << (this->numberOfStrings == 6 ? "Yes" : "No") << "\n";
}

void Guitar::String::checkThisStringLength()
{
    std::cout << "Is the string short ? " << (this->length <= 6.0f ? "Yes" : "No") << "\n";
}

void Guitar::String::calculateGuitarStringAgeBeforeBreakingDown(int ageLimit)
{   
    int newString = 0;
    while(newString < ageLimit)
    {   
        ++ newString;
        std::cout << "String age is increasing " << newString << std::endl;
    }
    std::cout << "String is too old " << std::endl;
}

void Guitar::String::breakDownGuitarString(float pressure, float thickness)
{
    if(pressure > 100 && thickness < 0.9f)
    {
        std::cout << "High pressure on string, it is breaking one of the " << age << " year old strings" << std::endl;
    }
}

void Guitar::String::oxidizeGuitarString(int ageMonths)
{
    if(ageMonths > 10)
    {
        std::cout << winding << " string is starting to oxidize" << std::endl;
    }
}

void Guitar::String::kill(int sharpness, float lengthCm)
{
    if(sharpness > 10 && lengthCm > 100)
    {
        std::cout << "string could be dangerous" << std::endl;
    }
}

void Guitar::reStringGuitar(int startingVal)
{
    for(int i = startingVal; i < numberOfStrings; ++ i)
    {
        std::cout << "Restringing the " << i + 1 << "th string" << std::endl;
    }

}
void Guitar::vibrateGuitarString(String string)
{
    if(string.length > 0.1f)
    {
        std::cout << "guitar is vibrating when strumming the "<< numberOfStrings << " strings." << std::endl;
    }
}

void Guitar::amplifyGuitar(bool guitarPluggedIn, int howLoud)
{
    
    if(guitarPluggedIn && howLoud > 10)
    {
        std::cout << howLoud << std::endl;
    }
    else
    {
        std::cout << logoName << "Guitar is not plugged in, mute amp" << std::endl;
    }
}

float Guitar::calculateElectricityConsumtion(float time)
{
    if (time > 0)
    {
        return time; 
    }
    return 0;
}

/*
 copied UDT 2:
 */
struct TVStation
{
    TVStation();
    ~TVStation();
    int channelChains = 24;
    int numberOfEmployees = 202;
    int numberOfCameras = 12;
    std::string tvStationName;
    float satelliteRange;

    struct Studio
    {
        Studio();
        ~Studio();
        bool isNewsStudio = false;
        int lightbulbs = 1000;
        bool isOnAir;
        int cameras;
        float size;

        void distributeLamps(int lampsPerRoom);
        void transmitVideo(bool cameraIsOn);
        void transmitAudio(bool microphone);
        bool getOnAirStatus(bool isCameraOn);
        void countCamerasInThisStudio(); 

        JUCE_LEAK_DETECTOR(Studio) 
    };

    Studio studioNested;
    void changeSatelliteRange(float steps, bool wider);
    void broadcastChannel(std::string channel);
    void produceVideo(Studio studio);
    std::string getFeedback(int date, std::string feedBack);
    void countThisStationsCameras();  

    JUCE_LEAK_DETECTOR(TVStation) 
};

struct TVStationWrapper
{
    TVStationWrapper(TVStation* ptr) : pointerToTVStation(ptr){}
    ~TVStationWrapper()
    {
        delete pointerToTVStation;
    }
    TVStation* pointerToTVStation = nullptr;
};

TVStation::TVStation() : tvStationName("Nickelodeon"), satelliteRange(180.0f) 
{
    std::cout << "construct TV station" << std::endl;
} 

TVStation::~TVStation() 
{
    std::cout << "deconstruct TVStation" << std::endl;
}

TVStation::Studio::Studio() : isOnAir(false), cameras(5), size(100) 
{
    std::cout << "construct studio" << std::endl;
} 

TVStation::Studio::~Studio()
{
    std::cout << "deconstruct Studio" << std::endl;
}

void TVStation::countThisStationsCameras()
{
    std::cout << "Station has "<< this->numberOfCameras << " cameras" << "\n";  
}

void TVStation::Studio::countCamerasInThisStudio()
{
    std::cout << "Enough cameras in the newsroom? " << (this->cameras > 0 && this->isNewsStudio ? "Yes" : "No") << "\n";
}


void TVStation::Studio::distributeLamps(int lampsPerRoom)
{
    int totalNumbOfRooms = 10;
    int roomNumber = 1;
    while(roomNumber < totalNumbOfRooms)
    {
       ++ roomNumber; 
       lightbulbs -= lampsPerRoom; 
       std::cout << "Amount of lightbulbs left: " << lightbulbs << std::endl;
    }  
    std::cout << "Amount of lightbulbs left: " << lightbulbs << std::endl;
}

void TVStation::Studio::transmitVideo(bool cameraIsOn)
{
    if(cameraIsOn)
    {
        std::cout << "transmitting video, we are on air: " << isOnAir << std::endl;
    }
    else
    {
        std::cout << "stop transmitting video" << std::endl;
    }

}

void TVStation::Studio::transmitAudio(bool microphone)
{
    if(microphone)
    {
        std::cout << "transmitting audio" << std::endl;
    }
    else
    {
        std::cout << "stop transmitting audio" << std::endl;
    }

}
 bool TVStation::Studio::getOnAirStatus(bool isCameraOn)
 {
    isOnAir = isCameraOn;
    return isOnAir;
 }

void TVStation::changeSatelliteRange(float stepSize, bool wider)
{
    for(int i = 0; i < 10; ++ i) 
    {
        if(wider)
        {
            satelliteRange += stepSize;
        }
        else
        {
            satelliteRange -= stepSize;
        }
        std::cout << satelliteRange << std::endl;
    }

}

void TVStation::broadcastChannel(std::string channel)
{
    if(channel == "CNN")
    {
        std::cout << channel << std::endl;
    }
    else
    {
        std::cout << tvStationName << std::endl;
    }
}

 void TVStation::produceVideo(Studio studio)
 {
     if(studio.cameras > 0)
     {
         std::cout << numberOfEmployees << " employees are producing video" << std::endl;
     }
     else
     {
         std::cout << "get cameras" << std::endl;
     }
 }
 
std::string TVStation::getFeedback(int date, std::string feedBack)
{  
    if(date > 0)
    {
        return feedBack;
    }
    return "";
}

/*
 copied UDT 3:
 */
struct VendingMachine
{
    VendingMachine();
    ~VendingMachine();
    
    int amountOfCandy = 50;
    int amountOfDrinks = 50;
    float insertedCoins;
    bool coolingSystem;
    std::string itemTag;

    float purchaseWithFiftyCents(float coinValue,int itemPrice);
    float chargeCustomer(bool creditcard, float itemPrice);
    void feedCustomer(int amountOfCandy);
    void coolDownMashine(int temperature, int duration);
    void checkThisCandyDrinksRatio();

    JUCE_LEAK_DETECTOR(VendingMachine)
};

struct VendingMachineWrapper
{
    VendingMachineWrapper(VendingMachine* ptr) : pointerToVendingMachine(ptr){}
    ~VendingMachineWrapper()
    {
        delete pointerToVendingMachine;
    }
    VendingMachine* pointerToVendingMachine = nullptr;
};

VendingMachine::VendingMachine() : insertedCoins(10), coolingSystem(true), itemTag("Orego")
{
    std::cout << "construct VendingMachine" << std::endl;
} 

VendingMachine::~VendingMachine()
{
    std::cout << "deconstruct VendingMachine" << std::endl;
}

void VendingMachine::checkThisCandyDrinksRatio()
{
    std::cout << "Do we need to refill drinks? " << (this->amountOfCandy > 
    this->amountOfDrinks ? "Yes" : "No") << "\n";
}
float VendingMachine::purchaseWithFiftyCents(float coinValue, int itemPrice)
{
    while(insertedCoins < itemPrice)
    {           
        insertedCoins += coinValue;
        std::cout << "Inserting cash: " << insertedCoins << std::endl;
    }
    std::cout << "Item price reached" << std::endl;
    return insertedCoins;
}

float VendingMachine::chargeCustomer(bool creditcard, float itemPrice)
{
    if(!creditcard)
    {
        return itemPrice - insertedCoins;           
    }
    return 0;
}

void VendingMachine::feedCustomer(int amountOfCandyOrdered)
{
    if(amountOfCandyOrdered > 0)
    {
        std::cout << "Chosen item: " << itemTag << std::endl;
    }  
}

void VendingMachine::coolDownMashine(int temperature, int duration)
{
    if(temperature > 30)
    {
        for(int i = 0; i < duration; ++ i) 
        {
            std::cout << "cooling down the mashine" << std::endl; 
        }
    }
}
/*
 new UDT 4:
 with 2 member functions
 */
struct Shop
{
    Shop();
    ~Shop();
    Guitar guitar;
    Guitar::String string;
    TVStation tvstation;
    VendingMachine vendingMachine;

    void sellSparePartsFromShopItems(int noOfItems);
    int repairItemFromShop(std::string itemName);
    void sumItemsForSale();

    JUCE_LEAK_DETECTOR(Shop)
};

struct ShopWrapper 
{
    ShopWrapper(Shop* ptr) : pointerToShop(ptr){}
    ~ShopWrapper()
    {
        delete pointerToShop;
    }
    Shop* pointerToShop = nullptr;
};

Shop::Shop()
 {
     std::cout << "Construct shop, guitar pickups available: " << guitar.numberOfPickups << std::endl;
 }
 
Shop::~Shop()
{
    std::cout << "deconstruct shop, guitar pickups available: " << guitar.numberOfPickups << std::endl;
}

void Shop::sumItemsForSale()
{
    std::cout << "The shop is selling this many items: " << (this->guitar.numberOfPickups + this->guitar.numberOfStrings + this->tvstation.numberOfCameras) << std::endl;   
    
     
}

void Shop::sellSparePartsFromShopItems(int noOfItems)
{
    guitar.numberOfPickups -= noOfItems;
}

int Shop::repairItemFromShop(std::string itemName)
{
    if (vendingMachine.coolingSystem)
    {
        std::cout << itemName << " has been repaired" << std::endl;
        return 1;
    }
    return 0;
}
/*
 new UDT 5:
 with 2 member functions
 */
struct MediaHouse
{   
    MediaHouse();
    ~MediaHouse();
    TVStation tvstation;
    VendingMachine vendingMachine;

    void cleanArea();
    void shutDownItem(std::string item);
    void thisAmountOfDrinks();

    JUCE_LEAK_DETECTOR(MediaHouse)
};

struct MediaHouseWrapper
{
    MediaHouseWrapper(MediaHouse* ptr) : pointerToMediaHouse(ptr){} 
    ~MediaHouseWrapper()
    {
        delete pointerToMediaHouse;
    }
    MediaHouse* pointerToMediaHouse = nullptr;
};

MediaHouse::MediaHouse()
{
    std::cout << "Construct MediaHouse" << std::endl;
}

MediaHouse::~MediaHouse()
{
    std::cout << "deconstruct MediaHouse" << std::endl;
}

void MediaHouse::thisAmountOfDrinks()
{
    std::cout << "Get amount of drinks in mediahouse: " << this->vendingMachine.amountOfDrinks << std::endl;
}

void MediaHouse::cleanArea()
{
    std::cout << "Cleaning TV station: " << tvstation.tvStationName << std::endl;
}

void MediaHouse::shutDownItem(std::string item)
{
    if (item == "VendingMachine")
    {
        std::cout << "shutting down VendingMachine" << std::endl;
        vendingMachine.amountOfCandy = 0;
        vendingMachine.amountOfDrinks = 0;
    } 
    else if (item == "TVstation")
    {
        std::cout << "shutting down TV station" << std::endl;
        tvstation.numberOfEmployees = 0;
    }    
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

//#include <iostream>

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
