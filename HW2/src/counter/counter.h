// counter.h
//
// Simple counter function.  Alternate implementations as namespace
// or class.
//
// No duplicate detection.
// No concurency
//
//
// Usage:
//   Counters are identified by name.
//
//   Methods:
//      reset(): set new (default: 0)
//      increment(): add offset (default: 1).
//      get(): return current value or instantiates new variable with
//        initial value 0.
//      dump(): log current value of all counters (call at program
//        termination)
//
//  TODO:
//    - add erase method to delete a counter.
//
// Example:
//   Counter::increment("var");
//
// Copyright 2012 Systems Deployment, LLC
// Author: Morris Bernstein

#if !defined(COUNTER_H)
#define COUNTER_H

#include <iostream>
#include <map>
#include <string>

// Use -DCOUNTER_AS_NAMESPACE on the command line to activate
// namespace version.  This is equivalent to
// #define COUNTER_AS_NAMESPACE

#if defined(COUNTER_AS_NAMESPACE)

namespace Counter {

  int reset(const std::string& name, int initial=0);
  int increment(const std::string& name, int delta=1);
  int get(const std::string& name);

  void dump(std::ostream& out=std::cerr);
}

#else

class Counter {
 public:
  static int reset(const std::string& name, int initial=0);
  static int increment(const std::string& name, int delta=1);
  static int get(const std::string& name);

  static void dump(std::ostream& out=std::cerr);
 private:
  static std::map<std::string, int> counters;

  // DISALLOW_COPY_AND_ASSIGN (do not implement)
  Counter(const Counter&);
  void operator=(const Counter&);
};

#endif

#endif

