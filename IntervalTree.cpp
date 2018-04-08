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


int IntervalTree::height(Direction direction) {
  return height(direction,root);
}

int IntervalTree::height(Direction direction, Node* x) {
  if(x == nullptr) return 0;
  if(direction == Direction::left) 
   return(1 + height(Direction::left,x->left)); 
  else 
   return(1 + height(Direction::left,x->right)); 

}

int IntervalTree::bfs() {
  bfs(root);
}

int IntervalTree::bfs(Node* x) {
  std::queue<Node*> q;
  q.push(x);

  while(! q.empty()) {

    int levelNodes = q.size();
    while(levelNodes > 0) {
      Node *n = q.front();

      std::cout << n->interval.getStart() << "-" << n->interval.getEnd() << " " ;

      if(n->left != nullptr) {
        q.push(n->left);
      }

      if(n->right != nullptr) {
        q.push(n->right);
      }

      levelNodes--;

      q.pop();
    }

      std::cout << std::endl;
  }
}
