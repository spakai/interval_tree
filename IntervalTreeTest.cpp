#include "gmock/gmock.h"
#include "IntervalTree.h"
#include "Interval.h"

using namespace testing;

class IntervalTreeTest : public Test {
    public:

        Interval i1,i2,i3,i4;
        std::string v1,v2,v3,v4;

        IntervalTree intervalTree;

        void SetUp() override {
          Interval i1(16,21);
          Interval i2(25,30);
          Interval i3(8,9);
          Interval i4(16,24);
          this->i1 = i1;
          this->i2 = i2;
          this->i3 = i3;
          this->i4 = i4; 
          std::string v1 = "1621";
          std::string v2 = "2530";
          std::string v3 = "0809";
          std::string v4 = "1624";
          this->v1=v1;
          this->v2=v2;
          this->v3=v3;
          this->v4=v4;
        }
};

TEST_F(IntervalTreeTest, SearchWhenThereTreeIsEmpty) {
    Interval i(6,6);

    ASSERT_THROW(intervalTree.find(i), NoMatchException);

}

TEST_F(IntervalTreeTest, SearchSuccessfulWhenRootOverlapsTheInterval) {
  intervalTree.insert(i1,v1);
  intervalTree.insert(i2,v2);
  intervalTree.insert(i3,v3);

  Interval i(17,17);

  ASSERT_THAT(intervalTree.find(i), Eq("1621"));

}

TEST_F(IntervalTreeTest, SearchSuccessfulWhenRootChildrenOverlapsTheInterval) {
  intervalTree.insert(i1,v1);
  intervalTree.insert(i2,v2);
  intervalTree.insert(i3,v3);

  Interval i(27,27) ;

  ASSERT_THAT(intervalTree.find(i), Eq("2530"));

}

TEST_F(IntervalTreeTest, SearchFailedBecauseNoOverlappingInterval) {
  intervalTree.insert(i1,v1);
  intervalTree.insert(i2,v2);
  intervalTree.insert(i3,v3);

  Interval i(10,10);

  ASSERT_THROW(intervalTree.find(i), NoMatchException);
}

TEST_F(IntervalTreeTest, InsertOverlapIntervals) {

  intervalTree.insert(i1,v1);
  intervalTree.insert(i2,v2);
  intervalTree.insert(i3,v3);
  intervalTree.insert(i4,v4);

  Interval i(24,24);

  ASSERT_THAT(intervalTree.find(i), Eq("1624"));


}
