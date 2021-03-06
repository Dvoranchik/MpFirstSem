#include "stdafx.h"
#include "Fun.h"
#include "gtest\gtest.h"


TEST(LetThreeBitPattern, First)
{
	ASSERT_EQ(0xffffffffi64, UINT_MAX); // unsigned int max
}

TEST(LetThreeBitPattern, Second)
{
	ASSERT_EQ(0, INT32_MIN + 0x80000000i64);//unsigned int min
}
TEST(LetThreeBitPattern, Third_1)
{
	char arr[] = "11111111111111111111111111111111";
	char*p = Bit3(4294967295);
		EXPECT_STREQ(arr, p);
		delete[]p;
}
TEST(LetThreeBitPattern, Third_2)
{
	char arr[] = "00000000000000000000000000000000";
	char*p = Bit3(0);
	EXPECT_STREQ(arr, p);
	delete[]p;
}
TEST(LetThreeBitPattern, Third_3)
{
	char arr[] = "00000000000000000000000000000011";
	char*p = Bit3(3);
	EXPECT_STREQ(arr, p);
	delete[]p;
}
TEST(LetThreeBitPattern, Third_4)
{
	char arr[] = "00000001000000100000001100000100";
	char*p = Bit3(0x01020304);
	EXPECT_STREQ(arr, p);
	delete[]p;
}
TEST(LetThreeBitPattern, Fourth_1)
{
	int arr[] = { 0xfd,0xfc,0xfb,0xfa };
	int*p = Byit4(0xfafbfcfd);
	EXPECT_TRUE(Bit(p, arr));
	delete[] p;
}

TEST(LetThreeBitPattern, Fourth_2)
{
	int arr[] = { 0,0,0,0 };
	EXPECT_TRUE(Bit(Byit4(0), arr));
	delete[] Byit4(0);
}
TEST(LetThreeBitPattern, Fourth_3)
{
	int arr[] = { 3,0,0,0 };
	EXPECT_TRUE(Bit(Byit4(3), arr));
	delete[] Byit4(3);
}
TEST(LetThreeBitPattern)
{
	int arr[] = { 3,1,0,0};
	 int*p = Byit4(259);
	 for (int i = 0; i < sizeof(unsigned int); ++i)
		 EXPECT_EQ(p[i], arr[i]);
		//std::cout<< p[i];        
}
TEST(LetThreeBitPattern, Fiveth_1)
{
	char arr[] = "11111111111111111111111111111111";
	char*p = Bit5(4294967295);
	EXPECT_STREQ(arr, p);
	delete[] p;
}
TEST(LetThreeBitPattern, Fiveth_2)
{
	char arr[] = "00000000000000000000000000000000";
	char*p = Bit5(0);
	EXPECT_STREQ(arr, p);
	delete[] p;
}
TEST(LetThreeBitPattern, Fiveth_3)
{
	char arr[] = "01011001000000010000000000000000";
	char*p = Bit5(345);
	EXPECT_STREQ(arr, p);
	delete[] p;
}
TEST(LetThreeBitPattern, Sixth_1)
{
	unsigned int arr[2] = { 35,329 };
	char mas[] = "0000000000000000000000000010001100000000000000000000000101001001";
	char*p = Bit6(arr,2);
	EXPECT_STREQ(mas, p);
	delete[] p;
}


int main(int argc, char* argv[])

{
	::testing::InitGoogleTest(&argc, argv);
	
    return RUN_ALL_TESTS();
}

