#pragma once
#include "stdafx.h"
#include "IPair.h"
#include <vector>
#include <map>
typedef IPair *(*PairLoaderPtr)(std::ifstream& stream);
struct PairFactory
{
	void RegisterLoader(const std::string& typeName, PairLoaderPtr loader);
	PairLoaderPtr GetLoader(const std::string& typeName);
	static PairFactory& GetInstance();

private:
	std::map<std::string, PairLoaderPtr> _registered;
};

PZ11IPAIRBORODIN_API void RegisterLoaders();
PZ11IPAIRBORODIN_API void Save(std::ostream& stream, IPair** bases, int count);
PZ11IPAIRBORODIN_API std::vector<IPair *> Load(std::ifstream& stream);
PZ11IPAIRBORODIN_API bool Save(const char* fileName, IPair** objects, size_t size);
PZ11IPAIRBORODIN_API std::vector<IPair *> Load(const char* fileName);
