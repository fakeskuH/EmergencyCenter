#include "sensorgroup.h"

void SensorGroup::test() {
    Logger::newline();
    Logger::log("Testing sensor group '" + m_sName + "'...",3);
    if (!m_vChildren.empty()) {
        for (int i = 0;i < m_vChildren.size();++i) {
            m_vChildren[i]->test();
        }
    } else {
        Logger::log("Sensor group '" + m_sName + "' appears empty.",1);
    }
    Logger::log("Done testing '" + m_sName + "'.",3);
}

void SensorGroup::add(shared_ptr<ISensorComponent> pComponent) {
    m_vChildren.push_back(static_pointer_cast<ISensorComponent>(pComponent));
}

void SensorGroup::overview(int level) {
    sort(m_vChildren.begin(), m_vChildren.end(), m_funcSort);
    for (int i = 0; i < level; ++i) cout << "\t";
    cout << "Group '" << m_sName << "' has following members:" << endl;
    level++;
    for (int j = 0;j < m_vChildren.size();++j) {
        m_vChildren[j]->overview(level);
    }
}
