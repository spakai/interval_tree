#pragma once

#include <set>
#include <string>
#include "Node.h"
#include "Interval.h"
#include "NoMatchException.h"

class IntervalTree {
    public:
        IntervalTree();
        void insert(Interval &i, std::string &value);
        std::set<std::string> find(Interval &i);

    private:
        Node* createNode(Interval &i, std::string &value);
        Node* root;
};
