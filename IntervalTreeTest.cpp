#include "gmock/gmock.h"
#include "IntervalTree.h"

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

  Interval i1 = IntervalBuilder()
                        .greaterThanOrEqual(16)
                        .lessThanOrEqual(21)
                        .build();

  Interval i2 = IntervalBuilder()
                        .greaterThanOrEqual(8)
                        .lessThanOrEqual(9)
                        .build();

  Interval i3 = IntervalBuilder()
                        .greaterThanOrEqual(25)
                        .lessThanOrEqual(30)
                        .build();

  Interval i4 = IntervalBuilder()
                        .greaterThanOrEqual(17)
                        .lessThanOrEqual(19)
                        .build();

  Interval i5 = IntervalBuilder()
                        .greaterThanOrEqual(26)
                        .lessThanOrEqual(26)
                        .build();

  Interval i6 = IntervalBuilder()
                        .greaterThanOrEqual(5)
                        .lessThanOrEqual(8)
                        .build();

  Interval i7 = IntervalBuilder()
                        .greaterThanOrEqual(15)
                        .lessThanOrEqual(23)
                        .build();

  Interval i8 = IntervalBuilder()
                        .greaterThanOrEqual(0)
                        .lessThanOrEqual(3)
                        .build();

  Interval i9 = IntervalBuilder()
                        .greaterThanOrEqual(6)
                        .lessThanOrEqual(10)
                        .build();

  Interval i10 = IntervalBuilder()
                        .greaterThanOrEqual(19)
                        .lessThanOrEqual(20)
                        .build();



  std::string s1 = "1621";
  std::string s2 = "0809";
  std::string s3 = "2530";
  std::string s4 = "1719";
  std::string s5 = "2626";
  std::string s6 = "0508";
  std::string s7 = "1523";
  std::string s8 = "0003";
  std::string s9 = "0610";
  std::string s10 = "1920";


  intervalTree.insert(i1,s1);
  intervalTree.insert(i2,s2);
  intervalTree.insert(i3,s3);
  intervalTree.insert(i4,s4);
  intervalTree.insert(i5,s5);
  intervalTree.insert(i6,s6);
  intervalTree.insert(i7,s7);
  intervalTree.insert(i8,s8);
  intervalTree.insert(i9,s9);
  intervalTree.insert(i10,s10);


  Interval i(15,20);

  intervalTree.bfs();
  int heightL = intervalTree.height(Direction::left);
  int heightR = intervalTree.height(Direction::right);

  std::cout << "Left depth:" << heightL << std::endl;
  std::cout << "Right depth:" << heightR << std::endl;
  std::cout << "Balance factor:" << intervalTree.balanceFactor() << std::endl;


  ASSERT_THAT(intervalTree.find(i), ElementsAre(s7,s1,s4,s10));

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

TEST_F(IntervalTreeTest, Rebalanced) {

Interval i1 = IntervalBuilder()
                        .greaterThanOrEqual(700)
                        .lessThanOrEqual(800)
                        .build();

Interval i2 = IntervalBuilder()
                        .greaterThanOrEqual(900)
                        .lessThanOrEqual(1000)
                        .build();

 Interval i3 = IntervalBuilder()
                        .greaterThanOrEqual(1100)
                        .lessThanOrEqual(1200)
                        .build();

  std::string s1 = "0708";
  std::string s2 = "0910";
  std::string s3 = "1112";

  intervalTree.insert(i1,s1);
  intervalTree.insert(i2,s2);
  intervalTree.insert(i3,s3);

  Interval i = IntervalBuilder()
                        .greaterThanOrEqual(730)
                        .lessThanOrEqual(930)
                        .build();

  intervalTree.bfs();
  int heightL = intervalTree.height(Direction::left);
  int heightR = intervalTree.height(Direction::right);

  std::cout << "Left depth:" << heightL << std::endl;
  std::cout << "Right depth:" << heightR << std::endl;
  std::cout << "Balance factor:" << intervalTree.balanceFactor() << std::endl;

  ASSERT_THAT(intervalTree.find(i), ElementsAre(s1,s2));
}
