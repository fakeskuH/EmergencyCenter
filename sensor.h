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
    Sensor(string name, string vendor, int type, int ID, bool isEnabled) : ISensorComponent(name,vendor,type,ID), m_bEnabled(isEnabled)  {}
    void enable();
    void disable();
    void alarm();
    void test();
    bool isSensor() { return true; }
    void overview(int level);

    vector<shared_ptr<Action>> m_vActions;

    Sensor& Sensor::operator++() // prefix
    {
        this->enable();
        return *this;
    }

    Sensor Sensor::operator++(int unused) // postfix
    {
        Sensor result = *this;
        result.enable();
        return result;
    }

    Sensor& Sensor::operator--() // prefix
    {
        this->disable();
        return *this;
    }

    Sensor Sensor::operator--(int unused) // postfix
    {
        Sensor result = *this;
        result.disable();
        return result;
    }

    friend ostream& operator <<(ostream& out, const Sensor& s) // output
    {
        out << "[Sensor]: " << endl;
        out << "\t Name: " << s.m_sName << endl;
        out << "\t Vendor: " << s.m_sVendor << endl;
        out << "\t Type: " << s.m_iType << endl;
        out << "\t ID: " << s.m_iID << endl;
        out << "\t State: " << (s.m_bEnabled ? "Enabled" : "Disabled") << endl;
        return out;
    }

private:
    bool m_bEnabled;
};
#endif // SENSOR_H
