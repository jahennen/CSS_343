/*
 * State.h
 *
 *  Created on: Mar 7, 2013
 *      Author: jay
 */

#ifndef STATE_H_
#define STATE_H_

#include "Event.h"

class State {
public:
	virtual State* getNextState(Event* e)=0;
	virtual std::string toString()=0;
private:
	virtual void pure()=0;
};

class CUOff : public State {
public:
	virtual State* getNextState(Event* e);
	virtual std::string toString();
	static CUOff* getInstanceOf();
private:
	static CUOff* instance;
	virtual void pure(){}
};

class OUOff : public State {
public:
	virtual State* getNextState(Event* e);
	virtual std::string toString();
	static OUOff* getInstanceOf();
private:
	static OUOff* instance;
	virtual void pure(){}
};

class CSOff : public State {
public:
	virtual State* getNextState(Event* e);
	virtual std::string toString();
	static CSOff* getInstanceOf();
private:
	static CSOff* instance;
	virtual void pure(){}
};

class OSOff : public State {
public:
	virtual State* getNextState(Event* e);
	virtual std::string toString();
	static OSOff* getInstanceOf();
private:
	static OSOff* instance;
	virtual void pure(){}
};

class CROn : public State {
public:
	virtual State* getNextState(Event* e);
	virtual std::string toString();
	static CROn* getInstanceOf();
private:
	static CROn* instance;
	virtual void pure(){}
};

#endif /* STATE_H_ */
