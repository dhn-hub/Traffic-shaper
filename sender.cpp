/*
 * Sender.cc
 *
 *  Created on: Mar 27, 2021
 *      Author: JATIN PENDHARKAR
 */
#include<omnetpp.h>

using namespace omnetpp;

class Sender: public cSimpleModule
{
private:
    cMessage*msg;
    cMessage *event;
    simtime_t currentTime, InterArrivalTime, prevTime;


public:
    Sender();
    virtual ~Sender();

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void sendNextMessage();
    virtual void createDelay();


};

Define_Module(Sender);


Sender::Sender()
{
    event = nullptr;
}

Sender::~Sender()
{
    cancelAndDelete(event);
     delete event;
}



void Sender::initialize()
{
    srand(time(nullptr));
    cMessage *msg=new cMessage("RandomMessage");
    send (msg, "out");
    createDelay();
    sendNextMessage();

}

void Sender::sendNextMessage()
{
 cMessage *msg = new cMessage("msg");
 currentTime =simTime();
 send(msg, "out");
 InterArrivalTime = currentTime - prevTime;
}

void Sender::handleMessage(cMessage *msg)
{
 if (msg == event)
 {
     EV<<"Message sent successfully\n";
     scheduleAt(simTime()+par("InterArrivalTime").doubleValue(), msg);
     send(msg, "out");
 }
 else
 {
     delete msg;
     sendNextMessage();
     createDelay();
 }
}

void Sender::createDelay()
{
    simtime_t delay = par("delay");
       event = new cMessage("event");
       scheduleAt(simTime() + delay, event);
       bool discard;
}
