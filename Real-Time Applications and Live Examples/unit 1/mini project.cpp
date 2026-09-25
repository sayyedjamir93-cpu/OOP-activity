#include <iostream>
#include <string>
using namespace std;
class SmartDevice
{
protected:
    string deviceName;
    bool status;

public:
    SmartDevice(string name)
    {
        deviceName = name;
        status = false;
    }
    void turnOn()
    {
        status = true;
        cout << deviceName << " is turned ON." << endl;
    }
    void turnOff()
    {
        status = false;
        cout << deviceName << " is turned OFF." << endl;
    }
    void display()
    {
        cout << "Device: " << deviceName
             << " | Status: " << (status ? "ON" : "OFF") << endl;
    }
};

class SmartLight : public SmartDevice
{
private:
    int brightness;

public:
    SmartLight(string name, int b) : SmartDevice(name)
    {
        brightness = b;
    }
    void setBrightness(int b)
    {
        brightness = b;
        cout << deviceName << " brightness changed to " << brightness << "%." << endl;
    }
    void displayLightInfo()
    {
        display();
        cout << "Brightness: " << brightness << "%" << endl;
    }
};

class SmartThermostat : public SmartDevice
{
private:
    float temperature;

public:
    SmartThermostat(string name, float temp) : SmartDevice(name)
    {
        temperature = temp;
    }
    void setTemperature(float temp)
    {
        temperature = temp;
        cout << deviceName << " temperature changed to " << temperature << "°C." << endl;
    }
    void displayThermostatInfo()
    {
        display();
        cout << "Temperature: " << temperature << "°C" << endl;
    }
};

int main()
{
    cout << "-----------SMART HOME MANAGER -----------" << endl
         << endl;
    SmartLight light("Living Room Light", 80);
    light.turnOn();
    light.setBrightness(50);
    light.displayLightInfo();
    cout << "\n-----------------------\n"
         << endl;
    SmartThermostat thermostat("Bedroom Thermostat", 24.5);
    thermostat.turnOn();
    thermostat.setTemperature(22.0);
    thermostat.displayThermostatInfo();
    return 0;
}