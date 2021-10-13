#pragma once
#include "LeakedObjectDetector.h"
#include "TVStation.h"
#include "VendingMachine.h"

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



