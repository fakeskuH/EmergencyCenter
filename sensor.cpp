#include "sensor.h"


void Sensor::enable() {
    m_bEnabled = true;
}

void Sensor::disable() {
    m_bEnabled = false;
}

void Sensor::alarm() {
    for (shared_ptr<Action> a : m_vActions) {
        a->execute();
    }
}

void Sensor::test() {
    if (m_bEnabled) {
        Logger::log("Testing sensor: '" + m_sName + "'...",3);
        alarm();
        Logger::log("Done testing sensor: '" + m_sName + "'.",3);
    } else {
        Logger::log(m_sName + " is disabled.", 1);
    }
}
