#include "Shop.h"
#include "VendingMachine.h"
//#include "Guitar.h"
#include <iostream>

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

