#include "stdafx.h"
#include "Predicates.h"

bool PredicatsBrand::operator()(int _data, int value)
{
	return _data>value;
}

bool PredicatsBrand::operator()(Computer& _data, Computer& value)
{
	return _data.GetCompBrand() > value.GetCompBrand();
}

bool PredicatsHardCapasity::operator()(Computer & _data, Computer & value)
{
	return _data.GetHardDiskCapasity() > value.GetHardDiskCapasity();
}

bool PredicatsCPUBrand::operator()(Computer & _data, Computer & value)
{
	return _data.GetCpuType() > value.GetCpuType();
}

bool PredicatsCpuFrequency::operator()(Computer & _data, Computer & value)
{
	return _data.GetCpuFrequency()>value.GetCpuFrequency();
}

bool PredicatsFindBrand::operator()(Computer & _data, std::string value)
{
	return _data.GetCompBrand() == value;
}

bool PredicatsFindCPUBrand::operator()(Computer & _data, std::string value)
{
	return _data.GetCpuType() == value;
}

bool PredicatsFindHardDiskCapasity::operator()(Computer & _data, int value)
{
	return _data.GetHardDiskCapasity()==value;
}

bool PredicatsFindRamSize::operator()(Computer & _data, int value)
{
	return _data.GetRamSize()==value;
}

 bool FindCriterion::operator()(int data, int value)
{
	return data==value;
}

 bool FindCriterion::operator()(char data, char value)
 {
	 return data == value;
 }