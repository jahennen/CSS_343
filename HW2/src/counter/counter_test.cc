// counter_test.cc
//
// Copyright 2012 Systems Deployment, LLC
// Author: Morris Bernstein

#include "counter.h"


int main() {

  Counter::increment("these");
  Counter::increment("these");

  Counter::increment("them", 44);
  Counter::increment("them", -1);

  Counter::increment("those", 33);
  Counter::reset("those", 121);

  Counter::reset("that", 99);
  Counter::increment("that");
  Counter::increment("that");
  Counter::increment("that");

  Counter::reset("this", Counter::get("them"));

  Counter::dump();

  return 0;
}
