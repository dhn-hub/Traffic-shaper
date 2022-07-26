/*
 * Receiver.cc
 *
 *  Created on: Mar 27, 2021
 *      Author: JATIN PENDHARKAR
 */
#include<omnetpp.h>

using namespace omnetpp;

class Receiver: public cSimpleModule
{
private:
    cMessage *msg;

public:
    Receiver();
    virtual ~Receiver();

protected:
   virtual void initialize() override;

};

Define_Module(Receiver);
Define_Module(Receiver);

Receiver::Receiver()
{
    msg = nullptr;
}

Receiver::~Receiver()
{
    cancelAndDelete(msg);
     delete msg;
}


void Receiver::initialize()
{
        EV << "Received Message\n";
        simtime_t timeout;
        delete msg;
}
