#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../src/rownanie.h"
#include <cmath>
using namespace testing;
TEST(Row, Delta)

{
    result s= solution( 1, -3, 2);
    ASSERT_EQ(s.count,2);
    EXPECT_TRUE(s.x1==1 || s.x2==1);
    EXPECT_TRUE(s.x2==2|| s.x1==2);
    EXPECT_NE(s.x1, s.x2);
    EXPECT_FALSE(s.identity);

}
TEST(Row, Delta1)
{
    result s= solution( 1, -3, 2);
    ASSERT_EQ(s.count,2);
    const double eps=1e-5;

    //double x1 =std::max(s.x1, s.x2);
    //EXPECT_NEAR(x1, 1.0, eps);
    //EXPECT_DOUBLE_EQ(x2, 2.0)
    EXPECT_TRUE(std::abs(s.x1-1)<eps || s.x2==1);
    EXPECT_TRUE(s.x2==2|| s.x1==2);
    EXPECT_NE(s.x1, s.x2);
    EXPECT_FALSE(s.identity);

}
TEST(Row, Delta2)
{
    result s= solution( 0, 4, 4);
    ASSERT_EQ(s.count,1);
    const double eps=1e-5;

    //double x1 =std::max(s.x1, s.x2);
    //EXPECT_NEAR(x1, 1.0, eps);
    EXPECT_DOUBLE_EQ(s.x1, -1.0);

    EXPECT_FALSE(s.identity);
}
TEST(Row, Delta3)
{
    result s= solution( 10, -2, 5);
    ASSERT_EQ(s.count,0);
    const double eps=1e-5;

    EXPECT_FALSE(s.identity);
}

