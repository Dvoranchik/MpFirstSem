
#include "stdafx.h"
#include "gtest\gtest.h"
#include "FunD.h"

TEST(Pz6Test, First)
{
	
	
	EXPECT_NEAR(-2.00073, Fallibility(F, -10., 10., 0.001),1e-4);
	
}
TEST(Pz6Test, Second)
{
	const char arr[] = "10.35";
	EXPECT_DOUBLE_EQ(10.35, Digit(arr));
}
TEST(Pz6Test, Seond)
{
	double a = -10;
	double b = 10;
	double arr[10];
	double x=0;
	int i = 0;

	do {

		x = Fallibility(C, a, b, 1e-5);
		//std::cout << x << "\n" << std::endl;
		a = x;

		if (x == -1)
			break;
		arr[i] = x;
		x = Fallibility(C, a, b, 1e-5,x);
		//std::cout << x << "\n" << std::endl;
		a = x;
		arr[i+1] = x;
		//system("pause");
	} 
	while (x != -1);
	

	std::cout << arr[0] << "\n" << std::endl;
	std::cout << arr[1] << "\n" << std::endl;



}
TEST(Pz6Test, Third)
{
	int a = 5;
	int b = 5;
	char arr1[] = "10.35";
	char arr2[] = "31.15";
	char arr3[] = "10.50";
	EXPECT_EQ(52, Summ(arr1,arr2,arr3));
	EXPECT_EQ(10, Summ(a, b));
	EXPECT_EQ(52, Summ("31.15", "10.35", "10.50"));
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}