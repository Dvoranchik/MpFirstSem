#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyF.h"


TEST(letuchka, First)
{
	unsigned char a[N] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,6,1,2,3,5};
	ASSERT_EQ(4, size(a,1,4));
}

TEST(letuchka, Second)
{
	EXPECT_EQ(127, CHAR_MAX);
	EXPECT_EQ(-128, CHAR_MIN);
	EXPECT_EQ(255, CHAR_MAX + 128);
	EXPECT_EQ(0, CHAR_MIN + 128);
	EXPECT_EQ(32767, SHRT_MAX);
	EXPECT_EQ(-32767i16-1, SHRT_MIN);
	EXPECT_EQ(65534, SHRT_MAX + 32767);
	EXPECT_EQ(0, SHRT_MIN + 32768);
	EXPECT_EQ(0x80000000-1, INT32_MAX);
	EXPECT_EQ(0x80000000, INT32_MIN);
	EXPECT_EQ(4294967294, INT32_MAX + 2147483647);
	EXPECT_DOUBLE_EQ(0, INT32_MIN + 2147483647+1);
	EXPECT_EQ(0x80000000-1, LONG_MAX);
	EXPECT_EQ(0x80000000, LONG_MIN);
	EXPECT_EQ(4294967294, LONG_MAX + 2147483648-1);
	EXPECT_EQ(0, LONG_MIN + 2147483647+1);
	EXPECT_EQ(0x7fffffffffffffffi64, LLONG_MAX);
	EXPECT_EQ(0x8000000000000000i64, LLONG_MIN);

}
TEST(letuchka, Third)
{
	ASSERT_EQ(1, sizeof(bool));
	ASSERT_EQ(1, sizeof(char));
	ASSERT_EQ(2, sizeof(short int));
	ASSERT_EQ(2, sizeof(unsigned short int));
	ASSERT_EQ(2, sizeof(wchar_t));
	ASSERT_EQ(1, sizeof(unsigned char));
	ASSERT_EQ(4, sizeof(int));
	ASSERT_EQ(4, sizeof(float));
	ASSERT_EQ(8, sizeof(long long));
	ASSERT_EQ(4, sizeof(long));
	ASSERT_EQ(8, sizeof(double));
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(size_t));

}
TEST(letuchka, Four)
{
	void*test;
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(test));

}
TEST(letuchka, Five)
{
	unsigned char*test;
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(test));
}
TEST(letuchka, Six)
{
	unsigned char*test;
	ASSERT_EQ(1, sizeof(*test));
}
TEST(letuchka, seven)
{
	unsigned char arr[N];
	ASSERT_EQ(20, sizeof(arr));
}
TEST(letuchka, eight)
{
	unsigned char arr[N];
	ASSERT_EQ(1,sizeof( arr[0]));
}
TEST(letuchka, nine)
{
	unsigned char arr[N];
	ASSERT_EQ(20, N * sizeof(arr[0]));
}
TEST(letuchka, ten)
{
	unsigned char arr[N];
	unsigned char *p = arr;
	//ASSERT_EQ(sizeof(p), sizeof(arr));
	ASSERT_NE(sizeof(p), sizeof(arr));
}
TEST(letuchka, eleven)
{
	bool a = false;
	unsigned char arr[N];
	unsigned char *p = arr;
	if (arr == p && p == &arr[0]) 
		a = true;
	ASSERT_EQ(true, a);
	
}
TEST(letuchka, twelth)
{
	bool a = false;
	unsigned char arr[N];
	unsigned char *p = arr;
	if (&arr[1] == p && p + 1 == &p[1])
		a = true;
	ASSERT_EQ(false, a);
}
TEST(letuchka, Thirtheen)
{
	bool a = false;
	unsigned char arr[N];
	unsigned char *p = arr;
	if (arr[1] == *(p + 1) && *(p + 1) == p[1] && p[1] == 1[p])
		a = true;
	ASSERT_EQ(true, a);
	
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


