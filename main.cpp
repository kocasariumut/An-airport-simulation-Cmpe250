#include <iostream>
#include <fstream>
#include "mycompare1.h"
#include "executive.h"

using namespace std;



void scenariOdd(const vector<Passenger*>& myPassengers,int scenario);
void scenarioEven(const vector<Passenger*>& myPassengers,int scenario);


int main(int argc, char* argv[]) {

    if(argc!=3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }
    ifstream infile;
    infile.open(argv[1]);

    if(infile.fail()){
        cout<<"input file can not be reached"<<endl;
        return 1;
    }

    infile >>Passenger::noPassenger>>Passenger::noLuggageCounter>>Passenger::noSecurityCounter;
    vector<Passenger*> myPassengers;

    for(int i=0;i<Passenger::noPassenger;i++){

        Passenger *passenger =new Passenger;

        infile>>passenger->arrival>>passenger->departure>>passenger->luggage>>passenger->security;
        char b;
        infile>>b;
        if(b=='V')
            passenger->isVip = true;
        infile>>b;
        if(b=='L')
            passenger->hasLuggage = true;

        myPassengers.push_back(passenger);


    }
    infile.close();

    scenariOdd(myPassengers,1);
    scenarioEven(myPassengers,2);
    scenariOdd(myPassengers,3);
    scenarioEven(myPassengers,4);
    scenariOdd(myPassengers,5);
    scenarioEven(myPassengers,6);
    scenariOdd(myPassengers,7);
    scenarioEven(myPassengers,8);


    ofstream outfile;
    outfile.open(argv[2]);



    if(outfile.fail()){
        cout<<"output file can not be reached"<<endl;
        return 1;
    }


    for(int i=0;i<Passenger::average.size();i++){


            outfile<<Passenger::average[i]<<" "<<Passenger::noMissing[i]<<endl;

    }

    outfile.close();


    for(int i=0;i<Passenger::noPassenger;i++) {

        delete myPassengers[i];

    }

    return 0;
}

void scenariOdd(const vector<Passenger*>& myPassengers,int scenario){

    queue<Passenger*> luggagequeue;
    queue<Passenger*> securityqueue;
    priority_queue<Event*,vector<Event*>,mycompare> eventqueue;


    for(int i=0;i<Passenger::noPassenger;i++){

        Event *a = new Event(myPassengers[i]->arrival,0,myPassengers[i]);

        eventqueue.push(a);

    }

    while(!eventqueue.empty()){

        Event::currenttime = eventqueue.top()->time;

        priority_queue<Event*,vector<Event*>,mycompare1> events;

        while(!eventqueue.empty()&&Event::currenttime ==eventqueue.top()->time){


            events.push(eventqueue.top());



            eventqueue.pop();



        }
        unsigned long temporary=events.size();
        for(int i=0;i<temporary;i++){

            switch(scenario){

                case 1:
                    executive::execute1(luggagequeue,securityqueue,eventqueue,events.top());
                    break;
                case 3:
                    executive::execute3(luggagequeue,securityqueue,eventqueue,events.top());
                    break;
                case 5:
                    executive::execute5(luggagequeue,securityqueue,eventqueue,events.top());
                    break;
                case 7:
                    executive::execute7(luggagequeue,securityqueue,eventqueue,events.top());
                    break;

            }

            Event* temp = events.top();
            events.pop();
            delete temp;
        }


    }

    Passenger::noMissing.push_back(Passenger::noMissingPassenger);
    Passenger::average.push_back(static_cast<double>(Passenger::sumoftime)/Passenger::noPassenger);
    Passenger::noMissingPassenger=0;
    Passenger::sumoftime=0;


}

void scenarioEven(const vector<Passenger*>& myPassengers,int scenario){

    priority_queue<Passenger*,vector<Passenger*>,mycompare2> luggagequeue;
    priority_queue<Passenger*,vector<Passenger*>,mycompare2> securityqueue;
    priority_queue<Event*,vector<Event*>,mycompare> eventqueue;

    for(int i=0;i<Passenger::noPassenger;i++){

        Event *a = new Event(myPassengers[i]->arrival,0,myPassengers[i]);

        eventqueue.push(a);

    }

    while(!eventqueue.empty()){

        Event::currenttime = eventqueue.top()->time;

        priority_queue<Event*,vector<Event*>,mycompare1> events;

        while(!eventqueue.empty()&&Event::currenttime ==eventqueue.top()->time){


            events.push(eventqueue.top());

            eventqueue.pop();

        }
        unsigned long temporary=events.size();
        for(int i=0;i<temporary;i++){

            switch(scenario){

                case 2:
                    executive::execute2(luggagequeue,securityqueue,eventqueue,events.top());
                    break;
                case 4:
                    executive::execute4(luggagequeue,securityqueue,eventqueue,events.top());
                    break;
                case 6:
                    executive::execute6(luggagequeue,securityqueue,eventqueue,events.top());
                    break;
                case 8:
                    executive::execute8(luggagequeue,securityqueue,eventqueue,events.top());
                    break;

            }


            Event* temp = events.top();
            events.pop();
            delete temp;
        }


    }

    Passenger::noMissing.push_back(Passenger::noMissingPassenger);
    Passenger::average.push_back(static_cast<double>(Passenger::sumoftime)/Passenger::noPassenger);
    Passenger::noMissingPassenger=0;
    Passenger::sumoftime=0;
}
