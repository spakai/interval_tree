#pragma once
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include "Node.h"
#include "NoMatchException.h"

enum class Direction { left, right };
 
class IntervalTree {
    public:
        IntervalTree();
        void insert(Interval &i, std::string &value);
        std::set<std::string> find(Interval &i);
        Node * rotateLeft(Node* x);
        Node * rotateRight(Node* x);
        int balanceFactor();
        int height(Direction direction);
        int height(Direction direction, Node* x);
        int bfs();

    private:
        Node* createNode(Interval &i, std::string &value);
        int bfs(Node* x);
        Node* root;
};
