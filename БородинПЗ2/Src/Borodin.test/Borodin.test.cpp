
#include "stdafx.h"
#include "gtest\gtest.h"
#include "limits.h"
#include "MyF.h"

TEST(ArrayTests, Positive)
{
	const int n = 10;
	double arr[n];
	Inf(arr, n, "Mass.txt");
	ASSERT_EQ(10, Summa(arr, n));
}
TEST(MaxElement, NoPositive)
{
	double a[5] = { 1, -2, 3, 5, 4 };
	ASSERT_EQ(4, Summa(a, 5));
}
TEST(LetThreeBitPattern, Second)
{
	double a[6] = { 2, 1, 2, 1, 2 ,1};
	Honesty(a, 6);
	double  d[] = { 1,1,1,2,2,2 };
	for (int i = 0; i < 6; ++i)
		ASSERT_EQ(a[i], d[i]);
}
TEST(LetThreeBitPattern, Second2)
{
	double a[] = { 1, 2, 3, 4, 5,6,7,8,9,10 };
	Honesty(a, 10);
	double  d[] = { 2,4,6,8,10,9,7,5,3,1 };
	for (int i = 0; i < 10; ++i)
		ASSERT_EQ(a[i], d[i]);

}

TEST(Test_mass2, ex)
{
	int const n = 10;
	double a[n] ;
	Inf(a, n, "Massiv.txt");
	Honesty(a, n);
	double  d[] = { 2,4,6,8,10,9,7,5,3,1 };
	for (int i = 0; i < 10; ++i)
		ASSERT_EQ(a[i], d[i]);
	EXPECT_TRUE(Equal(a, d, n));
	Outf(a, n, "Out.txt");
}

TEST(Test_mass3, Matrix)
{
	srand(time(0));
	const int n =4;
	int **matr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		matr[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			matr[i][j] = rand() % 50;
			if (j%n == 0)
				std::cout <<std:: endl;
			std::cout << matr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	EXPECT_EQ(4, Matrix(matr, n));
	for (size_t i = 0; i < n; ++i)
		delete[]matr[i];
	delete[] matr;
}
int main(int argc, char*argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}