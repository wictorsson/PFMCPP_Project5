#pragma once
#include "Wrappers.h"
#include "Guitar.h"
#include "TVStation.h"
#include "VendingMachine.h"
#include "Shop.h"
#include "MediaHouse.h"


GuitarWrapper::GuitarWrapper(Guitar* ptr) : pointerToGuitar(ptr){}
GuitarWrapper::~GuitarWrapper()
{
    delete pointerToGuitar;
}

TVStationWrapper::TVStationWrapper(TVStation* ptr) : pointerToTVStation(ptr){}
TVStationWrapper::~TVStationWrapper()
{
    delete pointerToTVStation;
}

VendingMachineWrapper::VendingMachineWrapper(VendingMachine* ptr) : pointerToVendingMachine(ptr){}
VendingMachineWrapper::~VendingMachineWrapper()
{
    delete pointerToVendingMachine;
}

ShopWrapper::ShopWrapper(Shop* ptr) : pointerToShop(ptr){}
ShopWrapper::~ShopWrapper()
{
    delete pointerToShop;
}

MediaHouseWrapper::MediaHouseWrapper(MediaHouse* ptr) : pointerToMediaHouse(ptr){} 
MediaHouseWrapper::~MediaHouseWrapper()
{
    delete pointerToMediaHouse;
}



   