//
// Created by student on 28.10.2018.
//

#include "Event.h"

int Event::currenttime=0;

Event::Event(int _time, int _type,Passenger* _tpassenger) {

    this->time= _time;
    this->type= _type;
    this->tpassenger = _tpassenger;
}

Event::~Event() {

}