#include "gmock/gmock.h"
#include "IntervalTree.h"
#include "Interval.h"

using namespace testing;

class IntervalTreeTest : public Test {
    public:
        Interval i1;
        Interval i2;
        Interval i3;
        IntervalTree intervalTree;

        void SetUp() override {
           i1.start = 16;
           i1.end = 21;
           i2.start = 25;
           i2.end = 30;
           i3.start = 8;
           i3.end = 9;
        }
};

TEST_F(IntervalTreeTest, Insertion) {
    std::string v1 = "1621";
    std::string v2 = "2530";
    std::string v3 = "0809";
    intervalTree.insert(i1,v1);
    intervalTree.insert(i2,v2);
    intervalTree.insert(i3,v3);
}
