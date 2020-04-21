#pragma once
#include "stdafx.h"
#include "Computer.h"
#include "Pz16STLBorodinApi.hpp"
class PredicatsBrand
{
public:
	PZ16STLBORODIN_API bool operator()(int _data, int value);
	PZ16STLBORODIN_API bool operator()(Computer& _data,Computer& value);
};
class PredicatsHardCapasity
{
public:
	PZ16STLBORODIN_API bool operator()(Computer& _data,Computer& value);
};

class PredicatsCPUBrand
{
public:
	PZ16STLBORODIN_API bool operator()(Computer& _data, Computer& value);
};

class PredicatsCpuFrequency
{
public:
	PZ16STLBORODIN_API bool operator()(Computer& _data, Computer& value);
};

class PredicatsFindBrand
{
public:
	PZ16STLBORODIN_API bool operator()( Computer& _data , std::string value );
};

class PredicatsFindCPUBrand
{
public:
	PZ16STLBORODIN_API bool operator()(Computer& _data, std::string value);
};

class PredicatsFindHardDiskCapasity
{
public:
	PZ16STLBORODIN_API bool operator()(Computer& _data, int value);
};

class PredicatsFindRamSize
{
public:
	PZ16STLBORODIN_API bool operator()(Computer& _data, int value);
};

class FindCriterion
{
public:
	PZ16STLBORODIN_API bool operator()(int data, int value);
	PZ16STLBORODIN_API bool operator()(char data, char value);
};