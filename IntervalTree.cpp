#include "IntervalTree.h"

IntervalTree::IntervalTree() {
  root = nullptr;
}

void IntervalTree::insert(Interval &interval, std::string &value) {

  auto key = interval.getStart();

  if ( root == nullptr) {
    root = createNode(interval, value);
    return;
  }

  Node* parent = nullptr;
  Node* curr = root;

  while (curr != nullptr) {
    parent = curr;

    if (curr->interval == interval) {
        curr->values.insert(value);
        return;
    } else if (key < curr->interval.getStart()) {
        curr = curr->left;
    } else {
        curr = curr->right;
    }
  }

  if (key < parent->interval.getStart()) {
    parent->left = createNode(interval, value);
  } else {
    parent->right = createNode(interval, value);
  }

  if (parent->max < key) {
    parent->max = key;
  }
}

Node* IntervalTree::createNode(Interval &interval, std::string &value) {
  Node* node = new Node();
  node->left = nullptr;
  node->right = nullptr;
  node->interval = interval;
  node->max = interval.getEnd();
  node->values.insert(value);
  return node;
}

std::set<std::string> IntervalTree::find(Interval &interval) {
  Node* curr = root;
  std::set<std::string> collector;
  while (curr != nullptr) {

      if(curr->interval.doTheyOverlap(interval)) {
        collector.insert(curr->values.begin(),curr->values.end());
      }

      auto key = interval.getStart();

      if(curr->left != nullptr && curr->left->max >= key) {
        curr = curr->left;
      } else {
        curr = curr->right;
      }

  }

  if(collector.size() == 0) {
    throw NoMatchException("No match found");
  } else {
    return collector;
  }
}


int IntervalTree::maxDepth() {
  return maxDepth(root);
}

int IntervalTree::maxDepth(Node *x) {
  if(x == nullptr ) {
    return 0;
  } else {
      int ldepth = maxDepth(x->left);
      int rdepth = maxDepth(x->right);
      if (ldepth > rdepth) {
        return ldepth + 1;
    } else  {
        return rdepth + 1;
    }
  }
}

void IntervalTree::print() {
  int h = maxDepth();
  for(int i = 1 ; i<=h ; i++) {
    print(root,i);
    std::cout << "|" << std::endl;
  }
}

void IntervalTree::print (Node * x, int level)
{
  if (x == nullptr)
      return;
  if (level == 1)
      std::cout << x->interval.getStart() << "," << x->interval.getEnd() << std::endl;
  else if (level > 1)
  {
      std::cout << "/" << std::endl;
      print(x->left, level-1);
      std::cout << "\\" << std::endl;
      print(x->right, level-1);
  }
}
