#include "stdafx.h"
#include "Trigram.h"
#include "Delimiters.h"

bool Trigram::IsSings(const char& value)
{
	static Delimiters sgn;
	return sgn.IsSings(value);
}

std::pair<int, int> Trigram::Sum(std::pair<std::unordered_map<std::string, int>, std::unordered_map<std::string, int>> res)
{
	std::pair<int, int> Sum;
	for (auto i = res.first.begin(); i != res.first.end(); ++i)
		Sum.first += i->second;
	for (auto j = res.second.begin(); j != res.second.end(); ++j)
		Sum.second += j->second;

	return Sum;
}

void Trigram::StaticToFile(std::pair<std::multimap<double, std::string>, std::multimap<double, std::string>> res,std::string fileName,int procent)
{
	int ru = procent * _sumRU / 100;
	int eu = procent * _sumEU / 100;
	std::ofstream Fout(fileName);
	Fout << "Ru Words:"<<std::endl;
	auto ie = res.first.rbegin();
	auto ir = res.second.rbegin();
	advance(ie,ru);
	advance(ir,eu);
	for (auto i = res.first.rbegin(); i != ie; ++i)
		Fout << i->first <<'%'<< '\t' << i->second  << std::endl;
	Fout << std::endl;
	Fout << "Eu Words:"<<std::endl;
	for (auto j = res.second.rbegin(); j != ir; ++j)
		Fout << j->first << '%' << '\t' << j->second << std::endl;
	Fout.close();
}

std::pair<std::unordered_map<std::string, int>, std::unordered_map<std::string, int>> Trigram::TrigramList(std::string fileName)
{
	std::string storage = ReadText(fileName);
	storage += ' ';
	int i = 0;
	std::string strru;
	std::string streu;
	std::pair<std::unordered_map<std::string,int>, std::unordered_map<std::string,int>> twoLang;
	std::unordered_map<std::string, int> preresultru;
	std::unordered_map<std::string, int> preresulteu;
	while (storage[i]!='\0')
	{
		storage[i] = tolower(storage[i]);
			if (strru.size() != 3)
			{
				if (storage[i] >= 'à' && storage[i] <= 'ÿ')
				{
					if (streu.size() != 3)
					streu.clear();
					strru += storage[i];
				}
				else
				{
					if (IsSings(storage[i]))
						if (!strru.empty()&&strru.back() != ' ')
							strru += ' ';
				}
			}
			else
			{
				preresultru[strru]++;
				strru.erase(strru.begin());
				if (streu.empty())
				continue;
			}
			if (streu.size() != 3)
			{
				if (storage[i] >= 'a' && storage[i] <= 'z')
				{
					if (strru.size() != 3)
					strru.clear();
					streu += storage[i];
				}
				else
				{
					if (IsSings(storage[i]))
						if (!streu.empty()&&streu.back() != ' ')
							streu += ' ';
				}
			}
			else
			{
				preresulteu[streu]++;
				streu.erase(streu.begin());
				if(strru.empty())
				continue;
			}
		++i;
	}
	twoLang.first = preresultru;
	twoLang.second = preresulteu;
	return twoLang;
}

std::string Trigram::ReadText(std::string fileName)
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

std::pair<std::multimap<double, std::string>, std::multimap<double, std::string>> Trigram::Statistic(std::string fileName)
{
	std::pair<std::unordered_map<std::string, int>, std::unordered_map<std::string, int>> preres = TrigramList(fileName);
	std::pair<std::multimap<double, std::string>, std::multimap<double, std::string>> result;
	_sumRU = Sum(preres).first;
	_sumEU = Sum(preres).second;
	for (auto i = preres.first.begin(); i != preres.first.end(); ++i)
	{
		result.first.emplace(100*(double)i->second / _sumRU, i->first);
	}

	for (auto j = preres.second.begin(); j != preres.second.end(); ++j)
	{
		result.second.emplace(100*(double)j->second / _sumEU,j->first);
	}
	return result;
}


