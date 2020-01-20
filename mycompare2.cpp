//
// Created by student on 28.10.2018.
//

#include "mycompare2.h"

bool mycompare2::operator()(Passenger *x, Passenger *y) {

   if(x->departure!=y->departure) {
       return x->departure > y->departure;
   }
    else{
       return x->arrival >  y->arrival;
   }

}