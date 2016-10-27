#ifndef ACTION_H
#define ACTION_H

#include <string>

class Action
{
public:
    Action() {}
    Action(std::string name) : m_sName(name) {}
    virtual void execute() = 0;
    std::string getName() { return m_sName; }

    std::string m_sName;
};

#endif // ACTION_H
