#pragma once

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
        void print ();
        int maxDepth();


    private:
        Node* createNode(Interval &i, std::string &value);
        void print (Node * x, int id);
        int maxDepth(Node *x);
        Node* root;
};
