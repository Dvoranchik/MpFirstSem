
#include "stdafx.h"
#include "Let16StatisticBorodin.h"
#include "StopWords.h"
#include "Sings.h"
bool Statistic::IsSings(const char& value)
{
	static Sings sgn;
	return sgn.IsSings(value);
}

std::unordered_map<std::string,int> Statistic::Statistica(std::string storage)
{
	int i = 0;
	StopWords stop("StopVocabulary.txt");
	std::string str;
	std::unordered_map<std::string, int> preresult;
	storage += ' ';
	while(storage[i] != '\0')
	{
		storage[i] = tolower(storage[i]);
		if (!IsSings(storage[i]))
			str += storage[i];
		else
		{
			if (IsStopWord(stop, str))
			{
				str.clear();
				++i;
				continue;
			}
			if (!str.empty())
			{
				preresult[str]++;
				str.clear();
			}
		}
		++i;
	}
	return preresult;
}

bool IsStopWord( const StopWords& ob, const std::string& value)
{
	if (std::find_if(ob._data.begin(), ob._data.end(), ErrorWords(value))!=ob._data.end())
			return true;
	return false;
}

std::string Statistic::ReadText(const char* fileName)
{
	setlocale(LC_ALL, "ru");
	std::ifstream inFile(fileName);
	std::string str;
	std::string storage;
	while (getline(inFile, str))
	{
		storage += str;
	}
	return storage;
}

std::multimap<int, std::string,std::greater<int>> Statistic::ResultMap(const char* fileName, int count)
{
	std::unordered_map<std::string, int> prev = Statistica(ReadText(fileName));
	std::multimap<int, std::string, std::greater<int>> result;
	for (auto it = prev.begin(); it != prev.end(); ++it)
		result.emplace(it->second, it->first);
	auto i = result.begin();
	std::advance(i, count);
	result.erase(i, result.end());
	return result;
}

std::vector<std::pair<int, std::string>> Statistic::ResultVector(const char* fileName,int count)
{
	std::unordered_map<std::string, int> prev = Statistica(ReadText(fileName));
	std::vector<std::pair<int, std::string>> result;
	for (auto it = prev.begin(); it != prev.end(); ++it)
		result.push_back(make_pair(it->second, it->first));
	std::sort(result.begin(), result.end(), PredicatPair());
	auto i = result.begin();
	std::advance(i, count);
	result.erase(i, result.end());
	return result;
}

