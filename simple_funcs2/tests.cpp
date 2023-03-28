#include "queue.h"
#include <gtest/gtest.h>
#include <queue>

// This file will cover gtest suite

class QueueTest : public ::testing::Test {
 protected:
  void SetUp() override {
     // q0_ remains empty
     q1_.Enqueue(1);
     q2_.Enqueue(2);
     q2_.Enqueue(3);
  }

  // void TearDown() override {}

  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

// we check if the initial queue is of size 0
TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(q0_.Size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {
// we check that the empty queue q0_ points to a null 
  int* n = q0_.Dequeue();
  EXPECT_EQ(n, nullptr);
// we expect that the q1_ after initialization is non null, that after dequeueing we get
//  a 1 (element we queued up) and that after dequeieng the size of our queue is 0
  n = q1_.Dequeue();
  ASSERT_NE(n, nullptr);
  EXPECT_EQ(*n, 1);
  EXPECT_EQ(q1_.Size(), 0);
  delete n;

  n = q2_.Dequeue();
  ASSERT_NE(n, nullptr);
  EXPECT_EQ(*n, 2);
  EXPECT_EQ(q2_.Size(), 1);
  delete n;
}

// we run the RUN_ALL_TESTS() command here to run all of the tests! 
// * 
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}