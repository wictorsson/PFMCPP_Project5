#pragma once
#include "LeakedObjectDetector.h"
#include "Guitar.h"
#include "TVStation.h"
#include "VendingMachine.h"

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


