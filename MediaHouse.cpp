#include "MediaHouse.h"
#include <iostream>

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
