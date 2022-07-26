# TrafficShaper

Problem Statement is given in TrafficShapper.pdf

SIMULATION AND MODELLING OF TOKEN BUCKET TRAFFIC SHAPER – COMMUNICATION NETWORKS

Language and Platform: OMNET++ and C++

About: Station-A is sending packets towards Station-B via the Traffic Shaper. The traffic from Station-A is randomly generated following Poisson distribution. That is, the inter-arrival time between packets is Poisson distributed and hence is of variable packet rate. The traffic shaper will queue the incoming packets from A and then “schedule” them at a constant packet rate towards Station-B.  Thus, the traffic between Station A and the Traffic Shaper is VBR, while between the Traffic Shaper and Station-B is CBR. The traffic shaper MUST be based on Token Bucket algorithm

Architecture

![image](https://user-images.githubusercontent.com/86410054/143660640-808ff356-4409-4a99-a439-cfc421a52ebf.png)
