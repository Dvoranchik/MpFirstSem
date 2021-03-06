
#include "stdafx.h"
#include "gtest\gtest.h"
#include "FunD.h"

TEMPLATE_SWAP_FIRST_AND_LAST(int);
TEMPLATE_SWAP_FIRST_AND_LAST(double);
TEST(sort, DOUBLE)
{
	double arr1[6] = { 2.1,-3.2,6.5,-5.4,4.2,-6.1 };
	double rez[6] = { -6.1,-5.4,-3.2,2.1,4.2,6.5 };
	bubblesort_double(arr1, 6);
	for (int i = 0; i < 6; ++i)
	{
		EXPECT_EQ(rez[i], arr1[i]);
	}
}
TEST(sort, DOU)
{
	double arr1[6] = { 5,0,6,9,4,-6 };
	double rez[6] = { 5,3,6,9,4,-6 };
	Modify(arr1, 6);
	for (int i = 0; i < 6; ++i)
	{
		EXPECT_EQ(rez[i], arr1[i]);
	}
}
TEST(EXTEND, CHAR)
{

	 char** cc2 = new char*[3];
	 cc2[0]=new char[15]{"1dasokdaspod"};
	 cc2[1] = new char[10] {"3dsadas"};
	 cc2[2] = new char[17] {"0oiyytdesdkajndw"};
	 
	char**ex = extend(cc2, 3);
	for (int i = 0; i < 3 + 2; ++i)
		printf("%s,", *(ex + i));
	for (int i = 0; i < 3; ++i)
		delete[] cc2[i];
	delete[] cc2;
	delete[] ex[4];
	delete[] ex;

}

TEST(Extend, INTEGER)
{
	int a[] = { 1,3,4,5,6,5,6,4,4,7 };
	int arr[] = { 1,3,4,5,6,5,6,4,4,7,7,45 };
	int *e = extend(a, 10);
	for (int i = 0; i < 10 + 2; ++i)
	{
		printf("%d, ", *(e + i));
	}
	for(int i=0;i<12;++i)
	EXPECT_EQ(arr[i], e[i]);
}
TEST(Sum, CHAR)
{
	char** cc2 = new char*[3];
	 char arr[] = "12aspod3dsadas4oiyytdndw";
	cc2[0] = new char[15]{ "12aspod" };
	cc2[1] = new char[10]{ "3dsadas" };
	cc2[2] = new char[17]{ "4oiyytdndw" };
	
	char *e = sum(cc2, 3);
	EXPECT_STREQ(arr, e);
	delete[] cc2;
}
TEST(Maxelement, CHAR)
{
	char** cc2 = new char*[3];
	char arr[] = "4oiyytdndw";
	cc2[0] = new char[15]{ "12aspod" };
	cc2[1] = new char[10]{ "3dsadas" };
	cc2[2] = new char[17]{ "4oiyytdndw" };
	char *e = max(cc2, 3);
	EXPECT_STREQ(arr, e);
	delete[] cc2;
}
TEST(maxElement, INTEGER)
{
	int arr1[6] = { 2,-3,6,-5,4,-6 };
	int ma = max(arr1, 6);
	EXPECT_EQ(6,ma );

	int arr2[1] = { 2 };
	ma = max(arr2, 1);
	EXPECT_EQ(2,ma);

	int arr3[6] = { 2,-3,6,-5,4,17 };
	ma = max(arr3, 6);
	EXPECT_EQ(17,ma);

}

TEST(maxElement, DOUBLE)
{
	double arr1[6] = { 2.1,-3,6.7,-5,4,-6 };
	double ma = max(arr1, 6);
	EXPECT_DOUBLE_EQ(6.7,ma);


	double arr3[6] = { 2.1,-3.12,6.5,-58.1,4.2,45.23 };
	ma = max(arr3, 6);	

	EXPECT_EQ(45.23,ma);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
