#include "VendingMachine.h"
#include <iostream>

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
