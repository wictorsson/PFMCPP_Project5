#include "TVStation.h"
#include <iostream>

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

void TVStation::countThisStationsCameras()
{
    std::cout << "Station has "<< this->numberOfCameras << " cameras" << "\n";  
}

void TVStation::Studio::countCamerasInThisStudio()
{
    std::cout << "Enough cameras in the newsroom? " << (this->cameras > 0 && this->isNewsStudio ? "Yes" : "No") << "\n";
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
