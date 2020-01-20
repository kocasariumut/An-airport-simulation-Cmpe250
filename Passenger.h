//
// Created by umutd on 27.10.2018.
//

#ifndef PROJECT2_PASSENGER_H
#define PROJECT2_PASSENGER_H

#include <vector>
using namespace std;

class Passenger{

public:
    static int noPassenger;
    static int noLuggageCounter;
    static int noSecurityCounter;
    static int noMissingPassenger;
    static int sumoftime;
    static vector<int> noMissing;
    static vector<double> average;
    int arrival;
    int departure;
    int luggage;
    int security;
    bool isVip;
    bool hasLuggage;

    Passenger();
    ~Passenger();


};


#endif //PROJECT2_PASSENGER_H
