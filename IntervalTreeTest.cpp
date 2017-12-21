#include "gmock/gmock.h"
#include "IntervalTree.h"
#include "Interval.h"

using namespace testing;

class IntervalTreeTest : public Test {
    public:
        Interval i1;
        IntervalTree intervalTree;

        void SetUp() override {
           i1.start = 16;
           i1.end = 21;
        }
};

TEST_F(IntervalTreeTest, RootIsNull) {
    Interval toFind;
    toFind.start=6;
    toFind.end=6;

    ASSERT_THROW(intervalTree.search(toFind), NoMatchException);
}

TEST_F(IntervalTreeTest, RootHasDataThatFallsUnderTheInterval) {
    std::string v = "XYZ";
    intervalTree.insert(i1,v);

    Interval toFind;
    toFind.start=18;
    toFind.end=18;

    ASSERT_THAT(intervalTree.search(toFind), Eq(v));
}

TEST_F(IntervalTreeTest, RootHasDataButDoesntFallUnderTheInterval) {
    std::string v = "XYZ";
    intervalTree.insert(i1,v);

    Interval toFind;
    toFind.start=6;
    toFind.end=15;

    ASSERT_THROW(intervalTree.search(toFind), NoMatchException);
}
