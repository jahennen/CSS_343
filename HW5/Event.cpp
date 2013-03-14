/*
 * Event.cpp
 *
 *  Created on: Mar 7, 2013
 *      Author: jay
 */

#include "Event.h"
#include "State.h"

using namespace std;

void error() {
	cout << "invalid event" << endl;
}

State* Event::getNextState(CUOff* s) {error(); return s;}
State* Event::getNextState(OUOff* s) {error(); return s;}
State* Event::getNextState(CSOff* s) {error(); return s;}
State* Event::getNextState(OSOff* s) {error(); return s;}
State* Event::getNextState(CROn* s) {error(); return s;}


State* OPEN_DOOR::getNextState(CUOff* s) {return OUOff::getInstanceOf();}
State* OPEN_DOOR::getNextState(CSOff* s) {return OSOff::getInstanceOf();}
State* OPEN_DOOR::getNextState(CROn* s) {return CSOff::getInstanceOf();}

State* CLOSE_DOOR::getNextState(OUOff* s) {return CUOff::getInstanceOf();}
State* CLOSE_DOOR::getNextState(OSOff* s) {return CSOff::getInstanceOf();}

State* SET_TIMER::getNextState(CUOff* s) {return CSOff::getInstanceOf();}
State* SET_TIMER::getNextState(CSOff* s) {return CSOff::getInstanceOf();}
State* SET_TIMER::getNextState(OUOff* s) {return OSOff::getInstanceOf();}

State* PRESS_START::getNextState(CSOff* s) {return CROn::getInstanceOf();}

State* PRESS_CANCEL::getNextState(CSOff* s) {return CUOff::getInstanceOf();}
State* PRESS_CANCEL::getNextState(OSOff* s) {return OUOff::getInstanceOf();}
State* PRESS_CANCEL::getNextState(CROn* s) {return CSOff::getInstanceOf();}

State* DING::getNextState(CROn* s) {return CUOff::getInstanceOf();}



