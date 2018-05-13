#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../src/irowkwa.h"

using namespace testing;

TEST(rowannie, pierwiastki)
{
    result s= solution( 1, -3, 2);
    ASSERT_EQ(s.count,2);
    EXPECT_TRUE(s.x1==1 || s.x2==2);
    EXPECT_TRUE(s.x2==1 || s.x1==2);
    EXPECT_NE(s.x1, s.x2);
    EXPECT_FALSE(s.identity);


}
