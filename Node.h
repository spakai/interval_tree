#pragma once
#include "Interval.h"

struct Node {
  Interval interval;
  long int max;
  Node * left;
  Node * right;
  std::set<std::string> values;
};
