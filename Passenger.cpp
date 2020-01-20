//
// Created by umutd on 27.10.2018.
//

#include "Passenger.h"

using namespace std;

int Passenger::noPassenger =0;
int Passenger::noLuggageCounter =0;
int Passenger::noSecurityCounter =0;
int Passenger::noMissingPassenger=0;
int Passenger::sumoftime= 0;
vector<int> Passenger::noMissing;
vector<double> Passenger::average;

Passenger::Passenger() {

    this->arrival=0;
    this->departure=0;
    this->luggage=0;
    this->security=0;
    this->hasLuggage=false;
    this->isVip=false;

}

Passenger::~Passenger() {

}