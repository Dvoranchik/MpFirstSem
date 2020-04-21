#include "stdafx.h"
#include "Computer.h"


Computer::Computer(int cpuFrequency, int ramSize, int hardDiskCapacity, int compCost, std::string compBrand, std::string cpuType, std::string code) : _code(code), _cpuFrequency(cpuFrequency), _ramSize(ramSize), _hardDiskCapacity(hardDiskCapacity), _compCost(compCost), _compBrand(compBrand), _cpuType(cpuType){}

Computer::Computer(const Computer & other):_code(other._code), _cpuFrequency(other._cpuFrequency), _ramSize(other._ramSize), _hardDiskCapacity(other._hardDiskCapacity), _compCost(other._compCost), _compBrand(other._compBrand), _cpuType(other._cpuType) {}

Computer::Computer(Computer&& other) : _code(other._code), _cpuFrequency(other._cpuFrequency), _ramSize(other._ramSize), _hardDiskCapacity(other._hardDiskCapacity), _compCost(other._compCost), _compBrand(other._compBrand), _cpuType(other._cpuType)
{
	other._code.clear();
	other._cpuFrequency = 0;
	other._compBrand.clear();
	other._compCost = 0;
	other._cpuType.clear();
	other._hardDiskCapacity = 0;
	other._ramSize = 0;
}

Computer::~Computer(){}

Computer& Computer::operator=(const Computer& other)
{

	if (this == &other)
		return *this;
	_code = other._code;
	_cpuFrequency = other._cpuFrequency;
	_compBrand = other._compBrand;
	_compCost = other._compCost;
	_cpuType = other._cpuType;
	_hardDiskCapacity = other._hardDiskCapacity;
	_ramSize = other._ramSize;
	return *this;
}

bool Computer::operator==(const Computer& other) const
{
	return ((_code == other._code) && (_cpuFrequency == other._cpuFrequency)
		&& (_compBrand == other._compBrand) && (_compCost == other._compCost)
		&& (_cpuType == other._cpuType) && (_hardDiskCapacity == other._hardDiskCapacity) && (_ramSize == other._ramSize));
}

std::string Computer::GetCode()
{
	return _code;
}

int Computer::GetCpuFrequency()
{
	return _cpuFrequency;
}

int Computer::GetRamSize()
{
	return _ramSize;
}

int Computer::GetHardDiskCapasity()
{
	return _hardDiskCapacity;
}

int Computer::GetCompCost()
{
	return _compCost;
}

std::string Computer::GetCompBrand()
{
	return _compBrand;
}

std::string Computer::GetCpuType()
{
	return _cpuType;
}
