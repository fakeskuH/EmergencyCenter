#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H

#include <sensor.h>

class SmokeSensor : public Sensor
{
public:
    SmokeSensor(string name, string vendor, int id, bool isEnabled) :
        Sensor(name, vendor, "Smoke", id, isEnabled) {
        m_vActions.push_back(shared_ptr<Action>(new NotifyPolice()));
        m_vActions.push_back(shared_ptr<Action>(new CustomAction("EnableSprinklers",[]() {
            Logger::log("Enabling sprinklers via a lambda!",0);
        })));
    }
};

#endif // SMOKESENSOR_H
