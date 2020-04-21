#include "stdafx.h"


TEST(Trigram, Text2)
{
	Trigram res;
	auto rs = res.TrigramList("Text1.txt");
	for (auto i = rs.first.begin(); i != rs.first.end(); ++i)
		std::cout << i->first << ' ' << i->second << std::endl;
	std::cout<<std::endl;
	for (auto j = rs.second.begin(); j != rs.second.end(); ++j)
		std::cout << j->first << ' ' << j->second << std::endl;
}

TEST(Trigram,ResultToFile)
{
	Trigram res;
	auto rs = res.Statistic("Text1.txt");
	res.StaticToFile(rs, "Result.txt",20);
}

TEST(Trigram, Result)
{
	Trigram res;
	auto rs = res.Statistic("Text1.txt");
	for (auto i = rs.first.begin(); i != rs.first.end(); ++i)
		std::cout << i->first << ' ' << i->second << std::endl;
	std::cout << std::endl;
	for (auto j = rs.second.begin(); j != rs.second.end(); ++j)
		std::cout << j->first << ' ' << j->second << std::endl;
}

TEST(Trigram, ResultText)
{
	Trigram res;
	auto rs = res.Statistic("Text.txt");
	res.StaticToFile(rs, "RusText.txt",30);
}

TEST(Trigram, ResultTask16)
{
	Trigram res;
	auto rs = res.Statistic("Task16.txt");
	res.StaticToFile(rs, "ResultText16.txt",20);
}