/*
 * State.h
 *
 *  Created on: Mar 7, 2013
 *      Author: jay
 */

#include "Event.h"

#ifndef STATE_H_
#define STATE_H_

class State {
public:
	virtual ~State();
	virtual State* getEvent(Event* e)=0;
	virtual static State* getInstanceOf();
private:
	State();
};

class CUOff : public State {
public:
	virtual State* getEvent( Event* e) {
		return e->getEvent(*this);
	}
};
class OUOff : public State {};
class CSOff : public State {};
class OSOff : public State {};
class CROn : public State {};

#endif /* STATE_H_ */
