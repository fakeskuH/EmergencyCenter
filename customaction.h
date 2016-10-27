#ifndef CUSTOMACTION_H
#define CUSTOMACTION_H

#include <functional>

class CustomAction : public Action {
public:
    std::function<void ()> customAction;
    CustomAction(std::string name, std::function<void()> cb) : Action(name), customAction(cb) {}
    void execute() {
        customAction();
    }
};

#endif // CUSTOMACTION_H
