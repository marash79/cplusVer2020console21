#pragma once
#include <iostream>
#include <string>

class  IElectronics {
    std::string m_brand, m_model;
public:
    IElectronics(const std::string& brand, const std::string& model) :m_brand(brand), m_model(model) {};
    virtual void showSpec() = 0;
    const std::string getSpec(); 
    virtual ~IElectronics() {};
};


class Device : virtual public IElectronics
{
    int m_batteryLife;
public:
    Device(const int batteryLife) : m_batteryLife(batteryLife) {}
    const int getBatteryLife();
};


class Appliances : virtual public IElectronics {
    int m_weight;
public:
    Appliances(const int weight) :m_weight(weight) {};
    const int getWeight();
};



class portablePlayer : public Device, Appliances
{
    int m_totalTracks;
public:
    portablePlayer(const int batteryLife, const int totalTracks, const std::string& brand, const std::string& model, const int weight)
        : Device(batteryLife), Appliances(weight), IElectronics(brand, model), m_totalTracks(totalTracks) {}

    virtual void showSpec() override;
};

class PowerBank :public Device {
public:
    PowerBank(const int batteryLife, const std::string& brand, const std::string& model)
        : Device(batteryLife), IElectronics(brand, model) {}
    virtual void showSpec() override;
};

class Fridge :public Appliances {
public:
    Fridge(const int weight, const std::string& brand, const std::string& model)
        : Appliances(weight), IElectronics(brand, model) {}
    virtual void showSpec() override;
};