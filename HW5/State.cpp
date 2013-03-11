/*
 * State.cpp
 *
 *  Created on: Mar 7, 2013
 *      Author: jay
 */

#include "State.h"

using namespace std;

CUOff* CUOff::instance = 0;
OUOff* OUOff::instance = 0;
CSOff* CSOff::instance = 0;
OSOff* OSOff::instance = 0;
CROn* CROn::instance = 0;

State* CUOff::getNextState(Event* e) {
	return e->getNextState(this);
}

string CUOff::toString() {
	return "CLOSED\tUNSET\tOFF";
}

CUOff* CUOff::getInstanceOf(){
	if(!instance) {
		instance = new CUOff();
	}
	return instance;
}

State* OUOff::getNextState(Event* e) {
	return e->getNextState(this);
}

string OUOff::toString() {
	return "OPEN\tUNSET\tOFF";
}

OUOff* OUOff::getInstanceOf() {
	if(!instance) {
		instance = new OUOff();
	}
	return instance;
}

State* CSOff::getNextState(Event* e){
	return e->getNextState(this);
}

string CSOff::toString() {
	return "CLOSED\tSET\tOFF";
}

CSOff* CSOff::getInstanceOf() {
	if(!instance) {
		instance = new CSOff();
	}
	return instance;
}

State* OSOff::getNextState(Event* e){
	return e->getNextState(this);
}

string OSOff::toString() {
	return "OPEN\tSET\tOFF";
}

OSOff* OSOff::getInstanceOf() {
	if(!instance) {
		instance = new OSOff();
	}
	return instance;
}

State* CROn::getNextState(Event* e){
	return e->getNextState(this);
}

string CROn::toString() {
	return "CLOSED\tRUN\tON";
}

CROn* CROn::getInstanceOf() {
	if(!instance) {
		instance = new CROn();
	}
	return instance;
}
