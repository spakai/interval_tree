#pragma once
#include "IntervalTree.h"
#include <iostream>

IntervalTree::IntervalTree() {
  root = nullptr;
}

void IntervalTree::insert(Interval i, std::string &value) {
  if (root == nullptr) {
    initializeRoot(i,value);
  }
}

void IntervalTree::initializeRoot(Interval i, std::string &value) {
  root = new Node();
  root->left = nullptr;
  root->right = nullptr;
  root->interval = i;
  root->max = i.end;
  root->value = value;
}

std::string IntervalTree::search(Interval i) {
  if (root == nullptr) {
    throw NoMatchException("No match found");
  } else {
    if(doTheyOverlap(root->interval, i)) {
      return root->value;
    } else {
      throw NoMatchException("No match found");
    }
  }
}

bool IntervalTree::doTheyOverlap(Interval i1, Interval i2) {
  if (i1.start <= i2.end && i2.start <=i1.end) {
    return true;
  } else {
    return false;
  }
}
