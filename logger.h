#ifndef LOGGER_H
#define LOGGER_H

#include <QDateTime>
#include <string>
#include <iostream>

using namespace std;

class Logger
{
public:
    static void log(string message, int type);
    static void newline();
};

#endif // LOGGER_H
