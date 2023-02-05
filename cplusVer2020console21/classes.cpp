#include "classes.h"

const std::string IElectronics::getSpec() {
    std::string s = m_brand + ":" + m_model + ":";
    return s;
}

void portablePlayer::showSpec()
{
    std::cout << getSpec()
        << "::Battery Life: " << getBatteryLife() << "min"
        << "::Weight: " << getWeight() << "gr"
        << "::Total tracks: " << m_totalTracks;
}

void PowerBank::showSpec()
{
    std::cout << getSpec()
        << "::Battery Life: " << getBatteryLife() << "min";
}

void Fridge::showSpec() 
{
    std::cout << getSpec()
        << "::Weight: " << getWeight() << "kg";
}

const int Device::getBatteryLife() { return m_batteryLife; }
const int Appliances::getWeight() { return m_weight; };