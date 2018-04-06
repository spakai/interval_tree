#pragma once
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include "Node.h"
#include "Interval.h"
#include "NoMatchException.h"

class IntervalTree {
    public:
        IntervalTree();
        void insert(Interval &i, std::string &value);
        std::set<std::string> find(Interval &i);
        int bfs();

    private:
        Node* createNode(Interval &i, std::string &value);
        int bfs(Node* x);
        Node* root;
};
