#include "stdafx.h"
#include "PairFactory.hpp"
#include "Money.h"
#include "Time.h"
void RegisterLoaders()
{
	PairFactory::GetInstance().RegisterLoader("Money",Money::Load);
	PairFactory::GetInstance().RegisterLoader("Time",Time::Load);
}
               
void Save(std::ostream& stream, IPair** bases, int count)
{
	for (int i = 0; i < count; ++i)
		bases[i]->Save(stream);
}

std::vector<IPair*> Load(std::ifstream& stream)
{
	std::vector<IPair*> result;	
	std::string typeName;

	while (stream >> typeName)
	{
		IPair *pair = PairFactory::GetInstance().GetLoader(typeName)(stream);
		result.push_back(pair);
	}
	return result;
}

bool Save(const char* fileName, IPair** objects, size_t size)
{
	std::ofstream outFile(fileName);
	if (!outFile)
		return false;

	Save(outFile, objects, size);

	for (size_t i = 0; i < size; ++i)
		delete objects[i];

	return true;
}

std::vector<IPair*> Load(const char* fileName)
{
	std::ifstream inFile(fileName);
	if (!inFile)
		throw std::runtime_error("Cannot open file!");

	auto objects = Load(inFile);

	return objects;
}

void PairFactory::RegisterLoader(const std::string& typeName, PairLoaderPtr loader)
{
		_registered[typeName] = loader;
}
PairLoaderPtr PairFactory::GetLoader(const std::string& typeName)
{
	if (_registered.find(typeName) == _registered.end())
		throw std::runtime_error("Illegal type!");

	return _registered[typeName];
}

PairFactory& PairFactory::GetInstance()
{
	static PairFactory soleInstance;

	return soleInstance;
}
