#include "stdafx.h"
TEST(File,ReadMap)
{
	Statistic a;
	std::multimap<int, std::string, std::greater<int>> d=a.ResultMap("FirstTest.txt",10);
	ASSERT_EQ(d.size(), 10);
	for (auto i = d.begin(); i != d.end(); ++i)
	{
		std::cout << i->first <<" "<<i->second<< std::endl;
	}
	auto it = d.begin();
	ASSERT_EQ(it->first, 2);
	ASSERT_EQ(it->second, "организации");
	++it;
	ASSERT_EQ(it->first, 2);
	ASSERT_EQ(it->second, "значение");
}
TEST(File, ReadVector)
{
	Statistic a;
	std::vector<std::pair<int, std::string>> d = a.ResultVector("FirstTest.txt", 10);
	ASSERT_EQ( d.size(),10);
	for (auto i = d.begin(); i != d.end(); ++i)
	{
		std::cout << i->first << " " << i->second << std::endl;
	}
	auto it = d.begin();
	ASSERT_EQ(it->first, 2);
	ASSERT_EQ(it->second, "позволяет");
	++it;
	ASSERT_EQ(it->first, 2);
	ASSERT_EQ(it->second, "значение");
}

TEST(File, ReadTask)
{
	Statistic a;
	std::multimap<int, std::string, std::greater<int>> d = a.ResultMap("Task16.txt",40);
	ASSERT_EQ( d.size(),40);
	for (auto i = d.begin(); i != d.end(); ++i)
	{
		std::cout << i->first << " " << i->second << std::endl;
	}
	auto it = d.begin();
	ASSERT_EQ(it->first, 373);
	ASSERT_EQ(it->second, "call");
	++it;
	ASSERT_EQ(it->first, 342);
	ASSERT_EQ(it->second, "avp");
}

TEST(File, ReadTest)
{
	Statistic a;
	std::multimap<int, std::string, std::greater<int>> d = a.ResultMap("Text.txt",2);
	ASSERT_EQ(d.size(), 2);
	for (auto i = d.begin(); i != d.end(); ++i)
	{
		std::cout << i->first << " " << i->second << std::endl;
	}
	auto it = d.begin();
	ASSERT_EQ(it->first, 3);
	ASSERT_EQ(it->second, "ada");
	++it;
	ASSERT_EQ(it->first, 3);
	ASSERT_EQ(it->second, "lol");
}

TEST(File, ReadVectorFish)
{
	Statistic a;
	std::vector<std::pair<int, std::string>> d = a.ResultVector("FishText.txt", 10);
	ASSERT_EQ(d.size(), 10);
	for (auto i = d.begin(); i != d.end(); ++i)
	{
		std::cout << i->first << " " << i->second << std::endl;
	}
	auto it = d.begin();
	ASSERT_EQ(it->first, 17);
	ASSERT_EQ(it->second, "развития");
	++it;
	ASSERT_EQ(it->first, 17);
	ASSERT_EQ(it->second, "деятельности");
	++it;
	ASSERT_EQ(it->first, 13);
	ASSERT_EQ(it->second, "направлений");
}