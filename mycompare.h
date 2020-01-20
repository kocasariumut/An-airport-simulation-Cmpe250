//
// Created by student on 28.10.2018.
//


#ifndef PROJECT2_MYCOMPARE_H
#define PROJECT2_MYCOMPARE_H
#include "Event.h"


class mycompare{

public:

    bool operator()(Event* x,Event* y);

};

#endif //PROJECT2_MYCOMPARE_H
