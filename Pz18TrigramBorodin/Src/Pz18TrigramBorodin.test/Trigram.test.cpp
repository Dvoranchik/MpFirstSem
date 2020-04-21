#include "stdafx.h"


TEST(Trigram, ReadFileToMultiByte)
{
	Trigram r;
	std::wstring result = r.ReadFileToMultiByte("Text.txt");
	wprintf(L"%s\n",result.c_str());
}

TEST(Trigram, Resulttext2)
{
	Trigram res;
	auto rs = res.Statistic("test2.txt");
	for (auto i = rs.first.begin(); i != rs.first.end(); ++i)
		std::wcout << i->first << ' ' << i->second << std::endl;
	std::cout << std::endl;
	for (auto j = rs.second.begin(); j != rs.second.end(); ++j)
		std::wcout << j->first << ' ' << j->second << std::endl;
}

TEST(Trigram, ResultTextFile)
{
	Trigram res;
	auto rs = res.Statistic("Text.txt");
	res.StaticToFile(rs, "RusText.txt",15);
}

TEST(Trigram, ResultTextFile16)
{
	Trigram res;
	auto rs = res.Statistic("Task16.txt");
	res.StaticToFile(rs, "ResultText16.txt", 10);
}

TEST(Trigram, ResultTextFile2)
{
	Trigram res;
	auto rs = res.Statistic("test2.txt");
	res.StaticToFile(rs, "ResultText2.txt", 10);
}

TEST(Trigram, ResultTextFile2All)
{
	Trigram res;
	auto rs = res.Statistic("test2.txt");
	res.StaticToFile(rs, "ResultText2All.txt", 100);
}