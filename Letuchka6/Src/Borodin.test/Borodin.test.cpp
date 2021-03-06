
#include "stdafx.h"
#include "gtest\gtest.h"

TEST(Test_UnderStr1, ex1)
{
	char str[] = "arararar";
	char substr[] = "ara";
	EXPECT_EQ(2, SubStrCount(str, substr));
}


TEST(TEST1, dop_test2)
{
	char str[] = "111223223";
	char substr[] = "1122";
	EXPECT_EQ(1, SubStrCount(str, substr));
}

TEST(TEST1, dop_test3)
{
	char str[] = "11123223";
	char substr[] = "1122";
	EXPECT_EQ(0, SubStrCount(str, substr));
}

TEST(Test_UnderStr1, ex2)
{
	char str[] = "arararar";
	char substr[] = " ";
	EXPECT_EQ(SubStrCount(str, substr), 0);
}

TEST(Test_UnderStr1, ex3)
{
	char str[] = "arararar";
	char substr[] = "arar";
	EXPECT_EQ(SubStrCount(str, substr), 2);
}

TEST(Test_UnderStr1, ex4)
{
	char str[] = "arararar";
	char substr[] = "a";
	EXPECT_EQ(SubStrCount(str, substr), 4);
}

TEST(Test_UnderStr2, ex1)
{
	wchar_t str[] = L"arararar";
	wchar_t substr[] = L"ara";
	EXPECT_EQ(SubStrCount(str, substr), 3);
}
TEST(Test_UnderStr2, ex7)
{
	wchar_t str[] = L"aaaaaaa";
	wchar_t substr[] = L"aa";
	EXPECT_EQ(6,SubStrCount(str, substr));
}
TEST(Test_UnderStr2, ex8)
{
	char str[] = "aaaaaaa";
	char substr[] = "aa";
	EXPECT_EQ(3, SubStrCount(str, substr));
}
TEST(Test_UnderStr2, ex9)
{
	char str[] = "aaaaaaa";
	char substr[] = "aa";
	EXPECT_EQ(6, SubStrCount<char>(str, substr));
}
TEST(Test_UnderStr2, ex2)
{
	wchar_t str[] = L"arar arar";
	wchar_t substr[] = L" ";
	EXPECT_EQ(SubStrCount(str, substr), 1);
}

TEST(Test_UnderStr2, ex3)
{
	wchar_t str[] = L"arararar";
	wchar_t substr[] = L"arar";
	EXPECT_EQ(SubStrCount(str, substr), 3);
}

TEST(Test_UnderStr2, ex4)
{
	wchar_t str[] = L"arararar";
	wchar_t substr[] = L"a";
	EXPECT_EQ(SubStrCount(str, substr), 4);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}


