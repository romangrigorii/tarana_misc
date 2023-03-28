#include <gtest/gtest.h>
#include "simplemath.h"
TEST(myfunctions, cubic)
{
    GTEST_ASSERT_EQ(cubic(10), 1000);
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}