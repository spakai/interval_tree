#pragma once
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include "Node.h"
#include "NoMatchException.h"

class IntervalTree {
    public:
        enum class Direction { left, right };
        IntervalTree();
        void insert(Interval &i, std::string &value);
        std::set<std::string> find(Interval &i);
        int height(Direction direction);
        int height(Direction direction, Node* x);
        int bfs();

    private:
        Node* createNode(Interval &i, std::string &value);
        int bfs(Node* x);
        Node* root;
};
