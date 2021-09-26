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

        FIXME: nested types need 3 member functions in addition to 5 properties
    };
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

    void sellParts(int noOfItems);
    int repairedItem(std::string itemName);
};

Shop::Shop()
 {
     std::cout << "Construct shop, guitar pickups available: " << guitar.numberOfPickups << std::endl;
 }
 
Shop::~Shop()
{
    std::cout << "deconstruct shop, guitar pickups available: " << guitar.numberOfPickups << std::endl;
}

void Shop::sellParts(int noOfItems)
{
    guitar.numberOfPickups -= noOfItems;
}

int Shop::repairedItem(std::string itemName)
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
        tvstation.numberOfEmployees=0;
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
    FIXME: implement instruction 6. 


    std::cout << std::endl;
    Guitar guitar;
    Guitar::String string;
    guitar.reStringGuitar(2);
    guitar.vibrate(string);
    guitar.amplify(true, 10);
    guitar.electricity(50);
    std::cout << "Is this a 6 stringed guitar? " << (guitar.numberOfStrings == 6 ? "Yes" : "No") << "\n";
    string.stringAgeUntilBreakdown(8);
    string.breakDown(200,0.1f);
    string.oxide(6);
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

    Phone phone;
    phone.generateNewSerialNumbers(10,10);
    phone.receiveCall(false);
    phone.receiveText(true, "this is a text");
    phone.makeNoise(2,10);
    std::cout << "This phone has "<< phone.numberOfSpeaker << " speakers" << "\n";
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

    Engine engine;
    std::cout << "Filling up the tank" << std::endl;
    engine.fillTank(1000.0f);
    engine.createMotion(20.0f);
    engine.convertEnergy(30.2f, 20.9f);
    engine.produceHeat(true);
    std::cout << "Engine has "<< engine.cylinders << " cylinders" << "\n";
    std::cout << std::endl;

    Wings wings;
    std::cout << "demounting panels" << std::endl;
    wings.demountPanels(3);
    wings.foldPanels(5);
    wings.holdPlaneUp(7);
    wings.holdTheEngines(100);
    std::cout << "We are flying with " << wings.tagText << "\n";
    std::cout << std::endl;

    Wheels wheels;
    std::cout << "Filling up with air" << std::endl;
    wheels.fillAir(1000.000, 10000);
    wheels.startRolling(true, 100.9f);
    wheels.balancePlane(10.0f);
    wheels.turnTheWheel("left");
    std::cout << "We are rolling with "<< wheels.manufactor << "\n";
    std::cout << std::endl;

    Seats seats;
    std::cout << "Adding seats" << std::endl;
    seats.addSeats(5);
    seats.carryPassangers(300,2000);
    seats.foldBack(150);
    seats.store(10);
    std::cout << "Seat color "<< seats.seatColor << "\n";
    std::cout << std::endl;

    Brakes brakes;
    std::cout << "adding pads to the brake" << std::endl;
    brakes.addPadsToBrake(2, 5);
    brakes.showWear("new");
    brakes.stop(10.0f);
    brakes.decelerate(10.0f);
    std::cout << "Wear indicator status: "<< brakes.wearIndicator << "\n";
    std::cout << std::endl;

    Airplane airplane;
    std::cout << "Starting to accelerate pistons" << std::endl;
    airplane.acceleratePiston(90, 100);
    airplane.fly("London", 1000);
    airplane.driveOnGround(true);
    airplane.brake(false);
    std::cout << (airplane.seats.lifeWest && airplane.wings.lampColor == "green" ? "Safe to fly" : "Not safe to fly") << "\n";
    

    std::cout << "good to go!" << std::endl;
}
