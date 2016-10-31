#ifndef SENSORGROUP_H
#define SENSORGROUP_H

#include <isensorcomponent.h>
#include <logger.h>

#include <vector>
#include <string>
#include <memory>
#include <functional>

using namespace std;
class SensorGroup : public ISensorComponent
{
public:
    SensorGroup(string name, int ID) : ISensorComponent(name,"",0,ID) {}
    void test();
    void generateOverview();
    void add(shared_ptr<ISensorComponent> pComponent);
    bool isSensor() { return false; }
    void overview(int level);
    void setSort(std::function<bool(shared_ptr<ISensorComponent>& lhs, shared_ptr<ISensorComponent>& rhs)> customSort) { m_funcSort = customSort; }
private:
    vector<shared_ptr<ISensorComponent>> m_vChildren;
    function<bool(shared_ptr<ISensorComponent>& lhs, shared_ptr<ISensorComponent>& rhs)> m_funcSort;
};

#endif // SENSORGROUP_H
