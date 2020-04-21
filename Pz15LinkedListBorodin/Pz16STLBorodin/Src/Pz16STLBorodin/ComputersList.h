#pragma once
#include "stdafx.h"
#include "Computer.h"

class ComputersList
{
public:
	PZ16STLBORODIN_API ComputersList(std::vector<Computer> data);
	PZ16STLBORODIN_API ComputersList(const ComputersList& other);
	PZ16STLBORODIN_API ComputersList(ComputersList&& other);

	PZ16STLBORODIN_API ~ComputersList();

	PZ16STLBORODIN_API ComputersList& operator=(const ComputersList& other);
	PZ16STLBORODIN_API bool operator==(const ComputersList& other);

	PZ16STLBORODIN_API void Push_back(const Computer& ob);
	PZ16STLBORODIN_API void Delete_back();
	PZ16STLBORODIN_API void Replace(const Computer& ob, int index);
	PZ16STLBORODIN_API int Size();
	PZ16STLBORODIN_API Computer& operator[](int index);
	PZ16STLBORODIN_API bool Empty();
	PZ16STLBORODIN_API Computer& Back();

	PZ16STLBORODIN_API void SortCompBrand();
	PZ16STLBORODIN_API void SortCpuFrequency();
	PZ16STLBORODIN_API void SortHardCapasity();
	PZ16STLBORODIN_API void SortCPUBrand();

	PZ16STLBORODIN_API std::list<Computer> FindCompBrand( std::string value);
	PZ16STLBORODIN_API std::list<Computer> FindCPUBrand(std::string value);
	PZ16STLBORODIN_API std::list<Computer> FindHardDiskCapasity(int value);
	PZ16STLBORODIN_API std::list<Computer> FindRamSize(int value);

private:
	std::vector<Computer> _data;
};



