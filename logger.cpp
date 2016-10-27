#include "logger.h"

void Logger::log(string message, int type) {
    cout << "[" << QDateTime::currentDateTime().toString("hh:mm:ss").toStdString() << "] ";
    if (type == 0) cout << "[SUCCESS] ";
    else if (type == 1) cout << "[WARNING] ";
    else if (type == 2) cout << "[ERROR] ";
    else if (type == 3) cout << "[INFO] ";
    else cout << "[UNKNOWN] ";
    cout << message << endl;
}

void Logger::newline() {
    cout << endl;
}
