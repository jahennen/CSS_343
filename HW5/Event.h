/*
 * Event.h
 *
 *  Created on: Mar 7, 2013
 *      Author: jay
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <iostream>


class State;
class CUOff;
class OUOff;
class CSOff;
class OSOff;
class CROn;

class Event {
public:
	virtual State* getNextState(CUOff* s);
	virtual State* getNextState(OUOff* s);
	virtual State* getNextState(CSOff* s);
	virtual State* getNextState(OSOff* s);
	virtual State* getNextState(CROn* s);
private:
	virtual void pure()=0;
};

class OPEN_DOOR : public Event {
public:
	virtual State* getNextState(CUOff* s);
	virtual State* getNextState(CSOff* s);
	virtual State* getNextState(CROn* s);
private:
	void pure(){};
};
class CLOSE_DOOR : public Event {
public:
	virtual State* getNextState(OUOff* s);
	virtual State* getNextState(OSOff* s);
private:
	void pure(){};
};
class SET_TIMER : public Event {
public:
	virtual State* getNextState(CUOff* s);
	virtual State* getNextState(CSOff* s);
	virtual State* getNextState(OUOff* s);
private:
	void pure(){};
};
class PRESS_START : public Event {
public:
	virtual State* getNextState(CSOff* s);
private:
	void pure(){}
};
class PRESS_CANCEL : public Event {
public:
	virtual State* getNextState(CSOff* s);
	virtual State* getNextState(OSOff* s);
	virtual State* getNextState(CROn* s);
private:
	void pure(){}
};
class DING : public Event {
public:
	virtual State* getNextState(CROn* s);
private:
	void pure(){}
};

#endif /* EVENT_H_ */
