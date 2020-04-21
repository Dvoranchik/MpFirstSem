#pragma once
#include "stdafx.h"
#include "set"
#include "Let16StatisticBorodinApi.hpp"
class StopWords
{
public:
	LET16STATISTICBORODIN_API StopWords(const char* fileName);
	std::vector<std::string> _data;
};