//
// Created by student on 28.10.2018.
//

#ifndef PROJECT2_EVENT_H
#define PROJECT2_EVENT_H
#include "Passenger.h"


class Event{

public:

   static int currenttime;
    int type;
    int time;
    Passenger* tpassenger=nullptr;


    Event(int _time,int _type,Passenger* _tpassenger);
    ~Event();

};


#endif //PROJECT2_EVENT_H
