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

TEST_F(IntervalTreeTest, SearchWhenThereTreeIsEmpty) {
    Interval i ;
    i.start = 6;
    i.end = 6;

    ASSERT_THROW(intervalTree.find(i), NoMatchException);

}

TEST_F(IntervalTreeTest, SearchSuccessfulWhenRootOverlapsTheInterval) {
  std::string v1 = "1621";
  std::string v2 = "2530";
  std::string v3 = "0809";
  intervalTree.insert(i1,v1);
  intervalTree.insert(i2,v2);
  intervalTree.insert(i3,v3);

  Interval i ;
  i.start = 17;
  i.end = 17;


  ASSERT_THAT(intervalTree.find(i), Eq("1621"));

}


TEST_F(IntervalTreeTest, SearchSuccessfulWhenRootChildrenOverlapsTheInterval) {
  std::string v1 = "1621";
  std::string v2 = "2530";
  std::string v3 = "0809";
  intervalTree.insert(i1,v1);
  intervalTree.insert(i2,v2);
  intervalTree.insert(i3,v3);

  Interval i ;
  i.start = 27;
  i.end = 27;


  ASSERT_THAT(intervalTree.find(i), Eq("2530"));

}

TEST_F(IntervalTreeTest, SearchFailedBecauseNoOverlappingInterval) {
  std::string v1 = "1621";
  std::string v2 = "2530";
  std::string v3 = "0809";
  intervalTree.insert(i1,v1);
  intervalTree.insert(i2,v2);
  intervalTree.insert(i3,v3);

  Interval i ;
  i.start = 10;
  i.end = 10;


  ASSERT_THROW(intervalTree.find(i), NoMatchException);


}
