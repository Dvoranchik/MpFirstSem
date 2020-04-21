#include "stdafx.h"

TEST(BinarySearch, NoRecEvenMiddle)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 5, pred);
	ASSERT_EQ(*result, 5);
}

TEST(BinarySearch, NoRecNoEven)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88,99};
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 5, pred);
	ASSERT_EQ(*result, 5);
}

TEST(BinarySearch, NoRecEven)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 5, pred);
	ASSERT_EQ(*result, 5);
}

TEST(BinarySearch, NoRecEvenFirst)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*result, 1);
}

TEST(BinarySearch, NoRecEvenLast)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 88, pred);
	ASSERT_EQ(*result, 88);
}

TEST(BinarySearch, NoRecNoEvenFirst)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88,99 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*result, 1);
}

TEST(BinarySearch, NoRecNoEvenLast)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88,99 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 99, pred);
	ASSERT_EQ(*result, 99);
}

TEST(BinarySearch, NoRecNoEvenNoMantioned)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88,99 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 25, pred);
	ASSERT_EQ(*result, 99);
}

TEST(BinarySearch, NoRecOneNumber)
{
	std::vector<int> arr = { 1 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*result, 1);
}

TEST(BinarySearch, NoRecOneNumberNoMantioned)
{
	std::vector<int> arr = { 1 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2,22, pred);
	ASSERT_EQ(*(result-1), 1);
}

TEST(BinarySearch, RecNoEven)
{
	std::vector<int> arr = { 1,2,4,4,5,6,7,8,9,10,11 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 3, pred);
	ASSERT_EQ(result, arr.end());
}

TEST(BinarySearch, RecNoEvenFirst)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11 ,88,99 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;
	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*result, 1);
}

TEST(BinarySearch, RecEvenFirst)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11 ,88 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;
	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*result, 1);
}

TEST(BinarySearch, RecNoEvenLast)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11 ,88,99 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 99, pred);
	ASSERT_EQ(*result, 99);
}

TEST(BinarySearch, RecEvenLast)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11 ,88 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 88, pred);
	ASSERT_EQ(*result, 88);
}

TEST(BinarySearch, RecNoOneNumber)
{
	std::vector<int> arr = { 1 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*result, 1);
}

TEST(BinarySearch, RecNoMantioned)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,100,125 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 25, pred);
	ASSERT_EQ(*(result - 1), 125);
}

TEST(BinarySearch, RecNoOneNumberNoMentioned)
{
	std::vector<int> arr = {1};
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 22, pred);
	ASSERT_EQ(*(result-1), 1);
}

TEST(BinarySearch, RecNoNoMentioned)
{
	std::vector<int> arr = { 3,4,5,6,7 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*(result - 1), 7);
}

TEST(BinarySearch, RecNoMiddleMentioned)
{
	std::vector<int> arr = { 3,4,5 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 4, pred);
	ASSERT_EQ(*result, 4);
}

TEST(BinarySearch, RecNoTwoNumbers)
{
	std::vector<int> arr = { 3,22 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 1, pred);
	ASSERT_EQ(*(result-1), 22);
}

TEST(BinarySearch, LinkedList)
{
	LinkedList<int> arr;
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(9);
	arr.push_back(10);
	arr.push_back(15);
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<LinkedList<int>::iterator, int, std::less<int>>(it, it2, 4, pred);
	ASSERT_EQ(*result, 4);
}

TEST(BinarySearch, LinkedListLast)
{
	LinkedList<int> arr;
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(9);
	arr.push_back(10);
	arr.push_back(15);
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<LinkedList<int>::iterator, int, std::less<int>>(it, it2, 25, pred);
	ASSERT_EQ(*(--result), 15);
}

TEST(BinarySearch, NoRecNoMantioned)
{
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,88,99,100 };
	auto it = arr.begin();
	auto it2 = arr.end();
	std::less<int> pred;

	auto result = BinarySearch<std::vector<int>::iterator, int, std::less<int>>(it, it2, 25, pred);
	ASSERT_EQ(*result, 99);
}


TEST(BinarySearch, RecNoTwoNumbersNoPred)
{
	std::vector<int> arr = { 3,22 };
	auto it = arr.begin();
	auto it2 = arr.end();

	auto result = RecursiveBinarySearch<std::vector<int>::iterator, int>(it, it2, 1);
	ASSERT_EQ(*(result - 1), 22);
}