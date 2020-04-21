#include "stdafx.h"

TEST(LinkedList, Push_back)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	LinkedList<int>::iterator it = arr.begin();
	int i = 1;
	for (; it != arr.end(); ++it)
	{
		EXPECT_EQ(*it, i);
		++i;
	}
}

TEST(LinkedList, CopyConstructor)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	
	LinkedList<int> arr2(arr);
	LinkedList<int>::iterator it = arr2.begin();
	int i = 1;
	for (; it != arr2.end(); ++it)
	{
		EXPECT_EQ(*it, i);
		++i;
	}
	arr2.push_back(5);
	arr2.push_front(0);
	LinkedList<int>::iterator it2 = arr2.begin();
	int i2 = 1;
	for (; it != arr2.end(); ++it2)
	{
		EXPECT_EQ(*it2, i2);
		++i2;
	}
}

TEST(LinkedList, PushFront)
{
	LinkedList<int> arr;
	arr.push_front(5);
	arr.push_front(4);
	arr.push_front(3);
	arr.push_front(2);
	arr.push_front(1);
	LinkedList<int>::iterator it = arr.begin();
	int i = 1;
	for (; it != arr.end(); ++it)
	{
		EXPECT_EQ(*it, i);
		++i;
	}
}

TEST(LinkedList, OperatorAssign)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	LinkedList<int> arr2;
	arr2.push_front(3);
	arr2.push_front(2);
	arr2.push_front(1);
	arr2 = arr;
	LinkedList<int>::iterator it = arr.begin();
	int k = 1;
	for (; it != arr.end(); ++it)
	{
		EXPECT_EQ(*it, k);
		++k;
	}
}

TEST(LinkedList, OperatorTransferring)
{
	LinkedList<char> arr2;
	arr2.push_back('r');
	arr2.push_back('t');
	LinkedList<char> arr1=std::move(arr2);
	auto it = arr1.begin();
	ASSERT_EQ(*it, 'r');
	ASSERT_FALSE(arr1.empty());
}

TEST(LinkedList, ConstructorTransferring)
{
	LinkedList<int> arr2;
	arr2.push_back(2);
	arr2.push_back(2);
	LinkedList<int> arr1(std::move(arr2));
	auto it = arr1.begin();
	ASSERT_EQ(*it, 2);
	ASSERT_FALSE(arr1.empty());
}

TEST(Iterator, insert)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	LinkedList<int>::iterator it = arr.begin();
	++it;
	ASSERT_EQ(*it, 2);
	ASSERT_EQ(*arr.insert(it, 5),5);
	ASSERT_EQ(*it, 2);
	--it;
	ASSERT_EQ(*it,5);
	++it;
	ASSERT_EQ(*it, 2);
}

TEST(Iterator, erase)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	LinkedList<int>::iterator it = arr.begin();
	ASSERT_EQ(*it, 1);
	++it;
	ASSERT_EQ(*arr.erase(it),3);
	LinkedList<int>::iterator it2 = arr.begin();
	ASSERT_EQ(*it2, 1);
	++it2;
	ASSERT_EQ(*it2, 3);
}

TEST(LinkedList, remove)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.remove(3);
	LinkedList<int>::iterator it = arr.begin();
	++it;
	++it;
	ASSERT_EQ(*it, 4);
}

TEST(LinkedList, Empty)
{
	LinkedList<char> arr;
	ASSERT_TRUE(arr.empty());
	arr.push_back('t');
	ASSERT_FALSE(arr.empty());
	arr.remove('t');
	arr.print();
	ASSERT_TRUE(arr.empty());
}

TEST(LinkedList, BeginEnd)
{
	LinkedList<int> arr;
	arr.push_back('t');
	arr.push_back('r');
	ASSERT_EQ(*arr.begin(),'t');
	LinkedList<int>::iterator it = arr.end();
	--it;
	ASSERT_EQ(*it, 'r');
}

TEST(Iterator, Moving)
{
	LinkedList<int> arr;
	arr.push_back('t');
	arr.push_back('r');
	arr.push_back('a');
	arr.push_back('p');
	LinkedList<int>::iterator it = arr.begin();
	ASSERT_EQ(*it, 't');
	++it;
	ASSERT_EQ(*it, 'r');
	++it;
	++it;
	ASSERT_EQ(*it, 'p');
	--it;
	ASSERT_EQ(*it, 'a');
}

TEST(Iterator, CompareBeginEnd)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	int i = 1;
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		ASSERT_EQ(*it, i);
		++i;
	}
}

TEST(Iterator, Compare)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	auto i1 = arr.begin();
	auto i2 = arr.end();
	--i2;
	ASSERT_TRUE(--i2 == ++i1);
}

