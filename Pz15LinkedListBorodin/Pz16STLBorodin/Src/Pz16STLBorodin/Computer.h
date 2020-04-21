#pragma once
#include "stdafx.h"
#include "Pz16STLBorodinApi.hpp"
class Computer
{
public:
	PZ16STLBORODIN_API Computer(int cpuFrequency, int ramSize, int hardDiskCapasity, int compCost, std::string compBrand, std::string cpuType, std::string code);
	PZ16STLBORODIN_API Computer(const Computer& other);
	PZ16STLBORODIN_API Computer(Computer&& other);

	PZ16STLBORODIN_API ~Computer();

	PZ16STLBORODIN_API Computer& operator=(const Computer& other);
	PZ16STLBORODIN_API bool operator==(const Computer& other) const;

	PZ16STLBORODIN_API int GetCpuFrequency();
	PZ16STLBORODIN_API int GetRamSize();
	PZ16STLBORODIN_API int GetHardDiskCapasity();
	PZ16STLBORODIN_API int GetCompCost();

	PZ16STLBORODIN_API std::string GetCode();
	PZ16STLBORODIN_API std::string GetCompBrand();
	PZ16STLBORODIN_API std::string GetCpuType();
private:

	int _cpuFrequency;
	int _ramSize;
	int _hardDiskCapacity;
	int _compCost;

	std::string _compBrand;
	std::string _cpuType;
	std::string _code;
};