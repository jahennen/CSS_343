// counter.cc
//
// See counter.h for description.
//
// Copyright 2012 Systems Deployment, LLC
// Author: Morris Bernstein

#include "counter.h"

#include <iostream>

#if defined(COUNTER_AS_NAMESPACE)

namespace Counter {
  static std::map<std::string, int> counters;

  int reset(const std::string& name, int initial) {
    counters[name] = initial;
    return initial;
  }

  int increment(const std::string& name, int delta) {
    std::map<std::string, int>::iterator it = counters.find(name);
    int new_value;
    if (it == counters.end()) {
      new_value = delta;
      counters[name] = delta;
    } else {
      new_value = it->second + delta;
      it->second = new_value;
    }
    return new_value;
  }

  int get(const std::string& name) {
    std::map<std::string, int>::iterator it = counters.find(name);
    int value;
    if (it == counters.end()) {
      value = 0;
      counters[name] = value;
    } else {
      value = it->second;
    }
    return value;
  }

  void dump(std::ostream& out) {
    out << "Counters\n";
    for (std::map<std::string, int>::const_iterator it = counters.begin();
	 it != counters.end();
	 ++it) {
      out << it->first << ": " << it->second << "\n";
    }
  }

}

#else

std::map<std::string, int> Counter::counters;

int Counter::reset(const std::string& name, int initial) {
  counters[name] = initial;
  return initial;
}

int Counter::increment(const std::string& name, int delta) {
  std::map<std::string, int>::iterator it = counters.find(name);
  int new_value;
  if (it == counters.end()) {
    new_value = delta;
    counters[name] = delta;
  } else {
    new_value = it->second + delta;
    it->second = new_value;
  }
  return new_value;
}

int Counter::get(const std::string& name) {
  std::map<std::string, int>::iterator it = counters.find(name);
  int value;
  if (it == counters.end()) {
    value = 0;
    counters[name] = value;
  } else {
    value = it->second;
  }
  return value;
}

void Counter::dump(std::ostream& out) {
  out << "Counters\n";
  for (std::map<std::string, int>::const_iterator it = counters.begin();
       it != counters.end();
       ++it) {
      out << it->first << ": " << it->second << "\n";
  }
}

#endif
