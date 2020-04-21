#pragma once
#include "stdafx.h"
#include "Pz18TrigramBorodinApi.hpp"

class Trigram
{
public:
	PZ18TRIGRAMBORODIN_API bool IsSigns(const char& value);
	PZ18TRIGRAMBORODIN_API std::wstring ReadFileToMultiByte(const char* fileName);
	PZ18TRIGRAMBORODIN_API std::pair<std::unordered_map<std::wstring, int>, std::unordered_map<std::wstring, int>> TrigramList(std::string fileName);
	PZ18TRIGRAMBORODIN_API std::pair<std::multimap<double, std::wstring>, std::multimap<double, std::wstring>> Statistic(std::string fileName);
	PZ18TRIGRAMBORODIN_API void StaticToFile(std::pair<std::multimap<double, std::wstring>, std::multimap<double, std::wstring>> res, std::string fileName,int procent);
	PZ18TRIGRAMBORODIN_API std::pair<int, int> Sum(std::pair<std::unordered_map<std::wstring, int>, std::unordered_map<std::wstring, int>> res);
private:
	int _sumRU=0, _sumEU=0;
};