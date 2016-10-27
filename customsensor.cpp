#include "customsensor.h"

void CustomSensor::addAction(shared_ptr<Action> pAction) {
    m_vActions.push_back(pAction);
}

void CustomSensor::removeAction(shared_ptr<Action> pAction) {
    m_vActions.erase(std::remove(m_vActions.begin(), m_vActions.end(), pAction), m_vActions.end());
}
