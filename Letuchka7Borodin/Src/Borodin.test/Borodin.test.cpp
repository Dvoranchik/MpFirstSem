#include "stdafx.h"
#include "gtest\gtest.h"
#include "Fun.h"

TEST(ValidBrackets, testFALSE)
{
	char arr1[] = ")((00))";
	char arr2[] = "(((00)))";
	char arr3[] = "(([]00))";
	EXPECT_FALSE(Brakets(arr1));
	EXPECT_TRUE(Brakets(arr2));
	EXPECT_TRUE(Brakets(arr3));
	EXPECT_FALSE(Brakets("(()))"));
	EXPECT_FALSE(Brakets("("));
	EXPECT_TRUE(Brakets(""));
	EXPECT_FALSE(Brakets("((ihsdhusaduic)kias)vv)"));
	EXPECT_TRUE(Brakets("<>"));
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}