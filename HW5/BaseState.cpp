#include <iostream>
using namespace std;

class BaseState;
class DerivedState1;
class DerivedState2;

class BaseEvent{
public:
	virtual BaseState& getNextState(BaseState& s) {
		cout << "INVALID;" << endl;
		return s;
	}
	virtual BaseState& getNextState(DerivedState1& s);
};

class DerivedEvent : public BaseEvent {
public:
	virtual BaseState& getNextState(BaseState& s) {
		cout << "DE::INVALID;" << endl;
		return s;
	}
	virtual BaseState& getNextState(DerivedState1& s);
private:

static DerivedEvent* instance;
};

class BaseState {
public:
	virtual void printType() {
		cout << "BaseState" << endl;
	}
	virtual BaseState& getNextState(BaseEvent& e) {
		return e.getNextState(*this);
	}
private:
};

class DerivedState1 : public BaseState {
public:
	static DerivedState1& getInstanceOf() {
		static DerivedState1 instance;
		return instance;
	}
	virtual void printType() {
		cout << "DerivedState1" << endl;
	}
	virtual BaseState& getNextState(BaseEvent& e) = *this->BaseState.getNextState;
private:
	DerivedState1(){};
};

class DerivedState2 : public BaseState {
public:
	static DerivedState2& getInstanceOf() {
		static DerivedState2 instance;
		return instance;
	}
	virtual void printType() {
		cout << "DerivedState2" << endl;
	}
	virtual BaseState& getNextState(BaseEvent& e) {
		return e.getNextState(*this);
	}
	DerivedState2() {};
private:
};

BaseState& BaseEvent::getNextState(DerivedState1& s) {
	cout << "In BaseEvent::getNextState with s = " << &s << endl;
	return DerivedState2::getInstanceOf();
}

BaseState& DerivedEvent::getNextState(DerivedState1& s) {
	cout << "In DerivedEvent::getNextState with s = " << &s << endl;
	return DerivedState2::getInstanceOf();
}

int main() {
	BaseState* s1 = &DerivedState1::getInstanceOf();
//	BaseState& s2 = DerivedState2::getInstanceOf();
	s1->printType();
//	s2.printType();
	DerivedEvent de;
	BaseEvent& e = de;
	cout << &e << endl;
	s1 = &s1->getNextState(e);
	s1->printType();
//	s1 = DerivedState2::getInstanceOf();
//	s1.printType();
//	DerivedState2 t = DerivedState2::getInstanceOf();
//	s1 = t;
//	s1.printType();
}
