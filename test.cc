#include "gtest/gtest.h"
#include "LinkedList.hpp"

namespace {

// The fixture for testing class Foo.
class LinkedListTest : public ::testing::Test {
};

TEST_F(LinkedListTest, SetupEmpty) {
  LinkedList<int> ll{};

  EXPECT_EQ(0u, ll.size());
  EXPECT_EQ(ll::begin(), ll::end());
}

TEST_F(LinkedListTest, SetupNonEmpty) {
  LinkedList<int> ll{1, 2};

  EXPECT_EQ(2u, ll.size());
  LinkedList<int>::iterator it = ll.begin();
  EXPECT_EQ(1, *ll);
  EXPECT_EQ(2, *(++ll));
}

TEST_F(LinkedListTest, AddElementBegin) {
  LinkedList<int> ll{};
  ll.insert(ll.begin(), 1);
  EXPECT_EQ(1u, ll.size());
  EXPECT_EQ(1, *ll.begin());
}

TEST_F(LinkedListTest, AddElementEnd) {
  LinkedList<int> ll{1};
  ll.insert(ll.end(), 2);
  EXPECT_EQ(2u, ll.size());
  EXPECT_EQ(1, *ll.begin());
  EXPECT_EQ(2, *(++ll.begin()));
}

TEST_F(LinkedListTest, AddElementBefore) {
  LinkedList<int> ll{1,2};
  LinkedList<int>::iterator it = ll.begin();
  ll.insert(++it, 3);
  EXPECT_EQ(3u, ll.size());
  it = ll.begin();
  EXPECT_EQ(1, *it);
  ++it;
  EXPECT_EQ(3, *it);
  ++it;
  EXPECT_EQ(2, *it);
}

TEST_F(LinkedListTest, RemoveElement) {
  LinkedList<int> ll{1,2, 3};
  LinkedList<int>::iterator it = ll.begin();
  ++it;
  ll.remove(it);

  EXPECT_EQ(3u, ll.size());
  LinkedList<int>::iterator it = ll.begin();
  EXPECT_EQ(1, *ll);
  EXPECT_EQ(3, *(++ll));
}
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
