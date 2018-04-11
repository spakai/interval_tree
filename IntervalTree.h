#pragma once
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include "Node.h"
#include "NoMatchException.h"
#include "algorithm"

enum class Direction { left, right };

class IntervalTree {
    public:
        IntervalTree();
        void insert(Interval &i, std::string &value);
        std::set<std::string> find(Interval &i);
        int balanceFactor();
        int height(Direction direction);
        int bfs();
        void rotateLeft(Node* x);
        void rotateRight(Node* x);

    private:
        Node* createNode(Interval &i, std::string &value);
        void find(Interval &i,Node* x, std::set<std::string> & collector);
        int height(Direction direction, Node* x);
        int bfs(Node* x);
        Node* root;
};
