#pragma once
#include <string>
#include "Node.h"
#include "Interval.h"

class IntervalTree {
    public:
        ~IntervalTree();
        void insert(Interval i, std::string &value);
        std::string search(Interval i);
        void initializeRoot(Interval i, std::string &value);
    private:
        Node *root;
};
