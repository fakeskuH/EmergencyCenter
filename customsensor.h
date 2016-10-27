#ifndef CUSTOMSENSOR_H
#define CUSTOMSENSOR_H

#include <sensor.h>
#include <algorithm>

class CustomSensor : public Sensor
{
public:
    CustomSensor(string name, string vendor, string type, int id, bool isEnabled) :
        Sensor(name, vendor, type, id, isEnabled) {}
    void addAction(shared_ptr<Action> pAction);
    void removeAction(shared_ptr<Action> pAction);
};

#endif // CUSTOMSENSOR_H
