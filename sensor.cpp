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

void Sensor::overview(int level) {
    for (int i = 0; i < level; ++i) cout << "\t";
    cout << "Sensor '" << m_sName << "' with ID '" << m_iID << "', type ID '" << m_iType << "' and vendor '" << m_sVendor << "'." << endl;
}
