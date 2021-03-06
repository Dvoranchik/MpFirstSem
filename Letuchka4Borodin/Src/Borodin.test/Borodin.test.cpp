
#include "stdafx.h"
#include "Functions.h"
#include "gtest\gtest.h"
const int b = 20;
TEST(CharTest, First)
{
	char arr[8] = "1a2.245";
	EXPECT_DOUBLE_EQ(2+10*b+b*b+2./b+4./b/b+5./b/b/b, Digit(arr,b));
}
TEST(CharTest, Second)
{
	char arr[8] = "1a2f5";
	EXPECT_DOUBLE_EQ(5+15*b+2*b*b+10*b*b*b+b*b*b*b, Digit(arr, b));
}
TEST(CharTest, Third)
{
	char arr[8] = ".1a25";
	EXPECT_DOUBLE_EQ(1./b+10./b/b+2./b/b/b+5./b/b/b/b, Digit(arr, b));
}
TEST(CharTest, Fourth)
{
	char arr[8] = "3f5.";
	EXPECT_DOUBLE_EQ(5+15*b+3*b*b, Digit(arr, b));
}

int main(int argc, char* argv[])

{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

