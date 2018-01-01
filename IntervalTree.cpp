#include "IntervalTree.h"

IntervalTree::IntervalTree() {
  root = nullptr;
}

void IntervalTree::insert(Interval interval, std::string &value) {

  auto key = interval.getStart();

  Node* newNode = createNode(interval, value);

  if ( root == nullptr) {
    root = newNode;
    return;
  }

  Node* parent = nullptr;
  Node* curr = root;
  while (curr != nullptr) {
    parent = curr;
    if (key < curr->interval.getStart()) {
      curr = curr->left;
    } else {
        curr = curr->right;
    }
  }

  if (key < parent->interval.getStart()) {
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
  node->max = interval.getEnd();
  node->value = value;
  return node;
}

std::string IntervalTree::find(Interval interval) {
  auto key = interval.getStart();

  if ( root == nullptr) {
    throw NoMatchException("No match found");
  }

  Node* curr = root;

  while (curr != nullptr) {
      if(interval.doTheyOverlap(curr->interval)) {
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
