#pragma once
#include "stdafx.h"
#include "Let16StatisticBorodinApi.hpp"
struct Sings
{
	LET16STATISTICBORODIN_API Sings();
	LET16STATISTICBORODIN_API bool IsSings(const char& elem) const;

	bool _table[256]{};
};

class PredicatPair
{
public:
	LET16STATISTICBORODIN_API bool operator()(const std::pair<int, std::string>& data, const std::pair<int, std::string>& value) const;
};

class ErrorWords
{
public:
	LET16STATISTICBORODIN_API ErrorWords(const std::string& value) :_value(value) {}
	LET16STATISTICBORODIN_API bool operator()(const std::string& data);
	std::string _value;
};