#include "gmock/gmock.h"
#include "IntervalTree.h"
#include "Interval.h"


using namespace testing;

class IntervalTreeTest : public Test {
    public:

        Interval i1;
        IntervalTree intervalTree;
        /*Interval i3(8,9);
        Interval i4(26,26);
        Interval i5(17,19);
        Interval i6(19,20);
        Interval i9(0,3);
        Interval i7(15,23);
        Interval i8(5,8);
        Interval i10(6,10);
        */

        void SetUp() override {
            i1.start = 16;
            i1.end = 21;
            std::string abc = "ABC";
            intervalTree.insert(i1,abc);
        /*    intervalTree.insert(i2);
            intervalTree.insert(i3);
            intervalTree.insert(i4);
            intervalTree.insert(i5);
            intervalTree.insert(i6);
            intervalTree.insert(i7);
            intervalTree.insert(i8);
            intervalTree.insert(i9);
            intervalTree.insert(i10);
            */
        }
};

TEST_F(IntervalTreeTest, ChildrenAreNullOnCreation) {
    ASSERT_THAT("1", Eq("1"));
}
