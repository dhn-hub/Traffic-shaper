/*
 * trafficshaper.cc
 *
 *  Created on: Mar 27, 2021
 *      Author: JATIN PENDHARKAR
 */
#include<omnetpp.h>

using namespace omnetpp;

class Trafficshaper: public cSimpleModule
{
private:

    int tokenBucket;
    cMessage *msg;
    cMessage *event;
    cQueue *queue;
    cMessage *Message;

    cMessage *sendNextMsg;
    cQueue *ingressQueue;

public:
    Trafficshaper();
        virtual ~Trafficshaper();



protected:
    virtual void initialize()override;
    virtual void handleMessage(cMessage *msg) override;
    void createDelay();
};

Define_Module(Trafficshaper);

Trafficshaper::Trafficshaper()
{
//event = nullptr;
}

Trafficshaper::~Trafficshaper()
{
// cancelAndDelete(event);
//  delete event;
}



void Trafficshaper::initialize()
{
  createDelay();
}

void Trafficshaper::handleMessage(cMessage *msg)
 {
   if (msg == event && tokenBucket <10) {
       tokenBucket++;
       EV<<"No of tokens: "<<tokenBucket<<"\n";

       if(!(ingressQueue->isEmpty()))
       {
          for (tokenBucket = 10;tokenBucket>0;tokenBucket--)
          {
          sendNextMsg = (cMessage *)ingressQueue->pop();
          send(sendNextMsg, "out");
          }

     createDelay();
   }
     else{

         if(tokenBucket > 0){
           send(msg, "out");
           tokenBucket--;
         }

         else{
         ingressQueue->insert(msg);
        }
     }
   }
 }

void Trafficshaper::createDelay()
{
        event = new cMessage("event");
        simtime_t tokenDelay = par("tokenDelay");
        scheduleAt(simTime() + tokenDelay, event);
}
