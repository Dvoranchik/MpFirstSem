#pragma once
#include "stdafx.h"
#include "Let16StatisticBorodinApi.hpp"
#include "StopWords.h"
#include "Sings.h"

class Statistic
{
public:
	LET16STATISTICBORODIN_API bool IsSings(const char& value);

	LET16STATISTICBORODIN_API std::unordered_map<std::string,int> Statistica(std::string str);
	LET16STATISTICBORODIN_API std::multimap<int, std::string, std::greater<int>> ResultMap(const char* fileName, int count);
	
	LET16STATISTICBORODIN_API std::vector<std::pair<int,std::string>> ResultVector(const char* fileName,int count);

	LET16STATISTICBORODIN_API std::string ReadText(const char* fileName);
};

LET16STATISTICBORODIN_API bool IsStopWord(const StopWords& ob, const std::string& str);