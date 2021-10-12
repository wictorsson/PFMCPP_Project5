#pragma once
#include "Guitar.h"
#include "TVStation.h"
#include "VendingMachine.h"
#include "Shop.h"
#include "MediaHouse.h"

struct GuitarWrapper
{
    GuitarWrapper(Guitar* ptr) : pointerToGuitar(ptr){}
    ~GuitarWrapper()
    {
        delete pointerToGuitar;
    }
    Guitar* pointerToGuitar = nullptr;
};

struct TVStationWrapper
{
    TVStationWrapper(TVStation* ptr) : pointerToTVStation(ptr){}
    ~TVStationWrapper()
    {
        delete pointerToTVStation;
    }
    TVStation* pointerToTVStation = nullptr;
};

struct VendingMachineWrapper
{
    VendingMachineWrapper(VendingMachine* ptr) : pointerToVendingMachine(ptr){}
    ~VendingMachineWrapper()
    {
        delete pointerToVendingMachine;
    }
    VendingMachine* pointerToVendingMachine = nullptr;
};

struct ShopWrapper 
{
    ShopWrapper(Shop* ptr) : pointerToShop(ptr){}
    ~ShopWrapper()
    {
        delete pointerToShop;
    }
    Shop* pointerToShop = nullptr;
};

struct MediaHouseWrapper
{
    MediaHouseWrapper(MediaHouse* ptr) : pointerToMediaHouse(ptr){} 
    ~MediaHouseWrapper()
    {
        delete pointerToMediaHouse;
    }
    MediaHouse* pointerToMediaHouse = nullptr;
};





