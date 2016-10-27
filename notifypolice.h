#ifndef NOTIFYPOLICE_H
#define NOTIFYPOLICE_H

#include <logger.h>
#include <action.h>

class NotifyPolice : public Action
{
public:
    NotifyPolice() {}
    void execute() { Logger::log("Notifying police..",0); }
};

#endif // NOTIFYPOLICE_H
