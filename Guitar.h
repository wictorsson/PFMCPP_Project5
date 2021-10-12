#pragma once
#include "LeakedObjectDetector.h"

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









