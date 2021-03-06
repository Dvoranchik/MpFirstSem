
#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFun.h"

TEST(PZ3, FistTask)
{
	ASSERT_NEAR(firstf(0), secondf(0),1e-6);
	ASSERT_NEAR(firstf(1.5), secondf(1.5),1e-6);
	ASSERT_NEAR(firstf(-3), secondf(-3), 1e-6);
	

}
TEST(PZ3, SecondTask)
{
	ASSERT_EQ(F(1, 1, 1), G(1, 1, 1));
	ASSERT_EQ(F(0, 0, 1), G(0, 0, 1));
	ASSERT_EQ(F(0, 0, 0), G(0, 0, 0));
	ASSERT_EQ(F(1, 0, 1), G(1, 0, 1));
	ASSERT_EQ(F(0, 1, 1), G(0, 1, 1));
	ASSERT_EQ(F(1, 0, 0), G(1, 0, 0));
	ASSERT_EQ(F(1, 1, 0), G(1, 1, 0));
	ASSERT_EQ(F(0, 1, 0), G(0, 1, 0));

}
TEST(PZ3, ThirdTask)
{
	ASSERT_DOUBLE_EQ(0, FUNCTION(-11));
	ASSERT_DOUBLE_EQ(-3, FUNCTION(-8));
	ASSERT_DOUBLE_EQ(-3, FUNCTION(0));
	ASSERT_DOUBLE_EQ(0, FUNCTION(3));
	ASSERT_DOUBLE_EQ(2, FUNCTION(5));
	ASSERT_DOUBLE_EQ(3, FUNCTION(8));
	ASSERT_DOUBLE_EQ(3, FUNCTION(6));
	ASSERT_DOUBLE_EQ(0, FUNCTION(-5));
	
}
TEST(PZ3, FourthTask)
{
	EXPECT_EQ(1, inside(-3, 2, 5));
	EXPECT_EQ(0, inside(6, 2, 3));
	EXPECT_EQ(0, inside(-4, -3, 5));
	EXPECT_EQ(1, inside(0, 5, 5));
	EXPECT_EQ(0, inside(1, 1, 2));
	EXPECT_EQ(1, inside(4, -3, 8));
	EXPECT_EQ(0, inside(12, 14, 8));
}
using namespace std;
int main(int argc, char*argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
 }

