//
// Created by student on 28.10.2018.
//

#include "mycompare1.h"

bool mycompare1::operator()(Event *x, Event *y) {

    if (x->type != y->type) {
        return x->type < y->type;
    } else {
        return x->tpassenger->arrival > y->tpassenger->arrival;
    }

}

