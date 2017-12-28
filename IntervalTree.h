#pragma once
#include <string>
#include "Node.h"
#include "Interval.h"
#include "NoMatchException.h"

class IntervalTree {
    public:
        IntervalTree();
        void insert(Interval i, std::string &value);
        std::string find(Interval i);

    private:
        Node* createNode(Interval i, std::string &value);
        bool doTheyOverlap(Interval i1, Interval i2);
        Node *root;
};
