#include "gmock/gmock.h"
#include "IntervalTree.h"
#include "Interval.h"

using namespace testing;

class IntervalTreeTest : public Test {
    public:
        IntervalTree intervalTree;
};

TEST_F(IntervalTreeTest, SearchWhenThereTreeIsEmpty) {
    Interval i(6,6);

    ASSERT_THROW(intervalTree.find(i), NoMatchException);

}

TEST_F(IntervalTreeTest, SearchSuccessfulWhenRootOverlapsTheInterval) {
  Interval i1(16,21);
  Interval i2(25,30);
  Interval i3(8,9);
  std::string s1 = "1621";
  std::string s2 = "2530";
  std::string s3 = "0809";

  intervalTree.insert(i1,s1);
  intervalTree.insert(i2,s2);
  intervalTree.insert(i3,s3);

  Interval i(17,25);

  ASSERT_THAT(intervalTree.find(i), ElementsAre(s1,s2));

}

TEST_F(IntervalTreeTest, SearchSuccessfulWhenRootChildrenOverlapsTheInterval) {
  Interval i1(16,21);
  Interval i2(25,30);
  Interval i3(8,9);
  std::string s1 = "1621";
  std::string s2 = "2530";
  std::string s3 = "0809";

  intervalTree.insert(i1,s1);
  intervalTree.insert(i2,s2);
  intervalTree.insert(i3,s3);

  Interval i(27,27) ;

  ASSERT_THAT(intervalTree.find(i), ElementsAre(s2));

}

TEST_F(IntervalTreeTest, SearchFailedBecauseNoOverlappingInterval) {
  Interval i1(16,21);
  Interval i2(25,30);
  Interval i3(8,9);
  std::string s1 = "1621";
  std::string s2 = "2530";
  std::string s3 = "0809";

  intervalTree.insert(i1,s1);
  intervalTree.insert(i2,s2);
  intervalTree.insert(i3,s3);

  Interval i(10,15) ;

  ASSERT_THROW(intervalTree.find(i), NoMatchException);
}

TEST_F(IntervalTreeTest, InsertOverlapIntervals) {

  Interval i1(16,21);
  Interval i2(25,30);
  Interval i3(8,9);
  Interval i4(16,24);
  std::string s1 = "1621";
  std::string s2 = "2530";
  std::string s3 = "0809";
  std::string s4 = "1624";

  intervalTree.insert(i1,s1);
  intervalTree.insert(i2,s2);
  intervalTree.insert(i3,s3);
  intervalTree.insert(i4,s4);

  Interval i(24,24);

  intervalTree.bfs();

  ASSERT_THAT(intervalTree.find(i), ElementsAre(s4));

}

TEST_F(IntervalTreeTest, InsertDuplicateIntervals) {
  Interval iv = IntervalBuilder()
                        .greaterThanOrEqual(16)
                        .lessThanOrEqual(24)
                        .build();

  std::string s1 = "1624a";
  std::string s2 = "1624b";
  intervalTree.insert(iv,s1);
  intervalTree.insert(iv,s2);

  Interval i(24,24);



  ASSERT_THAT(intervalTree.find(i), ElementsAre(s1,s2));

}
