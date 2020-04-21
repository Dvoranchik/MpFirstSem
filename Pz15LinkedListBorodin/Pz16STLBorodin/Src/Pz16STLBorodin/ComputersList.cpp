#include "stdafx.h"
#include "Algorithm.h"
#include "Predicates.h"
#include "ComputersList.h"

ComputersList::ComputersList(std::vector<Computer> data):_data(data){}

ComputersList::ComputersList(const ComputersList& other):_data(other._data){}

ComputersList::ComputersList(ComputersList&& other):_data(other._data)
{
	other._data.clear();
}

ComputersList::~ComputersList()
{
	_data.clear();
}

ComputersList& ComputersList::operator=(const ComputersList& other)
{
	if (this == &other)
		return *this;
	_data.~vector();
	_data = other._data;
	return *this;
}

bool ComputersList::operator==(const ComputersList& other)
{
	return _data==other._data;
}

void ComputersList::Push_back(const Computer& ob)
{
	_data.push_back(ob);
}

void ComputersList::Delete_back()
{
	_data.pop_back();
}

void ComputersList::Replace(const Computer& ob, int index)
{
	_data[index] = ob;
}

int ComputersList::Size()
{
	return _data.size();
}

Computer& ComputersList::operator[](int index)
{
	return _data[index];
}

bool ComputersList::Empty()
{
	return _data.empty();
}

 Computer& ComputersList::Back()
{
	 return _data.back();
}

 void ComputersList::SortCompBrand()
 {
	 auto it = _data.begin();
	 auto it2 = _data.end();
	 PredicatsBrand x;
	 Sort<std::vector<Computer>::iterator, Computer, PredicatsBrand>(it, it2, x);
 }

 void ComputersList::SortCpuFrequency()
 {
	 auto it = _data.begin();
	 auto it2 = _data.end();
	 PredicatsCpuFrequency x;
	 Sort<std::vector<Computer>::iterator, Computer, PredicatsCpuFrequency>(it, it2, x);
 }

 void ComputersList::SortHardCapasity()
 {
	 auto it = _data.begin();
	 auto it2 = _data.end();
	 PredicatsHardCapasity x;
	 Sort<std::vector<Computer>::iterator, Computer, PredicatsHardCapasity>(it, it2, x);
 }

 void ComputersList::SortCPUBrand()
 {
	 auto it = _data.begin();
	 auto it2 = _data.end();
	 PredicatsCPUBrand x;
	 Sort<std::vector<Computer>::iterator, Computer, PredicatsCPUBrand>(it, it2, x);
 }

 std::list<Computer> ComputersList::FindCompBrand(std::string value)
 {
	 auto it = _data.begin();
	 auto it2 = _data.end();
	 PredicatsFindBrand x;
	 return Find<std::vector<Computer>::iterator, Computer,std::string, PredicatsFindBrand>(it, it2, x, value);
 }

 std::list<Computer> ComputersList::FindCPUBrand(std::string value)
 {
	 auto it = _data.begin();
	 auto it2 = _data.end();
	 PredicatsFindCPUBrand x;
	 return Find<std::vector<Computer>::iterator, Computer, std::string, PredicatsFindCPUBrand>(it, it2, x, value);
 }

 std::list<Computer> ComputersList::FindHardDiskCapasity(int value)
 {
	 auto it = _data.begin();
	 auto it2 = _data.end();
	 PredicatsFindHardDiskCapasity x;
	 return Find<std::vector<Computer>::iterator, Computer, int, PredicatsFindHardDiskCapasity>(it, it2, x, value);
 }

std::list<Computer> ComputersList::FindRamSize(int value)
 {
	auto it = _data.begin();
	auto it2 = _data.end();
	PredicatsFindRamSize x;
	return Find<std::vector<Computer>::iterator, Computer, int, PredicatsFindRamSize>(it, it2, x, value);
 }

