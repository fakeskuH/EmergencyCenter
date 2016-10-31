#ifndef ISENSORGROUP_H
#define ISENSORGROUP_H

#include <string>

using namespace std;

class ISensorComponent
{
public:
    ISensorComponent(string name, string vendor, int typeID, int ID) : m_sName(name), m_sVendor(vendor), m_iType(typeID), m_iID(ID) {}

    virtual void test() = 0;
    virtual bool isSensor() = 0;
    virtual void overview(int level) = 0;

    string m_sName;
    string m_sVendor;
    int m_iType;
    int m_iID;
};

#endif // ISENSORGROUP_H
