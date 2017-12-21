#include "gmock/gmock.h"
#include "IntervalTree.h"
#include "Interval.h"

using namespace testing;

class IntervalTreeTest : public Test {
    public:
        IntervalTree intervalTree;

};

TEST_F(IntervalTreeTest, RootIsNull) {
    Interval toFind;
    toFind.start=6;
    toFind.end=6;

    ASSERT_THROW(intervalTree.search(toFind), NoMatchException);
}
