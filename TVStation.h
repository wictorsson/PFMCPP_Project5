#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

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
        void countCamerasInThisStudio(); 

        JUCE_LEAK_DETECTOR(Studio) 
    };

    Studio studioNested;
    void changeSatelliteRange(float steps, bool wider);
    void broadcastChannel(std::string channel);
    void produceVideo(Studio studio);
    std::string getFeedback(int date, std::string feedBack);
    void countThisStationsCameras();  

    JUCE_LEAK_DETECTOR(TVStation) 
};



