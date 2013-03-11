/*
 * Microwave.cpp
 *
 *  Created on: Mar 7, 2013
 *      Author: jay
 */

#include <map>
#include <cstdio>
#include "State.h"
#include "Event.h"

using namespace std;

int main() {
	map<string, Event*> events;
	string line;
	events[string("OPEN_DOOR")] = new OPEN_DOOR();
	events[string("CLOSE_DOOR")] = new CLOSE_DOOR();
	events[string("SET_TIMER")] = new SET_TIMER();
	events[string("PRESS_START")] = new PRESS_START();
	events[string("PRESS_CANCEL")] = new PRESS_CANCEL();
	events[string("DING")] = new DING();
	State* s = CUOff::getInstanceOf();
	printf("%16s\t", "INITIAL");
	cout << s->toString() << endl;
	while (getline(cin, line)) {
		s = s->getNextState(events[line]);
		printf("%16s\t", line.c_str());
		cout << s->toString() << endl;
	}
	return 0;
}



