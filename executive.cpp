//
// Created by student on 28.10.2018.
//

#include "executive.h"
#include <iostream>
using namespace std;


void executive::execute1(queue<Passenger *> &_luggagequeue, queue<Passenger *> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue,Event* top) {

    if(top->type==0){

        if(Passenger::noLuggageCounter!=0){

            Passenger::noLuggageCounter--;

            if(_luggagequeue.empty()) {
                _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
            }
            else{
                _luggagequeue.push(top->tpassenger);

                Passenger* temp = _luggagequeue.front();


                _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                _luggagequeue.pop();
            }


        }
        else{

            _luggagequeue.push(top->tpassenger);
        }
    }

    else if(top->type==1){

        Passenger::noLuggageCounter++;
        if(!_luggagequeue.empty()){
            Passenger* temp = _luggagequeue.front();
            _eventqueue.push(new Event(temp->luggage+Event::currenttime,1,temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }

        if(Passenger::noSecurityCounter!=0){


            if(_securityqueue.empty()){

                _eventqueue.push(new Event(top->tpassenger->security+Event::currenttime,2,top->tpassenger));
                Passenger::noSecurityCounter--;
            }

            else{
                _securityqueue.push(top->tpassenger);

                Passenger* temp = _securityqueue.front();


                _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
                _securityqueue.pop();
            }


        }
        else{

            _securityqueue.push(top->tpassenger);
        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.front();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();

            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;



    }
}

void executive::execute2(priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_luggagequeue,
                         priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue, Event *top) {

    if(top->type==0){

        if(Passenger::noLuggageCounter!=0){
            Passenger::noLuggageCounter--;

            if(_luggagequeue.empty()) {
                _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
            }
            else{
                _luggagequeue.push(top->tpassenger);

                Passenger* temp = _luggagequeue.top();


                _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                _luggagequeue.pop();
            }


        }
        else{

            _luggagequeue.push(top->tpassenger);
        }
    }

    else if(top->type==1){

        Passenger::noLuggageCounter++;
        if(!_luggagequeue.empty()){
            Passenger* temp = _luggagequeue.top();
            _eventqueue.push(new Event(temp->luggage+Event::currenttime,1,temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }

        if(Passenger::noSecurityCounter!=0){


            if(_securityqueue.empty()){

                _eventqueue.push(new Event(top->tpassenger->security+Event::currenttime,2,top->tpassenger));
                Passenger::noSecurityCounter--;
            }

            else{
                _securityqueue.push(top->tpassenger);

                Passenger* temp = _securityqueue.top();


                _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
                _securityqueue.pop();
            }


        }
        else{

            _securityqueue.push(top->tpassenger);
        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.top();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();
            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;



    }

}
void executive::execute3(queue<Passenger *> &_luggagequeue, queue<Passenger *> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue, Event *top) {


    if(top->type==0){

        if(Passenger::noLuggageCounter!=0){
            Passenger::noLuggageCounter--;

            if(_luggagequeue.empty()) {
                _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
            }
            else{
                _luggagequeue.push(top->tpassenger);

                Passenger* temp = _luggagequeue.front();


                _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                _luggagequeue.pop();
            }


        }
        else{

            _luggagequeue.push(top->tpassenger);
        }
    }

    else if(top->type==1) {

        Passenger::noLuggageCounter++;

        if (!_luggagequeue.empty()) {
            Passenger *temp = _luggagequeue.front();
            _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }

        if (top->tpassenger->isVip) {
            if(Event::currenttime>top->tpassenger->departure){
                Passenger::noMissingPassenger++;
            }

            Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;

        }
        else{
            if (Passenger::noSecurityCounter != 0) {


                if (_securityqueue.empty()) {

                    _eventqueue.push(new Event(top->tpassenger->security + Event::currenttime, 2, top->tpassenger));
                    Passenger::noSecurityCounter--;
                } else {
                    _securityqueue.push(top->tpassenger);

                    Passenger *temp = _securityqueue.front();


                    _eventqueue.push(new Event(temp->security + Event::currenttime, 2, temp));
                    _securityqueue.pop();
                }


            } else {

                _securityqueue.push(top->tpassenger);
            }
        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.front();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();
            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;



    }

}

void executive::execute4(priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_luggagequeue,
                         priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue, Event *top) {

    if(top->type==0){

        if(Passenger::noLuggageCounter!=0){
            Passenger::noLuggageCounter--;

            if(_luggagequeue.empty()) {
                _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
            }
            else{
                _luggagequeue.push(top->tpassenger);

                Passenger* temp = _luggagequeue.top();


                _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                _luggagequeue.pop();
            }


        }
        else{

            _luggagequeue.push(top->tpassenger);
        }
    }

    else if(top->type==1) {

        Passenger::noLuggageCounter++;
        if (!_luggagequeue.empty()) {
            Passenger *temp = _luggagequeue.top();
            _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }
        if (top->tpassenger->isVip) {
            if(Event::currenttime>top->tpassenger->departure){
                Passenger::noMissingPassenger++;
            }

            Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;

        }
        else{
            if (Passenger::noSecurityCounter != 0) {


                if (_securityqueue.empty()) {

                    _eventqueue.push(new Event(top->tpassenger->security + Event::currenttime, 2, top->tpassenger));
                    Passenger::noSecurityCounter--;
                } else {
                    _securityqueue.push(top->tpassenger);

                    Passenger *temp = _securityqueue.top();


                    _eventqueue.push(new Event(temp->security + Event::currenttime, 2, temp));
                    _securityqueue.pop();
                }


            } else {

                _securityqueue.push(top->tpassenger);
            }

        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.top();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();
            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;



    }

}

void executive::execute5(queue<Passenger *> &_luggagequeue, queue<Passenger *> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue, Event *top) {

    if(top->type==0) {

        if (top->tpassenger->hasLuggage){
            if (Passenger::noLuggageCounter != 0) {
                Passenger::noLuggageCounter--;

                if (_luggagequeue.empty()) {
                    _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
                } else {
                    _luggagequeue.push(top->tpassenger);

                    Passenger *temp = _luggagequeue.front();


                    _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                    _luggagequeue.pop();
                }


            } else {

                _luggagequeue.push(top->tpassenger);
            }
        }
        else{

            if(Passenger::noSecurityCounter!=0){


                if(_securityqueue.empty()){

                    _eventqueue.push(new Event(top->tpassenger->security+Event::currenttime,2,top->tpassenger));
                    Passenger::noSecurityCounter--;
                }

                else{
                    _securityqueue.push(top->tpassenger);

                    Passenger* temp = _securityqueue.front();


                    _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
                    _securityqueue.pop();
                }


            }
            else{

                _securityqueue.push(top->tpassenger);
            }
        }
    }

    else if(top->type==1){

        Passenger::noLuggageCounter++;
        if(!_luggagequeue.empty()){
            Passenger* temp = _luggagequeue.front();
            _eventqueue.push(new Event(temp->luggage+Event::currenttime,1,temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }

        if(Passenger::noSecurityCounter!=0){


            if(_securityqueue.empty()){

                _eventqueue.push(new Event(top->tpassenger->security+Event::currenttime,2,top->tpassenger));
                Passenger::noSecurityCounter--;
            }

            else{
                _securityqueue.push(top->tpassenger);

                Passenger* temp = _securityqueue.front();


                _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
                _securityqueue.pop();
            }


        }
        else{

            _securityqueue.push(top->tpassenger);
        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.front();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();
            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;



    }

}

void executive::execute6(priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_luggagequeue,
                         priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue, Event *top) {

    if(top->type==0) {

        if (top->tpassenger->hasLuggage){
            if (Passenger::noLuggageCounter != 0) {
                Passenger::noLuggageCounter--;

                if (_luggagequeue.empty()) {
                    _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
                } else {
                    _luggagequeue.push(top->tpassenger);

                    Passenger *temp = _luggagequeue.top();


                    _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                    _luggagequeue.pop();
                }


            } else {

                _luggagequeue.push(top->tpassenger);
            }
        }
        else{
            if(Passenger::noSecurityCounter!=0){


                if(_securityqueue.empty()){

                    _eventqueue.push(new Event(top->tpassenger->security+Event::currenttime,2,top->tpassenger));
                    Passenger::noSecurityCounter--;
                }

                else{
                    _securityqueue.push(top->tpassenger);

                    Passenger* temp = _securityqueue.top();


                    _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
                    _securityqueue.pop();
                }


            }
            else{

                _securityqueue.push(top->tpassenger);
            }
        }
    }

    else if(top->type==1){

        Passenger::noLuggageCounter++;
        if(!_luggagequeue.empty()){
            Passenger* temp = _luggagequeue.top();
            _eventqueue.push(new Event(temp->luggage+Event::currenttime,1,temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }

        if(Passenger::noSecurityCounter!=0){


            if(_securityqueue.empty()){

                _eventqueue.push(new Event(top->tpassenger->security+Event::currenttime,2,top->tpassenger));
                Passenger::noSecurityCounter--;
            }

            else{
                _securityqueue.push(top->tpassenger);

                Passenger* temp = _securityqueue.top();


                _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
                _securityqueue.pop();
            }


        }
        else{

            _securityqueue.push(top->tpassenger);
        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.top();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();
            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;



    }

}

void executive::execute7(queue<Passenger *> &_luggagequeue, queue<Passenger *> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue, Event *top) {

    if(top->type==0) {

        if (top->tpassenger->hasLuggage){

            if (Passenger::noLuggageCounter != 0) {
                Passenger::noLuggageCounter--;

                if (_luggagequeue.empty()) {
                    _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
                } else {
                    _luggagequeue.push(top->tpassenger);

                    Passenger *temp = _luggagequeue.front();


                    _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                    _luggagequeue.pop();
                }


            } else {

                _luggagequeue.push(top->tpassenger);
            }
        }
        else {
            if (top->tpassenger->isVip) {
                if(Event::currenttime>top->tpassenger->departure){
                    Passenger::noMissingPassenger++;
                }

                Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;

            }
            else{
                if (Passenger::noSecurityCounter != 0) {


                    if (_securityqueue.empty()) {

                        _eventqueue.push(new Event(top->tpassenger->security + Event::currenttime, 2, top->tpassenger));
                        Passenger::noSecurityCounter--;
                    } else {
                        _securityqueue.push(top->tpassenger);

                        Passenger *temp = _securityqueue.front();


                        _eventqueue.push(new Event(temp->security + Event::currenttime, 2, temp));
                        _securityqueue.pop();
                    }


                } else {

                    _securityqueue.push(top->tpassenger);
                }

            }
        }


    }

    else if(top->type==1) {

        Passenger::noLuggageCounter++;

        if (!_luggagequeue.empty()) {
            Passenger *temp = _luggagequeue.front();
            _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }

        if (top->tpassenger->isVip) {
            if(Event::currenttime>top->tpassenger->departure){
                Passenger::noMissingPassenger++;
            }

            Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;

        }
        else{
            if (Passenger::noSecurityCounter != 0) {


                if (_securityqueue.empty()) {

                    _eventqueue.push(new Event(top->tpassenger->security + Event::currenttime, 2, top->tpassenger));
                    Passenger::noSecurityCounter--;
                } else {
                    _securityqueue.push(top->tpassenger);

                    Passenger *temp = _securityqueue.front();


                    _eventqueue.push(new Event(temp->security + Event::currenttime, 2, temp));
                    _securityqueue.pop();
                }


            } else {

                _securityqueue.push(top->tpassenger);
            }
        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.front();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();
            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;



    }

}

void executive::execute8(priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_luggagequeue,
                         priority_queue<Passenger *, vector<Passenger *>, mycompare2> &_securityqueue,
                         priority_queue<Event *, vector<Event *>, mycompare> &_eventqueue, Event *top) {

    if(top->type==0) {

        if (top->tpassenger->hasLuggage){

            if (Passenger::noLuggageCounter != 0) {
                Passenger::noLuggageCounter--;

                if (_luggagequeue.empty()) {
                    _eventqueue.push(new Event(top->tpassenger->luggage + Event::currenttime, 1, top->tpassenger));
                } else {
                    _luggagequeue.push(top->tpassenger);

                    Passenger *temp = _luggagequeue.top();


                    _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
                    _luggagequeue.pop();
                }


            } else {

                _luggagequeue.push(top->tpassenger);
            }
        }
        else {
            if (top->tpassenger->isVip) {
                if(Event::currenttime>top->tpassenger->departure){
                    Passenger::noMissingPassenger++;
                }

                Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;

            }
            else{
                if (Passenger::noSecurityCounter != 0) {


                    if (_securityqueue.empty()) {

                        _eventqueue.push(new Event(top->tpassenger->security + Event::currenttime, 2, top->tpassenger));
                        Passenger::noSecurityCounter--;
                    } else {
                        _securityqueue.push(top->tpassenger);

                        Passenger *temp = _securityqueue.top();


                        _eventqueue.push(new Event(temp->security + Event::currenttime, 2, temp));
                        _securityqueue.pop();
                    }


                } else {

                    _securityqueue.push(top->tpassenger);
                }

            }
        }


    }

    else if(top->type==1) {

        Passenger::noLuggageCounter++;

        if (!_luggagequeue.empty()) {
            Passenger *temp = _luggagequeue.top();
            _eventqueue.push(new Event(temp->luggage + Event::currenttime, 1, temp));
            _luggagequeue.pop();
            Passenger::noLuggageCounter--;
        }

        if (top->tpassenger->isVip) {
            if(Event::currenttime>top->tpassenger->departure){
                Passenger::noMissingPassenger++;
            }

            Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;

        }
        else{
            if (Passenger::noSecurityCounter != 0) {


                if (_securityqueue.empty()) {

                    _eventqueue.push(new Event(top->tpassenger->security + Event::currenttime, 2, top->tpassenger));
                    Passenger::noSecurityCounter--;
                } else {
                    _securityqueue.push(top->tpassenger);

                    Passenger *temp = _securityqueue.top();


                    _eventqueue.push(new Event(temp->security + Event::currenttime, 2, temp));
                    _securityqueue.pop();
                }


            } else {

                _securityqueue.push(top->tpassenger);
            }
        }
    }

    else{

        Passenger::noSecurityCounter++;

        if(!_securityqueue.empty()){
            Passenger* temp = _securityqueue.top();
            _eventqueue.push(new Event(temp->security+Event::currenttime,2,temp));
            _securityqueue.pop();
            Passenger::noSecurityCounter--;
        }

        if(Event::currenttime>top->tpassenger->departure){
            Passenger::noMissingPassenger++;
        }

        Passenger::sumoftime +=Event::currenttime-top->tpassenger->arrival;


    }


}