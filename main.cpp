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

    shared_ptr<SensorGroup> g1(new SensorGroup("Service Center"));
    shared_ptr<SensorGroup> g2(new SensorGroup("Sensors Groep T M14"));
    shared_ptr<SensorGroup> g3(new SensorGroup("Sensors Groep T M13"));
    shared_ptr<CustomSensor> s1(new CustomSensor("Sensor1","ABC","Smoke",1,false));
    shared_ptr<CustomSensor> s2(new CustomSensor("Sensor2","ABC","Smoke",2,true));
    shared_ptr<CustomSensor> s3(new CustomSensor("Sensor3","ABC","Smoke",3,false));
    shared_ptr<SmokeSensor> smoke1(new SmokeSensor("Smoke M13","ABC",4,true));

    s1->addAction(shared_ptr<Action>(new NotifyPolice()));
    s1->addAction(shared_ptr<Action>(new CustomAction("MyCustomAction",myCustomAction)));
    s1->addAction(shared_ptr<Action>(new CustomAction("MyOtherCustomAction",[]() {
        Logger::log("Executing fancy lambda.",0);
    })));
    s1->enable();
    s2->disable();

    g1->add(g2);
    g1->add(g3);

    g2->add(s1);
    g2->add(s2);
    g2->add(s3);

    g3->add(smoke1);

    g1->test();

    return a.exec();
}
