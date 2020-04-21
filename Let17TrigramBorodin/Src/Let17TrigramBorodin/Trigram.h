#pragma once
#include "stdafx.h"
#include "Let17TrigramBorodinApi.hpp"


class Trigram
{
public:
	LET17TRIGRAMBORODIN_API std::pair<std::unordered_map<std::string, int>, std::unordered_map<std::string, int>> TrigramList(std::string fileName);
	LET17TRIGRAMBORODIN_API std::string ReadText(std::string fileName);
	LET17TRIGRAMBORODIN_API std::pair<std::multimap<double, std::string>, std::multimap<double, std::string>> Statistic(std::string fileName);
	LET17TRIGRAMBORODIN_API bool IsSings(const char& value);
	LET17TRIGRAMBORODIN_API std::pair<int, int> Sum(std::pair<std::unordered_map<std::string, int>, std::unordered_map<std::string, int>> res);
	LET17TRIGRAMBORODIN_API void StaticToFile(std::pair<std::multimap<double, std::string>, std::multimap<double, std::string>> res,std::string fileName,int procent);
private:
	int _sumEU=0, _sumRU=0;
};