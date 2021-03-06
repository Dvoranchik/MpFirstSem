#include "stdafx.h"
#include "gtest\gtest.h"
#include"Fun.h"

TEST(FailIsNotMine, ReadName)
{
	Entrant* arr = nullptr;
	int coll = 0;

	arr = ReadStructOfFile("Text.json", coll);
	EXPECT_STREQ(arr[0].Name, L"Daniil");
	EXPECT_STREQ(arr[1].Name, L"Sergey");
	EXPECT_STREQ(arr[2].Name, L"Nastya");

	delete[] arr;
}

TEST(FailIsNotMine, ReadNameNULLcolon)
{
	Entrant* arr = nullptr;
	int coll = 0;

	arr = ReadStructOfFile("Text1.json", coll);
	EXPECT_STREQ(arr[0].Name, L"");
	EXPECT_STREQ(arr[1].Name, L"");
	EXPECT_EQ(arr[0].Estimates[0], 0);

	delete[] arr;
}
TEST(FailIsNotMine, ReadEstimates)
{
	Entrant* arr = nullptr;
	int coll = 0;

	arr = ReadStructOfFile("Text.json", coll);
	EXPECT_EQ(arr[0].Estimates[0],3);
	EXPECT_EQ(arr[1].Estimates[1],4);
	EXPECT_EQ(arr[2].Estimates[3],4);

	delete[] arr;
}

TEST(FailIsNotMine, ReadPhone)
{
	Entrant* arr = nullptr;
	int coll = 0;

	arr = ReadStructOfFile("Text.json", coll);
	EXPECT_STREQ(arr[0].Phone, L"83655464");
	EXPECT_STREQ(arr[1].Phone, L"59984564");
	EXPECT_STREQ(arr[2].Phone, L"63474523");

	delete[] arr;
}

TEST(FailIsNotMine, OutFile)
{
	Entrant* arr = nullptr;
	int coll = 0;

	arr = ReadStructOfFile("Text.json", coll);
	EXPECT_TRUE(PrintToFile("Result.txt",arr,coll));
	PickingStruct(arr, 6);
	EXPECT_TRUE(PrintToFile("ResultSort.txt",arr,coll));
	
	delete[] arr;
}
TEST(FailIsNotMine, MiddleResult)
{
	Entrant* arr = nullptr;
	Entrant* middle = nullptr;
	int coll = 0;

	arr = ReadStructOfFile("Text.json", coll);
	middle = getEntrantMiddleBall(arr, coll, 3.5);
	EXPECT_TRUE(PrintToFile("ResultMiddle1.txt", middle, coll));
	delete[] middle;
	
	middle = getEntrantMiddleBall(arr, coll, 3.0);
	EXPECT_TRUE(PrintToFile("ResultSortMiddle2.txt", middle, coll));
	delete[] middle;

	middle = getEntrantMiddleBall(arr, coll, 3.8);
	EXPECT_TRUE(PrintToFile("ResultMiddle3.txt", middle, coll));
	delete[] middle;

	delete[] arr;
}

TEST(FileWrite, Midle_null)
{
	Entrant* arr = nullptr;
	Entrant* middle = nullptr;
	int coll = 0;

	arr = ReadStructOfFile("Text.json", coll);
	middle = getEntrantMiddleBall(arr, coll, 5);
	EXPECT_FALSE(PrintToFile("ResultMiddle_null.txt", middle, coll));
	delete[] middle;

	delete[] arr;
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
