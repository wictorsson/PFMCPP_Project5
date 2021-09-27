/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions to each of these new UDTs.
    these member functions should use your member variables

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */
#include <iostream>
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
    };

    void reStringGuitar(int startingVal);
    void vibrateGuitarString(String string);
    void amplifyGuitar(bool guitarPluggedIn, int howLoud);
    float calculateElectricityConsumtion(float time);  
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
    };

    void changeSatelliteRange(float steps, bool wider);
    void broadcastChannel(std::string channel);
    void produceVideo(Studio studio);
    std::string getFeedback(int date, std::string feedBack);
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

struct Engine 
{
    Engine();
    float fuelIntake = 10000.0f;
    int cylinders = 12;
    int compressors = 5;
    bool oilIndicator;
    int pistonSpeed;

    void fillTank(float loadsOfFuel);
    void createMotion(float speed);
    void convertEnergy(float time, float duration);
    void produceHeat(bool oilIndicator);

};
/*
 copied UDT 3:
 */
struct VendingMashine
{
    VendingMashine();
    ~VendingMashine();
    
    int amountOfCandy = 50;
    int amountOfDrinks = 50;
    float insertedCoins;
    bool coolingSystem;
    std::string itemTag;

    float purchaseWithFiftyCents(float coinValue,int itemPrice);
    float chargeCustomer(bool creditcard, float itemPrice);
    void feedCustomer(int amountOfCandy);
    void coolDownMashine(int temperature, int duration);
};

VendingMashine::VendingMashine() : insertedCoins(10), coolingSystem(true), itemTag("Orego")
{
    std::cout << "construct vendingmashine" << std::endl;
} 

VendingMashine::~VendingMashine()
{
    std::cout << "deconstruct VendingMashine" << std::endl;
}

float VendingMashine::purchaseWithFiftyCents(float coinValue, int itemPrice)
{
    while(insertedCoins < itemPrice)
    {           
        insertedCoins += coinValue;
        std::cout << "Inserting cash: " << insertedCoins << std::endl;
    }
    std::cout << "Item price reached" << std::endl;
    return insertedCoins;
}

float VendingMashine::chargeCustomer(bool creditcard, float itemPrice)
{
    if(!creditcard)
    {
        return itemPrice - insertedCoins;           
    }
    return 0;
}

void VendingMashine::feedCustomer(int amountOfCandyOrdered)
{
    if(amountOfCandyOrdered > 0)
    {
        std::cout << "Chosen item: " << itemTag << std::endl;
    }  
}

void VendingMashine::coolDownMashine(int temperature, int duration)
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
    VendingMashine vendingMashine;

    void sellSparePartsFromShopItems(int noOfItems);
    int repairItemFromShop(std::string itemName);
};

Shop::Shop()
 {
     std::cout << "Construct shop, guitar pickups available: " << guitar.numberOfPickups << std::endl;
 }
 
Shop::~Shop()
{
    std::cout << "deconstruct shop, guitar pickups available: " << guitar.numberOfPickups << std::endl;
}

void Shop::sellSparePartsFromShopItems(int noOfItems)
{
    guitar.numberOfPickups -= noOfItems;
}

int Shop::repairItemFromShop(std::string itemName)
{
    if (vendingMashine.coolingSystem)
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
    VendingMashine vendingMashine;

    void cleanArea();
    void shutDownItem(std::string item);
};

MediaHouse::MediaHouse()
{
    std::cout << "Construct MediaHouse" << std::endl;
}

MediaHouse::~MediaHouse()
{
    std::cout << "deconstruct MediaHouse" << std::endl;
}

void MediaHouse::cleanArea()
{
    std::cout << "Cleaning TV station: " << tvstation.tvStationName << std::endl;
}

void MediaHouse::shutDownItem(std::string item)
{
    if (item == "Vendingmashine")
    {
        std::cout << "shutting down vendingmashine" << std::endl;
        vendingMashine.amountOfCandy = 0;
        vendingMashine.amountOfDrinks = 0;
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
    //FIXME: implement instruction 6. 
    std::cout << std::endl;
    Guitar guitar;
    Guitar::String string;
    guitar.reStringGuitar(2);
    guitar.vibrateGuitarString(string);
    guitar.amplifyGuitar(true, 10);
    guitar.calculateElectricityConsumtion(50);
    std::cout << "Is this a 6 stringed guitar? " << (guitar.numberOfStrings == 6 ? "Yes" : "No") << "\n";
    string.calculateGuitarStringAgeBeforeBreakingDown(8);
    string.breakDownGuitarString(200,0.1f);
    string.oxidizeGuitarString(6);
    string.kill(5,5.5f);
    std::cout << "Is the string short ? " << (string.length <= 6 ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    VendingMashine vMachine;
    vMachine.purchaseWithFiftyCents(0.5f,15);
    vMachine.chargeCustomer(true, 5.5f);
    vMachine.feedCustomer(2);
    vMachine.coolDownMashine(25, 200);
    std::cout << "Do we need to refill drinks? " << (vMachine.amountOfCandy > vMachine.amountOfDrinks ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    TVStation tvStation;
    TVStation::Studio studio;
    std::cout << "Moving the satellite dish "<< "\n";
    tvStation.changeSatelliteRange(10.5f, true);
    tvStation.broadcastChannel("CNN");
    tvStation.produceVideo(studio);
    tvStation.getFeedback(10,"Nice show");
    std::cout << "Station has "<< tvStation.numberOfCameras << " cameras" << "\n";
    std::cout << "Distributing lightbulbs" << std::endl;
    studio.distributeLamps(10);
    studio.transmitVideo(true);
    studio.transmitAudio(true);
    studio.getOnAirStatus(false);
    std::cout << "Enough cameras in the newsroom? " << (studio.cameras > 0 && studio.isNewsStudio ? "Yes" : "No") << "\n";
    std::cout << std::endl;

    Shop shop;
    shop.sellSparePartsFromShopItems(2);
    shop.repairItemFromShop("Cooling system");
    std::cout << std::endl;

    MediaHouse mediahouse;
    mediahouse.cleanArea();
    mediahouse.shutDownItem("Vendingmashine");
    std::cout << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
