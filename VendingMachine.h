#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

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



