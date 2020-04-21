#include "stdafx.h"
#include "Pz15LinkedListBorodin.h"

TEST(ReverseIterator,PrefixPlus)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	auto it = arr.rbegin();
	ASSERT_EQ(*it, 5);
	int i = 5;
	for ( ; it != arr.rend(); ++it)
	{
		ASSERT_EQ(*it, i);
		--i;
	}
}

TEST(ReverseIterator, PrefixMinus)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	auto it = arr.rend();
	--it;
	int i = 1;
	for (; it != arr.rbegin(); --it)
	{
		ASSERT_EQ(*it, i);
		++i;
	}
}

TEST(ReverseIterator, PostfixPlus)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	auto it = arr.rbegin();
	ASSERT_EQ(*it++, 5);
	ASSERT_EQ(*it, 4);
}

TEST(ReverseIterator, PostfixMinus)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	auto it = arr.rend();
	ASSERT_EQ(*--it, 1);
	ASSERT_EQ(*it--, 1);
	ASSERT_EQ(*it, 2);
}

TEST(ReverseIterator, Compare)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	auto i1 = arr.rbegin();
	auto i2 = arr.rend();
	ASSERT_FALSE(i2 == i1);
	--i2;
	ASSERT_TRUE(--i2 == ++i1);
}

TEST(ReverseIterator, DistanceAdvance)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	auto it = arr.begin();
	auto it2 = arr.end();
	ASSERT_EQ(distance(it, it2),10);
	advance(it, 6);
	ASSERT_EQ(*it, 2);
}

TEST(ReverseIterator, Const)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	const LinkedList<int>& constiter = arr;
	auto it = constiter.rend();
	--it;
	int i = 1;
	for (; it != constiter.rbegin(); --it)
	{
		ASSERT_EQ(*it, i);
		++i;
	}
}