#include "IntervalTree.h"
#include "Node.h"
#include "Interval.h"

IntervalTree::~IntervalTree() {
    if (root != nullptr) {
      delete root;
    }
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

std::string IntervalTree:: search(Interval i) {

}
