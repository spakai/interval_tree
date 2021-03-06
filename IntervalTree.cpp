#include "IntervalTree.h"

IntervalTree::IntervalTree() {
  root = nullptr;
}

void IntervalTree::insert(Interval &interval, std::string &value) {

  root = insert(root, interval, value);

  balanceTree();
}

Node* IntervalTree::insert(Node * x, Interval & interval, std::string &value) {
  if (x == nullptr) {
    return createNode(interval, value);
  }

  auto key = interval.getStart();

  if(key < x->interval.getStart()) {
    x->left = insert(x->left, interval, value);
  } else {
    x->right = insert(x->right,interval,value);
  }

  if(x->max < interval.getEnd()) {
    x->max = interval.getEnd();
  }

  return x;
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

void IntervalTree::balanceTree() {
  if(balanceFactor() > 1) {
    rotateRootRight();
    root->max = std::max(root->max, std::max(root->left->max, root->right->max));
  } else if(balanceFactor() < -1) {
    rotateRootLeft();
    root->max = std::max(root->max, std::max(root->left->max, root->right->max));
  } else {
    //nicely balanced
  }
}

std::set<std::string> IntervalTree::find(Interval &interval) {
  std::set<std::string> collector;

  find(interval, root, collector);

  if(collector.size() == 0) {
    throw NoMatchException("No match found");
  } else {
    return collector;
  }
}

void IntervalTree::find(Interval &interval , Node * node, std::set<std::string> & collector) {

  if(node == nullptr) {
    return;
  }

  auto key = interval.getStart();

  if(node->interval.doTheyOverlap(interval)) {
    collector.insert(node->values.begin(), node->values.end());
  }

  if(node->left != nullptr && node->left->max >= key) {
    find(interval, node->left, collector);
  }

  find(interval, node->right, collector);

}

int IntervalTree::balanceFactor() {
    return height(Direction::left) - height(Direction::right);
}

int IntervalTree::height(Direction direction) {
  return height(direction,root);
}

int IntervalTree::height(Direction direction, Node* x) {
  if(x == nullptr) return 0;
  if(direction == Direction::left)
   return(1 + height(Direction::left,x->left));
  else
   return(1 + height(Direction::right,x->right));

}

void IntervalTree::rotateRootLeft() {
    Node * newRoot = root->right;
    root->right = root->right->left;
    newRoot->left = root;
    root = newRoot;
}

void IntervalTree::rotateRootRight() {
    Node * newRoot = root->left;
    root->left = root->left->right;
    newRoot->right = root;
    root = newRoot;
}

void IntervalTree::bfs() {
  bfs(root);
}

void IntervalTree::bfs(Node* x) {
  std::queue<Node*> q;
  q.push(x);

  while(! q.empty()) {

    int levelNodes = q.size();
    while(levelNodes > 0) {
      Node *n = q.front();

      std::cout << n->interval.getStart() << "-" << n->interval.getEnd() << "(" << n->max << ")";

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
      std::cout << std::endl;
  }
}

IntervalTree::~IntervalTree() {
  deleteNode(root);
}

void IntervalTree::deleteNode(Node *x) {

  if(x == nullptr) {
    return;
  }

  deleteNode(x->left);
  deleteNode(x->right);

  delete x;
}
