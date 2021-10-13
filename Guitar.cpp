#include "Guitar.h"
#include <iostream> 

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
