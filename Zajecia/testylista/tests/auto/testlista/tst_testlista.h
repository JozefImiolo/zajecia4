#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <memory>
#include "../../../src/lista.h"
#include "../../../src/list.cpp"




using namespace testing;
bool operator==(const List & a, const List & b){

    if(a.elemCount()!=b.elemCount())
        return false;
    return true;

}

TEST(testlista, testy)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}


TEST(testlista, testy1)
{
    constexpr int arr1[] = {1,2,3,4,5,6,7,8,9};
    std::unique_ptr<List> pL1(List::fromArray(arr1, 9));
   EXPECT_EQ(1, pL1->contains(3));

}

TEST(testlista, testy2)
{

    List example2;
    example2.insert(1);
    example2.insert(2);

    List example1;
    example1.insert(1);
    example1.insert(2);

    EXPECT_FALSE(opeartor==(example1,example2));


}

