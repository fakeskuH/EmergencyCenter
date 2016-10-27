#ifndef ISENSORGROUP_H
#define ISENSORGROUP_H

#include <string>

using namespace std;

class ISensorComponent
{
public:
    ISensorComponent(string name) : m_sName(name) {}

    virtual void test() = 0;

    string m_sName;
};

#endif // ISENSORGROUP_H
