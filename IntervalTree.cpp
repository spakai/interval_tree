#include "IntervalTree.h"

IntervalTree::IntervalTree() {
  root = nullptr;
}

void IntervalTree::insert(Interval interval, std::string &value) {

  auto key = interval.start;

  Node* newNode = createNode(interval, value);

  if ( root == nullptr) {
    root = newNode;
    return;
  }

  Node* parent = nullptr;
  Node* curr = root;
  while (curr != nullptr) {
    parent = curr;
    if (key < curr->interval.start) {
      curr = curr->left;
    } else {
        curr = curr->right;
    }
  }

  if (key < parent->interval.start) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }

  if (parent->max < key) {
    parent->max = key;
  }
}

Node* IntervalTree::createNode(Interval interval, std::string &value) {
  Node* node = new Node();
  node->left = nullptr;
  node->right = nullptr;
  node->interval = interval;
  node->max = interval.end;
  node->value = value;
  return node;
}

std::string IntervalTree::find(Interval interval) {
  auto key = interval.start;

  if ( root == nullptr) {
    throw NoMatchException("No match found");
  }

  Node* curr = root;

  while (curr != nullptr) {
      if(doTheyOverlap(interval, curr->interval)) {
        return curr->value;
      }

      if(curr->left != nullptr && curr->left->max >= key) {
            curr = curr->left;
      } else {
            curr = curr->right;
      }

  }

  throw NoMatchException("No match found");
}

bool IntervalTree::doTheyOverlap(Interval firstInterval, Interval secondInterval) {
  if (firstInterval.start <= secondInterval.end &&
    secondInterval.start <=firstInterval.end) {
    return true;
  } else {
      return false;
  }
}
