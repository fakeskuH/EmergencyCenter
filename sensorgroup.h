#ifndef SENSORGROUP_H
#define SENSORGROUP_H

#include <isensorcomponent.h>
#include <logger.h>

#include <vector>
#include <string>
#include <memory>

using namespace std;
class SensorGroup : public ISensorComponent
{
public:
    SensorGroup(string name) : ISensorComponent(name) {}
    void test();
    void add(shared_ptr<ISensorComponent> pComponent);
private:
    vector<shared_ptr<ISensorComponent>> m_vChildren;
};

#endif // SENSORGROUP_H
