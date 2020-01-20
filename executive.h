//
// Created by student on 28.10.2018.
//

#ifndef PROJECT2_EXECUTIVE_H
#define PROJECT2_EXECUTIVE_H

#include "Event.h"
#include "mycompare.h"
#include "mycompare2.h"
#include <queue>

class executive{
public:
    static void execute1(queue<Passenger*>& _luggagequeue,queue<Passenger*>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
    static void execute2(priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _luggagequeue,priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
    static void execute3(queue<Passenger*>& _luggagequeue,queue<Passenger*>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
    static void execute4(priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _luggagequeue,priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
    static void execute5(queue<Passenger*>& _luggagequeue,queue<Passenger*>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
    static void execute6(priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _luggagequeue,priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
    static void execute7(queue<Passenger*>& _luggagequeue,queue<Passenger*>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
    static void execute8(priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _luggagequeue,priority_queue<Passenger*,vector<Passenger*>,mycompare2>& _securityqueue,priority_queue<Event*,vector<Event*>,mycompare>& _eventqueue,Event* top);
};
#endif //PROJECT2_EXECUTIVE_H
