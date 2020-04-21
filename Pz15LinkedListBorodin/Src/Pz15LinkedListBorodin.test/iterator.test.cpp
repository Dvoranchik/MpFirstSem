#include "stdafx.h"
#include "Pz15LinkedListBorodin.h"

TEST(Iterator, Compare)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	auto i1 = arr.begin();
	auto i2 = arr.end();
	ASSERT_FALSE(i2 == i1);
	--i2;
	ASSERT_TRUE(--i2 == ++i1);
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


TEST(Iterator, AdvanceDistance)
{
	LinkedList<char> arr;
	arr.push_back('t');
	arr.push_back('r');
	arr.push_back('a');
	arr.push_back('p');
	arr.push_back('t');
	arr.push_back('r');
	arr.push_back('a');
	arr.push_back('p');
	arr.push_back('t');
	arr.push_back('r');
	arr.push_back('a');
	arr.push_back('p');
	LinkedList<char>::iterator it = arr.begin();
	LinkedList<char>::iterator it2 = arr.end();
	++it;
	ASSERT_EQ(distance(it, it2),11);
	advance(it, 6);
	ASSERT_EQ(*it, 'p');
}

TEST(iterator, Push_back)
{
	LinkedList<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	const LinkedList<int>& constiter = arr;
	LinkedList<int>::const_iterator it = constiter.begin();
	int i = 1;
	for (; it != constiter.end(); ++it)
	{
		EXPECT_EQ(*it, i);
		++i;
	}
}