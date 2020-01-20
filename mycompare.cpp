//
// Created by student on 28.10.2018.
//

#include "mycompare.h"

bool mycompare::operator()(Event *x, Event *y) {

    return x->time > y->time;
}

