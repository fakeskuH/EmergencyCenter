#ifndef SENSOR_H
#define SENSOR_H


#include <isensorcomponent.h>
#include <logger.h>
#include <action.h>
#include <notifypolice.h>
#include <customaction.h>

#include <vector>
#include <string>
#include <memory>

using namespace std;
class Sensor : public ISensorComponent
{
public:
    Sensor(string name, string vendor, string type, int id, bool isEnabled) : ISensorComponent(name), m_sVendor(vendor), m_sType(type), m_iID(id), m_bEnabled(isEnabled)  {}
    void enable();
    void disable();
    void alarm();
    void test();

    vector<shared_ptr<Action>> m_vActions;
private:
    string m_sVendor;
    string m_sType;
    int m_iID;
    bool m_bEnabled;
};
#endif // SENSOR_H
