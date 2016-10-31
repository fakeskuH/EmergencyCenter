#include <QCoreApplication>

#include <sensorgroup.h>
#include <sensor.h>
#include <customsensor.h>
#include <smokesensor.h>
#include <customaction.h>

void myCustomAction() {
    Logger::log("Executing some custom action.",0);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CustomSensor s1("Sensor1","ABC",2,1,false);

    shared_ptr<SensorGroup> pGroup1(new SensorGroup("Service Center",0));
    shared_ptr<SensorGroup> pGroup2(new SensorGroup("Sensors Groep T M14",1));
    shared_ptr<SensorGroup> pGroup3(new SensorGroup("Sensors Groep T M13",2));
    shared_ptr<SensorGroup> pGroup4(new SensorGroup("Sensors test",3));
    shared_ptr<CustomSensor> pSensor1(&s1);
    shared_ptr<CustomSensor> pSensor2(new CustomSensor("Sensor2","ABC",3,2,true));
    shared_ptr<CustomSensor> pSensor3(new CustomSensor("Sensor3","ABC",1,3,false));
    shared_ptr<SmokeSensor> pSmokeSensor1(new SmokeSensor("Smoke M13","ABC",4,true));
    shared_ptr<SmokeSensor> pSmokeSensor2(new SmokeSensor("Smoke M14","ABC",5,true));

    pSensor1->addAction(shared_ptr<Action>(new NotifyPolice()));
    pSensor1->addAction(shared_ptr<Action>(new CustomAction("MyCustomAction",myCustomAction)));
    pSensor1->addAction(shared_ptr<Action>(new CustomAction("MyOtherCustomAction",[]() {
        Logger::log("Executing fancy lambda.",0);
    })));

    ++s1; // Needs to be prefix, as the shared_ptr of the sensor object is used in testing. Since post-fix returns a copy of the object (and thus it's shared_ptr remains unchanged) it won't get updated.
    pSensor2->disable();

    pGroup1->add(pGroup2);
    pGroup1->add(pGroup3);
    pGroup1->setSort([](shared_ptr<ISensorComponent>& lhs, shared_ptr<ISensorComponent>& rhs) {
        return lhs->m_iType < rhs->m_iType;
    });

    pGroup2->add(pSensor1);
    pGroup2->add(pSensor2);
    pGroup2->add(pSensor3);
    pGroup2->setSort([](shared_ptr<ISensorComponent>& lhs, shared_ptr<ISensorComponent>& rhs) {
        return lhs->m_iType < rhs->m_iType;
    });

    pGroup3->add(pSmokeSensor1);
    pGroup3->add(pGroup4);
    pGroup3->setSort([](shared_ptr<ISensorComponent>& lhs, shared_ptr<ISensorComponent>& rhs) {
        return lhs->m_iType < rhs->m_iType;
    });

    pGroup4->add(pSmokeSensor2);
    pGroup4->setSort([](shared_ptr<ISensorComponent>& lhs, shared_ptr<ISensorComponent>& rhs) {
        return lhs->m_iType < rhs->m_iType;
    });

    pGroup1->test();
    pGroup1->overview(0);
    cout << s1;
    return a.exec();
}
