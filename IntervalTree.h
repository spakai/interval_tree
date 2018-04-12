#pragma once
#include "algorithm"
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include "Node.h"
#include "NoMatchException.h"

enum class Direction { left, right };

class IntervalTree {
    public:
        IntervalTree();
        ~IntervalTree();
        void insert(Interval &i, std::string &value);
        std::set<std::string> find(Interval &i);
        int bfs();

    private:
        Node* createNode(Interval &i, std::string &value);
        void find(Interval &i,Node* x, std::set<std::string> & collector);
        int height(Direction direction, Node* x);
        int balanceFactor();
        int height(Direction direction);
        int bfs(Node* x);
        void deleteNode(Node* x);
        void balanceTree();
        void rotateRootLeft();
        void rotateRootRight();
        Node* root;
};
