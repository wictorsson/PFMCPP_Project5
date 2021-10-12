#pragma once

struct Guitar;
struct TVStation;
struct VendingMachine;
struct Shop;
struct MediaHouse;

struct GuitarWrapper
{
    GuitarWrapper(Guitar* ptr);
    ~GuitarWrapper(); 
    Guitar* pointerToGuitar = nullptr;
};

struct TVStationWrapper
{
    TVStationWrapper(TVStation* ptr);
    ~TVStationWrapper();
    TVStation* pointerToTVStation = nullptr;
};

struct VendingMachineWrapper
{
    VendingMachineWrapper(VendingMachine* ptr);
    ~VendingMachineWrapper();
    VendingMachine* pointerToVendingMachine = nullptr;
};

struct ShopWrapper 
{
    ShopWrapper(Shop* ptr);
    ~ShopWrapper();
    Shop* pointerToShop = nullptr;
};

struct MediaHouseWrapper
{
    MediaHouseWrapper(MediaHouse* ptr);
    ~MediaHouseWrapper();
    MediaHouse* pointerToMediaHouse = nullptr;
};





