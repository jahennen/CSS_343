/*
 * Event.h
 *
 *  Created on: Mar 7, 2013
 *      Author: jay
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
public:
	virtual ~Event();
	static virtual Event* getInstanceOf()=0;
	static Event* e=0;
private:
	Event();
};

class OPEN_DOOR : public Event {
public:
	virtual State* getEvent(CUOff* s) {
		return COOff::getInstanceOf();
	}
};
class CLOSE_DOOR : public Event {};
class SET_TIMER : public Event {};
class PRESS_START : public Event {};
class PRESS_CANCEL : public Event {};
class DING : public Event {};

#endif /* EVENT_H_ */
